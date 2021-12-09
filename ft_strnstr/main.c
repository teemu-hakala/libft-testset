/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:57:16 by thakala           #+#    #+#             */
/*   Updated: 2021/12/09 18:58:30 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_heap;
	char	*needle_heap;
	char	*std_result;
	char	*ft_result;

	haystack_heap = (char *)malloc(sizeof(char) * (strlen(haystack) + 1));
	needle_heap = (char *)malloc(sizeof(char) * (strlen(needle) + 1));
	std_result = strnstr(haystack_heap, needle_heap, len);
	ft_result = ft_strnstr(haystack_heap, needle_heap, len);
	free(haystack_heap);
	free(needle_heap);
	return (std_result == ft_result);
}

int	main(void)
{
	if (!ft_test("", "", 0)
		|| !ft_test("", "", 10)
		|| !ft_test("Haystack", "Needle", 1)
		|| !ft_test("Haystack", "Haystack", 100)
		|| !ft_test("NeedleNeedle", "NeedleNeedle", 7)
		|| !ft_test("Haystack", "", 9)
		|| !ft_test("", "Needle", 5)
		|| !ft_test("qwertyuiopasdfghjkl", "iopa", 9)
		|| !ft_test("qwertyuiopasdfghjkl", "iopa", 11)
		|| !ft_test("qwertyuiopasdfghjkl", "iopa", 19))
	{
		printf("KO: ft_strnstr\n");
		return (1);
	}
	printf("OK: ft_strnstr\n");
}
