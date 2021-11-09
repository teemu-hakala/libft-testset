/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 05:59:57 by thakala           #+#    #+#             */
/*   Updated: 2021/11/05 06:14:14 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <ctype.h>

int	main(void)
{
	int		c;

	c = -1000;
	while (c <= 1000)
	{
		if (isalnum(c) != ft_isalnum(c))
		{
			ft_putstr_test("KO: ft_isalnum");
			ft_putstr_test((char *)&c);
		}
		c++;
	}
	ft_putstr_test("OK: ft_isalnum");
}
