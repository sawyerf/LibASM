global ft_strcmp

section .text
ft_strcmp:
    movzx rax, byte[rdi]
    cmp byte [rsi], al
    jnz ret
    cmp byte[rsi], 0x00
    jz ret
    inc rdi
    inc rsi
    jmp ft_strcmp
    ret:
        movzx rcx, byte[rsi]
        sub rax, rcx
        ret