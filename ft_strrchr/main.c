/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:06:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:43:12 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>

static int	ft_test(const char *s, const char c)
{
	return (strrchr(s, c) == ft_strrchr(s, c));
}

int	main(void)
{
	if (!ft_test("Unbreakable", 'U')
		|| !ft_test("Unbreakable", '\0'))
	{
		printf("KO: ft_strrchr");
		return (1);
	}
	printf("OK: ft_strrchr");
}
