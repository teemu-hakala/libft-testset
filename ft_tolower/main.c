/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:42:24 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 13:03:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <ctype.h>
#include <stdio.h>

static int	ft_test(int c)
{
	return (tolower(c) == ft_tolower(c));
}

int	main(void)
{
	int		i;

	i = -1000;
	while (i <= 1000)
	{
		if (!ft_test(i))
		{
			printf("KO: ft_tolower\n");
			return (1);
		}
		i++;
	}
	printf("OK: ft_tolower\n");
}
