/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:37:22 by thakala           #+#    #+#             */
/*   Updated: 2021/11/05 08:28:01 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <stdlib.h>

int	main(void)
{
	size_t	size;
	size_t	i;
	char	*area;

	size = 10000000;
	area = (char *)ft_memalloc(size);
	while (i < size)
	{
		if (area[i++])
		{
			ft_putstr_test("KO: ft_memalloc\n");
			return (1);
		}
	}
	ft_putstr_test("OK: ft_memalloc\n");
	free(area);
}
