%include "include.inc"
section .text

strcmp:

    xor rax, rax

loop:

    mov r8b, [rsi]
    cmp [rdi], r8b
    jne stop
    cmp byte[rdi], 0
    je stop_null
    cmp byte[rsi], 0
    inc rsi
    inc rdi
    jmp loop

stop:

    mov rax, [rdi]
    sub rax, [rsi]
    ret

stop_null:

    ret