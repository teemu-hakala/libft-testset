/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:23:09 by thakala           #+#    #+#             */
/*   Updated: 2021/11/07 20:08:56 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"

static void	ft_putstr_len(char *string, size_t length)
{
	size_t	i;

	i = 0;
	while (i++ < length)
		ft_putchar_test(*string++);
	ft_putchar_test('\n');
}

static int	ft_test(char *s)
{
	char	*string;
	char	*string_copy;
	size_t	length;

	string = strdup(s);
	length = strlen(string);
	string_copy = string;
	ft_putstr_len(string, length);
	ft_memdel((void **)&string);
	ft_putstr_len(string_copy, length);
	if (!string)
		return (1);
	return (0);
}

int	main(void)
{
	ft_memdel(NULL);
	if (ft_test("Test string."))
		ft_putstr_test("OK: ft_memdel");
	else
		ft_putstr_test("KO: ft_memdel");
}
