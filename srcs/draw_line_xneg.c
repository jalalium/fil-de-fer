/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_xneg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:58:23 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 20:36:43 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_xneg_y(unsigned char **str, t_couple po, int *tab, int k)
{
	int				x;
	int				y;
	int				x_t;
	int				p;
	unsigned char	*ptr;

	x = (po.a).x;
	y = (po.a).y;
	ptr = *str;
	p = 2 * ((po.a).x - (po.b).x) - ((po.b).y - (po.a).y);
	while (x >= (po.b).x && y <= (po.b).y)
	{
		ptr[4 * (x + tab[3] * (y + k))] = 255 * ((double)(((double)((po.b).z -
	(po.a).z) / ((po.b).y - (po.a).y)) * (y - (po.a).y) + (po.a).z - tab[5]) /
	(tab[2] - tab[5]));
		ptr[4 * (x + tab[3] * (y + k)) + 1] = tab[10];
		ptr[4 * (x + tab[3] * (y + k)) + 2] = (tab[2] == 0 && tab[5] == 0 ?
	255 : 255 * ((double)(tab[2] - ((((double)((po.b).z - (po.a).z) /
	((po.b).y - (po.a).y)) * (y - (po.a).y) + (po.a).z))) / (tab[2] - tab[5])));
		ptr[4 * (x + tab[3] * (y + k)) + 3] = 0;
		x_t = (p >= 0 ? x - 1 : x);
		p += 2 * ((po.a).x - (po.b).x) - 2 * ((po.b).y - (po.a).y) * (x - x_t);
		x = x_t;
		y++;
	}
}

void	fill_xneg_x(unsigned char **str, t_couple po, int *tab, int k)
{
	int				x;
	int				y;
	int				y_t;
	int				p;
	unsigned char	*ptr;

	x = (po.a).x;
	y = (po.a).y;
	ptr = *str;
	p = 2 * ((po.b).y - (po.a).y) - ((po.a).x - (po.b).x);
	while (x >= (po.b).x && y <= (po.b).y)
	{
		ptr[4 * (x + tab[3] * (y + k))] = 255 * ((double)(((double)((po.b).z -
	(po.a).z) / ((po.a).x - (po.b).x)) * ((po.a).x - x) + (po.a).z - tab[5]) /
	(tab[2] - tab[5]));
		ptr[4 * (x + tab[3] * (y + k)) + 1] = tab[10];
		ptr[4 * (x + tab[3] * (y + k)) + 2] = (tab[2] == 0 && tab[5] == 0 ?
	255 : 255 * ((double)(tab[2] - ((((double)((po.b).z - (po.a).z) /
	((po.a).x - (po.b).x)) * ((po.a).x - x) + (po.a).z))) / (tab[2] - tab[5])));
		ptr[4 * (x + tab[3] * (y + k)) + 3] = 0;
		y_t = (p >= 0 ? y + 1 : y);
		p += 2 * ((po.b).y - (po.a).y) - 2 * ((po.a).x - (po.b).x) * (y_t - y);
		y = y_t;
		x--;
	}
}

void	draw_line_xneg(unsigned char **str, t_couple po, int *tab)
{
	int k;

	k = 0;
	if ((po.b).y - (po.a).y > (po.a).x - (po.b).x)
	{
		while (k < (tab[9] == 1 ? 6 * ((abs(tab[6]))) : 1))
		{
			fill_xneg_y(str, po, tab, k);
			k++;
		}
	}
	else
	{
		while (k < (tab[9] == 1 ? 6 * ((abs(tab[6]))) : 1))
		{
			fill_xneg_x(str, po, tab, k);
			k++;
		}
	}
}
