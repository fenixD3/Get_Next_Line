/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:55:59 by ylila             #+#    #+#             */
/*   Updated: 2019/04/17 16:02:36 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> // open() for fd and flags to open
#include <sys/stat.h> // permission flags
#include <sys/types.h> // type mode_t for permission flags
#include <unistd.h> // write(), read(), close()
#include "get_next_line.h"

#define SIZE 1

int		main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int gnl_error;
	char *line = ft_strnew(255);

	while ((gnl_error = get_next_line(fd, &line)) == 1)
		printf("%s\n", line);
	/*get_next_line(fd, &line);
	printf("%s\n", line);*/

	close(fd);
	return (0);
}
