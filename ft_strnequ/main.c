/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:00:57 by thakala           #+#    #+#             */
/*   Updated: 2021/11/30 17:54:40 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2, size_t n, int expected)
{
	return (ft_strnequ(s1, s2, n) == expected);
}

static int	ft_test_loop(const char *s1, const char *s2, size_t upto)
{
	upto += 2;
	while (--upto)
		if (ft_strnequ(s1, s2, upto - 1) == !!strncmp(s1, s2, upto - 1))
			return (0);
	return (1);
}

int	main(void)
{
	if (!ft_test("", "", 0, 1)
		|| !ft_test("a", "b", 0, 1)
		|| !ft_test("", "", 1, 1)
		|| !ft_test_loop("equal", "equal", 6)
		|| !ft_test_loop("Not equal", "not equal", 10)
		|| !ft_test_loop("not equal\0", "not equal\1", 11))
	{
		printf("KO: ft_strnequ\n");
		return (1);
	}
	printf("OK: ft_strnequ\n");
	return (0);
}
