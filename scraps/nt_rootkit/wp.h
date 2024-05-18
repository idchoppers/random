/*
        wp.h

        Used to disable or enable the write-protect
        bit in the cr0 register, for 32 bit, implement
        these in inline asm, for 64 bit, implement them in
        an asm source file, then compile and link the object.
*/

#ifndef _WP_H_
#define _WP_H_

int __stdcall disable_wp();
int __stdcall enable_wp();

#endif