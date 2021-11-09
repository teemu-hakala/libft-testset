/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:57:59 by thakala           #+#    #+#             */
/*   Updated: 2021/11/02 10:18:25 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_ft.h"
#include <errno.h>
#include <stdlib.h>

char	*ft_strdup_test(char *src)
{
	int		len;
	char	*copy;

	len = ft_strlen_test(src) + 1;
	copy = (char *)malloc(sizeof(*copy) * len);
	if (!copy)
	{
		errno = ENOMEM;
		return (0);
	}
	while (--len >= 0)
		*(copy + len) = *(src + len);
	return (copy);
}
