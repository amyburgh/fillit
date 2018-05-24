/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:49:09 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/23 23:58:32 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stddef.h>
# define BUFSIZE 21

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_lst
{
	char			letter;
	t_point			tab[4];
	int				width;
	int				height;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	int		size;
	char	**tab;
}				t_map;
/*
** ----- main.c -----
*/
int				main(int argc, char **argv);
/*
** ----- input.c -----
*/
t_lst			*add_width_height(t_lst *list, t_lst *node);
t_lst			*move_top_left(t_lst *list, t_lst *node);
t_lst			*store_data(t_lst *node, char *buf, char letter);
t_lst			*read_tet(int fd);
/*
** ----- utilities.c -----
*/
size_t			ft_lstsize(t_lst *begin_list);
t_lst			*create_node(void);
void			ft_memdel(void **ap);
void			free_map(t_map *map);
t_lst			*free_list(t_lst *list);
/*
** ----- utilities2.c -----
*/
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
/*
** ----- validate.c -----
*/
int				validate_block(char *bf, int bytes);
int				validate_shift(char *buf);
/*
** ----- map.c -----
*/
void			print_map(t_map *map);
int				min_map(int tets);
t_map			*create_map(int size);
/*
** ----- solver.c ------
*/
int				check_place(t_lst *node, t_map *map, int x, int y);
void			place_piece(t_lst *node, t_map *map, int x, int y);
void			remove_piece(t_lst *node, t_map *map, int x, int y);
int				sove_map(t_lst *node, t_map *map);
t_map			*solver(t_lst *list);

#endif
