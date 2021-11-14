/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:05:12 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 16:13:52 by thakala          ###   ########.fr       */
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
#define _LIBC_MSG " libc"
#define LIBFT_MSG "libft"

char	*g_message;
int		g_std_segfault;
jmp_buf	g_buffer;
int		g_print;

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
	g_print = 1;
	g_message = strdup(_LIBC_MSG);
}

/*
** gcc *.c -L../../libft -lft
*/

int	main(void)
{
	struct sigaction	sa_segv;
	size_t				id;

	id = 0;
	ft_initialize_segv_test(&sa_segv);
	if (ft_segfault_memset()
		|| ft_segfault_bzero())
	{
		printf("KO: SEGV diff\n");
		free(g_message);
		return (1);
	}
	printf("OK: SEGV diff\n");
	free(g_message);
	return (0);
}
