/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubbster_play.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:28:20 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/25 16:20:23 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBBSTER_PLAY_H
# define CUBBSTER_PLAY_H

# include "../minilibx_Darwin/mlx.h"
# include "cub3d.h"
# include "cubbster_keycodes.h"
# include "cubbster_errors.h"
# include "cubbster_colors.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

# define SPRITE_SIZE 50
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define START_RAY_NUM 319.5
# define SCREEN_DIST 554.256258
# define WIN_TITLE "CUBBSTER 3D"
# define STEP_SIZE 2.0
# define RAD 0.0174532925
# define SPACE '0'
# define BLOCK '1'
# define SPRITE '2'

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_ray {
	int			nbr;
	double		sin;
	double		cos;
	double		radian;
	double		distance;
	double		x_bar;
	double		y_bar;
	long long	x_block;
	long long	y_block;
	bool		is_vertical;
}	t_ray;

typedef struct s_sprite {
	int		x_block;
	int		y_block;
	double	distance;
	int		center_ray_nbr;
	int		half_sprite_height;
	bool	to_del;
}				t_sprite;

void	init_workspace(t_mlx *workspace, t_all *s_all);
void	set_new_window(t_mlx *workspace, t_all *s_all, t_image *img);
void	set_new_image(t_mlx *workspace, t_image *img);
void	draw_state(t_mlx *workspace, t_image *img, t_state *current);
void	put_pixel(t_image *img, int x, int y, int color);
int		get_color(t_image *img, int x, int y);
int		set_start_image(t_mlx *workspace);
double	get_distance_for_step(t_state *state, double ray_radian);
void	set_hooks_for_drawing(t_mlx *workspace, t_state *state);
void	cast_rays(t_image *img, t_state *state);
void	set_ray_info(t_state *state, t_ray *ray);
void	cast_wall(t_image *img, t_state *state, t_ray *ray);
void	cast_sprites(t_image *img, t_state *state, t_ray *ray);
void	draw_minimap(t_image *img, t_state *state);
void	clear_sprites_info(t_list *sprites);
void	update_sprite_info(t_state *state, t_ray *ray);
void	put_info(t_mlx *workspace, t_state *state);

#endif
