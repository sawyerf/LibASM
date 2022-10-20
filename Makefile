NAME = libasm.a

CC = nasm

CFLAGS = -f elf64

SRC_DIR = src

SRC_FILE = 	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \


OBJ_DIR = .obj
OBJ_FILE = $(SRC_FILE:.s=.o)

CRT_DIR = .

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILE))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILE))
CRT = $(addprefix $(OBJ_DIR)/,$(CRT_DIR))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s Makefile
	@printf "\033[0;32m[Libft] Compilation [o.]\033[0;0m\r"
	@mkdir -p $(CRT) 2> /dev/null || true
	$(CC) $(CFLAGS) $< -o $@
	@printf "\033[0;32m[Libft] Compilation [.o]\033[0;0m\r"

$(NAME): $(OBJ)
	@printf "\033[0;32m[Libft] Compilation [OK]\033[0;0m\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc -I inc test.c libasm.a -o test -no-pie

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)
	@printf "\033[0;31m[Libft] Deleted *.o\033[0;0m\n"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
