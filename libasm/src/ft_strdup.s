bits 64
%define MACH_SYSCALL(nb)    0x2000000 |  nb
%define WRITE               4
extern ___error
extern _malloc
global _ft_strdup
extern _ft_strlen
extern _ft_strcpy

;rdi, rsi, rdx, rcx, r8, r9.
section .text
    global _ft_strdup

_ft_strdup:
    push rdi          ;save s on stack cause we will use rsi for malloc
    call _ft_strlen ;rax = len(s)
    inc rax         ; len(s) ++ cause of the \0

    mov rdi, rax    ; put len(s) in rsi, register used by malloc to alocate space
    call _malloc    ; will return on rax my allocate space
    cmp rax, 0      ; if malloc failed
    jz  error       ;
    pop rsi         ; take stacked rsi and pop it on rdi
    mov rdi, rax    ; put my allocated memory on rdi, who will be used as dest
    call _ft_strcpy ; cpy on my new space s

    ret


error:
    push rax
    call ___error
    pop qword [rax]
    mov rax, -1
    ret



return:
    mov rax, rdi
    ret
