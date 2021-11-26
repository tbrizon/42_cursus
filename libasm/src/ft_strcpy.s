bits 64

section .text
    global _ft_strcpy


_ft_strcpy:
    mov rax, rdi    ; dest is the default return value
    test rdi, rdi   ; rdi ?
    jz return
    test rsi, rsi
    jz return

    xor rcx, rcx  ; cmpt = 0

next:
    cmp byte[rsi + rcx], 0x0    ; if src[i] = '\0' -> zf = 1
    mov al, [rsi + rcx]         ; tmp[i] = src[i], al fait 1 octet
    mov [rdi + rcx], al
    je  return                  ; jmp if zf == 1
    inc rcx                     ; i++
    jmp next


return:
    mov rax, rdi
    ret
