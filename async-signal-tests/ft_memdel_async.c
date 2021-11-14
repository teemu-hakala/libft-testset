/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_async.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:24:18 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 17:07:06 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "ft_segfaults.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>

static void	ft_putstr_len(char *string, size_t length)
{
	size_t	i;

	i = 0;
	while (i++ < length)
		printf("%c", *string++);
	printf("\n");
}

static int	ft_sigabrt(const char *s, size_t dbg)
{
	char	*string;
	char	*string_copy;
	size_t	length;
	int		jmp_result;
	int		truth;

	truth = 1;
	strcpy(g_message, LIBFT_MSG);
	string = strdup(s);
	if (!string)
	{
		printf("Memory allocation error.\n");
		exit(42);
	}
	length = strlen(string);
	string_copy = string;
	ft_memdel((void **)&string);
	jmp_result = setjmp(g_buffer);
	if (g_print)
		printf("ft_memdel: test%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		free(string_copy);
		truth = 0;
	}
	return (truth);
}

int	ft_sigabrt_memdel(void)
{
	size_t	id;

	id = 0;
	return (!ft_sigabrt("", id++)
		|| !ft_sigabrt("Ten chars", id++));
}
