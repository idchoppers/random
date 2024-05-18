#include "idt.h"

void dump_idt() {
        KDESCRIPTOR64 descr;
        __sidt(&descr.Limit);

        ULONG n = (descr.Limit + 1) / sizeof(KIDTENTRY64);

        if (n)
        {
                int i = 0;
                KIDTENTRY64* pidte = (KIDTENTRY64*)descr.Base;

                do
                {
                        ULONG_PTR addr =
                                ((ULONG_PTR)pidte->OFFSETS.OffsetHigh << 32)
                                + ((ULONG_PTR)pidte->OFFSETS.OffsetMiddle << 16)
                                + pidte->OFFSETS.OffsetLow;

                        DbgPrint("Interrupt %u -> %p\n", i++, addr);

                } while (pidte++, --n);
        }
}

/*
KIDTENTRY64 GetIDTAddress() {
        KDESCRIPTOR64 idt_addr;
        _disable();
        __sidt(&idt_addr.Limit);
        _enable();

        return idt_addr;
}*/

/*void hook_idt(_In_ UINT16 service, _In_ UINT32 hook_addr,
        _Out_ UINT32 old_isr_addr) {
        UINT32 isr_addr;
        UINT16 hook_addr_low;
        UINT16 hook_addr_high;
        KIDTENTRY64* descr_addr;

        isr_addr = GetISRAddress(service);

}*/