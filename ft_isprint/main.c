/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:07:04 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 17:32:35 by thakala          ###   ########.fr       */
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
		if (isprint(c) != ft_isprint(c))
		{
			printf("KO: ft_isprint\n");
			printf("%s", (char *)&c);
		}
		c++;
	}
	printf("OK: ft_isprint\n");
}
