/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:55:59 by ylila             #+#    #+#             */
/*   Updated: 2019/04/19 13:55:04 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h> // open() for fd and flags to open
#include <sys/stat.h> // permission flags
#include <sys/types.h> // type mode_t for permission flags
#include <unistd.h> // write(), read(), close()
#include "get_next_line.h"

int		main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("gnl7_3.txt", O_RDONLY);
	int gnl_error;
	char *line = NULL;
	int count_lines = 0;
	int errors = 0;

	while ((gnl_error = get_next_line(fd1, &line)) > 0)
		printf("Error code = %d\n%s\n", gnl_error, line);
	printf("Error code = %d\n", gnl_error);

	/*while ((gnl_error = get_next_line(fd1, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			errors++;
		if (count_lines == 2 && strcmp(line, "4567890") != 0)
			errors++;
		if (count_lines == 3 && strcmp(line, "defghijk") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");*/

	/*gnl_error = get_next_line(fd, &line);
	printf("Error code = %d\n%s\n", gnl_error, line);

	gnl_error = get_next_line(fd1, &line);
	printf("Error code = %d\n%s\n", gnl_error, line);

	gnl_error = get_next_line(fd, &line);
	printf("Error code = %d\n%s\n", gnl_error, line);*/

	close(fd1);
	close(fd);
	return (0);
}
