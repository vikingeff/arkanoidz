/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:56 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:47:11 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char		*set_rest(char *str)
{
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n' && str[1] != '\0')
		return (ft_strdup(++str));
	else
		return (NULL);
}

static void		add_str(char **line, char *str)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	if (*line)
	{
		tmp = ft_strdup(*line);
		free(*line);
		len = ft_strlen(tmp) + ft_strlen(str);
		*line = (char *)malloc(sizeof(char) * (len + 1));
		ft_strcpy(*line, tmp);
		free(tmp);
		while ((*line)[i])
			i++;
	}
	else
	{
		len = ft_strlen(str);
		*line = (char *)malloc(sizeof(char) * (len + 1));
	}
	while (*str != '\0' && *str != '\n')
		(*line)[i++] = *str++;
	(*line)[i] = '\0';
}

static int		init_with_rest(char **line, char **rest)
{
	char	*del;

	if (*rest && ft_strchr(*rest, '\n'))
	{
		add_str(line, *rest);
		del = *rest;
		*rest = set_rest(del);
		free(del);
		return (1);
	}
	else if (*rest && !ft_strchr(*rest, '\n'))
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (0);
}

static int		start(char **line, char **rest, int const fd)
{
	if (*line)
		free(*line);
	*line = NULL;
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (init_with_rest(line, rest))
		return (1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int				check;
	size_t			ret;
	char			*str;
	static char		*rest = NULL;

	check = start(line, &rest, fd);
	if (check != 0)
		return (check);
	str = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, str, BUFF_SIZE)) > 0 && !ft_strchr(str, '\n'))
	{
		add_str(line, str);
		ft_bzero(str, BUFF_SIZE + 1);
	}
	if (ret > 0)
	{
		str[ret] = '\0';
		add_str(line, str);
		rest = set_rest(str);
	}
	free(str);
	ret = (ret > 1) ? 1 : ret;
	ret = (ret == 0 && *line != NULL) ? 1 : ret;
	return (ret);
}
