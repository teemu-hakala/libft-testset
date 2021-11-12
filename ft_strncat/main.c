/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:02:00 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 13:00:10 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(char *s1, const char *s2, size_t n)
{
	char	*std_catted_str;
	char	*ft_catted_str;
	size_t	catted_len;

	catted_len = strlen(s1) + n + 1;
	std_catted_str = (char *)malloc(sizeof(char) * catted_len);
	ft_catted_str = (char *)malloc(sizeof(char) * catted_len);
	if (!std_catted_str || !ft_catted_str)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	strcpy(std_catted_str, s1);
	memcpy(ft_catted_str, std_catted_str, catted_len);
	return (strcmp(strncat(std_catted_str, s2, n),
			ft_strncat(ft_catted_str, s2, n)));
}

int	main(void)
{
	if (ft_test("ft_", "strncat", 4)
		|| ft_test("", "", 0))
	{
		printf("KO: ft_strncat\n");
		return (1);
	}
	printf("OK: ft_strncat\n");
}
