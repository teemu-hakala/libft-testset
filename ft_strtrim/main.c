/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:37:08 by thakala           #+#    #+#             */
/*   Updated: 2021/11/18 10:07:00 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *input, const char *reference)
{
	char	*trimmed_str;
	int		result;

	trimmed_str = ft_strtrim(input);
	if (!trimmed_str)
	{
		printf("Memory allocation error.\n");
		exit(42);
	}
	result = strcmp(reference, trimmed_str);
	free(trimmed_str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test(" ", "")
		|| ft_test(" \t\n\t ", "")
		|| ft_test("\tbest\n", "best")
		|| ft_test("O \t\n K", "O \t\n K")
		|| ft_test("continue", "continue")
		|| ft_test("break ;", "break ;")
		|| ft_test(" One Night in Tokyo\t", "One Night in Tokyo"))
	{
		printf("KO: ft_strtrim\n");
		return (1);
	}
	printf("OK: ft_strtrim\n");
	return (0);
}
