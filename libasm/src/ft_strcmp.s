bits 64

section .text
    global _ft_strcmp

_ft_strcmp:
     xor rcx, rcx           ; we take the register usually used for inc
     xor rax, rax
     test rdi, rdi          ; if s1 == '\0'
     je return
     test rsi, rsi          ; if s2 == '\0'
     je return

next:
    cmp BYTE [rdi, rcx], 0x0; if s1[i] == '\0'
    jz return
    cmp BYTE [rsi, rcx], 0x0; if s2[i] == '\0'
    jz return

    mov al, [rdi + rcx]      ;extract s1[i] value to a 8 bits register c=s1[i]
    cmp BYTE [rsi + rcx], al ;s2[i] == c ? zf = 1 : zf = 0
    jnz return               ;if zf == 0 jmp
    inc rcx
    jmp next




return:
    movzx rax, BYTE[rdi + rcx] ; stock the last byte in rdi + rcx to compare
    movzx rdx, BYTE[rsi + rcx] ; same
    sub rax, rdx               ; compare
    ret