%include "include.inc"
section .text

strncmp:
    xor rax, rax
    xor rcx, rcx

loop:
    cmp rdx, rcx
    je end
    mov dl, BYTE [rdi + rcx]
    mov r8b, BYTE [rsi + rcx]
    cmp dl, r8b
    cmp dl, 0
    je end
    inc rcx

diff:
    movsx eax, dl
    movsx ebx, r8b
    sub eax, ebx

end:
    ret