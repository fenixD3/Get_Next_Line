/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:29 by ylila             #+#    #+#             */
/*   Updated: 2019/04/18 12:47:37 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>

/*static size_t	check_lb(const char *buff, size_t size)
{
	size_t i;

	i = 0;
	while (size--)
	{
		if (buff[i] == '\n')
			return (i);
		++i;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	static char	*strs;
	ssize_t		ret;
	size_t		ind_len;

	if (fd == -1 || !line || !*line)
		return (-1);
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if (!(ind_len = check_lb(buff, ret)))
			*line = ft_strncat(*line, buff, ret);
		else
		{
			*line = ft_strncat(*line, buff, ind_len);
			return (1);
		}
	}
	return (0);
}*/

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*strs;
	char		*final;
	ssize_t		bytes;

	if ((fd < 0 || !line || !*line) || (strs == NULL && !(strs = ft_strnew(0))))
		return (-1);
	while (!ft_strchr(strs, '\n') && (bytes = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (!ft_strchr(buff, '\n'))
			strs = ft_strjoin(strs, buff);
		else
		{
			final = ft_strsub(buff, 0, ft_strchr(buff, '\n') - buff);
			strs = ft_strjoin(strs, final);
			*line = ft_strsub(strs, 0, ft_strlen(strs));
			strs = ft_strsub(buff, (unsigned int)(ft_strlen(final) + 1),
					ft_strlen(buff) - ft_strlen(final));
			printf("--------------------------------\n");
			printf("Strs: %s - Final: %s\n", strs, final);
			return (1);
		}
	}
	printf("--------------------------------\n");
	printf("Strs before: %s\n", strs);
	*line = ft_strsub(strs, 0, ft_strchr(strs, '\n') - strs);
	strs = ft_strsub(strs, (unsigned int)(ft_strlen(*line) + 1),
			ft_strlen(strs) - ft_strlen(*line));
	printf("Strs: %s\n", strs);
	if (!strs)
		return (0);
	return (1);
}
