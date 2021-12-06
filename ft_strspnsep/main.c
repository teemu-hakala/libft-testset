/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:02:39 by thakala           #+#    #+#             */
/*   Updated: 2021/12/06 13:21:34 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *base, const char *delim,
	char **token_ref)
{
	char	*ft_string;
	char	*beginning_ft;
	char	*token_ft;

	ft_string = strdup(base);
	if (!ft_string)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	beginning_ft = ft_string;
	while (1)
	{
		token_ft = ft_strspnsep(&ft_string, delim);
		if (!*token_ref && !token_ft)
			break ;
		if (strcmp(*token_ref++, token_ft))
		{
			free(beginning_ft);
			return (1);
		}
	}
	if (*token_ref != token_ft)
	{
		free(beginning_ft);
		return (1);
	}
	free(beginning_ft);
	return (0);
}

int	main(void)
{
	if (ft_test("", "",
			(char *[]){"", NULL})
		|| ft_test("", "a",
			(char *[]){"", NULL})
		|| ft_test("", "",
			(char *[]){"", NULL})
		|| ft_test("M'envoler vers toi", " ",
			(char *[]){"M'envoler", "vers", "toi", NULL})
		|| ft_test("I love you!", "!",
			(char *[]){"I love you", NULL})
		|| ft_test("I STOP love STOP you STOP", " STOP",
			(char *[]){"I", "love", "you", NULL}))
	{
		printf("KO: ft_strspnsep\n");
		return (1);
	}
	printf("OK: ft_strspnsep\n");
	return (0);
}
