/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:26:12 by thakala           #+#    #+#             */
/*   Updated: 2021/12/10 11:44:06 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(long value, char reference)
{
	return (ft_sign(value) != reference);
}

int	main(void)
{
	if (ft_test(0, 1)
		|| ft_test(-1l, -1)
		|| ft_test(1l, 1)
		|| ft_test(-123456789l, -1)
		|| ft_test(123456789l, 1)
		|| ft_test(-10000000000000000l, -1)
		|| ft_test(10000000000000000l, 1))
	{
		printf("KO: ft_sign\n");
		return (1);
	}
	printf("OK: ft_sign\n");
	return (0);
}
