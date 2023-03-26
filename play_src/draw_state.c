/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:29 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:10:29 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

void	get_mouse_position(void *win, t_state *state)
{
	int	x_mouse;
	int	y_mouse;

	mlx_mouse_get_pos(win, &x_mouse, &y_mouse);
	state->angle += (x_mouse - state->x_mouse);
	state->angle = (state->angle + 360) % 360;
	state->x_mouse = x_mouse;
	state->y_mouse = y_mouse;
}

void	draw_ceiling(t_image *img, t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(img, x, y, state->ceiling);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_image *img, t_state *state)
{
	int	x;
	int	y;

	y = WIN_HEIGHT / 2 + 1;
	while (y <= WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(img, x, y, state->floor);
			x++;
		}
		y++;
	}
}

void	game_over(t_mlx *workspace, void *img_ptr)
{
	static int	time;

	if (time == 0)
		mlx_hook(workspace->win, 2, 1L << 0, NULL, NULL);
	if (time == 100)
		exit(0);
	mlx_put_image_to_window(workspace->mlx, workspace->win, img_ptr, 0, 0);
	time++;
}

void	draw_state(t_mlx *workspace, t_image *img, t_state *state)
{
	mlx_destroy_image(workspace->mlx, img->img_ptr);
	set_new_image(workspace, img);
	get_mouse_position(workspace->win, state);
	ft_lstclear(&state->visible_sprites, free);
	if (state->coins_need != 0 && state->coins_need == state->coins_count)
		game_over(workspace, state->textures.game_over.img_ptr);
	else if (set_start_image(workspace))
	{
		draw_ceiling(img, state);
		draw_floor(img, state);
		cast_rays(img, state);
		draw_minimap(img, state);
		mlx_put_image_to_window(
			workspace->mlx, workspace->win, img->img_ptr, 0, 0);
		put_info(workspace, state);
	}
}
