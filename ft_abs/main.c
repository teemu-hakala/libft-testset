/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:24:43 by thakala           #+#    #+#             */
/*   Updated: 2021/12/10 11:49:10 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(long value, size_t reference)
{
	return (ft_abs(value) != reference);
}

int	main(void)
{
	if (ft_test(-9223372036854775807l - 1l, (size_t)(-1l))
		|| ft_test(-10000000000000l, 10000000000000)
		|| ft_test(-9876543210l, 9876543210)
		|| ft_test(-1234567890l, 1234567890)
		|| ft_test(-1000l, 1000)
		|| ft_test(-1l, 1)
		|| ft_test(0l, 0)
		|| ft_test(1l, 1)
		|| ft_test(1000l, 1000)
		|| ft_test(1234567890l, 1234567890)
		|| ft_test(9876543210l, 9876543210)
		|| ft_test(9223372036854775807, 9223372036854775807))
	{
		printf("KO: ft_abs\n");
		return (1);
	}
	printf("OK: ft_abs\n");
}
