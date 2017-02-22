/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:56:34 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/26 15:17:05 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_rez;
int		g_i;
int		g_j;
t_list	*g_beg;
t_list	*g_elem;

int		check_overlap(int size, int l, int k)
{
	if (g_i + l >= size)
	{
		if (find_prev(g_elem) == NULL)
			return (0);
		remove_elem(find_prev(g_elem), size);
		g_elem = find_prev(g_elem);
		g_i = g_elem->i;
		g_j = g_elem->j;
		return (2);
	}
	else if (g_j + k >= size)
	{
		g_i++;
		g_j = 0;
		return (1);
	}
	return (5);
}

int		try_position(int size)
{
	int		l;
	int		k;
	int		ret;

	l = 0;
	ret = 0;
	while (l < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (g_rez[l + g_i][k + g_j] != '.' && g_elem->elem[l][k] != '.')
				return (elems_bad(size));
			else if (g_elem->elem[l][k] != '.')
			{
				ret = check_overlap(size, l, k);
				if (ret != 5)
					return (ret);
			}
			k++;
		}
		l++;
	}
	return (3);
}

int		parse(int size)
{
	int		par;

	par = 4;
	g_elem = g_beg;
	while (g_elem != NULL)
	{
		while (1)
		{
			par = try_position(size);
			if (par == 0)
				return (0);
			else if (par == 3)
				break ;
		}
		add_to_rez(g_elem, g_i, g_j, size);
		g_elem = g_elem->next;
		g_i = 0;
		g_j = 0;
	}
	return (1);
}

void	solve(void)
{
	int		size;

	size = count_size();
	while (size < 20)
	{
		g_i = 0;
		g_j = 0;
		create_rez(size);
		if (parse(size) == 1)
		{
			print(size);
			return ;
		}
		else
		{
			g_i = 0;
			g_j = 0;
			clear(size);
			size++;
		}
	}
}

int		main(int argc, char const *argv[])
{
	char	*str;

	str = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file_to_solve\n");
		return (0);
	}
	if (ft_read(argv[1]) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	solve();
	return (0);
}
