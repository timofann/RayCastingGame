UNAME			=	$(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_FLAGS := -framework OpenGL -framework AppKit
endif

ifeq ($(UNAME), Linux)
	MLX_FLAGS := -lm -lbsd -lX11 -lXext
endif

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -std=c89
NAME			=	cub3d
BONUS_NAME		=	cub3d_bonus

HEADERS			=	include/cubbster_play.h			include/cub3d.h				\
					include/cubbster_colors.h		include/cubbster_errors.h	\
					include/cubbster_keycodes.h		include/get_next_line.h

PARSE_SRC		=	check_map_borders.c				making_map.c				\
            		find_player.c					parse_utils.c				\
            		get_next_line.c					parsing.c					\
            		get_next_line_utils.c			set_params.c				\
            		get_textures.c					utils.c						\
            		init_struct.c

PLAY_SRC		=	cast_rays.c						put_error.c					\
            	    cast_sprites.c					put_info.c					\
            	    cast_wall.c						put_pixel.c					\
            	    clear_sprites_info.c			set_hooks_for_drawing.c		\
            	    draw_minimap.c					set_new_image.c				\
            	    draw_state.c					set_new_window.c			\
            	    get_color.c						set_ray_info.c				\
            	    get_distance_for_step.c			set_start_image.c			\
            	    init_workspace.c				update_sprite_info.c		\
            	    main.c

PARSE_OBJ		=	$(addprefix obj/, $(PARSE_SRC:.c=.o))
PLAY_OBJ		=	$(addprefix obj/, $(PLAY_SRC:.c=.o))
BONUS_PARSE_OBJ	=	$(addprefix bonus_obj/, $(PARSE_SRC:.c=.o))
BONUS_PLAY_OBJ	=	$(addprefix bonus_obj/, $(PLAY_SRC:.c=.o))

.PHONY : all bonus clean fclean re bre norm

all : FTLIB MLXLIB obj $(NAME)
	@printf '\033[3;37m---   Cub3D tasks completed. There is nothing else to be done. ---\033[0m\n'

bonus : FTLIB MLXLIB bonus_obj $(BONUS_NAME)
	@printf '\033[3;37m---   Cub3D tasks completed. There is nothing else to be done. ---\033[0m\n'

$(NAME): $(PARSE_OBJ) $(PLAY_OBJ)
	$(CC) $(PARSE_OBJ) $(PLAY_OBJ) -Llibft -lft -Lminilibx_$(UNAME) -lmlx $(MLX_FLAGS) -o $(NAME) 2> cub3d_warnings.txt
	@printf '\033[3;36mCub3D: successful compilation\033[0m\n'

$(PLAY_OBJ): obj/%.o: play_src/%.c $(HEADERS)
	@printf '\033[37m'
	$(CC) $(CFLAGS) -Iminilibx_$(UNAME)/mlx.h -Ilibfl/libft.h -c $< -o $@
	@printf '\033[0m'

$(PARSE_OBJ): obj/%.o: parse_src/%.c $(HEADERS)
	@printf '\033[37m'
	$(CC) $(CFLAGS) -Iminilibx_$(UNAME)/mlx.h -Ilibfl/libft.h -c $< -o $@
	@printf '\033[0m'

$(BONUS_NAME): $(BONUS_PARSE_OBJ) $(BONUS_PLAY_OBJ)
	$(CC) $(BONUS_PARSE_OBJ) $(BONUS_PLAY_OBJ) -Llibft -lft -Lminilibx_$(UNAME) -lmlx $(MLX_FLAGS) -o $(BONUS_NAME) 2> cub3d_warnings.txt
	@printf '\033[3;36mCub3D: successful bonus compilation\033[0m\n'

$(BONUS_PLAY_OBJ): bonus_obj/%.o: play_src/%.c $(HEADERS)
	@printf '\033[37m'
	$(CC) $(CFLAGS) -DBONUS=1 -Iminilibx_$(UNAME)/mlx.h -Ilibfl/libft.h -c $< -o $@
	@printf '\033[0m'

$(BONUS_PARSE_OBJ): bonus_obj/%.o: parse_src/%.c $(HEADERS)
	@printf '\033[37m'
	$(CC) $(CFLAGS) -DBONUS=1 -Iminilibx_$(UNAME)/mlx.h -Ilibfl/libft.h -c $< -o $@
	@printf '\033[0m'

obj :
	@mkdir obj

bonus_obj :
	@mkdir bonus_obj

FTLIB :
	cd libft && make

MLXLIB :
	cd minilibx_$(UNAME) && make

clean :
	rm -rf obj bonus_obj cub3d_warnings.txt
	@printf '\033[3;36mCub3D: object files removed\033[0m\n'
	cd libft && make clean
	cd minilibx_$(UNAME) && make clean

fclean : clean
	rm -rf $(BONUS_NAME) $(NAME) libft/libft.a minilibx_$(UNAME)/libmlx.a

re : fclean all

bre : fclean bonus

norm :
	@printf '\033[3;33m--- NORMINETTE LIBFT ---\033[0m\n'
	norminette libft
	@printf '\033[3;36m--- NORMINETTE CUB3D ---\033[0m\n'
	norminette include
	norminette parse_src
	norminette play_src
