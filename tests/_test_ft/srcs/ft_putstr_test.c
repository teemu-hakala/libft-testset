/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:16:19 by thakala           #+#    #+#             */
/*   Updated: 2021/11/02 10:18:44 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_ft.h"
#include <unistd.h>

void	ft_putstr_test(char *str)
{
	write(1, str, ft_strlen_test(str));
}
