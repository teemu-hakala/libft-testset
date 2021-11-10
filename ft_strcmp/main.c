/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:04:56 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 16:35:07 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2)
{
	char	*string1;
	char	*string2;
	int		std_result;
	int		ft_result;

	string1 = strdup(s1);
	string2 = strdup(s2);
	std_result = strcmp(string1, string2);
	ft_result = ft_strcmp(string1, string2);
	free(string1);
	free(string2);
	return (std_result == ft_result);
}

int	main(void)
{
	if (!ft_test("test", "test")
		|| !ft_test("", "")
		|| !ft_test("best", "zest")
		|| !ft_test("ok", "oko")
		|| !ft_test("abc", "abe")
		|| !ft_test("ab\0de", "ab\0cde"))
	{
		printf("KO: ft_strcmp\n");
	}
	printf("OK: ft_strcmp\n");
}
