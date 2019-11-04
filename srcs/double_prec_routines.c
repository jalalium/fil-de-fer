/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_prec_routines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:07:13 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:09:25 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	from_old(int x, int y, int *in, int col)
{
	if (x % 2 == 0 && y % 2 == 0)
	{
		return (in[3 * (x / 2 + (y / 2) * ((col + 1) / 2)) + 2]);
	}
	return (0);
}

int	hor(int x, int y, int *in, int col)
{
	return ((double)((in[3 * ((x + 1) / 2 + (y / 2) * ((col + 1) / 2)) + 2])
	+ (in[3 * ((x - 1) / 2 + (y / 2) * ((col + 1) / 2)) + 2])) / 2);
}

int	ver(int x, int y, int *in, int col)
{
	return ((double)((in[3 * (x / 2 + ((y + 1) / 2) * ((col + 1) / 2)) + 2])
	+ (in[3 * (x / 2 + ((y - 1) / 2) * ((col + 1) / 2)) + 2])) / 2);
}

int	diag(int x, int y, int *in, int col)
{
	return ((double)((in[3 * ((x + 1) / 2 + ((y + 1) / 2) * ((col + 1) / 2)) +
	2]) + (in[3 * ((x - 1) / 2 + ((y - 1) / 2) * ((col + 1) / 2)) + 2])) / 2);
}
