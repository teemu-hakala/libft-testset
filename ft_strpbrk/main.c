/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:37:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/28 17:00:52 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *origin, const char *charset)
{
	int	result;

	result = 0;
	while (*origin && !result)
	{
		result = strpbrk(origin, charset) != ft_strpbrk(origin, charset);
		origin++;
	}
	result = strpbrk(origin, charset) != ft_strpbrk(origin, charset);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("", "I")
		|| ft_test(" ", "")
		|| ft_test(" ", "l")
		|| ft_test("ove", "")
		|| ft_test("ove", "U")
		|| ft_test("a", "a")
		|| ft_test("lw", "w")
		|| ft_test("ays", "y")
		|| ft_test("tripletest", "t")
		|| ft_test("doubletest", "t")
		|| ft_test("odd", "d")
		|| ft_test("quadrupletest", "quadrplets")
		|| ft_test("tokyo", "toy")
		|| ft_test("Beast in Black", "Beast")
		|| ft_test("Beast in B", "Beast in"))
	{
		printf("KO: ft_strpbrk\n");
		return (1);
	}
	printf("OK: ft_strpbrk\n");
	return (0);
}
