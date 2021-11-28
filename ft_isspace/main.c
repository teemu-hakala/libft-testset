/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:56:59 by thakala           #+#    #+#             */
/*   Updated: 2021/11/28 13:57:21 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int		c;

	c = -1000;
	while (c <= 1000)
	{
		if (isspace(c) != ft_isspace(c))
		{
			printf("KO: ft_isspace\n");
			printf("%s", (char *)&c);
		}
		c++;
	}
	printf("OK: ft_isspace\n");
}
