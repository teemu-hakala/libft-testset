/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:58:29 by thakala           #+#    #+#             */
/*   Updated: 2021/12/08 12:44:34 by thakala          ###   ########.fr       */
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
		|| !ft_test("-0")
		|| !ft_test("+0")
		|| !ft_test("-")
		|| !ft_test("+")
		|| !ft_test("a")
		|| !ft_test("+a")
		|| !ft_test("-b")
		|| !ft_test("+0872346")
		|| !ft_test("-0654673")
		|| !ft_test("+0x901329")
		|| !ft_test("-0x764981")
		|| !ft_test("7")
		|| !ft_test("+7a3")
		|| !ft_test("\t\n\r\v\f  469 \n")
		|| !ft_test("-6O40")
		|| !ft_test("++10")
		|| !ft_test("--10")
		|| !ft_test("+-10")
		|| !ft_test("-+10")
		|| !ft_test("2147483647")
		|| !ft_test("-2147483648")
		|| !ft_test("1000000000000")
		|| !ft_test("-1000000000000"))
	{
		printf("KO: ft_atoi\n");
		return (1);
	}
	printf("OK: ft_atoi\n");
	if (!ft_test("9999999999999999999999999999999998")
		||!ft_test("-9999999999999999999999999999999998"))
	{
		printf("No long max or min protection\n");
		return (1);
	}
	printf("long max and min protection");
	return (0);
}
