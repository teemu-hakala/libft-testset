/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:43:48 by thakala           #+#    #+#             */
/*   Updated: 2021/11/17 22:32:32 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *s1, const char *s2, const char *reference)
{
	char	*joined_str;
	int		result;

	joined_str = ft_strjoin(s1, s2);
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

	joined_str = ft_strjoin(s1, s2);
	if (!joined_str)
	{
		printf("Memory allocation error\n");
		exit(42);
	}
	nested_str = ft_strjoin(joined_str, s3);
	if (!nested_str)
	{
		printf("Memory allocation error\n");
		exit(42);
	}
	result = strcmp(nested_str, reference);
	free(joined_str);
	free(nested_str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "", "")
		|| ft_test("ft_", "", "ft_")
		|| ft_test("", "strjoin", "strjoin")
		|| ft_test("ft_", "strjoin", "ft_strjoin")
		|| ft_test_nested("OK: ", "ft_", "strjoin", "OK: ft_strjoin"))
	{
		printf("KO: ft_strjoin\n");
		return (1);
	}
	printf("OK: ft_strjoin\n");
	return (0);
}
