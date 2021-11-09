/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:24:36 by thakala           #+#    #+#             */
/*   Updated: 2021/11/05 06:25:00 by thakala          ###   ########.fr       */
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
		if (isdigit(c) != ft_isdigit(c))
		{
			ft_putstr_test("KO: ft_isdigit");
			ft_putstr_test((char *)&c);
		}
		c++;
	}
	ft_putstr_test("OK: ft_isdigit");
}
