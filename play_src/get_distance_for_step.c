/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance_for_step.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:02 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:11:02 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

static
double	check_x_direction(t_state *state, t_ray *x_ray)
{
	if (x_ray->sin == 0)
		return (-1);
	x_ray->x_bar = ((int)(state->x_pos / BLOCK_SIZE) + (x_ray->sin > 0))
		* BLOCK_SIZE;
	x_ray->y_bar = (x_ray->cos / x_ray->sin) * (state->x_pos - x_ray->x_bar)
		+ state->y_pos;
	x_ray->x_block = x_ray->x_bar / BLOCK_SIZE - (x_ray->sin < 0);
	x_ray->y_block = x_ray->y_bar / BLOCK_SIZE;
	if (x_ray->x_block < 0 || (size_t)x_ray->x_block >= state->map_width
		|| x_ray->y_block < 0 || (size_t)x_ray->y_block >= state->map_height)
		return (-1);
	if (state->map[x_ray->y_block][x_ray->x_block] == BLOCK)
		return (sqrt(
				pow(x_ray->x_bar - state->x_pos, 2)
				+ pow(x_ray->y_bar - state->y_pos, 2)));
	return (-1);
}

static
double	check_y_direction(t_state *state, t_ray *y_ray)
{
	if (y_ray->cos == 0)
		return (-1);
	y_ray->y_bar = ((int)(state->y_pos / BLOCK_SIZE) + (y_ray->cos < 0))
		* BLOCK_SIZE;
	y_ray->x_bar = (y_ray->sin / y_ray->cos) * (state->y_pos - y_ray->y_bar)
		+ state->x_pos;
	y_ray->x_block = y_ray->x_bar / BLOCK_SIZE;
	y_ray->y_block = y_ray->y_bar / BLOCK_SIZE - (y_ray->cos > 0);
	if (y_ray->x_block < 0 || (size_t)y_ray->x_block >= state->map_width
		|| y_ray->y_block < 0 || (size_t)y_ray->y_block >= state->map_height)
		return (-1);
	if (state->map[y_ray->y_block][y_ray->x_block] == BLOCK)
		return (sqrt(
				pow(y_ray->x_bar - state->x_pos, 2)
				+ pow(y_ray->y_bar - state->y_pos, 2)));
	return (-1);
}

double	get_distance_for_step(t_state *state, double ray_radian)
{
	t_ray	ray;
	double	x_ray_distance;
	double	y_ray_distance;

	ray.radian = ray_radian;
	ray.sin = sin(ray_radian);
	ray.cos = cos(ray_radian);
	x_ray_distance = check_x_direction(state, &ray);
	y_ray_distance = check_y_direction(state, &ray);
	if (x_ray_distance < 0 && y_ray_distance < 0)
		return (STEP_SIZE * state->speed);
	if (x_ray_distance < 0
		|| (y_ray_distance > 0 && y_ray_distance <= x_ray_distance))
		return (y_ray_distance);
	return (x_ray_distance);
}
