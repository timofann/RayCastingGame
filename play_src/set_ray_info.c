/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:13:08 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:13:08 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

static
void	set_angle_params(t_state *state, t_ray *ray)
{
	ray->radian = atan(((double)ray->nbr - START_RAY_NUM) / SCREEN_DIST)
		+ state->angle * RAD;
	ray->sin = sin(ray->radian);
	ray->cos = cos(ray->radian);
}

static
bool	check_block(t_state *state, t_ray *ray)
{
	if (ray->x_block >= 0 && (size_t)ray->x_block < state->map_width
		&& ray->y_block >= 0 && (size_t)ray->y_block < state->map_height)
	{
		if (state->map[ray->y_block][ray->x_block] == BLOCK)
			return (1);
		else if (state->map[ray->y_block][ray->x_block] == SPRITE)
			update_sprite_info(state, ray);
	}
	return (0);
}

static
void	check_closest_x_barrier(t_state *state, t_ray *ray,
								int *x_bar, double *y)
{
	ray->x_block = *x_bar / BLOCK_SIZE - (ray->sin < 0);
	ray->y_block = *y / BLOCK_SIZE;
	if (check_block(state, ray))
	{
		ray->x_bar = *x_bar;
		ray->y_bar = *y;
		ray->is_vertical = 1;
		ray->distance = sqrt(pow(ray->x_bar - state->x_pos, 2) + pow(ray->y_bar
					- state->y_pos, 2)) * cos(state->angle * RAD - ray->radian);
	}
	*x_bar += ((ray->sin > 0) - (ray->sin < 0)) * BLOCK_SIZE;
	*y = (ray->cos / ray->sin) * (state->x_pos - (double)(*x_bar))
		+ state->y_pos;
}

static
void	check_closest_y_barrier(t_state *state, t_ray *ray,
								double *x, int *y_bar)
{
	ray->x_block = *x / BLOCK_SIZE;
	ray->y_block = *y_bar / BLOCK_SIZE - (ray->cos > 0);
	if (check_block(state, ray))
	{
		ray->x_bar = *x;
		ray->y_bar = *y_bar;
		ray->is_vertical = 0;
		ray->distance = sqrt(pow(ray->x_bar - state->x_pos, 2) + pow(ray->y_bar
					- state->y_pos, 2)) * cos(state->angle * RAD - ray->radian);
	}
	*y_bar += ((ray->cos < 0) - (ray->cos > 0)) * BLOCK_SIZE;
	*x = (ray->sin / ray->cos) * (state->y_pos - (double)(*y_bar))
		+ state->x_pos;
}

void	set_ray_info(t_state *state, t_ray *ray)
{
	int		x_bar;
	int		y_bar;
	double	x;
	double	y;

	set_angle_params(state, ray);
	clear_sprites_info(state->visible_sprites);
	x_bar = (int)(state->x_pos / BLOCK_SIZE) * BLOCK_SIZE
		+ (ray->sin > 0) * BLOCK_SIZE;
	y = (ray->cos / ray->sin) * (state->x_pos - (double)x_bar) + state->y_pos;
	y_bar = (int)(state->y_pos / BLOCK_SIZE) * BLOCK_SIZE
		+ (ray->cos < 0) * BLOCK_SIZE;
	x = (ray->sin / ray->cos) * (state->y_pos - (double)y_bar) + state->x_pos;
	ray->distance = -1;
	while (ray->distance < 0)
	{
		if (ray->sin != 0)
			while (fabs(state->y_pos - y) < fabs(state->y_pos - (double)y_bar)
				&& ray->distance < 0)
				check_closest_x_barrier(state, ray, &x_bar, &y);
		if (ray->cos != 0 && ray->distance < 0)
			while (fabs(state->x_pos - (double)x_bar) >= fabs(state->x_pos - x)
				&& ray->distance < 0)
				check_closest_y_barrier(state, ray, &x, &y_bar);
	}
}
