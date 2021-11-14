/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_async.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:00:18 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 17:08:29 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "ft_segfaults.h"
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <stdlib.h>

static int	ft_segfault(void *ptr, size_t count, size_t dbg)
{
	int		jmp_result;
	int		truth;

	jmp_result = setjmp(g_buffer);
	truth = 1;
	if (g_print)
		printf("   bzero: test%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, _LIBC_MSG);
		bzero(ptr, count);
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	if (g_print)
		printf("ft_bzero: test%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, LIBFT_MSG);
		ft_bzero(ptr, count);
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	free(ptr);
	printf("\n");
	return (truth);
}

int	ft_segfault_bzero(void)
{
	size_t	id;
	int		result;
	char	*str3;
	char	*str4;
	char	*str5;

	id = 0;
	str3 = strdup("Memory issues 0.\n");
	str4 = strdup("Memory issues 1.\n");
	str5 = strdup("Memory issues 21.\n");
	if (!str3 || !str4 || !str5)
	{
		printf("Memory allocation error.\n");
		exit(42);
	}
	result = !ft_segfault(NULL, 0, id++)
		|| !ft_segfault(NULL, 1, id++)
		|| !ft_segfault(NULL, 211, id++)
		|| !ft_segfault(str3, 0, id++)
		|| !ft_segfault(str4, 1, id++)
		|| !ft_segfault(str5, 19, id++);
	return (result);
}
