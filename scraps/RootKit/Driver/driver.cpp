/*+===================================================================
  File:      driver.cpp

  Summary:   Contains the main code of the RootKit and related helper 
			 functions.

  Author:    idchoppers
  Date:      2/25/2024
===================================================================+*/

/*--------------------------------------------------------------------
  Headers & Globals
--------------------------------------------------------------------*/

#include <ntddk.h>
#include <ntifs.h>
#include "RootKit.h"
#include "AutoLock.h"
#include "Mutex.h"
#include "FastMutex.h"
#include "SysMonCommon.h"
#include "SysMon.h"

Globals g_Globals;

EprocessOffsets EpOffsets;
EthreadOffsets EtOffsets;

/*--------------------------------------------------------------------
  Prototypes
--------------------------------------------------------------------*/

void
RootKitUnload (_In_ PDRIVER_OBJECT DriverObject);

NTSTATUS
RootKitCreateClose (_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp);

void
OnProcessNotify (PEPROCESS Process, HANDLE ProcessId, PPS_CREATE_NOTIFY_INFO CreateInfo);

void
PushItem (LIST_ENTRY* entry);

NTSTATUS
RootKitRead (PDEVICE_OBJECT, PIRP Irp);

/*
NTSTATUS
RootKitDeviceControl (PDEVICE_OBJECT, PIRP Irp);
*/

/*--------------------------------------------------------------------
  Entry
--------------------------------------------------------------------*/

extern "C"
NTSTATUS
RootKitEntry (_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	// Create a Device Object & symbolic link so client can comm with driver
	// Hide Process:
	//  1. Recieve ProcID from client
	//  2. Use CONTAINING_RECORD () to look through the process list
	//     starting at PsActiveProcessHead
	//  3. Hide the process in a way that evades patch guard (somehow)

	/*
	auto status = STATUS_SUCCESS;

	InitializeListHead (&g_Globals.ItemsHead);
	g_Globals.Mutex.Init ();

	PDEVICE_OBJECT DeviceObject = nullptr;
	UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\RootKit");
	bool symLinkCreated = false;

	do
	{
		UNICODE_STRING devName = RTL_CONSTANT_STRING(L"\\Device\\RootKit");
		status = IoCreateDevice(
			DriverObject,
			0,
			&devName,
			FILE_DEVICE_UNKNOWN,
			0,
			TRUE,
			&DeviceObject
		);

		if (!NT_SUCCESS (status))
		{
			DbgPrint(("failed to create device object (0x%08X)\n"), status);
			break;
		}
		DeviceObject->Flags |= DO_DIRECT_IO;

		status = IoCreateSymbolicLink(&symLink, &devName);

		if (!NT_SUCCESS (status))
		{
			DbgPrint(("Failed to create symbolic link (0x%08X)\n"), status);
			break;
		}
		symLinkCreated = true;

		status = PsSetCreateProcessNotifyRoutineEx (OnProcessNotify, FALSE);
		if (!NT_SUCCESS(status))
		{
			DbgPrint(("Failed to register process callback (0x%08X)\n"), status);
			break;
		}
	} while (false);

	if (!NT_SUCCESS(status))
	{
		if (symLinkCreated)
			IoDeleteSymbolicLink (&symLink);
		if (DeviceObject)
			IoDeleteDevice (DeviceObject);
	}

	DriverObject->DriverUnload = RootKitUnload;
	DriverObject->MajorFunction[IRP_MJ_CREATE] =
		DriverObject->MajorFunction[IRP_MJ_CLOSE] = RootKitCreateClose;
	DriverObject->MajorFunction[IRP_MJ_READ] = RootKitRead;
	*/



	return STATUS_SUCCESS;
}

/*--------------------------------------------------------------------
  Defenitions
--------------------------------------------------------------------*/

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: RootKitUnload

  Summary:  Deletes symbolic link and device object.

  Args:     PDRIVER_OBJECT DriverObject
			  The driver to unload.
