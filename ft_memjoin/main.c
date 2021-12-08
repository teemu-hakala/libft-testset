/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:43:48 by thakala           #+#    #+#             */
/*   Updated: 2021/12/08 21:06:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *s1, const char *s2, const char *reference)
{
	char	*joined_str;
	int		result;

	joined_str = (char *)ft_memjoin(s1, s2);
	if (!joined_str)
	{
		printf("Memory allocation error\n");
		exit(42);
	}
	result = strcmp(joined_str, reference);
	free(joined_str);
	return (result);
}

static int	ft_test_nested(const char *s1, const char *s2, const char *s3,
	const char *reference)
{
	char	*joined_str;
	char	*nested_str;
	int		result;

	joined_str = (char *)ft_memjoin(s1, s2);
	if (!joined_str)
	{
		printf("Memory allocation error\n");
		return (1);
	}
	nested_str = (char *)ft_memjoin(joined_str, s3);
	if (!nested_str)
	{
		printf("Memory allocation error\n");
		return (1);
	}
	result = strcmp(nested_str, reference);
	free(joined_str);
	free(nested_str);
	return (result);
}

static int	ft_test_memory(const void *mem1, const void *mem2,
	size_t len1, size_t len2, const void *reference)
{
	void	*joined_mem;
	int		result;

	joined_mem = ft_memjoin(mem1, mem2, len1, len2);
	if (!joined_mem)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	result = memcmp(joined_mem, reference, len1 + len2);
	free(joined_mem);
	return (result);
}

int	main(void)
{
	if (ft_test("", "", "")
		|| ft_test("ft_", "", "ft_")
		|| ft_test("", "strjoin", "strjoin")
		|| ft_test("ft_", "strjoin", "ft_strjoin")
		|| ft_test_nested("OK: ", "ft_", "strjoin", "OK: ft_strjoin")
		|| ft_test_array((int []){-2147483648, -100000, -2, -1, 0}, \
			(int []){1, 2, 100000, 2147483647}, sizeof(int) * 5, \
			sizeof(int) * 4, (int []){-2147483648, -100000, -2, -1, 0, \
			1, 2, 100000, 2147483647}))
	{
		printf("KO: ft_strjoin\n");
		return (1);
	}
	printf("OK: ft_strjoin\n");
	return (0);
}
