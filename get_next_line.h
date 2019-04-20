/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:36 by ylila             #+#    #+#             */
/*   Updated: 2019/04/20 16:12:12 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

# include <stdio.h>

# define BUFF_SIZE 8

typedef struct	s_lines
{
	int				fd;
	char			*str;
	char			*lb;
	struct s_list	*next;
}				t_line;

int				get_next_line(const int fd, char **line);

#endif
