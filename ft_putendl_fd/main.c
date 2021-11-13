/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:21:52 by thakala           #+#    #+#             */
/*   Updated: 2021/11/13 14:52:01 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	ft_test_rdwr(char *str, int fd)
{
	char	*read_str;
	size_t	size;
	ssize_t	rb;
	int		result;
	char	*strnl;

	ft_putendl_fd(str, fd);
	size = strlen(str);
	read_str = (char *)malloc(sizeof(char) * (size + (size_t)2));
	strnl = (char *)malloc(sizeof(char) * (strlen(str) + 2));
	if (!read_str || !strnl)
	{
		printf("Memory allocation error!\n");
		free(read_str);
		free(strnl);
		return (1);
	}
	lseek(fd, 0, SEEK_SET);
	rb = read(fd, read_str, size + 1);
	if (rb == -1)
	{
		printf("File read error.\n");
		free(read_str);
		free(strnl);
		return (1);
	}
	read_str[rb] = '\0';
	result = strcmp(strcat(strcpy(strnl, str), "\n"), read_str);
	free(read_str);
	free(strnl);
	return (result);
}

static int	ft_test(char *str)
{
	int		fd;

	fd = open("ft_putendl_fd.output",
			O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("File open error.\n");
		return (1);
	}
	ft_test_rdwr(str, fd);
	if (close(fd) == -1)
		printf("File close error.\n");
	return (0);
}

int	main(void)
{
	if (ft_test("42")
		|| ft_test("")
		|| ft_test("ft_putendln\0\n"))
	{
		printf("KO: ft_putendln_fd\n");
		return (1);
	}
	printf("OK: ft_putendln_fd\n");
	return (0);
}
