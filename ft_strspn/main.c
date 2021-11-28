/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:27:33 by thakala           #+#    #+#             */
/*   Updated: 2021/11/28 18:48:18 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *string, const char *charset)
{
	return (strspn(string, charset) != ft_strspn(string, charset));
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test(" ", "")
		|| ft_test(" ", " ")
		|| ft_test(" ", "u")
		|| ft_test("r", "cool")
		|| ft_test("sweet", "t")
		|| ft_test("amazing", "amz")
		|| ft_test("neat", "net")
		|| ft_test("quirky", "uirky")
		|| ft_test("lively", "l")
		|| ft_test("beautiful", "beautiful")
		|| ft_test("\0I\0love\0you\0", "\0Iloveyou"))
	{
		printf("KO: ft_strspn\n");
		return (1);
	}
	printf("OK: ft_strspn\n");
	return (0);
}
