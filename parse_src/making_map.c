/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:31 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:58 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reading_until_map_begins(char **s, int fd)
{
	while (1)
	{
		*s = get_next_line(fd);
		if (!*s || is_map(*s))
			return ;
		free (*s);
	}
}

t_list	*make_map_in_lists(int fd, t_state *state)
{
	t_list	*map;
	char	*s;

	map = 0;
	state->map_width = 0;
	state->coins_need = 0;
	reading_until_map_begins(&s, fd);
	while (s)
	{
		if (!is_map(s) || !*s)
			ft_error("Wrong map");
		add_coin(state, s);
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(s)));
		if (state->map_width < ft_strlen(s))
			state->map_width = ft_strlen(s);
		free(s);
		s = get_next_line(fd);
	}
	if (!s && !map)
		ft_error("No map");
	free(s);
	close(fd);
	return (map);
}

static void	*malloc_x(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error(NULL);
	return (ptr);
}

void	make_map_array(char *map_name, t_state *state)
{
	size_t	i;
	t_list	*map_list;
	t_list	*head;
	int		fd;

	fd = check_fd(map_name);
	map_list = make_map_in_lists(fd, state);
	head = map_list;
	state->map_height = ft_lstsize(map_list);
	state->map = (char **)malloc_x(sizeof(char *) * (state->map_height + 1));
	i = 0;
	while (i < state->map_height)
	{
		state->map[i] = malloc_x(state->map_width + 1);
		ft_memset(state->map[i], ' ', state->map_width);
		state->map[i][state->map_width] = '\0';
		ft_memcpy(state->map[i], map_list->str, ft_strlen(map_list->str));
		map_list = map_list->next;
		i++;
	}
	ft_lstclear(&head, free);
	state->map[i] = NULL;
}
