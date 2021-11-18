/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:27:12 by thakala           #+#    #+#             */
/*   Updated: 2021/11/18 17:30:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *src, size_t n)
{
	char	*std_str;
	char	*ft_str;
	int		result;

	std_str = (char *)calloc(n, sizeof(char));
	ft_str = (char *)calloc(n, sizeof(char));
	if (!std_str || !ft_str)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	std_str = strncpy(std_str, src, n);
	ft_str = ft_strncpy(ft_str, src, n);
	result = memcmp(std_str, ft_str, n);
	free(std_str);
	free(ft_str);
	return (result);
}

int	main(void)
{
	if (ft_test("man strncpy", 3)
		|| ft_test("man malloc", 20)
		|| ft_test("", 1))
	{
		printf("KO: ft_strncpy\n");
		return (1);
	}
	printf("OK: ft_strncpy\n");
}
