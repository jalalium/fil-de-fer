/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:04:44 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:21:08 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key_sub_small(int key, void *param, int *vals)
{
	if (key == 3)
		filling(vals, param);
	else if (key == 8)
		color_change(vals, param);
	else if (key == 32)
		unfilling(vals, param);
	else if (key == 18)
		para_proj(vals, param);
	else if (key == 19)
		iso_proj(vals, param);
	else if (key == 35)
		zoom_in(vals, param);
	else if (key == 37)
		zoom_out(vals, param);
	return (0);
}

int	deal_key_sub_large(int key, void *param, int *vals)
{
	if (key == 69)
		raise(vals, param);
	else if (key == 78)
		lower(vals, param);
	else if (key == 123)
		left(vals, param);
	else if (key == 125)
		down(vals, param);
	else if (key == 124)
		right(vals, param);
	else if (key == 126)
		up(vals, param);
	else if (key == 43)
		thirty(vals, param);
	else if (key == 47)
		sixty(vals, param);
	return (0);
}

int	deal_key(int key, void *param)
{
	static int	vals[8] = {0, 0, 0, 0, 1, 0, 0};
	t_data		data;

	data = *((t_data*)param);
	ft_init_im((data.im_str).str, (data.im_str).start, 7200 * 4800 * 4);
	if (key == 53)
		exit(0);
	else if (key > 40)
		deal_key_sub_large(key, param, vals);
	else
		deal_key_sub_small(key, param, vals);
	return (1);
}
