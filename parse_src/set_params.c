/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:53 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:29:02 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_params(t_all *s_all, int fd, t_state *state)
{
	char	*s;

	while (1)
	{
		s = get_next_line(fd);
		if (!s || is_map(s))
		{
			if (s)
				free(s);
			break ;
		}
		choose_param(s, s_all, state);
		free(s);
	}
	if (s_all->count_no != 1 || s_all->count_so != 1
		|| s_all->count_ea != 1 || s_all->count_we != 1
		|| s_all->count_f != 1 || s_all->count_c != 1)
		ft_error("Wrong params or not enough params");
	get_textures(s_all, &state->textures);
	close(fd);
}

void	count_and_write_path(int *count, char **text_path, char *s)
{
	(*count)++;
	*text_path = ft_strtrim((s + 2), " ");
}

void	count_and_write_color(int *count, int *color, char *s)
{
	char	*color_temp;

	color_temp = ft_strtrim((s + 2), " ");
	(*count)++;
	*color = parse_color(color_temp);
	free(color_temp);
}

void	choose_param(char *s, t_all *s_all, t_state *state)
{
	if (!ft_strncmp(s, "NO ", 3))
		count_and_write_path(&s_all->count_no, &s_all->no, s);
	else if (!ft_strncmp(s, "SO ", 3))
		count_and_write_path(&s_all->count_so, &s_all->so, s);
	else if (!ft_strncmp(s, "WE ", 3))
		count_and_write_path(&s_all->count_we, &s_all->we, s);
	else if (!ft_strncmp(s, "EA ", 3))
		count_and_write_path(&s_all->count_ea, &s_all->ea, s);
	else if (!ft_strncmp(s, "F ", 2))
		count_and_write_color(&s_all->count_f, &state->floor, s);
	else if (!ft_strncmp(s, "C ", 2))
		count_and_write_color(&s_all->count_c, &state->ceiling, s);
	else if (!*s)
		return ;
	else
		ft_error("Invalid string in mapfile");
}

int	parse_color(char *color)
{
	int		rgb[3];
	int		i;
	int		res;

	i = 0;
	if (!consist_of_num_or_coma(color))
		ft_error("Wrong floor or ceilling color");
	while (i < 3)
	{
		rgb[i] = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_error("Wrong color number");
		color++;
		i++;
	}
	res = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	return (res);
}
