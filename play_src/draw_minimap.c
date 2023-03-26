/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:17 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:10:17 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

#define MINIMAP_X 80
#define MINIMAP_Y 65
#define MINIMAP_H 45
#define MINIMAP_W 60
#define MINIMAP_BLOCK 10

static
void	fill_minimap_space(t_image *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINIMAP_W)
	{
		y = 0;
		while (y < MINIMAP_H)
		{
			put_pixel(img, MINIMAP_X + x + 1, MINIMAP_Y - y, LIGHT_PURPLE);
			put_pixel(img, MINIMAP_X + x + 1, MINIMAP_Y + y + 1, LIGHT_PURPLE);
			put_pixel(img, MINIMAP_X - x, MINIMAP_Y + y + 1, LIGHT_PURPLE);
			put_pixel(img, MINIMAP_X - x, MINIMAP_Y - y, LIGHT_PURPLE);
			y++;
		}
		x++;
	}
}

static
void	put_block(t_image *img, t_state *state, int x, int y)
{
	long long	x_block;
	long long	y_block;

	x_block = (state->x_pos + x * MINIMAP_BLOCK) / BLOCK_SIZE;
	y_block = (state->y_pos + y * MINIMAP_BLOCK) / BLOCK_SIZE;
	if (x_block >= 0 && (size_t)x_block < state->map_width
		&& y_block >= 0 && (size_t)y_block < state->map_height)
	{
		if (state->map[y_block][x_block] == '0')
			put_pixel(img, MINIMAP_X + x, MINIMAP_Y + y, LAVENDER);
		else if (state->map[y_block][x_block] == '1')
			put_pixel(img, MINIMAP_X + x, MINIMAP_Y + y, PURPLE);
		else if (state->map[y_block][x_block] == '2')
			put_pixel(img, MINIMAP_X + x, MINIMAP_Y + y, PINK);
		else
			put_pixel(img, MINIMAP_X + x, MINIMAP_Y + y, LIGHT_PURPLE);
	}
}

static
void	draw_blocks(t_image *img, t_state *state)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINIMAP_W)
	{
		y = 0;
		while (y < MINIMAP_H)
		{
			put_block(img, state, x + 1, 0 - y);
			put_block(img, state, x + 1, y + 1);
			put_block(img, state, 0 - x, y + 1);
			put_block(img, state, 0 - x, 0 - y);
			y++;
		}
		x++;
	}
}

static
void	draw_player(t_image *img)
{
	int	x;
	int	y;

	x = MINIMAP_X - 2;
	while (x <= MINIMAP_X + 2)
	{
		y = MINIMAP_Y - 2;
		while (y <= MINIMAP_Y + 2)
		{
			put_pixel(img, x, y, GREEN);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_image *img, t_state *state)
{
	fill_minimap_space(img);
	draw_blocks(img, state);
	draw_player(img);
}
