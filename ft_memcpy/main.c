/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:47:00 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:27:42 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int	main(void)
{
	if (ft_test("abcdefBghijklmnopq")
		|| ft_test("abcde\x1\fBghi\0jklmnopq"))
	{
		printf("KO: ft_memcpy");
		return (1);
	}
	printf("OK: ft_memcpy");
}
