/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:17:12 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:18:57 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		*prec_mode(int argc, char **argv)
{
	int *tab;

	tab = (int*)malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 0;
	if (argc > 2 && ft_strncmp(argv[1], "-d", 2) == 0
	&& ft_isdigit(argv[2][0]) == 1)
	{
		tab[0] = ft_atoi(argv[2]);
		tab[1] = 2;
	}
	return (tab);
}

int		**doubled_arr(int i, int **tab)
{
	int j;

	j = 0;
	while (j < min(i, min(7, min(1100 / tab[1][0], 1100 / tab[1][1]))))
	{
		tab = double_prec(tab[0], tab[1][0], tab[1][1]);
		j++;
	}
	return (tab);
}
