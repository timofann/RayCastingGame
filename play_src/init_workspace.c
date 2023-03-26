/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_workspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:10 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:11:10 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

void	init_workspace(t_mlx *workspace, t_all *s_all)
{
	workspace->mlx = s_all->mlx;
	workspace->win = mlx_new_window(
			workspace->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!workspace->win)
		put_error(MEMORY_ERROR);
}
