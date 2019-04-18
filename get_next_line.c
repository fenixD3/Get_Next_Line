/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:29 by ylila             #+#    #+#             */
/*   Updated: 2019/04/18 15:39:03 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*strs;
	char		*lb;
	ssize_t		b;

	if ((fd < 0 || !line || !*line) || (!strs && !(strs = ft_strnew(0))))
		return (-1);
	while (!(lb = ft_strchr(strs, '\n')) && (b = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[b] = '\0';
		strs = ft_strjoin(strs, buf);
	}
	if (b == 0)
	{
		ft_strdel(&strs);
		return (0);
	}
	*line = ft_strsub(strs, 0, lb - strs);
	strs = ft_strsub(strs, (unsigned int)(ft_strlen(*line) + 1),
			ft_strlen(strs) - ft_strlen(*line));
	return (1);
}
