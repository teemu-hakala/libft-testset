/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:58:29 by thakala           #+#    #+#             */
/*   Updated: 2021/11/07 20:29:10 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <stdlib.h>

int	ft_test(char *n)
{
	int		i1;
	int		i2;

	i1 = atoi(n);
	i2 = ft_atoi(n);
	ft_putnbr_test(i1);
	ft_putchar_test(' ');
	ft_putnbr_test(i2);
	ft_putchar_test('\n');
	return (i1 == i2);
}

int	main(void)
{
	ft_atoi(NULL);
	if (ft_test("0")
		&& ft_test("-0")
		&& ft_test("+0")
		&& ft_test("-")
		&& ft_test("+")
		&& ft_test("a")
		&& ft_test("+a")
		&& ft_test("-b")
		&& ft_test("7")
		&& ft_test("+7a3")
		&& ft_test("-6O4")
		&& ft_test("++10")
		&& ft_test("--10")
		&& ft_test("2147483647")
		&& ft_test("-2147483648")
		&& ft_test("1000000000000")
		&& ft_test("-1000000000000"))
		ft_putstr_test("OK: ft_atoi");
	else
		ft_putstr_test("KO: ft_atoi");
}
