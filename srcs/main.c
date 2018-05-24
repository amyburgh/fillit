/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:43:37 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 16:34:25 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	char	buf[BUFSIZE];
	t_lst	*list;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit \033[31msource_file\033[0m\n");
		exit(0);
	}
	if (!(list = read_tet(open(argv[1], O_RDONLY), buf)))
	{
		ft_putstr("error\n");
		exit(0);
	}
	map = solver(list);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}
