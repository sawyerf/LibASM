global ft_strdup

extern ft_strcpy
extern ft_strlen

section .text
ft_strdup:
    call ft_strlen
    call malloc