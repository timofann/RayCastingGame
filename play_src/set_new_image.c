/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:12:41 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:12:41 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

void	set_new_image(t_mlx *workspace, t_image *img)
{
	img->img_ptr = mlx_new_image(workspace->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img_ptr)
		put_error(IMG_INITIALIZATION_FAILED);
	img->addr = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		put_error(IMG_INITIALIZATION_FAILED);
}
