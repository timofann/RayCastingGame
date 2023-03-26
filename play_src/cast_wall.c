/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:09:57 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:09:57 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

static
t_image	*choose_wall_texture(t_textures *textures, t_ray *ray)
{
	if (ray->is_vertical)
	{
		if (ray->sin < 0)
			return (&(textures->west));
		return (&(textures->east));
	}
	if (ray->cos < 0)
		return (&(textures->south));
	return (&(textures->north));
}

static
int	count_x_wall_texture(t_image *texture, t_ray *ray)
{
	double	x_map;

	if (ray->is_vertical)
	{
		x_map = fmod(ray->y_bar, BLOCK_SIZE);
		if (ray->sin < 0)
			x_map = (double)BLOCK_SIZE - x_map;
		return (x_map * (double)texture->width / (double)BLOCK_SIZE);
	}
	x_map = fmod(ray->x_bar, BLOCK_SIZE);
	if (ray->cos < 0)
		x_map = (double)BLOCK_SIZE - x_map;
	return (x_map * (double)texture->width / (double)BLOCK_SIZE);
}

void	put_wall_pixel(t_image *img, t_ray *ray, ssize_t y, int color)
{
	if (!(color >> 24))
	{
		if (ray->is_vertical)
			color = (color >> 1) & 8355711;
		put_pixel(img, ray->nbr, y, color);
	}
	else
		put_pixel(img, ray->nbr, y, LAVENDER);
}

static
void	put_wall_slice(t_image *img, t_image *texture,
	t_ray *ray, int x_texture)
{
	int		color;
	ssize_t	y;
	int		y_texture;
	int		half_wall_height;
	double	texture_step;

	half_wall_height = round(
			(double)BLOCK_SIZE * SCREEN_DIST * 0.5 / ray->distance);
	texture_step = (double)(texture->height / 2) / (double)half_wall_height;
	y = 0;
	while (y < half_wall_height && y <= WIN_HEIGHT / 2)
	{
		y_texture = (texture->height / 2) - y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		put_wall_pixel(img, ray, WIN_HEIGHT / 2 - y, color);
		y_texture = (texture->height / 2) + y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		put_wall_pixel(img, ray, WIN_HEIGHT / 2 + y, color);
		y++;
	}
}

void	cast_wall(t_image *img, t_state *state, t_ray *ray)
{
	t_image	*texture;
	int		x_texture;

	texture = choose_wall_texture(&state->textures, ray);
	x_texture = count_x_wall_texture(texture, ray);
	put_wall_slice(img, texture, ray, x_texture);
}
