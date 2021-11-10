/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 05:59:57 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 17:31:41 by thakala          ###   ########.fr       */
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
		if (isalnum(c) != ft_isalnum(c))
		{
			printf("KO: ft_isalnum\n");
			printf("%s\n", (char *)&c);
		}
		c++;
	}
	printf("OK: ft_isalnum\n");
}
