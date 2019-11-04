/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:00:35 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 20:36:57 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	invert_points(t_couple *bal)
{
	int			temp;
	t_couple	po;

	po = *bal;
	temp = (po.b).x;
	(po.b).x = (po.a).x;
	(po.a).x = temp;
	temp = (po.b).y;
	(po.b).y = (po.a).y;
	(po.a).y = temp;
	temp = (po.b).z;
	(po.b).z = (po.a).z;
	(po.a).z = temp;
}

void	fill_pos_y(unsigned char **str, t_couple po, int *tab, int k)
{
	int				x;
	int				y;
	int				x_t;
	int				p;
	unsigned char	*ptr;

	x = (po.a).x;
	y = (po.a).y;
	ptr = *str;
	p = 2 * ((po.b).x - (po.a).x) - ((po.b).y - (po.a).y);
	while (x <= (po.b).x && y <= (po.b).y)
	{
		ptr[4 * (x + tab[3] * (y + k))] = 255 * ((double)((
	(double)((po.b).z - (po.a).z) / ((po.b).y - (po.a).y)) *
	(y - (po.a).y) + (po.a).z - tab[5]) / (tab[2] - tab[5]));
		ptr[4 * (x + tab[3] * (y + k)) + 1] = tab[10];
		ptr[4 * (x + tab[3] * (y + k)) + 2] = (tab[2] == 0 && tab[5] == 0 ?
	255 : 255 * ((double)(tab[2] - ((((double)((po.b).z - (po.a).z) /
	((po.b).y - (po.a).y)) * (y - (po.a).y) + (po.a).z))) / (tab[2] - tab[5])));
		ptr[4 * (x + tab[3] * (y + k)) + 3] = 0;
		x_t = (p >= 0 ? x + 1 : x);
		p += 2 * ((po.b).x - (po.a).x) - 2 * ((po.b).y - (po.a).y) * (x_t - x);
		x = x_t;
		y++;
	}
}

void	fill_pos_x(unsigned char **str, t_couple po, int *tab, int k)
{
	int				x;
	int				y;
	int				y_t;
	int				p;
	unsigned char	*ptr;

	x = (po.a).x;
	y = (po.a).y;
	ptr = *str;
	p = 2 * ((po.b).y - (po.a).y) - ((po.b).x - (po.a).x);
	while (x <= (po.b).x && y <= (po.b).y)
	{
		ptr[4 * (x + tab[3] * (y + k))] = 255 * ((double)(((double)((po.b).z
	- (po.a).z) / ((po.b).x - (po.a).x)) * (x - (po.a).x) +
	(po.a).z - tab[5]) / (tab[2] - tab[5]));
		ptr[4 * (x + tab[3] * (y + k)) + 1] = tab[10];
		ptr[4 * (x + tab[3] * (y + k)) + 2] = (tab[2] == 0 && tab[5] == 0 ?
	255 : 255 * ((double)(tab[2] - ((((double)((po.b).z - (po.a).z) / ((po.b).x
	- (po.a).x)) * (x - (po.a).x) + (po.a).z))) / (tab[2] - tab[5])));
		ptr[4 * (x + tab[3] * (y + k)) + 3] = 0;
		y_t = (p >= 0 ? y + 1 : y);
		p += 2 * ((po.b).y - (po.a).y) - 2 * ((po.b).x - (po.a).x) * (y_t - y);
		y = y_t;
		x++;
	}
}

void	draw_line_pos(unsigned char **str, t_couple po, int *tab)
{
	int k;

	k = 0;
	if ((po.b).y - (po.a).y > (po.b).x - (po.a).x)
	{
		while (k < (tab[9] == 1 ? 6 * ((abs(tab[6]))) : 1))
		{
			fill_pos_y(str, po, tab, k);
			k++;
		}
	}
	else
	{
		while (k < (tab[9] == 1 ? 6 * ((abs(tab[6]))) : 1))
		{
			fill_pos_x(str, po, tab, k);
			k++;
		}
	}
}
