/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:10:09 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 17:01:37 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void	add_width_height(t_lst *list, t_lst *node)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (node->tab[i].x + 1 > node->width)
			node->width = node->tab[i].x + 1;
		if (node->tab[i].y + 1 > node->height)
			node->height = node->tab[i].y + 1;
	}
	if (node->next)
		add_width_height(list, node->next);
}

void	move_top_left(t_lst *list, t_lst *node)
{
	int	i;
	int min_x;
	int min_y;

	i = -1;
	min_x = 3;
	min_y = 3;
	while (++i < 4)
	{
		node->tab[i].x < min_x ? min_x = node->tab[i].x : min_x;
		node->tab[i].y < min_y ? min_y = node->tab[i].y : min_y;
	}
	if (min_x < 3 || min_y < 3)
	{
		i = -1;
		while (++i < 4)
		{
			node->tab[i].x -= min_x;
			node->tab[i].y -= min_y;
		}
	}
	if (node->next)
		move_top_left(list, node->next);
}

t_lst	*store_data(t_lst *node, char *buf, char letter)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (letter != 'A')
	{
		if (!(node->next = create_node()))
			return (NULL);
		node = node->next;
	}
	node->letter = letter;
	node->width = 0;
	node->height = 0;
	while (++i < 20)
	{
		if (buf[i] == '#')
		{
			node->tab[j] = *(t_point*)malloc(sizeof(t_point));
			node->tab[j].x = i % 5;
			node->tab[j++].y = i / 5;
		}
	}
	return (node);
}

t_lst	*read_tet(int fd, char *buf)
{
	int		bytes;
	int		t_bytes;
	t_lst	*list;
	t_lst	*current;
	char	letter;

	if (!(list = create_node()))
		return (NULL);
	letter = 'A';
	current = list;
	t_bytes = 0;
	while ((bytes = read(fd, buf, BUFSIZE)) >= 20)
	{
		if (validate_block(buf, bytes) && letter <= 'Z')
			return (NULL);
		if (!(current = store_data(current, buf, letter++)))
			return (NULL);
		t_bytes += bytes;
	}
	if (!t_bytes || t_bytes != (letter - 'A') * 21 - 1)
		return (NULL);
	move_top_left(list, list);
	add_width_height(list, list);
	close(fd);
	return (list);
}
