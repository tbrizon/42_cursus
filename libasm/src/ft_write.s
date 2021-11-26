bits 64
%define MACH_SYSCALL(nb)    0x2000000 |  nb
%define WRITE               4
extern	___error

section .text
    global _ft_write

_ft_write:
    mov rax, MACH_SYSCALL(WRITE)
    syscall                     ; if syscall fails, carry flag will be set
    jc error_plusfraiche        ; jump to error if cf is set
    ret

error:                          ; normally it's in C but we need to set the errno value to trigger good STR_ERROR message
    push    r15                 ; save r15 on the stack
    mov     r15, rax            ; store the returned value we need to push in erno adress
	call ___error               ; errno location return the adresse of erno, so in RAX i will have the adress of erno

	mov     [rax], r15             ; going to the adresse stored in rax, put our previous return value in it
	pop     r15                    ; take the stacked saved value of r15
	mov     rax, -1                ; moving our classic error value
	ret

error_plusfraiche:
    push    rax                    ; push rax on stack
    call    ___error               ; calling error, now we have adress of erno in rax
    pop     qword [rax]             ; pop rax into [rax], using qword (64bits) cause operation size must be specified
    mov     rax, -1
    ret


