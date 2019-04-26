/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:29 by ylila             #+#    #+#             */
/*   Updated: 2019/04/26 18:14:07 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*strs[10240];
	char		*lb;
	char		*tmp;
	ssize_t		b;

	if (fd < 0 || !line || (strs[fd] == NULL && !(strs[fd] = ft_strnew(0))))
		return (-1);
	while (!(lb = ft_strchr(strs[fd], '\n')) && (b = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[b] = '\0';
		tmp = strs[fd];
		strs[fd] = ft_strjoin(strs[fd], buf);
		ft_strdel(&tmp);
	}
	if (b == -1 || !*(tmp = strs[fd]))
		return (b == -1 ? -1 : 0);
	if (!lb)
		*line = ft_strdup(strs[fd]);
	else
		*line = ft_strsub(strs[fd], 0, lb - strs[fd]);
	strs[fd] = ft_strsub(strs[fd], (unsigned int)(ft_strlen(*line) + 1),
			ft_strlen(strs[fd]) - ft_strlen(*line));
	ft_strdel(&tmp);
	return (1);
}*/

t_list	*find_node(t_line *head, const size_t fd)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->content_size == fd)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*head;
	t_list			*cur;
	char			*tmp;
	ssize_t			b;

	if (fd < 0 || !line || (!(cur = find_node(head, fd)) &&
				!(ft_lstpush(&head, ft_lstnew(ft_strnew(fd), fd)))))
		return (-1);
	while (!(ft_strchr(cur->str, '\n')) &&
			(b = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[b] = '\0';
		tmp = cur->str;
		cur->str = ft_strjoin(cur->str, buf);
		ft_strdel(&tmp);
	}
	if (b == -1 || !*(tmp = cur->str))
		return (b == -1 ? -1 : 0);
	if (!cur->lb)
		*line = ft_strdup(cur->str);
	else
		*line = ft_strsub(cur->str, 0, cur->lb - cur->str);
	cur->str = ft_strsub(cur->str, (unsigned int)(ft_strlen(*line) + 1),
			ft_strlen(cur->str) - ft_strlen(*line));
	ft_strdel(&tmp);
	return (1);
}
