global ft_strcmp

ft_strcmp:
    xor     rcx, rcx        ; initialize the counter to 0

.loop:
    mov     al, [rdi + rcx] ; load a byte from s1
    mov     bl, [rsi + rcx] ; load a byte from s2
    cmp     al, bl          ; compare the two bytes
    jne     .return
    cmp     al, 0           ; check if we have reached the end of either strings
    je      .return
    inc     rcx
    jmp     .loop

.return:
    movzx   eax, al         ; Zero-extend the lower 8 bits of al to 32 bits
    movzx   ebx, bl         ; Zero-extend the lower 8 bits of bl to 32 bits
    sub     eax, ebx        ; Calculate the difference between the two bytes
    ret

section .note.GNU-stack progbits
