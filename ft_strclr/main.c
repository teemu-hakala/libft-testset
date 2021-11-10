/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:33:42 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 16:35:59 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(char *s)
{
	size_t	len;
	char	*std_calloc;
	char	*ft_clear;
	int		result;

	len = strlen(s);
	std_calloc = (char *)calloc(len, sizeof(char));
	ft_clear = strdup(s);
	if (!std_calloc || !ft_clear)
	{
		free(std_calloc);
		free(ft_clear);
		printf("Memory allocation failure: calloc or strdup");
		return (1);
	}
	ft_strclr(ft_clear);
	result = memcmp(ft_clear, std_calloc, len);
	free(std_calloc);
	free(ft_clear);
	return (result);
}

int	main(void)
{
	if (ft_test("String to be cleared.")
		|| ft_test(""))
	{
		printf("KO: ft_strclr");
		return (1);
	}
	printf("OK: ft_strclr");
}
