/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:08:03 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 12:59:03 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *src)
{
	char	*std_str;
	char	*ft_str;
	size_t	len;
	int		result;

	len = strlen(src) + 1;
	std_str = (char *)malloc(sizeof(char) * len);
	ft_str = (char *)malloc(sizeof(char) * len);
	if (!std_str || !ft_str)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	std_str = strcpy(std_str, src);
	ft_str = ft_strcpy(ft_str, src);
	result = memcmp(std_str, ft_str, len);
	free(std_str);
	free(ft_str);
	return (result);
}

int	main(void)
{
	if (ft_test("man strcpy")
		|| ft_test(""))
	{
		printf("KO: ft_strcpy\n");
		return (1);
	}
	printf("OK: ft_strcpy\n");
}
