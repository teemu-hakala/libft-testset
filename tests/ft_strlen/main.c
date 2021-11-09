/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:50:14 by thakala           #+#    #+#             */
/*   Updated: 2021/11/06 14:27:29 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <string.h>

void	ft_test(char *s)
{
	if (ft_strlen(s) == strlen(s))
		ft_putstr_test("OK: ft_strlen\n");
	else
		ft_putstr_test("KO: ft_strlen\n");
}

int	main(void)
{
	ft_test("test");
	ft_test("");
}
