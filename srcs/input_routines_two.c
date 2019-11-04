/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_routines_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:16:26 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:19:22 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		col_num(char *str)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_strparse(str, ' ');
	while (temp[i] != NULL)
		i++;
	free(temp);
	return (i);
}

int		file_nums(char *name, int *line, int *col)
{
	int		i;
	int		r;
	int		fd;
	char	*str;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 1)
		return (-1);
	while ((r = get_next_line(fd, &str)) > 0)
	{
		if (i == 0)
			*col = col_num(str);
		i++;
	}
	close(fd);
	*line = i;
	if (*line == 0 || *col == 0 || r == -1)
		return (-1);
	return (0);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}

double	min(double a, double b)
{
	return (a < b ? a : b);
}
