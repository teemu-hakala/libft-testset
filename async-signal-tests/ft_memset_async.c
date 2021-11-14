/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_async.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:17:31 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 16:06:03 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#define _LIBC_MSG " libc"
#define LIBFT_MSG "libft"

char	*g_message;
int		g_std_segfault;
jmp_buf	g_buffer;
int		g_print;

static int	ft_segfault(void *ptr, int byte, size_t count, size_t dbg)
{
	int		jmp_result;
	int		truth;

	jmp_result = setjmp(g_buffer);
	truth = 1;
	if (g_print)
		printf("   memset: jump%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, _LIBC_MSG);
		memset(ptr, byte, count);
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	if (g_print)
		printf("ft_memset: jump%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, LIBFT_MSG);
		ft_memset(ptr, byte, count);
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	printf("\n");
	return (truth);
}

int	ft_segfault_memset(void)
{
	size_t	id;

	id = 0;
	return (!ft_segfault(NULL, 1000, 0, id++)
		|| !ft_segfault(NULL, 1000, 1, id++));
}
