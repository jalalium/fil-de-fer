/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_to_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:49:49 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:06:39 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**generate_tabs(int c_num, int l_num)
{
	int **out;

	out = (int**)malloc(sizeof(int*) * 2);
	out[0] = (int*)malloc(sizeof(int) * c_num * l_num * 3);
	out[1] = (int*)malloc(sizeof(int) * 13);
	return (out);
}

void	init_free(int *i, int *j, char *str, char **temp)
{
	if (i != NULL && j != NULL)
	{
		*i = 0;
		*j = 0;
	}
	if (str != NULL && temp != NULL)
	{
		free(str);
		free(temp);
	}
}

int		populate(int **out, char *name, int c_num, int l_num)
{
	int		i;
	int		j;
	int		fd;
	char	*str;
	char	**temp;

	init_free(&i, &j, NULL, NULL);
	fd = open(name, O_RDONLY);
	while (i < l_num)
	{
		j = 0;
		get_next_line(fd, &str);
		if (col_num(str) < c_num)
			return (-1);
		temp = ft_strparse(str, ' ');
		while (j < c_num)
		{
			out[0][3 * (j + i * c_num)] = j;
			out[0][3 * (j + i * c_num) + 1] = i;
			out[0][3 * (j + i * c_num) + 2] = ft_atoi(temp[j]);
			j++;
		}
		i++;
	}
	return (0);
}

int		**into_tab(char *name)
{
	int **out;
	int c_num;
	int l_num;

	if (file_nums(name, &l_num, &c_num) == -1)
		return (NULL);
	out = generate_tabs(c_num, l_num);
	if (populate(out, name, c_num, l_num) == -1)
		return (NULL);
	out[1][0] = c_num;
	out[1][1] = l_num;
	out[1][2] = ft_maxz(out[0], c_num, l_num);
	out[1][5] = ft_minz(out[0], c_num, l_num);
	out[1][12] = diff_vals(out[0], c_num, l_num);
	return (out);
}
