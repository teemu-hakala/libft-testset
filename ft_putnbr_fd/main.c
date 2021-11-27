/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:02:39 by thakala           #+#    #+#             */
/*   Updated: 2021/11/27 11:31:09 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_test(int written_int)
{
	char	read_int[11];
	int		fd;

	fd = open("ft_putnbr_fd.output",
			O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("File open error.\n");
		return (1);
	}
	ft_putnbr_fd(written_int, fd);
	lseek(fd, 0, SEEK_SET);
	if (read(fd, &read_int, 11) == -1)
	{
		printf("File read error.\n");
		close(fd);
		return (1);
	}
	if (written_int == atoi(read_int))
		printf("OK: ft_putnbr_fd\n");
	else
	{
		printf("KO: ft_putnbr_fd\n");
		printf("read byte: %d\n", atoi(read_int));
	}
	close(fd);
	return (0);
}

int	main(void)
{
	if (ft_test(0)
		|| ft_test(4)
		|| ft_test((int)(~(~0u >> 1)))
		|| ft_test((int)((~0u >> 1)))
		|| ft_test(1000000000))
		return (1);
}
