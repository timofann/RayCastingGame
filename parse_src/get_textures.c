/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:53 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:29:02 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub3d.h"

void	get_one_texture(void *mlx, char *filename, t_image *texture)
{
	if (!filename)
		ft_error("Not all params are set");
	texture->img_ptr = mlx_xpm_file_to_image(mlx, filename,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
		ft_error("Wrong texture path");
	texture->addr = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

void	get_textures(t_all *s_all, t_textures *textures)
{
	get_one_texture(s_all->mlx, s_all->no, &textures->north);
	get_one_texture(s_all->mlx, s_all->so, &textures->south);
	get_one_texture(s_all->mlx, s_all->ea, &textures->east);
	get_one_texture(s_all->mlx, s_all->we, &textures->west);
	get_one_texture(s_all->mlx, "./drawable/heart0.xpm", &textures->sprite0);
	get_one_texture(s_all->mlx, "./drawable/heart1.xpm", &textures->sprite1);
	get_one_texture(s_all->mlx, "./drawable/heart2.xpm", &textures->sprite2);
	get_one_texture(s_all->mlx, "./drawable/heart3.xpm", &textures->sprite3);
	get_one_texture(s_all->mlx, "./drawable/heart4.xpm", &textures->sprite4);
	get_one_texture(s_all->mlx, "./drawable/heart5.xpm", &textures->sprite5);
	get_one_texture(s_all->mlx, "./drawable/bunny.xpm", &textures->game_over);
}
