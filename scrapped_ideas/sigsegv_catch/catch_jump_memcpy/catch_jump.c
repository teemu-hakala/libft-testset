/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_jump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:48:10 by thakala           #+#    #+#             */
/*   Updated: 2021/11/11 17:38:14 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

jmp_buf	g_buffer;

void	segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)arg;
	printf("Caught segfault at address %p\n", si->si_addr);
	longjmp(g_buffer, 10000);
	//exit(0);
}

int	main(void)
{
	int					*foo;
	struct sigaction	sa;
	int					jmp_result;

	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = segfault_sigaction;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sa, NULL);
	foo = NULL;
	jmp_result = setjmp(g_buffer);
	printf("jmp_result %d\n", jmp_result);
	if (jmp_result == 0)
		*foo = 1;
	jmp_result = setjmp(g_buffer);
	printf("Recovered execution\n");
	return (0);
}
