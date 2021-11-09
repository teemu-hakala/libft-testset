/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:06:17 by thakala           #+#    #+#             */
/*   Updated: 2021/11/07 18:11:54 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"

static int	ft_test(const char *s, const char c)
{
	return (strrchr(s, c) == ft_strrchr(s, c));
}

int	main(void)
{
	if (!ft_test("Unbreakable", 'U')
		|| !ft_test("Unbreakable", '\0'))
	{
		ft_putstr_test("KO: ft_strrchr");
		return (1);
	}
	ft_putstr_test("OK: ft_strrchr");
}
