/*
        idt.h

        Defines hooking the Interrupt Descriptor Table and manipulating it
        in x64 Windows.
*/

#ifndef _IDT_H_
#define _IDT_H_

#include <ntddk.h>

typedef union _KIDTENTRY64 {
        struct _OFFSETS {
                USHORT OffsetLow;
                USHORT Selector;
                USHORT IstIndex : 3;
                USHORT Reserved0 : 5;
                USHORT Type : 5;
                USHORT Dpl : 2;
                USHORT Present : 1;
                USHORT OffsetMiddle;
                ULONG OffsetHigh;
                ULONG Reserved1;
        } OFFSETS;
        UINT64 Alignment;
} KIDTENTRY64;

typedef struct _KDESCRIPTOR64 {
        USHORT Pad[3];
        USHORT Limit;
        PVOID Base;
} KDESCRIPTOR64;

void dump_idt();

#endif