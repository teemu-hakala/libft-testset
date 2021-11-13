/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 04:48:33 by thakala           #+#    #+#             */
/*   Updated: 2021/11/13 18:57:35 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <setjmp.h>
#define _LIBC_MSG " libc"
#define LIBFT_MSG "libft"

char	*g_message;
int		g_std_segfault;
jmp_buf	g_buffer;
int		g_print;

static int	ft_test_int_array(int *std_array, size_t len)
{
	int		*ft_array;

	ft_array = (int *)malloc(sizeof(int) * len);
	memcpy(ft_array, std_array, len);
	ft_bzero(ft_array, len);
	bzero(std_array, len);
	if (memcmp(ft_array, std_array, len))
	{
		printf("KO: ft_bzero int array\n");
		free(ft_array);
		return (1);
	}
	free(ft_array);
	return (0);
}

static int	ft_test_str(char *std_s, size_t len)
{
	char	*ft_s;

	ft_s = (char *)malloc(sizeof(char) * len);
	strncpy(ft_s, std_s, len);
	ft_bzero(ft_s, len);
	bzero(std_s, len);
	if (memcmp(ft_s, std_s, len))
	{
		printf("KO: ft_bzero string\n");
		free(ft_s);
		free(std_s);
		return (1);
	}
	free(ft_s);
	free(std_s);
	return (0);
}

static int	ft_segfault(void *ptr, size_t count, size_t dbg)
{
	int		jmp_result;
	int		truth;

	jmp_result = setjmp(g_buffer);
	truth = 1;
	if (g_print)
		printf("jump%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, _LIBC_MSG);
		bzero(ptr, count);
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	if (g_print)
		printf("jump%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, LIBFT_MSG);
		ft_bzero(ptr, count);
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	return (truth);
}

static void	segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)si;
	(void)arg;
	if (g_print)
		printf("SIGSEGV: %s\n", g_message);
	g_std_segfault = 1;
	longjmp(g_buffer, 19);
}

static void	ft_initialize_segv_test(struct sigaction *sa)
{
	memset(sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa->sa_mask);
	sa->sa_sigaction = segfault_sigaction;
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, sa, NULL);
	g_std_segfault = 0;
	g_print = 0;
	g_message = strdup(_LIBC_MSG);
}

int	main(void)
{
	struct sigaction	sa;
	size_t				id;

	id = 0;
	ft_initialize_segv_test(&sa);
	if (ft_test_int_array((int []){1, 2, 3, 4, 5, 6, 7, 8}, sizeof(int) * 8)
		|| ft_test_str(strdup("Ten chars"), 10))
	{
		printf("KO: ft_bzero\n");
		return (1);
	}
	else if (!ft_segfault(NULL, (size_t)0, id++)
		|| !ft_segfault(NULL, (size_t)1, id++))
	{
		printf("KO: ft_bzero: SIGSEGV diff %zu\n", id);
		return (1);
	}
	printf("OK: ft_bzero\n");
	free(g_message);
	return (0);
}
