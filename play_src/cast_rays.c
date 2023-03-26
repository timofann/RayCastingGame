/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:09:11 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:09:11 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

void	cast_one_ray(t_image *img, t_state *state, int ray_nbr)
{
	t_ray	ray;

	ray.nbr = ray_nbr;
	set_ray_info(state, &ray);
	cast_wall(img, state, &ray);
	cast_sprites(img, state, &ray);
}

void	cast_rays(t_image *img, t_state *state)
{
	int	ray_nbr;

	ray_nbr = 0;
	while (ray_nbr < WIN_WIDTH)
		cast_one_ray(img, state, ray_nbr++);
}
