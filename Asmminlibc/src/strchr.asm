%include "include.inc"
section .text

strchr:

    xor rax, rax
    cmp rdi, 0
    je stop_null

loop:

    cmp BYTE [rdi + rax], sil
    je stop
    cmp BYTE [rdi + rax], 0
    je stop_null
    inc rax
    jmp loop

stop:

    add rdi, rax
    mov rax, rdi
    ret

stop_null:

    mov rax, 0
    ret