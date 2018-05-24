/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 00:58:20 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/23 17:02:29 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_place(t_lst *node, t_map *map, int x, int y)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (map->tab[node->tab[i].y + y][node->tab[i].x + x] != '.')
			return (1);
	}
	return (0);
}

void	place_piece(t_lst *node, t_map *map, int x, int y)
{
	int	i;

	i = -1;
	while (++i < 4)
		map->tab[node->tab[i].y + y][node->tab[i].x + x] = node->letter;
}

void	remove_piece(t_lst *node, t_map *map, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		map->tab[node->tab[i].y + y][node->tab[i].x + x] = '.';
}

int		solve_map(t_lst *node, t_map *map)
{
	int	x;
	int	y;

	if (node == NULL)
		return (1);
	y = 0;
	while (y <= map->size - node->height)
	{
		x = 0;
		while (x <= map->size - node->width)
		{
			if (!check_place(node, map, x, y))
			{
				place_piece(node, map, x, y);
				if (solve_map(node->next, map))
					return (1);
				else
					remove_piece(node, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*solver(t_lst *list)
{
	t_lst	*node;
	t_map	*map;
	int		size;

	node = list;
	size = min_map(ft_lstsize(list));
	map = create_map(size);
	while (!solve_map(node, map))
	{
		free_map(map);
		size++;
		map = create_map(size);
		node = list;
	}
	return (map);
}
