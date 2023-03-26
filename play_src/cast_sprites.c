/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:09:47 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:09:47 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

static
void	delete_outdated_sprites(t_list **sprites)
{
	t_list	*prev;
	t_list	*elem;

	prev = NULL;
	elem = *sprites;
	while (elem)
	{
		if (((t_sprite *)elem->str)->to_del)
		{
			if (prev)
				prev->next = elem->next;
			else
				*sprites = elem->next;
			free(elem->str);
			free(elem);
		}
		else
			prev = elem;
		if (prev)
			elem = prev->next;
		else
			elem = *sprites;
	}
}

static
t_image	*choose_sprite_texture(t_textures *textures)
{
	static int	time;

	if (time == 30000)
		time = 0;
	else
		time ++;
	if (time < 5000)
		return (&textures->sprite0);
	else if (time < 10000)
		return (&textures->sprite1);
	else if (time < 15000)
		return (&textures->sprite2);
	else if (time < 20000)
		return (&textures->sprite3);
	else if (time < 25000)
		return (&textures->sprite4);
	else
		return (&textures->sprite5);
}

static
int	count_x_sprite_texture(t_image *texture, t_ray *ray, t_sprite *sprite)
{
	int	btw;
	int	x;

	btw = (ray->nbr - sprite->center_ray_nbr);
	if (abs(btw) > sprite->half_sprite_height)
		return (-1);
	x = btw * texture->width * 0.5 / (sprite->half_sprite_height);
	return (texture->width * 0.5 + x);
}

static
void	put_sprite_slice(t_image *img, t_image *texture,
	t_ray *ray, t_sprite *sprite)
{
	int		color;
	ssize_t	y;
	int		y_texture;
	double	texture_step;
	int		x_texture;

	x_texture = count_x_sprite_texture(texture, ray, sprite);
	if (x_texture < 0)
		return ;
	texture_step = (double)(texture->height / 2)
		/ (double)sprite->half_sprite_height;
	y = 0;
	while (y < sprite->half_sprite_height && y <= WIN_HEIGHT / 2)
	{
		y_texture = (texture->height / 2) - y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		if (!(color >> 24))
			put_pixel(img, ray->nbr, WIN_HEIGHT / 2 - y, color);
		y_texture = (texture->height / 2) + y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		if (!(color >> 24))
			put_pixel(img, ray->nbr, WIN_HEIGHT / 2 + y, color);
		y++;
	}
}

void	cast_sprites(t_image *img, t_state *state, t_ray *ray)
{
	t_list	*elem;
	t_image	*texture;

	delete_outdated_sprites(&state->visible_sprites);
	texture = choose_sprite_texture(&state->textures);
	elem = state->visible_sprites;
	while (elem)
	{
		put_sprite_slice(img, texture, ray, elem->str);
		elem = elem->next;
	}
}
