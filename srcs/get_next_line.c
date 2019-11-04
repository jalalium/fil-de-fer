/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:42:25 by mmaaouni          #+#    #+#             */
/*   Updated: 2018/10/28 12:50:21 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

static int		ft_retrieve(t_list *s, char **line, int ret)
{
	int		len;

	len = 0;
	while (((char*)(s->content))[len] != '\n' && ((char*)(s->content))[len] !=
		'\0')
		len++;
	*line = (char*)malloc(len + 1);
	if (((char*)(s->content))[len] == '\n')
	{
		*line = ft_strsub(((char*)(s->content)), 0, (size_t)len);
		(*line)[len] = '\0';
		s->content = ft_strdup((char*)(s->content) + len + 1);
	}
	else if (((char*)(s->content))[len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line((int)(s->content_size), line));
		*line = ft_strdup(((char*)(s->content)));
		(*line)[len] = '\0';
		((char*)(s->content))[0] = 0;
	}
	return (1);
}

static t_list	*genese(t_list *tmp, t_list **files, int fd)
{
	tmp = ft_lstnew((void*)ft_strnew(1), (size_t)fd);
	ft_lstadd(files, tmp);
	*files = tmp;
	return (tmp);
}

static t_list	*filefinder(t_list **files, int fd)
{
	t_list *tmp;

	tmp = *files;
	while (tmp != NULL)
	{
		if (tmp->content_size == (size_t)fd)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	char			*buf;
	t_list			*tmp;
	int				ret;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || (ret = read(fd, buf, BUFF_SIZE)) < 0 || (void*)line == 0)
		return (-1);
	if (files == NULL)
		files = ft_lstnew((void*)ft_strnew(1), (size_t)fd);
	tmp = filefinder(&files, fd);
	while (ret > 0)
	{
		if (tmp == NULL)
			tmp = genese(tmp, &files, fd);
		buf[ret] = '\0';
		tmp->content = ft_strjoin((char*)(tmp->content), buf);
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret == 0 && (((char*)(tmp->content))[0] == '\0'))
		return (0);
	return (ft_retrieve(tmp, line, ret));
}
