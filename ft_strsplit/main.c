/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:09:08 by thakala           #+#    #+#             */
/*   Updated: 2021/11/30 19:14:58 by thakala          ###   ########.fr       */
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

static size_t	arrlen(char **arr)
{
	size_t	len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

static int	ft_test(const char *str, const char chr, char **ref)
{
	char	**splits;
	size_t	i;
	size_t	count;

	count = arrlen(ref);
	splits = ft_strsplit(str, chr);
	if (!splits)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	i = 0;
	while (splits[i] && ref[i])
	{
		if (strcmp(splits[i], ref[i]))
		{
			free_all(splits, count);
			return (1);
		}
		i++;
	}
	if (splits[i] && splits[i] != ref[i])
	{
		free_all(splits, count);
		return (1);
	}
	else if (splits[0])
		free_all(splits, count);
	else
		free(splits);
	return (0);
}

static int	ft_test_either(const char *str, const char chr, char **ref1,
	char **ref2)
{
	return (!(!ft_test(str, chr, ref1)
			|| !ft_test(str, chr, ref2)));
}

int	main(void)
{
	if (ft_test_either("", '*',
			(char *[]){"", NULL}, (char *[]){NULL})
		|| ft_test_either("******", '*',
			(char *[]){"", NULL}, (char *[]){NULL})
		|| ft_test("***a***", '*',
			(char *[]){"a", NULL})
		|| ft_test("*hello*fellow***students*", '*',
			(char *[]){"hello", "fellow", "students", NULL})
		|| ft_test("hi*", '*',
			(char *[]){"hi", NULL})
		|| ft_test("*hi", '*',
			(char *[]){"hi", NULL}))
	{
		printf("KO: ft_strsplit\n");
		return (1);
	}
	printf("OK: ft_strsplit\n");
	return (0);
}
