/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:28:20 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:49 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BONUS
#  define BONUS 0
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "../minilibx_Darwin/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include "cubbster_errors.h"

# define BLOCK_SIZE 100

typedef struct s_image {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_image;

typedef struct s_textures {
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
	t_image		sprite0;
	t_image		sprite1;
	t_image		sprite2;
	t_image		sprite3;
	t_image		sprite4;
	t_image		sprite5;
	t_image		game_over;
}				t_textures;

typedef struct s_state {
	double		x_pos;
	double		y_pos;
	int			angle;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	t_textures	textures;
	int			floor;
	int			ceiling;
	int			x_mouse;
	int			y_mouse;
	int			speed;
	int			coins_count;
	int			coins_need;
	t_list		*visible_sprites;
}				t_state;

typedef struct s_all
{
	char		*no;
	char		*we;
	char		*ea;
	char		*so;
	int			count_no;
	int			count_so;
	int			count_ea;
	int			count_we;
	int			count_f;
	int			count_c;
	void		*mlx;
}				t_all;

void	init_struct(t_all *s_all);
void	parsing(char *map_name, t_all *s_all, t_state *state);
int		check_map_file(char *map_name);

/* params_parse */
void	choose_param(char *s, t_all *s_all, t_state *state);
void	set_params(t_all *s_all, int fd, t_state *state);
int		create_trgb(int t, int r, int g, int b);
int		parse_color(char *color);
void	get_textures(t_all *s_all, t_textures *textures);

/* map_parse */
t_list	*make_map_in_lists(int fd, t_state *state);
void	make_map_array(char *map_name, t_state *state);
int		is_map(char *s);
int		is_map_border(char *s);
void	check_map_borders(t_state *state);
void	find_player(t_state *state);

/* utils */
void	printarray(char **map);
void	printlist(t_list *lst);
int		consist_of_num_or_coma(char *s);
char	*skip_space(char *s);
int		ft_error(char *str);
int		check_fd(char *map_name);
void	add_coin(t_state *state, char *s);

#endif