/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:35:30 by thakala           #+#    #+#             */
/*   Updated: 2021/11/29 23:29:07 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_test(const char *src, size_t dstsize)
{
	char	*std_dst;
	char	*ft_dst;
	size_t	l_dst;
	char	r_cmp;
	int		r_memcmp;

	l_dst = strlen(src) + 7;
	std_dst = (char *)malloc(sizeof(char) * l_dst);
	ft_dst = (char *)malloc(sizeof(char) * l_dst);
	memset(std_dst, 1, l_dst);
	memcpy(ft_dst, std_dst, l_dst);
	if (dstsize == (size_t)(-1))
		dstsize = l_dst - 3;
	r_cmp = strlcpy(std_dst + 3, src, dstsize) \
	== ft_strlcpy(ft_dst + 3, src, dstsize);
	r_memcmp = memcmp(std_dst, ft_dst, l_dst);
	free(std_dst);
	free(ft_dst);
	return (!(r_cmp && !r_memcmp));
}

static int	ft_test_nested(const char *src1, const char *src2)
{
	char	*std_dst;
	char	*ft_dst;
	size_t	l_dst;
	size_t	std_result;
	size_t	ft_result;
	char	r_cmp;
	int		r_memcmp;

	l_dst = strlen(src1) + strlen(src2) + 9;
	std_dst = (char *)malloc(sizeof(char) * l_dst);
	ft_dst = (char *)malloc(sizeof(char) * l_dst);
	memset(std_dst, 1, l_dst);
	memcpy(ft_dst, std_dst, l_dst);
	std_result = strlcpy(std_dst + 4, src1, l_dst - 4);
	ft_result = ft_strlcpy(ft_dst + 4, src1, l_dst - 4);
	r_cmp = std_result == ft_result;
	std_result = strlcpy(std_dst + 4 + std_result, src2, \
	l_dst - 4 - std_result);
	ft_result = ft_strlcpy(ft_dst + 4 + ft_result, src2, \
	l_dst - 4 - ft_result);
	r_cmp += std_result == ft_result;
	r_memcmp = memcmp(std_dst, ft_dst, l_dst);
	free(std_dst);
	free(ft_dst);
	return (!(r_cmp == 2 && !r_memcmp));
}

static int	ft_test_loop(const char *src)
{
	size_t	dstsize;
	int		result;

	dstsize = strlen(src) + 1;
	while (dstsize--)
	{
		result = ft_test(src, dstsize);
		if (result)
			break ;
	}
	return (result);
}

int	main(void)
{
	if (ft_test("", (size_t)(-1))
		|| ft_test("\0", (size_t)(-1))
		|| ft_test(" ", (size_t)(-1))
		|| ft_test("u", (size_t)(-1))
		|| ft_test("r", (size_t)(-1))
		|| ft_test_nested("n", "ice")
		|| ft_test_nested("re", "ally")
		|| ft_test_nested("testing", "testing")
		|| ft_test_nested("testing", "gnitset")
		|| ft_test_loop("very hard"))
	{
		printf("KO: ft_strlcpy\n");
		return (1);
	}
	printf("OK: ft_strlcpy\n");
	return (0);
}
