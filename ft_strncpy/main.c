/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:27:12 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:38:04 by thakala          ###   ########.fr       */
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

	std_str = (char *)malloc(sizeof(char) * n);
	ft_str = (char *)malloc(sizeof(char) * n);
	if (!std_str || !ft_str)
	{
		printf("Memory allocation error!");
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
		printf("KO: ft_strncpy");
		return (1);
	}
	ft_strncpy(NULL, NULL, 10);
	printf("OK: ft_strncpy");
}
