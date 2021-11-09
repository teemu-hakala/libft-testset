/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:02:39 by thakala           #+#    #+#             */
/*   Updated: 2021/11/04 17:20:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_test(int written_int)
{
	char	read_int[11];
	int		fd;

	fd = open("ft_putnbr_fd.output",
			O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_test("File open error.\n");
		return (1);
	}
	ft_putnbr_fd(written_int, fd);
	lseek(fd, 0, SEEK_SET);
	if (read(fd, &read_int, 11) == -1)
	{
		ft_putstr_test("File read error.\n");
		close(fd);
		return (1);
	}
	if (written_int == ft_atoi_test(read_int))
		ft_putstr_test("OK: ft_putnbr_fd\n");
	else
	{
		ft_putstr_test("KO: ft_putnbr_fd\n");
		ft_putstr_test("read byte: ");
		ft_putnbr_test(ft_atoi_test(read_int));
		ft_putchar_test('\n');
	}
	close(fd);
	return (0);
}

int	main(void)
{
	if (ft_test(4))
		return (1);
}
