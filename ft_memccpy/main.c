/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:59:44 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 12:56:30 by thakala          ###   ########.fr       */
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

static size_t	ft_occurence_len(char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c)
		len++;
	return (len + 1);
}

static int	ft_display_cmp(char *std_res, char *ft_res, size_t remaining)
{
	size_t	i;

	if (0)
	{
		i = 0;
		while (i < remaining)
			printf("%c", std_res[i++]);
		i = 0;
		printf("%c", '\n');
		while (i < remaining)
			printf("%c", ft_res[i++]);
		printf("%c", '\n');
	}
	return (memcmp(std_res, ft_res, remaining));
}

static int	ft_compare(char *src, char c, char *std_dst, char *ft_dst)
{
	size_t	len;
	char	*std_res;
	char	*ft_res;

	len = strlen(src);
	std_res = (char *)memccpy(std_dst, src, c, len);
	ft_res = (char *)ft_memccpy(ft_dst, src, c, len);
	if (!std_res && !ft_res)
		return (0);
	return (ft_display_cmp(std_res, ft_res, len - ft_occurence_len(src, c)));
}

static int	ft_test(char *str, char c)
{
	char	*std_dst;
	char	*ft_dst;
	size_t	length;
	int		result;

	length = strlen(str);
	std_dst = (char *)malloc(sizeof(char) * length);
	ft_dst = (char *)memdup(std_dst, length);
	result = ft_compare(str, c, std_dst, ft_dst);
	free(std_dst);
	free(ft_dst);
	return (result);
}

int	main(void)
{
	if (ft_test("abcdefBghijklmnopq", 'B')
		|| ft_test("abcdefBghijk\0lmnopq", 'C'))
	{
		printf("KO: ft_memccpy\n");
		return (1);
	}
	printf("OK: ft_memccpy\n");
}
