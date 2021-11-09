/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:49:11 by thakala           #+#    #+#             */
/*   Updated: 2021/11/06 13:59:10 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include "../_test_ft/includes/test_ft.h"
#include <stdlib.h>

static int	ft_test(const char *string)
{
	char	*std_str;
	char	*ft_str;
	int		result;

	std_str = strdup(string);
	ft_str = ft_strdup(string);
	result = strcmp(std_str, ft_str);
	free(std_str);
	free(ft_str);
	return (result);
}

int	main(void)
{
	if (ft_test("Unbreakable")
		|| ft_test(""))
	{
		ft_putstr_test("KO: ft_strdup");
		return (1);
	}
	ft_strdup(NULL);
	ft_putstr_test("OK: ft_strdup");
}
