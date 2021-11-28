/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:02:39 by thakala           #+#    #+#             */
/*   Updated: 2021/11/28 14:34:31 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *base, const char *delim)
{
	char	*std_string;
	char	*ft_string;
	char	*beginning_std;
	char	*beginning_ft;

	std_string = strdup(base);
	ft_string = strdup(std_string);
	beginning_std = std_string;
	beginning_ft = ft_string;
	while (1)
	{
		if (strcmp(strsep(&std_string, delim), ft_strsep(&ft_string, delim)))
		{
			free(beginning_std);
			free(beginning_ft);
			return (1);
		}
	}
	free(beginning_std);
	free(beginning_ft);
	return (0);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("", "a")
		|| ft_test("", "")
		|| ft_test("M'envoler vers toi", " ")
		|| ft_test("I STOP love STOP you STOP", " STOP"))
	{
		printf("KO: ft_strsep\n");
		return (1);
	}
	printf("OK: ft_strsep\n");
	return (0);
}
