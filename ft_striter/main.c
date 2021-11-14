/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:14:16 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 17:34:15 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static void	ft_evenswitchcase(char *c)
{
	if (!(*c % 2))
	{
		if (*c >= 'A' && *c <= 'Z')
			*c = (char)tolower(*c);
		else if (*c >= 'a' && *c <= 'z')
			*c = (char)toupper(*c);
	}
}

static int	ft_test(const char *s, const char *reference)
{
	char	*str;
	int		result;

	str = strdup(s);
	if (!str)
	{
		printf("Memory allocation error.\n");
		exit(42);
	}
	ft_striter(str, &ft_evenswitchcase);
	result = strcmp(str, reference);
	free(str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("evenswitchcase", "eVeNswiTcHcase")
		|| ft_test("OK: ft_striter", "OK: FT_sTRiTeR")
		|| ft_test("qwertyuiopasdfghjklzxcvbnm", "qweRTyuioPasDFgHJkLZXcVBNm")
		|| ft_test("QWERTYUIOPASDFGHJKLZXCVBNM", "QWErtYUIOpASdfGhjKlzxCvbnM"))
	{
		printf("KO: ft_striter\n");
		return (1);
	}
	printf("OK: ft_striter\n");
	return (0);
}
