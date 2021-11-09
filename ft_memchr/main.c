/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:49:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/05 13:56:59 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <string.h>

static int	ft_test(char *str, int c)
{
	size_t	len;

	len = strlen(str);
	return (memchr(str, c, len) == ft_memchr(str, c, len));
}

int	main(void)
{
	if (ft_test("Test string.", 's')
		|| ft_test("Test string.", '.')
		|| ft_test("Test string.", '\0'))
	{
		ft_putstr_test("KO: ft_memchr");
		return (1);
	}
	ft_putstr_test("OK: ft_memchr");
	return (0);
}
