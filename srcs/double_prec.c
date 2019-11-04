/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 22:03:41 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:10:11 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	double_table(int *out, int c_num, int l_num)
{
	int i;
	int j;

	i = 0;
	while (i < l_num)
	{
		j = 0;
		while (j < c_num)
		{
			out[3 * (j + i * c_num) + 2] *= 2;
			j++;
		}
		i++;
	}
}

void	fill_old(int **str, int len, int wid, int *in)
{
	int i;
	int j;
	int *out;

	i = 0;
	out = *str;
	while (i < 2 * len - 1)
	{
		j = 0;
		while (j < 2 * wid - 1)
		{
			out[3 * (j + i * (2 * wid - 1))] = j;
			out[3 * (j + i * (2 * wid - 1)) + 1] = i;
			out[3 * (j + i * (2 * wid - 1)) + 2] = from_old(j, i, in, 2 *
	wid - 1);
			j++;
		}
		i++;
	}
}

void	fill_new(int **str, int len, int wid, int *in)
{
	int i;
	int j;
	int *out;

	i = 0;
	out = *str;
	while (i < 2 * len - 1)
	{
		j = 0;
		while (j < 2 * wid - 1)
		{
			if (j % 2 == 1 && i % 2 == 0)
				out[3 * (j + i * (2 * wid - 1)) + 2] = hor(j, i, in, 2 *
	wid - 1);
			if (j % 2 == 0 && i % 2 == 1)
				out[3 * (j + i * (2 * wid - 1)) + 2] = ver(j, i, in, 2 *
	wid - 1);
			if (j % 2 == 1 && i % 2 == 1)
				out[3 * (j + i * (2 * wid - 1)) + 2] = diag(j, i, in, 2 *
	wid - 1);
			j++;
		}
		i++;
	}
}

int		**double_prec(int *in, int wid, int len)
{
	int **out;

	double_table(&(in[0]), wid, len);
	out = (int**)malloc(sizeof(int*) * 2);
	out[0] = (int*)malloc(sizeof(int) * 3 * (2 * wid - 1) * (2 * len - 1));
	out[1] = (int*)malloc(sizeof(int) * 12);
	fill_old(&(out[0]), len, wid, in);
	fill_new(&(out[0]), len, wid, in);
	out[1][0] = 2 * wid - 1;
	out[1][1] = 2 * len - 1;
	out[1][2] = ft_maxz(out[0], 2 * len - 1, 2 * wid - 1);
	out[1][5] = ft_minz(out[0], 2 * len - 1, 2 * wid - 1);
	out[1][12] = diff_vals(out[0], 2 * len - 1, 2 * wid - 1);
	return (out);
}
