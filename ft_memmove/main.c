/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:33:46 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:33:14 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *dst, size_t dst_len,
	const char *src, size_t len)
{
	char	*std_destination;
	char	*ft_destination;

	std_destination = (char *)malloc(sizeof(char) * dst_len);
	ft_destination = (char *)malloc(sizeof(char) * dst_len);
	if (!std_destination || !ft_destination)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	std_destination = (char *)memcpy(std_destination, dst, dst_len);
	ft_destination = (char *)memmove(ft_destination, std_destination, dst_len);
	return (memcmp(memmove(std_destination, src, len),
			ft_memmove(ft_destination, src, len), len));
}

static int	ft_test_overlap(const char *dstsrc, size_t offset, size_t direction,
	size_t len)
{
	char	*std_destinationsource;
	char	*ft_destinationsource;
	int		result;

	std_destinationsource = strdup(dstsrc);
	ft_destinationsource = strdup(dstsrc);
	if (!std_destinationsource || !ft_destinationsource)
	{
		printf("Memory allocation error!\n");
		return (1);
	}
	if (!direction)
	{
		memmove(std_destinationsource, std_destinationsource + offset, len);
		ft_memmove(ft_destinationsource, ft_destinationsource + offset, len);
	}
	else
	{
		memmove(std_destinationsource + offset, std_destinationsource, len);
		ft_memmove(ft_destinationsource + offset, ft_destinationsource, len);
	}
	result = memcmp(std_destinationsource, ft_destinationsource,
			strlen(dstsrc));
	free(std_destinationsource);
	free(ft_destinationsource);
	return (result);
}

int	main(void)
{
	if (ft_test("destination", 12, "source", 6)
		|| ft_test_overlap("destinationsource", 3, 0, 5)
		|| ft_test_overlap("destinationsource", 3, 1, 5))
	{
		printf("KO: ft_memmove\n");
		return (1);
	}
	printf("OK: ft_memmove\n");
}
