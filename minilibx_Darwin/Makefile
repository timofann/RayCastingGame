#
#

NOM=libmlx.a
SRC1= mlx_shaders.c mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c
SRC2= mlx_mouse.m mlx_new_window.m mlx_init_loop.m mlx_new_image.m
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

.PHONY : all clean re

all: $(NOM)
	@rm -f minilibx_warnings.txt
	@printf '\033[3;37m--- Minilibx tasks completed. There is nothing else to be done. ---\033[0m\n'

$(NOM): $(OBJ1) $(OBJ2)
	@2>>minilibx_warnings.txt ar -r $(NOM) $(OBJ1) $(OBJ2)
	@ranlib $(NOM)
	@printf '\n\033[3;34mMinilibx compiled\033[0m\n'

$(OBJ1): %.o: %.c
	@2>>minilibx_warnings.txt cc -O2 -DSTRINGPUTX11   -c -o $@ $<
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'

$(OBJ2): %.o: %.m
	@2>>minilibx_warnings.txt cc -O2 -DSTRINGPUTX11   -c -o $@ $<
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'
	@printf '\033[3;37m█\033[0m'


clean:
	@rm -f mlx_app $(OBJ1) $(OBJ2) *~
	@printf '\033[3;34mMinilibx is cleaned\033[0m\n'

fclean: clean
	@rm -f $(NOM)


re: fclean all
