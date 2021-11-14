/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:37:16 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 18:27:03 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static void	ft_alternate_case(unsigned int i, char *c)
{
	if (!(i % 2))
		*c = (char)toupper(*c);
	else
		*c = (char)tolower(*c);
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
	ft_striteri(str, &ft_alternate_case);
	result = strcmp(str, reference);
	free(str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("evenswitchcase", "EvEnSwItChCaSe")
		|| ft_test("OK: ft_striteri", "Ok: Ft_sTrItErI")
		|| ft_test("qwertyuiopasdfghjklzxcvbnm", "QwErTyUiOpAsDfGhJkLzXcVbNm")
		|| ft_test("QWERTYUIOPASDFGHJKLZXCVBNM", "QwErTyUiOpAsDfGhJkLzXcVbNm"))
	{
		printf("KO: ft_striteri\n");
		return (1);
	}
	printf("OK: ft_striteri\n");
	return (0);
}
