/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:18:38 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 11:10:19 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_test(char *str, int fd)
{
	char	*str_;
	size_t	size;

	ft_putstr_fd(str, fd);
	size = ft_strlen_test(str);
	str_ = (char *)malloc(sizeof(*str_) * (size + (size_t)1));
	lseek(fd, 0, SEEK_SET);
	if (read(fd, &str_, size) == -1)
	{
		ft_putstr_test("File read error.\n");
		return (1);
	}
	str_[size] = '\0';
	ft_putstr_test(str);
	ft_putchar_test(' ');
	ft_putstr_test(str_);
	ft_putchar_test('\n');
	if (ft_strcmp_test(str, str_) == 0)
		ft_putstr_test("OK: ft_putstr_fd\n");
	else
	{
		ft_putstr_test("KO: ft_putstr_fd\n");
		ft_putstr_test(str_);
	}
	return (0);
}

int	main(void)
{
	int		fd;

	fd = open("ft_putstr_fd.output",
			O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_test("File open error.\n");
		return (1);
	}
	if (ft_test("42", fd))
		return (1);
	close(fd);
}
