/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:37:22 by thakala           #+#    #+#             */
/*   Updated: 2021/11/13 18:43:19 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	size_t	size;
	size_t	i;
	char	*area;

	size = 10000000;
	i = 0;
	area = (char *)ft_memalloc(size);
	while (i < size)
	{
		if (area[i++])
		{
			printf("KO: ft_memalloc\n");
			free(area);
			return (1);
		}
	}
	printf("OK: ft_memalloc\n");
	free(area);
}
