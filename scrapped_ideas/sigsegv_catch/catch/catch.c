/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:48:10 by thakala           #+#    #+#             */
/*   Updated: 2021/11/11 15:56:57 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)arg;
	printf("Caught segfault at address %p\n", si->si_addr);
	//exit(0);
}

int	main(void)
{
	int					*foo;
	struct sigaction	sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = segfault_sigaction;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sa, NULL);
	foo = NULL;
	*foo = 1;
	printf("Recovered execution\n");
	return (0);
}
