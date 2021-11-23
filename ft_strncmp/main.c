/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:38:47 by thakala           #+#    #+#             */
/*   Updated: 2021/11/23 14:40:09 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2, size_t len)
{
	char	*string1;
	char	*string2;
	int		std_result;
	int		ft_result;

	string1 = strdup(s1);
	string2 = strdup(s2);
	std_result = strncmp(string1, string2, len);
	ft_result = ft_strncmp(string1, string2, len);
	free(string1);
	free(string2);
	return (std_result == ft_result);
}

int	main(void)
{
	if (!ft_test("", "", 0)
		|| !ft_test("", "", 1)
		|| !ft_test("test", "test", 0)
		|| !ft_test("test", "test", (size_t)-23)
		|| !ft_test("aest", "fest", 0)
		|| !ft_test("best", "zest", 10)
		|| !ft_test("ok", "oko", 2)
		|| !ft_test("abc", "abe", 5)
		|| !ft_test("ab\0de", "ab\0cde", 5)
		|| !ft_test("a\0bde", "ab\0cde", 5)
		|| !ft_test("a\0bde", "zy\0xwv", 5))
	{
		printf("KO: ft_strncmp\n");
		return (1);
	}
	printf("OK: ft_strncmp\n");
}
