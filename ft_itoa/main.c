/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:53:59 by thakala           #+#    #+#             */
/*   Updated: 2021/11/24 17:03:01 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <string.h>

int	ft_test(int i, char *a)
{
	return (!!strcmp(ft_itoa(i), a));
}

int	main(void)
{
	if (ft_test(1, "1")
		|| ft_test(-1, "-1")
		|| ft_test(-10, "-10")
		|| ft_test(2147483647, "2147483647")
		|| ft_test(-2147483648, "-2147483648")
		|| ft_test(0, "0")
		|| ft_test(1000, "1000")
		|| ft_test(2345, "2345")
		|| ft_test(19, "19")
		|| ft_test(55, "55")
		|| ft_test(-3000, "-3000")
		|| ft_test(250000, "250000"))
	{
		printf("KO: ft_itoa\n");
		return (1);
	}
	printf("OK: ft_itoa\n");
	return (0);
}
