/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:06:04 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 18:27:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(size_t size)
{
	char	*new_str;

	new_str = ft_strnew(size++);
	while (size)
		if (new_str[--size])
			return (1);
	return (0);
}

int	main(void)
{
	if (ft_test(2)
		|| ft_test(0)
		|| ft_test(10000000))
	{
		printf("KO: ft_strnew\n");
		return (1);
	}
	printf("OK: ft_strnew\n");
}
