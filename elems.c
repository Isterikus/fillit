/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:52:02 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/23 10:34:19 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*g_beg;

char	**get_elem(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**elem;

	i = 0;
	k = 0;
	elem = (char **)malloc(sizeof(char *) * 5);
	while (k < 20)
	{
		j = 0;
		elem[i] = (char *)malloc(sizeof(char) * 5);
		while (str[k] != '\n' && str[k] != 0)
		{
			elem[i][j] = str[k];
			k++;
			j++;
		}
		elem[i][j] = '\0';
		i++;
		k++;
	}
	elem[i] = 0;
	return (elem);
}

char	**create_elem(char **elem, int l, int k)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		j = 0;
		new[i] = (char *)malloc(sizeof(char) * 5);
		while (j < 4)
		{
			if (l + i < 4 && k + j < 4)
				new[i][j] = elem[l + i][k + j];
			else
				new[i][j] = '.';
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**move_elem(char **elem)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = -1;
	l = -1;
	while (i < 4 && (k == -1 || l == -1))
	{
		j = 0;
		while (j < 4 && (k == -1 || l == -1))
		{
			if (elem[i][j] == '#' && l == -1)
				l = i;
			if (elem[j][i] == '#' && k == -1)
				k = i;
			j++;
		}
		i++;
	}
	return (create_elem(elem, l, k));
}

void	lst_add(char **elem, int num)
{
	t_list	*move;
	t_list	*new;

	move = g_beg;
	new = (t_list *)malloc(sizeof(t_list));
	elem = move_elem(elem);
	change_hash(elem, num, new);
	new->next = NULL;
	new->i = 0;
	new->j = 0;
	if (num == 0)
		g_beg = new;
	else
	{
		while (move->next)
			move = move->next;
		move->next = new;
	}
}

t_list	*find_prev(t_list *elem)
{
	t_list	*prev;

	if (elem == g_beg)
		return (NULL);
	prev = g_beg;
	while (prev->next != elem)
		prev = prev->next;
	return (prev);
}
