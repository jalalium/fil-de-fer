/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:03:21 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:22:37 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_in(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[2]++;
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[10] = vals[7];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	zoom_out(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[2]--;
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[10] = vals[7];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	raise(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[3] += 8;
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[10] = vals[7];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}

void	lower(int *vals, void *param)
{
	t_data data;

	data = *((t_data*)param);
	vals[3] -= 8;
	((data.im_str).pab)[7] = vals[3];
	((data.im_str).pab)[6] = vals[2];
	((data.im_str).pab)[11] = vals[5];
	((data.im_str).pab)[8] = vals[4];
	((data.im_str).pab)[10] = vals[7];
	draw_image((data.im_str).str, (data.im_str).tab, &((data.im_str).pab));
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, vals[0],
	vals[1]);
}
