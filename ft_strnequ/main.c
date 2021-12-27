/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:00:57 by thakala           #+#    #+#             */
/*   Updated: 2021/12/27 22:27:49 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2, size_t n, int expected)
{
	char	*heap_s1;
	char	*heap_s2;
	int		result;

	heap_s1 = (char *)malloc(sizeof(char) * (strlen(s1) + 1));
	heap_s2 = (char *)malloc(sizeof(char) * (strlen(s2) + 1));
	if (!heap_s1 || !heap_s2)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	ft_strcpy(heap_s1, s1);
	ft_strcpy(heap_s2, s2);
	result = ft_strnequ(s1, s2, n) == expected;
	free(heap_s1);
	free(heap_s2);
	return (result);
}

static int	ft_test_loop(const char *s1, const char *s2, size_t upto)
{
	char	*heap_s1;
	char	*heap_s2;
	int		result;

	heap_s1 = (char *)malloc(sizeof(char) * (strlen(s1) + 1));
	heap_s2 = (char *)malloc(sizeof(char) * (strlen(s2) + 1));
	if (!heap_s1 || !heap_s2)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	ft_strcpy(heap_s1, s1);
	ft_strcpy(heap_s2, s2);
	result = 1;
	upto += 2;
	while (--upto)
	{
		if (ft_strnequ(s1, s2, upto - 1) == !!strncmp(s1, s2, upto - 1))
		{
			result = 0;
			break ;
		}
	}
	free(heap_s1);
	free(heap_s2);
	return (result);
}

int	main(void)
{
	if (!ft_test("", "", 0, 1)
		|| !ft_test("a", "b", 0, 1)
		|| !ft_test("", "", 1, 1)
		|| !ft_test_loop("equal", "equal", 6)
		|| !ft_test_loop("Not equal", "not equal", 10)
		|| !ft_test_loop("not equal\0", "not equal\1", 11))
	{
		printf("KO: ft_strnequ\n");
		return (1);
	}
	printf("OK: ft_strnequ\n");
	return (0);
}
