/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:50:45 by thakala           #+#    #+#             */
/*   Updated: 2021/12/22 18:09:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2, int expected)
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
	result = ft_strequ(heap_s1, heap_s2) == expected;
	free(heap_s1);
	free(heap_s2);
	return (result);
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
