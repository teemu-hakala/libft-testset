/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:39:27 by thakala           #+#    #+#             */
/*   Updated: 2021/11/13 16:46:37 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	ft_display_mem(void *dst, size_t l)
{
	unsigned char	*char_dst;
	size_t			i;

	char_dst = (unsigned char *)dst;
	i = 0;
	while (i < l)
		printf("%c", char_dst[i++]);
	printf("\n");
}

static void	ft_debug_print(char *std_dst, char *ft_dst, size_t len)
{
	printf("std_dst: ");
	ft_display_mem(std_dst, len);
	printf("\n ft_dst: ");
	ft_display_mem(ft_dst, len);
	printf("\n");
}

static int	ft_compare(char *std_dst, char *ft_dst, const char *src, size_t len)
{
	size_t	std_result;
	size_t	ft_result;

	std_result = strlcat(std_dst, src, len);
	ft_result = ft_strlcat(ft_dst, src, len);
	return (std_result != ft_result);
}

static int	ft_test(const char *dst_init, const char *src, size_t length)
{
	char	*std_dst;
	char	*ft_dst;
	size_t	len;
	int		result;

	len = strlen(dst_init) + length;
	std_dst = (char *)malloc(sizeof(char) * len);
	memset(std_dst, 1, len);
	strcpy(std_dst, dst_init);
	ft_dst = (char *)malloc(sizeof(char) * len);
	ft_dst = (char *)memcpy(ft_dst, std_dst, len);
	if (ft_compare(std_dst, ft_dst, src, length))
		return (1);
	result = memcmp(std_dst, ft_dst, len);
	if (result)
	{
		ft_debug_print(std_dst, ft_dst, len);
		free(std_dst);
		free(ft_dst);
		return (1);
	}
	free(std_dst);
	free(ft_dst);
	return (0);
}

static int	ft_test_range(const char *dst_init, const char *src, size_t range)
{
	size_t	i;

	i = 0;
	while (i <= range)
	{
		if (ft_test(dst_init, src, i))
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	if (ft_test("", "", 0)
		|| ft_test_range("Source", "concatenation", 20)
		|| ft_test_range("longer than dstsize", "source", 35))
	{
		printf("KO: ft_strlcat\n");
		return (1);
	}
	printf("OK: ft_strlcat\n");
	return (0);
}
