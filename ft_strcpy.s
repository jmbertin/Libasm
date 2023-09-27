global ft_strcpy

ft_strcpy:                  ; rdi = dest, rsi = src
    xor rcx, rcx            ; initialize the counter to 0

.loop:
    mov al, [rsi + rcx]     ; load a byte from the src and write it to the dest
    mov [rdi + rcx], al
    cmp al, 0               ; check if we have reached the end of the string
    je .return
    inc rcx
    jmp .loop

.return:
    mov rax, rdi
    ret

section .note.GNU-stack progbits
