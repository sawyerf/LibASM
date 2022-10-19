global ft_strcpy

section .text
ft_strcpy:
    lea rax, [rdi]
    loop:
        cmp byte[rsi], 0x00
        jz return
        mov cl, byte[rsi]
        mov byte[rdi], cl
        inc rdi
        inc rsi
        jmp loop
    return:
        mov byte[rdi], 0x00
        ret