/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:57:31 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 21:59:56 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	generate_points(int *tab, t_point *a, int i, int *pab)
{
	int temp1;
	int temp2;

	temp1 = tab[i] - tab[i + 1];
	temp2 = tab[i] + tab[i + 1];
	if (pab[11] == 1)
	{
		a->z = (((double)pab[7] / sqrt(max(pab[0], pab[1])))) * tab[i + 2];
		a->x = 1800 + pab[6] * (((temp1) * cos(pab[8] * 0.523599)));
		a->y = 1200 - a->z + pab[6] * (temp2) * sin(pab[8] * 0.523599);
	}
	else
	{
		a->x = 1300 + pab[6] * tab[i];
		a->y = 1100 + pab[6] * tab[i + 1];
		a->z = pab[6] * tab[i + 2];
	}
}
