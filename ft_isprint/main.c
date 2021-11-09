/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:07:04 by thakala           #+#    #+#             */
/*   Updated: 2021/11/08 19:07:35 by thakala          ###   ########.fr       */
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
		if (isprint(c) != ft_isprint(c))
		{
			ft_putstr_test("KO: ft_isprint");
			ft_putstr_test((char *)&c);
		}
		c++;
	}
	ft_putstr_test("OK: ft_isprint");
}
