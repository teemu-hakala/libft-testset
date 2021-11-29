/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:32:21 by thakala           #+#    #+#             */
/*   Updated: 2021/11/29 10:52:16 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(int numeral)
{
	ft_putnbr(numeral);
	printf("\n");
	return (0);
}

static int	ft_test_range(int from, int upto)
{
	ft_test(from);
	while (from++ < upto)
		ft_test(from);
	return (0);
}

int	main(void)
{
	if (ft_test((int)0x80000000)
		|| ft_test(-1000000000)
		|| ft_test(-987654321)
		|| ft_test(-123456789)
		|| ft_test_range(-100, 100)
		|| ft_test(123456789)
		|| ft_test(987654321)
		|| ft_test((int)0x7FFFFFFF))
	{
		return (1);
	}
	printf("Observe results in stdout.\n");
	return (0);
}
