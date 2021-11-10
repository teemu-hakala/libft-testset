/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:03:40 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 15:14:07 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

static int	ft_test(const char *haystack, const char *needle)
{
	char	*std_result;
	char	*ft_result;

	std_result = strstr(haystack, needle);
	ft_result = ft_strstr(haystack, needle);
	return (std_result == ft_result);
}

int	main(void)
{
	if (!ft_test("", "")
		|| !ft_test("Haystack", "Needle")
		|| !ft_test("Haystack", "Haystack")
		|| !ft_test("NeedleNeedle", "NeedleNeedle")
		|| !ft_test("Haystack", "")
		|| !ft_test("", "Needle")
		|| !ft_test("qwertyuiopasdfghjkl", "iopa"))
	{
		printf("KO: ft_strstr\n");
		return (1);
	}
	printf("OK: ft_strstr\n");
}
