/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:50:14 by thakala           #+#    #+#             */
/*   Updated: 2021/11/10 14:35:40 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <string.h>
#include <stdio.h>

void	ft_test(char *s)
{
	if (ft_strlen(s) == strlen(s))
		printf("OK: ft_strlen\n");
	else
		printf("KO: ft_strlen\n");
}

int	main(void)
{
	ft_test("test");
	ft_test("");
}
