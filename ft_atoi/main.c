/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:58:29 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 17:25:57 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_test(char *n)
{
	int		i1;
	int		i2;

	i1 = atoi(n);
	i2 = ft_atoi(n);
	if (0)
		printf("%d %d\n", i1, i2);
	return (i1 == i2);
}

int	main(void)
{
	if (!ft_test("0")
		&& !ft_test("-0")
		&& !ft_test("+0")
		&& !ft_test("-")
		&& !ft_test("+")
		&& !ft_test("a")
		&& !ft_test("+a")
		&& !ft_test("-b")
		&& !ft_test("7")
		&& !ft_test("+7a3")
		&& !ft_test("-6O4")
		&& !ft_test("++10")
		&& !ft_test("--10")
		&& !ft_test("2147483647")
		&& !ft_test("-2147483648")
		&& !ft_test("1000000000000")
		&& !ft_test("-1000000000000"))
	{
		printf("KO: ft_atoi");
		return (1);
	}
	printf("OK: ft_atoi");
}
