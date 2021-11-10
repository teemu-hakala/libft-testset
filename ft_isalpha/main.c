/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:18:47 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 17:31:46 by thakala          ###   ########.fr       */
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
		if (isalpha(c) != ft_isalpha(c))
		{
			printf("KO: ft_isalpha\n");
			printf("%s\n", (char *)&c);
		}
		c++;
	}
	printf("OK: ft_isalpha\n");
}
