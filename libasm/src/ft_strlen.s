bits 64

section .text
    global _ft_strlen

return:
    mov rax, rcx            ; move the value contained on rcx on rax, rax is the register used for return values
    ret

_ft_strlen:
     xor rcx, rcx           ; we take the register usually used for inc

loop:
    cmp byte [rdi + rcx], 0 ; checking if the value in rdi (our string) is \0
    jz return               ; if zf === 0 (zf is the return of cmp), do the instruction
    inc rcx
    jmp loop




