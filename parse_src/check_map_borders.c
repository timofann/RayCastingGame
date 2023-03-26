/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:26:55 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:51 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	line_has_zero_borders(char *s)
{
	char	*temp;

	temp = ft_strtrim_free(ft_strdup(s), " ");
	if (temp[0] == '1' && temp[ft_strlen(temp) - 1] == '1')
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

static int	spaces_around_zero(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' '
		|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (1);
	if (!map[i][j - 1] || !map[i][j + 1]
		|| !map[i - 1][j] || !map[i + 1][j])
		return (1);
	return (0);
}

void	check_map_borders(t_state *state)
{
	size_t	len;
	size_t	j;
	size_t	i;

	i = 1;
	if (!is_map_border(state->map[0])
		|| !is_map_border(state->map[state->map_height - 1]))
		ft_error("Wrong borders");
	while (i < state->map_height - 1)
	{
		if (line_has_zero_borders(state->map[i]))
			ft_error("Wrong borders");
		len = ft_strlen(state->map[i]);
		j = 0;
		while (j < len - 1)
		{
			if (state->map[i][j] == '0' || state->map[i][j] == 'N'
				|| state->map[i][j] == 'W' || state->map[i][j] == 'E'
				|| state->map[i][j] == 'S' || state->map[i][j] == '2')
				if (spaces_around_zero(state->map, i, j))
					ft_error("Wrong borders");
			j++;
		}
		i++;
	}
}
