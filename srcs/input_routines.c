/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:48:13 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:18:32 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_maxz(int *tab, int col, int lin)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (i < lin)
	{
		j = 0;
		while (j < col)
		{
			if (tab[3 * (j + i * col) + 2] > max)
				max = tab[3 * (j + i * col) + 2];
			j++;
		}
		i++;
	}
	return (max);
}

int		diff_vals(int *tab, int col, int lin)
{
	int min;
	int i;
	int out;
	int j;

	i = 0;
	out = 0;
	min = ft_minz(tab, col, lin);
	while (i < lin)
	{
		j = 0;
		while (j < col)
		{
			if (tab[3 * (j + i * col) + 2] == min)
			{
				out++;
				min++;
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (out);
}

int		ft_minz(int *tab, int col, int lin)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (i < lin)
	{
		j = 0;
		while (j < col)
		{
			if (tab[3 * (j + i * col) + 2] < max)
				max = tab[3 * (j + i * col) + 2];
			j++;
		}
		i++;
	}
	return (max);
}
