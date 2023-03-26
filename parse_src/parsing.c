/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:47 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:29:00 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parsing(char *map_name, t_all *s_all, t_state *state)
{
	int	fd;

	fd = check_map_file(map_name);
	set_params(s_all, fd, state);
	make_map_array(map_name, state);
	check_map_borders(state);
	find_player(state);
}

int	check_map_file(char *map_name)
{
	int		fd;

	if ((ft_strlen(map_name) < 4) || \
	ft_strncmp(map_name + (ft_strlen(map_name) - 4), ".cub", 4))
		ft_error("Invalid map file");
	fd = check_fd(map_name);
	if (read(fd, NULL, 0) < 0)
		ft_error(NULL);
	if (read(fd, NULL, 10) == 0)
		ft_error("Empty file");
	return (fd);
}
