/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:00:12 by thakala           #+#    #+#             */
/*   Updated: 2021/11/03 10:01:00 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_test(char written_byte, int fd)
{
	char	read_byte;

	ft_putchar_fd(written_byte, fd);
	lseek(fd, 0, SEEK_SET);
	if (read(fd, &read_byte, 1) == -1)
	{
		ft_putstr_test("File read error.\n");
		close(fd);
		return (1);
	}
	if (written_byte == read_byte)
		ft_putstr_test("OK: ft_putchar_fd\n");
	else
	{
		ft_putstr_test("KO: ft_putchar_fd\n");
		ft_putstr_test("read byte: ");
		ft_putchar_test(read_byte);
		ft_putchar_test('\n');
	}
	return (0);
}

int	main(void)
{
	int		fd;

	fd = open("ft_putchar_fd.output",
			O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_test("File open error.\n");
		return (1);
	}
	if (ft_test('1', fd))
		return (1);
	close(fd);
}
