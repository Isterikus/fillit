/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:54:09 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/26 15:16:39 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_rez;
t_list	*g_beg;

void	clear(int size)
{
	int		i;

	i = 0;
	while (i <= size + 4)
		free(g_rez[i++]);
	free(g_rez);
}

int		ft_sqrt(int size)
{
	int		i;

	i = 2;
	while (i < size * 4)
	{
		if (i * i >= size * 4)
			return (i);
		i++;
	}
	return (0);
}

int		count_size(void)
{
	t_list	*temp;
	int		size;
	int		i;

	temp = g_beg;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	size = ft_sqrt(i);
	return (size);
}
