global ft_write
extern __errno_location

ft_write:                           ; rdi = fd, rsi = buf, rdx = count
    mov rax, 1                      ; sys_write
    syscall                         ; perform the system call
error_handling:
    cmp rax, 0
    jns .return                     ; if not, skip the error handling
    mov rdi, rax                    ; copy the error value
    neg rdi                         ; negate the value to make it positive
    call __errno_location WRT ..plt ; get the address of errno
    mov [rax], edi                  ; set errno to the error number
    mov rax, -1                     ; set the return value to -1
.return:
    ret                             ; return

section .note.GNU-stack progbits
