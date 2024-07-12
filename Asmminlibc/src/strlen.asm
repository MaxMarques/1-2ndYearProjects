%include "include.inc"
section .text

strlen:

    xor rax, rax

loop:

    cmp BYTE [rdi], 0
    je stop
    inc rax
    inc rdi
    jmp loop

stop:

    ret