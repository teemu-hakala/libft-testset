/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:05:12 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 16:47:43 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "ft_segfaults.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <setjmp.h>

static void	sigsegv_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)si;
	(void)arg;
	if (g_print)
		printf("SIGSEGV: %s\n", g_message);
	g_std_segfault = 1;
	longjmp(g_buffer, 19);
}

static void	sigabrt_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)si;
	(void)arg;
	if (g_print)
		printf("SIGABRT: %s\n", g_message);
	g_std_segfault = 1;
	longjmp(g_buffer, 361);
}

static void	ft_initialize_segv_test(struct sigaction *sa)
{
	memset(sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa->sa_mask);
	sa->sa_sigaction = sigsegv_sigaction;
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, sa, NULL);
	g_std_segfault = 0;
	g_print = 1;
	g_message = strdup(_LIBC_MSG);
}

static void	ft_initialize_abrt_test(struct sigaction *sa)
{
	memset(sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa->sa_mask);
	sa->sa_sigaction = sigabrt_sigaction;
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGABRT, sa, NULL);
}

/*
** gcc *.c -L../../libft -lft
*/

int	main(void)
{
	struct sigaction	sa_segv;
	struct sigaction	sa_abrt;
	size_t				id;

	id = 0;
	ft_initialize_segv_test(&sa_segv);
	ft_initialize_abrt_test(&sa_abrt);
	if (ft_segfault_memset()
		|| ft_segfault_bzero()
		|| ft_sigabrt_memdel())
	{
		printf("KO: SEGV diff\n");
		free(g_message);
		return (1);
	}
	printf("OK: SEGV diff\n");
	free(g_message);
	return (0);
}
