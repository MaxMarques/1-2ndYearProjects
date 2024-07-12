%include "include.inc"
section .text

memset:

    xor rax, rax
    cmp rdi, 0
    je stop_null
    cmp rdx, 0
    jg loop
    jmp stop_null

loop:

    cmp rdx, 0
    je stop
    mov BYTE [rdi + rax], sil
    je stop
    dec rdx
    inc rax
    jmp loop

stop:

    mov rax, rdi
    ret

stop_null:

    mov rax, 0
    ret