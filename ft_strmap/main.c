/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:57:56 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 18:26:05 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static char	ft_evenswitchcase(char c)
{
	if (!(c % 2))
	{
		if (c >= 'A' && c <= 'Z')
			return ((char)tolower(c));
		else if (c >= 'a' && c <= 'z')
			return ((char)toupper(c));
	}
	return (c);
}

static int	ft_test(const char *s, const char *reference)
{
	char	*str;
	int		result;

	str = ft_strmap(s, &ft_evenswitchcase);
	if (!str)
	{
		printf("Memory allocation error.\n");
		exit(42);
	}
	result = strcmp(str, reference);
	free(str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("evenswitchcase", "eVeNswiTcHcase")
		|| ft_test("OK: ft_strmap", "OK: FT_sTRmaP")
		|| ft_test("qwertyuiopasdfghjklzxcvbnm", "qweRTyuioPasDFgHJkLZXcVBNm")
		|| ft_test("QWERTYUIOPASDFGHJKLZXCVBNM", "QWErtYUIOpASdfGhjKlzxCvbnM"))
	{
		printf("KO: ft_strmap\n");
		return (1);
	}
	printf("OK: ft_strmap\n");
	return (0);
}
