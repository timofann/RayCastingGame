/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:13:28 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:13:28 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

static
t_sprite	*find_existing_sprite(t_list *lst, int x_block, int y_block)
{
	t_list		*elem;
	t_sprite	*sprite;

	elem = lst;
	while (elem)
	{
		sprite = (t_sprite *)(elem->str);
		if (sprite->x_block == x_block && sprite->y_block == y_block)
			return (sprite);
		elem = elem->next;
	}
	return (NULL);
}

static
void	get_sprite_info(t_state *state, t_ray *ray, t_sprite *sprite)
{
	double	x_sprite;
	double	y_sprite;

	sprite->x_block = ray->x_block;
	sprite->y_block = ray->y_block;
	sprite->to_del = 0;
	x_sprite = ((double)sprite->x_block + 0.5) * BLOCK_SIZE;
	y_sprite = ((double)sprite->y_block + 0.5) * BLOCK_SIZE;
	sprite->center_ray_nbr = SCREEN_DIST * tan(
			atan((x_sprite - state->x_pos) / (state->y_pos - y_sprite))
			- state->angle * RAD)
		+ START_RAY_NUM;
	sprite->distance = sqrt(
			pow(x_sprite - state->x_pos, 2) + pow(y_sprite - state->y_pos, 2))
		* cos(atan((sprite->center_ray_nbr - START_RAY_NUM) / SCREEN_DIST));
	sprite->half_sprite_height = round(
			(double)SPRITE_SIZE * SCREEN_DIST * 0.5 / sprite->distance);
}

void	add_sprite_to_right_place(t_list **sprites, t_list *new)
{
	t_list	*prev;
	t_list	*elem;

	prev = NULL;
	elem = *sprites;
	while (elem
		&& ((t_sprite *)elem->str)->distance > ((t_sprite *)new->str)->distance)
	{
		prev = elem;
		elem = elem->next;
	}
	new->next = elem;
	if (prev)
		prev->next = new;
	else
		*sprites = new;
}

void	add_new_sprite(t_state *state, t_ray *ray, t_list **sprites)
{
	t_sprite	*sprite;
	t_list		*new;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		put_error(MEMORY_ERROR);
	get_sprite_info(state, ray, sprite);
	new = ft_lstnew(sprite);
	if (!new)
		put_error(MEMORY_ERROR);
	add_sprite_to_right_place(sprites, new);
}

void	update_sprite_info(t_state *state, t_ray *ray)
{
	t_sprite	*sprite;

	sprite = find_existing_sprite(
			state->visible_sprites, ray->x_block, ray->y_block);
	if (!sprite)
		add_new_sprite(state, ray, &state->visible_sprites);
	else
		sprite->to_del = 0;
}
