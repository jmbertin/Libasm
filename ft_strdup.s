global  ft_strdup
extern  malloc
extern  ft_strlen
extern  ft_strcpy
extern  __errno_location

ft_strdup:                          ; rdi = src
    cmp     rdi, 0                  ; check if src is NULL
    jz      error
    push    rdi                     ; save src (we need rdi for ft_strlen)
    call    ft_strlen               ; rax = ft_strlen(src) = source's size
    mov     rdi, rax
    inc     rdi                     ; add 1 for '\0'

    call	malloc WRT ..plt        ; malloc(length = rdi)
    cmp     rax, 0                  ; check if malloc failed
    jz      error

    mov     rdi, rax                ; dest for ft_strcpy
    pop     rsi                     ; restore src for ft_strcpy
    call    ft_strcpy               ; ft_strcpy(dest, src)
    jmp		return

error:
    xor     rax, rax                    ; set rax = NULL
    call    __errno_location WRT ..plt  ; Get the address of errno
    mov     dword [rax], 12             ; Set errno to ENOMEM
return:
    ret

section .note.GNU-stack progbits
