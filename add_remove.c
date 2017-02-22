/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:50:52 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/22 19:14:48 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_rez;
int		g_i;
int		g_j;
t_list	*g_beg;
t_list	*g_elem;

void	remove_elem(t_list *elem, int size)
{
	int		i;
	int		j;
	t_list	*temp;
	int		count;

	i = 0;
	count = 0;
	temp = g_beg;
	while (temp != elem)
	{
		temp = temp->next;
		count++;
	}
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (g_rez[i][j] == (count + 65))
				g_rez[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	add_to_rez(t_list *elem, int i, int j, int size)
{
	int		l;
	int		k;

	l = 0;
	while (l < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (elem->elem[l][k] != '.')
				g_rez[l + i][k + j] = elem->elem[l][k];
			k++;
		}
		l++;
	}
	if (j == size - 1)
	{
		elem->i = i + 1;
		elem->j = 0;
	}
	else
	{
		elem->i = i;
		elem->j = j + 1;
	}
}

void	create_rez(int size)
{
	int		i;
	int		j;

	i = 0;
	g_rez = (char **)malloc(sizeof(char *) * (size + 5));
	while (i < size + 4)
	{
		g_rez[i] = (char *)malloc(sizeof(char) * (size + 5));
		j = 0;
		while (j < size + 4)
		{
			g_rez[i][j] = '.';
			j++;
		}
		g_rez[i][j] = '\0';
		i++;
	}
	g_rez[i] = NULL;
}

int		elems_bad(int size)
{
	if (g_j == size)
		if (g_i == size)
		{
			remove_elem(find_prev(g_elem), size);
			g_elem = find_prev(g_elem);
			g_i = g_elem->i;
			g_j = g_elem->j;
			return (2);
		}
		else
		{
			g_i++;
			g_j = 0;
			return (1);
		}
	else
	{
		g_j++;
		return (1);
	}
	return (0);
}
