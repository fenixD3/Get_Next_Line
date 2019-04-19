/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:29 by ylila             #+#    #+#             */
/*   Updated: 2019/04/19 13:51:55 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void		check_EOF(char *buf, ssize_t bytes)
{
	// with one condition (< or <=) work bad at different input!
	if (bytes < BUFF_SIZE && buf[bytes - 1] != '\n')
	{
		buf[bytes] = '\n';
		buf[bytes + 1] = '\0';
	}
	else
		buf[bytes] = '\0';
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 2];
	static char	*strs[256];
	char		*lb;
	ssize_t		b;

	if (fd < 0 || !line || (strs[fd] == NULL && !(strs[fd] = ft_strnew(0))))
		return (-1);
	while (!(lb = ft_strchr(strs[fd], '\n')) &&
			(b = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		check_EOF(buf, b);
		strs[fd] = ft_strjoin(strs[fd], buf);
	}
	/*if (b == -1)
		return (-1);
	if (b == 0)
	{
		ft_strdel(&strs[fd]);
		return (0);
	}*/
	if (b == -1 || !*strs[fd])
		return (b == -1 ? -1 : 0);
	*line = ft_strsub(strs[fd], 0, lb - strs[fd]);
	strs[fd] = ft_strsub(strs[fd], (unsigned int)(ft_strlen(*line) + 1),
			ft_strlen(strs[fd]) - ft_strlen(*line));
	return (1);
}
