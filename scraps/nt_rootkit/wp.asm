;
;       wp.asm
;
;       Assembly implementation for disabling and enabling the write-protect
;       bit in x64 Windows.
;

.code

;
;       Disables the write-protect bit.
;
disable_wp PROC PUBLIC

cli
push rbx
mov rbx, cr0
and rbx, 0FFFFFFFFFFFEFFFFh
mov cr0, rbx
pop rbx
ret

disable_wp ENDP

;
;       Enables the write-protect bit.
;
enable_wp PROC PUBLIC

push rbx
mov rbx, cr0
or rbx, 0000000000010000h
mov cr0, rbx
pop rbx
sti
ret

enable_wp ENDP

END