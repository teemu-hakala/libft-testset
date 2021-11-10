/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:24:36 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 17:31:54 by thakala          ###   ########.fr       */
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
		if (isdigit(c) != ft_isdigit(c))
		{
			printf("KO: ft_isdigit\n");
			printf("%s\n", (char *)&c);
		}
		c++;
	}
	printf("OK: ft_isdigit\n");
}
