# 🧬 LibASM
The aim of this project is to get familiar with assembly language. 

## Functions
```C
size_t  ft_strlen(char *str);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
```

## Note
### Variables
| x64     | x32       | What is ?               |
|:-------:|:---------:|-------------------------|
| RAX     | EAX       | Return Value            |
| RCX     | ECX       | Counter (or Fourth Arg) |
| RDX     | EDX       | Third Arg               | 
| RSI     | ESI       | Second Arg              |
| RDI     | EDI       | First Arg of Function   |
| RSP     | ESP       | Stack Pointer           |
| RIP     | EIP       | Next Instruction        |
| R8-R11  | r8d-r11d  | Scratch register        |
| R12-R15 | r12d-r15d | Preserved register      |

[Source](https://www.cs.uaf.edu/2017/fall/cs301/lecture/09_11_registers.html)

## Operation
| Operation             | Explication             |
|:----------------------|-------------------------|
| **MOV** size dest,src | dest ← src              |
| **LEA** dest,\[op\]   | dest ← addr op          |
| **PUSH** op           | Increase RSP & Store op |
| **POP** op            | Load op & Discrease RSP |
|                       |                         |
| **ADD** op1,op2       | op1 ← op1 + op2         |
| **SUB** op1,op2       | op1 ← op1 - op2         |
| **NEG** reg           | reg ← -reg              |
| **INC** reg           | reg ← reg + 1           |
| **DEC** reg           | reg ← reg - 1           |
|                       |                         |
| **AND** op1,op2       | op1 ← op1 & op2         |
| **OR**  op1,op2       | op1 ← op1 | op2         |
| **XOR** op1,op2       | op1 ← op1 ^ op2         |
|                       |                         |
| **CMP** op1,op2       | op1 - op2               |
| **TEST** op1,op2      | op1 & op2               |
| **JMP** op            | Jump to op              |

[Source - Page 21](https://www.lacl.fr/tan/asm)

## Links
- [List syscall](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
