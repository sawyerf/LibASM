global ft_strlen

section .text
ft_strlen:
	lea rax, [rdi]
    loop:
        cmp byte[rax], 0x00
        jz endloop
        inc rax
        jmp loop
    endloop:
        sub rax, rdi
        ret