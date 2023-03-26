/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:06 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:53 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	write_player_data(t_state *state, int x, int y, char dir)
{
	state->x_pos = ((double)x + 0.5) * BLOCK_SIZE;
	state->y_pos = ((double)y + 0.5) * BLOCK_SIZE;
	if (dir == 'N')
		state->angle = 0;
	else if (dir == 'E')
		state->angle = 90;
	else if (dir == 'S')
		state->angle = 180;
	else if (dir == 'W')
		state->angle = 270;
	else
		state->angle = 0;
}

void	find_player(t_state *state)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (state->map[++i])
	{
		j = 0;
		while (state->map[i][j])
		{
			if (state->map[i][j] == 'N' || state->map[i][j] == 'S'
				|| state->map[i][j] == 'E' || state->map[i][j] == 'W')
			{
				count++;
				write_player_data(state, j, i, state->map[i][j]);
				state->map[i][j] = '0';
			}
			j++;
		}
	}
	if (count == 0)
		ft_error("Error: Player not found");
	if (count > 1)
		ft_error("Error: More than 1 player in map");
}
