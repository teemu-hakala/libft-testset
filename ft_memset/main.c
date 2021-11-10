/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:19:28 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 11:51:44 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void	*memdup(const void *mem, size_t size)
{
	void	*out;

	out = malloc(size);
	if (out)
		memcpy(out, mem, size);
	return (out);
}

static int	ft_test(int c, char *s, size_t len)
{
	char	*std_array;
	char	*ft_array;
	int		result;

	std_array = (char *)memdup(s, len);
	ft_array = (char *)memdup(std_array, len);
	memset(std_array, c, len);
	ft_memset(ft_array, c, len);
	result = memcmp(std_array, ft_array, len);
	free(std_array);
	free(ft_array);
	return (result);
}

int	main(void)
{
	if (ft_test(-1, "\0\r\t", 4))
	{
		printf("KO: ft_memset\n");
		return (1);
	}
	printf("OK: ft_memset\n");
}
