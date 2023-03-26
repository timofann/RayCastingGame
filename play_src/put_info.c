/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:37 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:11:37 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

#define MRGN 578

void	put_speed_info(t_mlx *workspace, t_state *state)
{
	char	*text;

	text = ft_itoa(state->speed);
	if (!text)
		put_error(MEMORY_ERROR);
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN - 21, 38, PURPLE, text);
	free(text);
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN, 38, PURPLE, "speed");
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN - 47, 54, LIGHT_PURPLE, "( +/- keys )");
}

void	put_coins_info(t_mlx *workspace, t_state *state)
{
	char	*text;
	size_t	len;

	text = ft_itoa(state->coins_need);
	if (!text)
		put_error(MEMORY_ERROR);
	len = ft_strlen(text);
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN - 7 * (len + 2), 74, PURPLE, text);
	free(text);
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN - 7 * (len + 4), 74, PURPLE, "/");
	text = ft_itoa(state->coins_count);
	if (!text)
		put_error(MEMORY_ERROR);
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN - 7 * (len + 5 + ft_strlen(text)), 74, PURPLE, text);
	free(text);
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN, 74, PURPLE, "coins");
	mlx_string_put(workspace->mlx, workspace->win,
		MRGN - 68, 90, LIGHT_PURPLE, "( collect all )");
}

void	put_info(t_mlx *workspace, t_state *state)
{
	put_speed_info(workspace, state);
	put_coins_info(workspace, state);
}
