/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:50:45 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 18:56:29 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2, int expected)
{
	return (ft_strequ(s1, s2) == expected);
}

int	main(void)
{
	if (!ft_test("", "", 1)
		|| !ft_test("equal", "equal", 1)
		|| !ft_test("Not equal", "not equal", 0)
		|| !ft_test("not equal\0", "not equal\1", 0))
	{
		printf("KO: ft_strequ\n");
		return (1);
	}
	printf("OK: ft_strequ\n");
}
