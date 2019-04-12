/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:29 by ylila             #+#    #+#             */
/*   Updated: 2019/04/12 14:39:19 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static size_t	check_lb(const char *buff, size_t size)
{
	size_t i;

	i = 0;
	while (size--)
	{
		if (buff[i] == '\n' || buff[i] == EOF)
			return (i);
		++i;
	}
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	ssize_t		ret;
	size_t		ind_len;

	if (fd == -1 || !line || !*line)
		return (-1);
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if (!(ind_len = check_lb(buff, BUFF_SIZE)))
			*line = ft_strncat(*line, buff, BUFF_SIZE);
		else
		{
			*line = ft_strncat(*line, buff, ind_len - 1);
			return (1);
		}
	}
	return (0);
}
