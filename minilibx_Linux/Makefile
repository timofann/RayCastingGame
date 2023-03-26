


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)
	@rm -f minilibx_warnings.txt
	@printf '\033[3;37m--- Minilibx tasks completed. There is nothing else to be done. ---\033[0m\n'

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@2>>minilibx_warnings.txt swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@printf '\n\033[3;34mMinilibx compiled\033[0m\n'

%.o: %.swift
	@2>>minilibx_warnings.txt swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'

%.swiftmodule: %.swift
	@2>>minilibx_warnings.txt swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'

clean:
	rm -f $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
	@printf '\033[3;34mMinilibx is cleaned\033[0m\n'

fclean: clean
	rm -f $(NAME)

re : fclean all

