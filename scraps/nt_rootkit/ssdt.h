/*
        ssdt.h

        Used to define hooking and manipulating the ssdt in x64 Windows.
*/

#ifndef _SSDT_H_
#define _SSDT_H_

#include <ntddk.h>

/*
        Defines the System Service Table.
*/
typedef struct SST
{
        UINT32* ServiceTable;
        UINT32* CounterTable;
        UINT32 ServiceLimit;
        UINT32* ArgumentTable;
} SST;

/*
        A prototype of the NtCreateFile service.
*/
typedef NTSTATUS(*NtCreateFilePrototype)(PHANDLE FileHandle,
        ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes,
        PIO_STATUS_BLOCK IoStatusBlock, PLARGE_INTEGER AllocationSize,
        ULONG FileAttributes, ULONG ShareAccess, ULONG CreateDisposition,
        ULONG CreateOptions, PVOID EaBuffer, ULONG EaLength);

/*
        The NtCreateFile service.
*/
NTSYSAPI NTSTATUS NtCreateFile(PHANDLE FileHandle, 
        ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, 
        PIO_STATUS_BLOCK IoStatusBlock, PLARGE_INTEGER AllocationSize, 
        ULONG FileAttributes, ULONG ShareAccess, ULONG CreateDisposition, 
        ULONG CreateOptions, PVOID EaBuffer, ULONG EaLength);

/*
        The hooked NtCreateFile service.
*/
NTSTATUS hook_ntcreatefile(PHANDLE FileHandle, ACCESS_MASK DesiredAccess,
        POBJECT_ATTRIBUTES ObjectAttributes, PIO_STATUS_BLOCK IoStatusBlock,
        PLARGE_INTEGER AllocationSize, ULONG FileAttributes, ULONG ShareAccess,
        ULONG CreateDisposition, ULONG CreateOptions, PVOID EaBuffer,
        ULONG EaLength);

/*
        Finds a service function and replaces 
        its address with the hooked function.
*/
PULONG hook_ssdt(UINT32 user_syscall, PULONG function, PLONG hook_function);

#endif