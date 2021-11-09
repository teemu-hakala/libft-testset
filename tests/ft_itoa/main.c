/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:53:59 by thakala           #+#    #+#             */
/*   Updated: 2021/11/05 07:35:49 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <string.h>

int	ft_test(int i, char *a)
{
	if (strcmp(ft_itoa(i), a))
	{
		ft_putstr_test("KO: ft_itoa\n");
		ft_putstr_test(a);
		return (1);
	}
	return (0);
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
		return (1);
	else
		ft_putstr_test("OK: ft_itoa\n");
}
