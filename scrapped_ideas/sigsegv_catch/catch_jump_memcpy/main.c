/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:47:00 by thakala           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:28 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf	g_buffer;
int		g_std_segfault;
char	*g_message;

void	*ft_memcpy(void *dst, const void *src, size_t n);

static void	*memdup(const void *mem, size_t size)
{
	void	*out;

	out = malloc(size);
	if (out)
		memcpy(out, mem, size);
	return (out);
}

static int	ft_display_cmp(char *std_res, char *ft_res, size_t remaining)
{
	size_t	i;

	if (0)
	{
		i = 0;
		while (i < remaining)
			printf("%c", (std_res[i++]));
		i = 0;
		printf("\n");
		while (i < remaining)
			printf("%c", (ft_res[i++]));
		printf("\n");
	}
	return (memcmp(std_res, ft_res, remaining));
}

static int	ft_compare(char *src, char *std_dst, char *ft_dst)
{
	size_t	len;
	char	*std_res;
	char	*ft_res;

	len = (size_t)strlen(src);
	std_res = (char *)memcpy(std_dst, src, len);
	ft_res = (char *)ft_memcpy(ft_dst, src, len);
	if (!std_res && !ft_res)
		return (0);
	return (ft_display_cmp(std_res, ft_res, len));
}

static int	ft_test(char *str)
{
	char	*std_dst;
	char	*ft_dst;
	size_t	length;
	int		result;

	length = strlen(str);
	std_dst = (char *)malloc(sizeof(char) * length);
	ft_dst = (char *)memdup(std_dst, length);
	result = ft_compare(str, std_dst, ft_dst);
	free(std_dst);
	free(ft_dst);
	return (result);
}

static int	ft_segfault(void *dst, void *src, size_t len, size_t n)
{
	int		jmp_result;
	int		truth;

	jmp_result = setjmp(g_buffer);
	truth = 1;
	printf("jump%zu: %d\n", n, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, " libc");
		memcpy(dst, src, len);
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	printf("jump%zu: %d\n", n, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, "libft");
		ft_memcpy(dst, src, len);
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	return (truth);
}

static int	ft_segfault_dst(char *dst, void *src, size_t len, size_t n)
{
	int		jmp_result;
	char	*std_dst;
	char	*ft_dst;
	int		truth;

	std_dst = strdup(dst);
	ft_dst = strdup(dst);
	jmp_result = setjmp(g_buffer);
	truth = 1;
	printf("jump_std%zu: %d\n", n, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, " libc");
		memcpy(std_dst, src, len);
		printf(" libc: no segmentation fault\n");
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	printf("jump__ft%zu: %d\n", n, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, "libft");
		ft_memcpy(ft_dst, src, len);
		printf("libft: no segmentation fault\n");
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	free(std_dst);
	free(ft_dst);
	return (truth);
}

static int	ft_segfault_same(char *dstsrc, size_t len, size_t n)
{
	int		jmp_result;
	char	*destinationsource;
	int		truth;

	destinationsource = (char *)malloc(sizeof(char) * len);
	strcpy(destinationsource, dstsrc);
	jmp_result = setjmp(g_buffer);
	truth = 1;
	printf("jump_std%zu: %d\n", n, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, " libc");
		memcpy(destinationsource, destinationsource, len);
		printf(" libc: no segmentation fault\n");
		g_std_segfault = 0;
	}
	jmp_result = setjmp(g_buffer);
	printf("jump__ft%zu: %d\n", n, jmp_result);
	if (!jmp_result)
	{
		strcpy(g_message, "libft");
		ft_memcpy(destinationsource, destinationsource, len);
		printf("libft: no segmentation fault\n");
		truth = !g_std_segfault;
		g_std_segfault = 0;
	}
	free(destinationsource);
	return (truth);
}

static void	segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
	(void)signal;
	(void)arg;
	printf("Caught segfault at address %p\n", si->si_addr);
	printf("SIGSEGV: %s\n", g_message);
	g_std_segfault = 1;
	//g_test = !g_test;
	longjmp(g_buffer, 19);
}

int	main(void)
{
	struct sigaction	sa;
	size_t				id;

	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = segfault_sigaction;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sa, NULL);
	g_std_segfault = 0;
	g_message = strdup(" libc");
	if (ft_test("abcdefBghijklmnopq")
		|| ft_test("abcde\x1\fBghi\0jklmnopq"))
	{
		printf("KO: ft_memcpy");
		return (1);
	}
	id = 0;
	printf("truth: %d\n", ft_segfault(NULL, NULL, 0, id++));
	printf("truth: %d\n", ft_segfault(NULL, NULL, 10, id++));
	printf("truth: %d\n", ft_segfault(NULL, "src", 0, id++));
	printf("truth: %d\n", ft_segfault(NULL, "src", 3, id++));
	printf("truth: %d\n", ft_segfault_dst("dst", NULL, 0, id++));
	printf("truth: %d\n", ft_segfault_dst("dst", NULL, 3, id++));
	printf("truth: %d\n", ft_segfault(NULL, "src", (size_t)-1, id++));
	printf("truth: %d\n", ft_segfault_same("dst", 3, id++));
	printf("truth: %d\n", ft_segfault(NULL, NULL, 10, id++));
	printf("truth: %d\n", ft_segfault(NULL, NULL, 10, id++));
	printf("truth: %d\n", ft_segfault(NULL, NULL, 10, id++));
	printf("OK: ft_memcpy");
	free(g_message);
}
