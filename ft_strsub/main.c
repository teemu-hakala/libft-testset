/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:44:25 by thakala           #+#    #+#             */
/*   Updated: 2021/12/09 10:19:06 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(char *string, unsigned int start,
	size_t length, char *reference)
{
	char	*output;
	int		result;

	output = ft_strsub(string, start, length);
	result = strcmp(output, reference);
	free(output);
	return (result);
}

int	main(void)
{
	if (ft_test("", 0, 0, "")
		|| ft_test("ft_strsub", 0, 0, "")
		|| ft_test("ft_strsub", 0, 1, "f")
		|| ft_test("ft_strsub", 1, 0, "")
		|| ft_test("ft_strsub", 1, 1, "t")
		|| ft_test("ft_strsub", 0, 9, "ft_strsub")
		|| ft_test("ft\0strsub", 0, 2, "ft"))
	{
		printf("KO: ft_strsub\n");
		return (1);
	}
	printf("OK: ft_strsub\n");
	return (0);
}
