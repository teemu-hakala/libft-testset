/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:02:39 by thakala           #+#    #+#             */
/*   Updated: 2021/11/28 16:01:09 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *base, const char *delim)
{
	char	*std_string;
	char	*ft_string;
	char	*beginning_std;
	char	*beginning_ft;
	char	*token_std;
	char	*token_ft;

	std_string = strdup(base);
	if (!std_string)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	ft_string = strdup(std_string);
	if (!ft_string)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	beginning_std = std_string;
	beginning_ft = ft_string;
	while (1)
	{
		token_std = strsep(&std_string, delim);
		token_ft = ft_strsep(&ft_string, delim);
		if (!token_std && !token_ft)
			break ;
		if (strcmp(token_std, token_ft))
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
		|| ft_test("I love you!", "!")
		|| ft_test("I STOP love STOP you STOP", " STOP"))
	{
		printf("KO: ft_strsep\n");
		return (1);
	}
	printf("OK: ft_strsep\n");
	return (0);
}
