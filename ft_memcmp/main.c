/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:07:58 by thakala           #+#    #+#             */
/*   Updated: 2021/11/20 14:43:11 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

static int	ft_test(const void *arr1, const void *arr2, size_t n)
{
	return (memcmp(arr1, arr2, n) != ft_memcmp(arr1, arr2, n));
}

static int	ft_test_equal(const void *arr0, size_t n)
{
	return (ft_test(arr0, arr0, n));
}

int	main(void)
{
	if (ft_test_equal((int []){0, 1, 2, 3, 4, 5}, sizeof(int) * 6)
		|| ft_test((int []){0, 1, 2, 3, 4, 5}, (int []){0, 1, 2, 3, 4, 6},
		sizeof(int) * 6)
		|| ft_test_equal("ft_test_equal", 14)
		|| ft_test("ft_test_unequal", "ft_test-unequal", 16)
		|| ft_test("abcdefghij", "abcdefgxyz", 7)
		|| ft_test("character", "pqrstring", 0))
	{
		printf("KO: ft_memcmp\n");
		return (1);
	}
	printf("OK: ft_memcmp\n");
}
