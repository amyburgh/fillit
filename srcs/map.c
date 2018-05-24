/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 22:59:10 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/23 23:52:38 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void	print_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->tab[i]);
		write(1, "\n", 1);
	}
}

int		min_map(int tets)
{
	int	size;

	size = 2;
	while (size * size < tets * 4)
		size++;
	return (size);
}

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = -1;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->tab = (char**)ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++i < size)
	{
		j = -1;
		if (!(map->tab[i] = ft_strnew(size + 1)))
			return (NULL);
		while (++j < size)
			map->tab[i][j] = '.';
	}
	return (map);
}
