/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:55:59 by ylila             #+#    #+#             */
/*   Updated: 2019/04/12 13:09:48 by ylila            ###   ########.fr       */
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
	int fd1 = open("test1.txt", O_RDONLY);

	char buff[SIZE];
	size_t byte = read(fd, buff, SIZE);
	printf("Test: %s\n", buff);
	size_t byte1 = read(fd1, buff, SIZE);
	printf("Test1: %s\n", buff);
	byte = read(fd, buff, SIZE);
	printf("Test: %s\n", buff);

	close(fd1);
	close(fd);
	return (0);
}
