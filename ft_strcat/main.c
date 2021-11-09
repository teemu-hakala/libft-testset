/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:39:48 by thakala           #+#    #+#             */
/*   Updated: 2021/11/06 14:59:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <stdlib.h>

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
		ft_putstr_test("Memory allocation error!");
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
		ft_putstr_test("KO: ft_strcat");
		return (1);
	}
	ft_strcat(NULL, NULL);
	ft_putstr_test("OK: ft_strcat");
}
