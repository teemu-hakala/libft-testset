/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:09:08 by thakala           #+#    #+#             */
/*   Updated: 2021/11/19 14:51:18 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static void	free_all(char **memory, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(memory[i++]);
	free(memory);
}

static int	ft_test(const char *str, const char chr, char **ref,
	size_t count)
{
	char	**splits;
	size_t	i;

	splits = ft_strsplit(str, chr);
	i = 0;
	while (i < count)
	{
		if (strcmp(splits[i], ref[i]))
		{
			free_all(splits, count);
			return (1);
		}
		i++;
	}
	if (splits[i] != ref[i])
	{
		free_all(splits, count);
		return (1);
	}
	free_all(splits, count);
	return (0);
}

int	main(void)
{
	if (ft_test("", '*',
			(char *[]){"", NULL}, 1)
		|| ft_test("******", '*',
			(char *[]){"", NULL}, 1)
		|| ft_test("***a***", '*',
			(char *[]){"a", NULL}, 1)
		|| ft_test("*hello*fellow***students*", '*',
			(char *[]){"hello", "fellow", "students", NULL}, 3))
	{
		printf("KO: ft_strsplit\n");
		return (1);
	}
	printf("OK: ft_strsplit\n");
	return (0);
}
