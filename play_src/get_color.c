/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:40 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:10:40 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

int	get_color(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	return (*(int *)dst);
}
