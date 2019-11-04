/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:01:10 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 22:19:33 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(unsigned char **str, t_couple po, int *tab)
{
	int		delta_x;
	int		delta_y;
	t_point	temp;

	delta_x = (po.b).x - (po.a).x;
	delta_y = (po.b).y - (po.a).y;
	if (delta_x < 0 && delta_y >= 0)
		draw_line_xneg(str, po, tab);
	else if (delta_x >= 0 && delta_y < 0)
		draw_line_yneg(str, po, tab);
	else
	{
		if (delta_x < 0 && delta_y < 0)
		{
			temp = po.b;
			po.b = po.a;
			po.a = temp;
			draw_line_pos(str, po, tab);
		}
		else
			draw_line_pos(str, po, tab);
	}
}
