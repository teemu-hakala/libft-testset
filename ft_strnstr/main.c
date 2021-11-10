/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:57:16 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 16:00:13 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

static int	ft_test(const char *haystack, const char *needle, size_t len)
{
	char	*std_result;
	char	*ft_result;

	std_result = strnstr(haystack, needle, len);
	ft_result = ft_strnstr(haystack, needle, len);
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
