/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:19:28 by thakala           #+#    #+#             */
/*   Updated: 2021/11/13 18:52:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#define _LIBC_MSG " libc"
#define LIBFT_MSG "libft"

jmp_buf	g_buffer;
int		g_std_segfault;
char	*g_message;
int		g_print;

static void	*memdup(const void *mem, size_t size)
{
	void	*out;

	out = malloc(size);
	if (out)
		memcpy(out, mem, size);
	return (out);
}

static int	ft_test(char *s, int c, size_t len)
{
	char	*std_array;
	char	*ft_array;
	int		result;

	std_array = (char *)memdup(s, len);
	ft_array = (char *)memdup(std_array, len);
	memset(std_array, c, len);
	ft_memset(ft_array, c, len);
	result = memcmp(std_array, ft_array, len);
	free(std_array);
	free(ft_array);
	return (result);
}

static int	ft_segfault(void *area, int byte, size_t len, size_t dbg)
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
		memset(area, byte, len);
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	if (g_print)
		printf("jump%zu: %d\n", dbg, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, LIBFT_MSG);
		ft_memset(area, byte, len);
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	return (truth);
}

static void	segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)arg;
	(void)si;
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

	ft_initialize_segv_test(&sa);
	id = 0;
	if (ft_test("", 1, 1)
		|| ft_test("Never Give up on Your Dreams\n", -1, 4)
		|| ft_test("\0\r\t", -1, 4))
	{
		printf("KO: ft_memset\n");
		return (1);
	}
	else if (!ft_segfault(NULL, 0, 0, id++)
		|| !ft_segfault(NULL, 0, 1, id++)
		|| !ft_segfault(NULL, -1, 0, id++)
		|| !ft_segfault(NULL, -1, 1, id++))
	{
		printf("KO: ft_memset: SIGSEGV diff %zu\n", id);
		return (1);
	}
	printf("OK: ft_memset\n");
}
