/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:07:53 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:24:17 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_im(unsigned char **tmp, unsigned char *str, int len)
{
	int				i;
	unsigned char	*temp;

	i = 0;
	temp = *tmp;
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
}

int		errors(int argc, int **tab)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [-d iterations] File_name\n");
		return (-1);
	}
	if (tab == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}

void	instructions(void *a, void *b, char *str)
{
	mlx_string_put(a, b, 890, 400, 51000, "FDF of :");
	mlx_string_put(a, b, 910, 450, 5100000, str);
	mlx_string_put(a, b, 880, 500, 51000, "iso proj : 1");
	mlx_string_put(a, b, 880, 550, 51000, "para proj : 2");
	mlx_string_put(a, b, 881, 600, 51000, "zoom in/out : p/l");
	mlx_string_put(a, b, 883, 650, 51000, "raise/lower : +/-");
	mlx_string_put(a, b, 875, 700, 51000, "change colors : c");
	mlx_string_put(a, b, 875, 750, 51000, "fill/unfill : f/u");
	mlx_string_put(a, b, 875, 800, 51000, "view : </>");
	mlx_string_put(a, b, 875, 850, 51000, "directions : arrows");
}

int		main(int argc, char **argv)
{
	t_data			data;
	void			*img2;
	unsigned char	*temp;
	unsigned char	*str2;
	int				**tab;

	tab = into_tab(argv[1 + prec_mode(argc, argv)[1]]);
	if (errors(argc - prec_mode(argc, argv)[1], tab) == -1)
		return (0);
	tab = doubled_arr(prec_mode(argc, argv)[0], tab);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1800, 1200, "FDF");
	instructions(data.mlx_ptr, data.mlx_win, (argc == 2 ? argv[1] : argv[3]));
	img2 = mlx_new_image(data.mlx_ptr, 7200, 4800);
	str2 = (unsigned char*)mlx_get_data_addr(img2, &(tab[1][3]),
	&(tab[1][3]), &(tab[1][3]));
	tab[1][3] = 7200;
	tab[1][4] = 4800;
	data.img = img2;
	temp = malloc(sizeof(unsigned char) * 7200 * 4800 * 4);
	ft_init_im(&temp, str2, 7200 * 4800 * 4);
	data.im_str = (t_image){ .str = &str2, .tab = tab[0],
		.pab = tab[1], .start = temp};
	mlx_key_hook(data.mlx_win, deal_key, &(data));
	mlx_loop(data.mlx_ptr);
}
