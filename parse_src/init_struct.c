/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:15 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:55 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_struct(t_all *s_all)
{
	s_all->no = NULL;
	s_all->we = NULL;
	s_all->ea = NULL;
	s_all->so = NULL;
	s_all->mlx = mlx_init();
	s_all->count_no = 0;
	s_all->count_so = 0;
	s_all->count_ea = 0;
	s_all->count_we = 0;
	s_all->count_f = 0;
	s_all->count_c = 0;
	if (!s_all->mlx)
		ft_error(MAP_INITIALIZATION_FAILED);
}
