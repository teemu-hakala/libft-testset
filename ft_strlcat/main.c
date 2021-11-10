/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:39:27 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:41:59 by thakala          ###   ########.fr       */
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

static int	ft_test(const char *dst_init, const char *src, size_t l)
{
	char	*std_dst;
	char	*ft_dst;
	size_t	len;
	int		result;

	len = strlen(dst_init) + l;
	std_dst = (char *)malloc(sizeof(char) * len);
	strcpy(std_dst, dst_init);
	ft_dst = (char *)malloc(sizeof(char) * len);
	ft_dst = (char *)memcpy(ft_dst, std_dst, len);
	if (strlcat(std_dst, src, l) != ft_strlcat(ft_dst, src, l))
		return (1);
	result = memcmp(std_dst, ft_dst, len);
	if (result)
	{
		ft_display_mem(std_dst, len);
		ft_display_mem(ft_dst, len);
		free(std_dst);
		free(ft_dst);
		return (1);
	}
	free(std_dst);
	free(ft_dst);
	return (0);
}

int	main(void)
{
	if (ft_test("Source", "concatenation", 10)
		|| ft_test("", "", 0))
	{
		printf("KO: ft_strlcat\n");
		return (1);
	}
	printf("OK: ft_strlcat\n");
}
