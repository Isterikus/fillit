/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:38:23 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/26 15:16:54 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

extern	char		**g_rez;
extern	int			g_i;
extern	int			g_j;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_fill_zero(char *str);
int				ft_read(const char *file);
void			print(int size);
int				count_blocks(char **elem);
int				check_beside(char **elem, int i, int j);
int				check_valid(char *str, int num);
int				check(char *str, int num, int kostil);
char			**get_elem(char *str);
char			**create_elem(char **elem, int l, int k);
char			**move_elem(char **elem);
void			lst_add(char **elem, int num);
void			clear(int size);
int				ft_sqrt(int size);
int				count_size(void);
void			create_rez(int size);
int				elems_bad(int size);
int				check_overlap(int size, int l, int k);
int				try_position(int size);
int				parse(int size);
void			solve(void);

typedef struct	s_list
{
	char		elem[4][4];
	int			i;
	int			j;
	void		*next;
}				t_list;

extern	t_list	*g_beg;
extern	t_list	*g_elem;

void			change_hash(char **elem, int num, t_list *new);
t_list			*find_prev(t_list *elem);
void			remove_elem(t_list *elem, int size);
void			add_to_rez(t_list *elem, int i, int j, int size);

#endif