-----------------------------------------------------------------F-F*/
void
RootKitUnload (_In_ PDRIVER_OBJECT DriverObject)
{
	//PsSetCreateProcessNotifyRoutineEx (OnProcessNotify, TRUE);

	UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\RootKit");
	IoDeleteSymbolicLink (&symLink);
	IoDeleteDevice (DriverObject->DeviceObject);

	while (!IsListEmpty(&g_Globals.ItemsHead))
	{
		auto entry = RemoveHeadList (&g_Globals.ItemsHead);
		ExFreePool (CONTAINING_RECORD (entry, FullItem<ItemHeader>, Entry));
	}
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: RootKitCreateClose

  Summary:  Handles creation and closing of IRP from client to driver.

  Args:     PDRIVER_OBJECT DriverObject
			  The driver to listen for IRP.
			PIRP Irp
			  The IRP provided by client.
-----------------------------------------------------------------F-F*/
NTSTATUS
RootKitCreateClose (_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp)
{
	UNREFERENCED_PARAMETER (DeviceObject);

	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest (Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: OnProcessNotify

  Summary:  Performs actions when it is notified of process creation.

  Args:     PEPROCESS Process
			  The process to perform actions to.
			HANDLE ProcessId
			  The process handle.
			PPS_CREATE_NOTIFY_INFO CreateInfo
			  The process creation info from the notifier.
-----------------------------------------------------------------F-F*/
void
OnProcessNotify (PEPROCESS Process, HANDLE ProcessId, PPS_CREATE_NOTIFY_INFO CreateInfo)
{
	if (CreateInfo)
	{
		USHORT allocSize = sizeof (FullItem<ProcessCreateInfo>);
		USHORT commandLineSize = 0;

		if (CreateInfo->CommandLine)
		{
			commandLineSize = CreateInfo->CommandLine->Length;
			allocSize += commandLineSize;
		}

		auto info = (FullItem<ProcessCreateInfo>*)ExAllocatePoolWithTag (PagedPool,
			allocSize, DRIVER_TAG);

		if (info == nullptr)
		{
			DbgPrint ("failed allocation\n");
			return;
		}

		auto& item = info->Data;
		KeQuerySystemTimePrecise (&item.Time);
		item.Type = ItemType::ProcessCreate;
		item.Size = sizeof (ProcessCreateInfo) - commandLineSize;
		item.ProcessId = HandleToULong (ProcessId);
		item.ParentProcessId = HandleToULong (CreateInfo->ParentProcessId);

		if (commandLineSize > 0)
		{
			::memcpy ((UCHAR*)&item + sizeof (item), CreateInfo->CommandLine->Buffer,
				commandLineSize);
			item.CommandLineLength = commandLineSize / sizeof (WCHAR);
			item.CommandLineOffset = sizeof (item);
		}
		else
		{
			item.CommandLineLength = 0;
		}
		PushItem (&info->Entry);
	}
	else
	{
		auto info = (FullItem<ProcessExitInfo>*)ExAllocatePoolWithTag(PagedPool, sizeof (FullItem<ProcessExitInfo>), DRIVER_TAG);
		
		if (info == nullptr)
		{
			DbgPrint ("failed to allocate\n");
			return;
		}

		auto& item = info->Data;
		KeQuerySystemTimePrecise (&item.Time);
		item.Type = ItemType::ProcessExit;
		item.ProcessId = HandleToULong (ProcessId);
		item.Size = sizeof (ProcessExitInfo);

		PushItem (&info->Entry);
	}
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: PushItem

  Summary:  Pushes an entry onto the process list.

  Args:     LIST_ENTRY* entry
			  The entry to push.
-----------------------------------------------------------------F-F*/
void
PushItem (LIST_ENTRY* entry)
{
	AutoLock<FastMutex> lock (g_Globals.Mutex);

	if (g_Globals.ItemCount > 1024)
	{
		auto head = RemoveHeadList (&g_Globals.ItemsHead);
		--g_Globals.ItemCount;
		auto item = CONTAINING_RECORD (head, FullItem<ItemHeader>, Entry);
		ExFreePool (item);
	}

	InsertTailList (&g_Globals.ItemsHead, entry);
	g_Globals.ItemCount++;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function: RootKitRead

  Summary:  Read request for the user's buffer.

  Args:     PDRIVER_OBJECT
			  The driver object to operate with.
			PIRP
			  The IRP to read.
-----------------------------------------------------------------F-F*/
NTSTATUS
RootKitRead (PDEVICE_OBJECT, PIRP Irp)
{
	auto stack = IoGetCurrentIrpStackLocation (Irp);
	auto len = stack->Parameters.Read.Length;
	auto status = STATUS_SUCCESS;
	auto count = 0;
	NT_ASSERT (Irp->MdlAddress);

	auto buffer = (UCHAR*)MmGetSystemAddressForMdlSafe (Irp->MdlAddress,
		NormalPagePriority);
	if (!buffer)
	{
		status = STATUS_INSUFFICIENT_RESOURCES;
	}
	else
	{
		AutoLock lock(g_Globals.Mutex);

		while (true)
		{
			if (IsListEmpty(&g_Globals.ItemsHead)) break;

			auto entry = RemoveHeadList (&g_Globals.ItemsHead);
			auto info = CONTAINING_RECORD (entry, FullItem<ItemHeader>, Entry);
			auto size = info->Data.Size;

			if (len < size)
			{
				InsertHeadList (&g_Globals.ItemsHead, entry);
				break;
			}

			--g_Globals.ItemCount;
			::memcpy (buffer, &info->Data, size);
			len -= size;
			buffer += size;
			count += size;

			ExFreePool (info);
		}
		
		Irp->IoStatus.Status = status;
		Irp->IoStatus.Information = count;
		IoCompleteRequest (Irp, 0);
		return status;
	}
}

/*
NTSTATUS
RootKitDeviceControl(PDEVICE_OBJECT, PIRP Irp)
{
	auto stack = IoGetCurrentIrpStackLocation (Irp);
	auto status = STATUS_SUCCESS;

	switch (stack->Parameters.DeviceIoControl.IoControlCode)
	{
	case IOCTL_ROOTKIT_SET_PRIORITY:

		if (stack->Parameters.DeviceIoControl.InputBufferLength < sizeof (ThreadData))

		break;
	default:
		status = STATUS_INVALID_DEVICE_REQUEST;
		break;
	}

	Irp->IoStatus.Status = status;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest (Irp, IO_NO_INCREMENT);

	return status;
}
*/