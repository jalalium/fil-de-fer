/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:01:42 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 22:24:38 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_image_sub_sub(unsigned char **str, int *tab, int *pab, int i)
{
	int			j;
	t_point		a;
	t_point		b;
	t_point		c;
	t_couple	cord;

	j = 0;
	while (j < pab[0])
	{
		generate_points(tab, &a, 3 * (j + i * pab[0]), pab);
		if (j != (pab[0] - 1))
		{
			generate_points(tab, &b, 3 * (j + 1 + i * pab[0]), pab);
			cord = (t_couple){ .a = a, .b = b};
			draw_line(str, cord, pab);
		}
		if (i != (pab[1] - 1))
		{
			generate_points(tab, &c, 3 * (j + (i + 1) * pab[0]), pab);
			cord = (t_couple){ .a = a, .b = c};
			draw_line(str, cord, pab);
		}
		j++;
	}
}

void	draw_image_sub(unsigned char **str, int *tab, int *pab)
{
	int i;

	i = 0;
	while (i < pab[1])
	{
		draw_image_sub_sub(str, tab, pab, i);
		i++;
	}
}

void	draw_image(unsigned char **str, int *tab, int **cab)
{
	int temp1;
	int temp2;
	int *pab;

	pab = *cab;
	temp1 = pab[2];
	temp2 = pab[5];
	pab[2] *= (pab[11] == 1 ? (double)(pab[7]) / sqrt(max(pab[0]
	, pab[1])) : pab[6]);
	pab[5] *= (pab[11] == 1 ? (double)(pab[7]) / sqrt(max(pab[0]
	, pab[1])) : pab[6]);
	draw_image_sub(str, tab, pab);
	pab[2] = temp1;
	pab[5] = temp2;
}
