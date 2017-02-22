/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:50:05 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/23 10:39:09 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**g_rez;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_fill_zero(char *str)
{
	int		i;

	i = 0;
	while (i < 19)
		str[i++] = '\0';
}

int		ft_read(const char *file)
{
	int		fd;
	char	*str;
	int		count;
	int		i;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	str = (char *)malloc(sizeof(char) * 22);
	while ((i = read(fd, str, 21)) == 21)
	{
		str[21] = '\0';
		if (check(str, count, 0) == 0)
			return (0);
		count++;
		ft_fill_zero(str);
	}
	if (check(str, count, 1) == 0)
		return (0);
	if (i < 19)
		return (0);
	count = 0;
	return (1);
}

void	print(int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(g_rez[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
