/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sprites_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:09 by dedelmir          #+#    #+#             */
/*   Updated: 2022/07/25 16:10:09 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster_play.h"

void	clear_sprites_info(t_list *sprites)
{
	t_list		*elem;
	t_sprite	*sprite;

	elem = sprites;
	while (elem)
	{
		sprite = elem->str;
		sprite->to_del = 1;
		elem = elem->next;
	}
}
