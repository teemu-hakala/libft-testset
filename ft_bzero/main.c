/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 04:48:33 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 10:45:00 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void	ft_test_int_array(int *std_array, size_t len)
{
	int		*ft_array;

	ft_array = (int *)malloc(sizeof(int) * len);
	memcpy(ft_array, std_array, len);
	ft_bzero(ft_array, len);
	bzero(std_array, len);
	if (!memcmp(ft_array, std_array, len))
		printf("OK: ft_bzero int array\n");
	else
		printf("KO: ft_bzero int array\n");
	free(ft_array);
}

void	ft_test_str(char *std_s, size_t len)
{
	char	*ft_s;

	ft_s = (char *)malloc(sizeof(char) * len);
	strncpy(ft_s, std_s, len);
	ft_bzero(ft_s, len);
	bzero(std_s, len);
	if (!memcmp(ft_s, std_s, len))
		printf("OK: ft_bzero string\n");
	else
		printf("KO: ft_bzero string\n");
	free(ft_s);
	free(std_s);
}

int	main(void)
{
	ft_test_int_array((int []){1, 2, 3, 4, 5, 6, 7, 8}, sizeof(int) * 8);
	ft_test_str(strdup("Ten chars"), 10);
	return (0);
}
