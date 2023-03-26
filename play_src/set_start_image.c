/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:13:19 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:13:19 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

static
void	set_start(t_mlx *workspace, char *filename)
{
	t_image	img;

	img.img_ptr = mlx_xpm_file_to_image(workspace->mlx, filename,
			&img.width, &img.height);
	if (!img.img_ptr)
		ft_error("Wrong texture path");
	img.addr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(workspace->mlx, workspace->win, img.img_ptr, 0, 0);
}

int	set_start_image(t_mlx *workspace)
{
	static int	time;

	if (time > 90)
		return (1);
	if (time < 10)
		set_start(workspace, "./drawable/start_game_001.xpm");
	else if (time < 20)
		set_start(workspace, "./drawable/start_game_005.xpm");
	else if (time < 30)
		set_start(workspace, "./drawable/start_game_009.xpm");
	else if (time < 40)
		set_start(workspace, "./drawable/start_game_013.xpm");
	else if (time < 50)
		set_start(workspace, "./drawable/start_game_017.xpm");
	else if (time < 60)
		set_start(workspace, "./drawable/start_game_021.xpm");
	else if (time < 70)
		set_start(workspace, "./drawable/start_game_025.xpm");
	else if (time < 80)
		set_start(workspace, "./drawable/start_game_029.xpm");
	else
		set_start(workspace, "./drawable/start_game_033.xpm");
	time++;
	return (0);
}
