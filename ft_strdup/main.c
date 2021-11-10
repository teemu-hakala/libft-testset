/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:49:11 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:36:38 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *string)
{
	char	*std_str;
	char	*ft_str;
	int		result;

	std_str = strdup(string);
	ft_str = ft_strdup(string);
	result = strcmp(std_str, ft_str);
	free(std_str);
	free(ft_str);
	return (result);
}

int	main(void)
{
	if (ft_test("Unbreakable")
		|| ft_test(""))
	{
		printf("KO: ft_strdup");
		return (1);
	}
	printf("OK: ft_strdup");
}
