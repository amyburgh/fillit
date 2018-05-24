/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 01:10:05 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/23 01:36:16 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

t_lst	*create_node(void)
{
	t_lst	*node;

	node = (t_lst*)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

size_t	ft_lstsize(t_lst *begin_list)
{
	size_t		i;
	t_lst		*size;

	i = 0;
	size = begin_list;
	while (size)
	{
		size = size->next;
		i++;
	}
	return (i);
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	free_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void**)&(map->tab[i]));
	ft_memdel((void**)(map->tab));
	ft_memdel((void**)&map);
}

t_lst	*free_list(t_lst *list)
{
	t_lst	*node;

	while (list)
	{
		node = list->next;
		ft_memdel((void**)&list);
		list = node;
	}
	return (NULL);
}
