%include "include.inc"
section .text

memcpy:

    xor rbx, rbx
    cmp	rdi, 0
	je stop
	cmp rsi, 0
	je stop
	cmp rdx, 0
	jg loop
	jmp stop

loop:

    cmp BYTE [rsi + rbx], 0
    je stop
    cmp rdx, rbx
    je stop
    mov rcx, [rsi + rbx]
    mov [rdi + rbx], rcx
    inc rbx
    jmp loop

stop:

    mov rax, rdi
    ret