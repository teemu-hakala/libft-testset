/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:39:48 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 12:59:50 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(char *s1, const char *s2)
{
	char	*std_catted_str;
	char	*ft_catted_str;
	size_t	catted_len;

	catted_len = strlen(s1) + strlen(s2) + 1;
	std_catted_str = (char *)malloc(sizeof(char) * catted_len);
	ft_catted_str = (char *)malloc(sizeof(char) * catted_len);
	if (!std_catted_str || !ft_catted_str)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	strcpy(std_catted_str, s1);
	memcpy(ft_catted_str, std_catted_str, catted_len);
	return (strcmp(strcat(std_catted_str, s2), ft_strcat(ft_catted_str, s2)));
}

int	main(void)
{
	if (ft_test("ft_", "strcat")
		|| ft_test("man", " strcat")
		|| ft_test("", "")
		|| ft_test("\0", "\1"))
	{
		printf("KO: ft_strcat\n");
		return (1);
	}
	printf("OK: ft_strcat\n");
}
