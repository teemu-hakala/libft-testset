/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:49:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/20 19:06:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

static int	ft_test_diff(char *str, int c, size_t len)
{
	return (memchr(str, c, len) == ft_memchr(str, c, len));
}

static int	ft_test(char *str, int c)
{
	return (ft_test_diff(str, c, strlen(str)));
}

int	main(void)
{
	if (!ft_test("Test string.", 's')
		|| !ft_test("Test string.", '.')
		|| !ft_test_diff("Test str\0ng.", '\0', 13))
	{
		printf("KO: ft_memchr\n");
		return (1);
	}
	printf("OK: ft_memchr\n");
	return (0);
}
