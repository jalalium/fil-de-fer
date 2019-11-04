/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:02:53 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:22:36 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_change(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[7] += 20;
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[10] = vals[7];
	((data.im_str).pab)[11] = vals[5];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	filling(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[6] = 1;
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[9] = vals[6];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	unfilling(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[6] = 0;
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[9] = vals[6];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	para_proj(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[5] = 1;
	vals[2] = ((data.im_str).pab[0] > 70 ? 17. : 25.) /
	(sqrt((data.im_str).pab[0]) * cos(0.523599) - sqrt((data.im_str).pab[1])
	* sin(0.523599));
	vals[0] = ((data.im_str).pab[0] > 300 ? -900 : -1400) + 400 -
	400. / (12 - 500) * (12 - ((data.im_str).pab)[0]);
	vals[1] = ((data.im_str).pab[1] > 70 ? -1100 : -900) + 200 -
	200. / (12 - 500) * (12 - ((data.im_str).pab)[1]);
	vals[3] = vals[2] * sqrt(max((data.im_str).pab[0], (data.im_str).pab[1]))
	/ max(log((data.im_str).pab[12]), 2);
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[10] = vals[7];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	iso_proj(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[5] = 0;
	vals[2] = max(min((double)(90) / sqrt((data.im_str).pab[0]),
	(double)(60) / sqrt(((data.im_str).pab)[1])), 1);
	vals[0] = -1300 + 400 - 400. / (12 - 500) *
	(12 - log(((data.im_str).pab)[0]));
	vals[1] = -1100 + 200 - 200. / (12 - 500) *
	(12 - log(((data.im_str).pab)[1]));
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[10] = vals[7];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}
