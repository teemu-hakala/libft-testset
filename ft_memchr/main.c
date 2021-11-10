/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:49:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:34:26 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

static int	ft_test(char *str, int c)
{
	size_t	len;

	len = strlen(str);
	return (memchr(str, c, len) == ft_memchr(str, c, len));
}

int	main(void)
{
	if (!ft_test("Test string.", 's')
		|| !ft_test("Test string.", '.')
		|| !ft_test("Test string.", '\0'))
	{
		printf("KO: ft_memchr");
		return (1);
	}
	printf("OK: ft_memchr");
	return (0);
}
