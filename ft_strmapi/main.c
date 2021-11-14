/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:28:10 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 18:45:19 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static char	ft_alternate_case(unsigned int i, char c)
{
	if (!(i % 2))
		return ((char)toupper(c));
	else
		return ((char)tolower(c));
}

static int	ft_test(const char *s, const char *reference)
{
	char	*str;
	int		result;

	str = ft_strmapi(s, &ft_alternate_case);
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
		|| ft_test("ft_alternate_case", "Ft_aLtErNaTe_cAsE")
		|| ft_test("OK: ft_strmapi", "Ok: Ft_sTrMaPi")
		|| ft_test("qwertyuiopasdfghjklzxcvbnm", "QwErTyUiOpAsDfGhJkLzXcVbNm")
		|| ft_test("QWERTYUIOPASDFGHJKLZXCVBNM", "QwErTyUiOpAsDfGhJkLzXcVbNm"))
	{
		printf("KO: ft_strmapi\n");
		return (1);
	}
	printf("OK: ft_strmapi\n");
	return (0);
}
