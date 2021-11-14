/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:23:09 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 16:24:04 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_putstr_len(char *string, size_t length)
{
	size_t	i;

	i = 0;
	while (i++ < length)
		printf("%c", *string++);
	printf("\n");
}

static int	ft_test(char *s)
{
	char	*string;
	char	*string_copy;
	size_t	length;

	string = strdup(s);
	length = strlen(string);
	string_copy = string;
	if (0)
		ft_putstr_len(string, length);
	ft_memdel((void **)&string);
	if (0)
		ft_putstr_len(string_copy, length);
	if (!string)
		return (1);
	return (0);
}

int	main(void)
{
	if (ft_test("Test string."))
	{
		printf("OK: ft_memdel\n");
		return (1);
	}
	printf("KO: ft_memdel\n");
	return (0);
}
