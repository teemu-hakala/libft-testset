/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:06:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 20:53:45 by thakala          ###   ########.fr       */
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
		|| !ft_test("Unbreakable", '\0')
		|| !ft_test("", '\0')
		|| !ft_test("Un\0breakable", '\0')
		|| !ft_test("Un\0breakable", 'r'))
	{
		printf("KO: ft_strrchr\n");
		return (1);
	}
	printf("OK: ft_strrchr\n");
}
