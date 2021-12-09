/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:33:46 by thakala           #+#    #+#             */
/*   Updated: 2021/12/09 20:15:27 by thakala          ###   ########.fr       */
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

	printf("%zu\n", offset);
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

static int	ft_test_overlap_loop(const char *dstsrc, size_t len)
{
	size_t	offset;

	offset = 0;
	while (offset < len)
		if (ft_test_overlap(dstsrc, offset++, 0, len))
			return (1);
	while (offset + 1)
		if (ft_test_overlap(dstsrc, offset--, 1, len))
			return (1);
	return (0);
}

int	main(void)
{
	if (ft_test("destination", 12, "source", 6)
		|| ft_test_overlap("destinationsource", 3, 0, 5)
		|| ft_test_overlap("destinationsource", 3, 1, 5)
		|| ft_test_overlap_loop("Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution. Just to see if an evaluated ft_memmove is \
		wrong or not with a ridiculously long string of characters, in case I \
		called it wrongfully a dubious solution.", 420))
	{
		printf("KO: ft_memmove\n");
		return (1);
	}
	printf("OK: ft_memmove\n");
}
