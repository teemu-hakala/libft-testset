/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:44:19 by thakala           #+#    #+#             */
/*   Updated: 2021/11/29 09:25:52 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *string, const char *charset)
{
	return (strcspn(string, charset) != ft_strcspn(string, charset));
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test(" ", "")
		|| ft_test("", "g")
		|| ft_test(" ", "g")
		|| ft_test("w", "w")
		|| ft_test("w", ":")
		|| ft_test("ijk", "pqr")
		|| ft_test("mno", "o")
		|| ft_test("set", "yws")
		|| ft_test("long\0er char star", "er charst"))
	{
		printf("KO: ft_strcspn\n");
		return (1);
	}
	printf("OK: ft_strcspn\n");
	return (0);
}
