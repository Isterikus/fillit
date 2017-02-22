/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:43:00 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/23 10:34:56 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_blocks(char **elem)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (elem[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		check_beside(char **elem, int i, int j)
{
	int		flag;

	flag = 0;
	if (j > 0 && elem[i][j - 1] == '#')
		flag++;
	if (j < 3 && elem[i][j + 1] == '#')
		flag++;
	if (i > 0 && elem[i - 1][j] == '#')
		flag++;
	if (i < 3 && elem[i + 1][j] == '#')
		flag++;
	if (flag == 0)
		return (-100000);
	else
		return (flag);
}

int		check_valid(char *str, int num)
{
	int		i;
	int		j;
	char	**elem;
	int		count;

	i = 0;
	elem = get_elem(str);
	count = 0;
	if (count_blocks(elem) != 4)
		return (0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (elem[i][j] == '#')
				count += check_beside(elem, i, j);
			j++;
		}
		i++;
	}
	if (count < 6)
		return (0);
	lst_add(elem, num);
	return (1);
}

int		check(char *str, int num, int kostil)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if ((i + 1) % 5 == 0)
		{
			if (str[i] != '\n' && kostil != 1)
				return (0);
		}
		else if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	if (kostil == 0)
		if (str[20] != '\n')
			return (0);
	return (check_valid(str, num));
}

void	change_hash(char **elem, int num, t_list *new)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (elem[i][j] == '#')
				new->elem[i][j] = num + 65;
			else
				new->elem[i][j] = '.';
			j++;
		}
		i++;
	}
}
