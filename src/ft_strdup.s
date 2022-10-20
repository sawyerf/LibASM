global ft_strdup

extern ft_strcpy
extern ft_strlen
extern malloc

section .text
ft_strdup:
    call ft_strlen
    push rdi
    mov rdi, rax
    inc rdi
    call malloc
    cmp rax, 0
    jz error
    lea rdi, [rax]
    pop rsi
    call ft_strcpy
    ret
    error:
        pop rdi
        ret