/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 06:48:23 by thakala           #+#    #+#             */
/*   Updated: 2021/11/02 10:18:49 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_ft.h"

void	ft_putnbr_test(int n)
{
	if (n < 0)
	{
		ft_putchar_test('-');
		if (n == (int)(~(~0u >> 1)))
		{
			ft_putnbr_test(-(n / 10));
			ft_putnbr_test(-(n % 10));
		}
		else
			ft_putnbr_test(-n);
	}
	else if (n > 9)
	{
		ft_putnbr_test(n / 10);
		ft_putnbr_test(n % 10);
	}
	else
		ft_putchar_test('0' + n);
}
