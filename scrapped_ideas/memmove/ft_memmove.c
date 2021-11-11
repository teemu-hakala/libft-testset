/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:35:21 by thakala           #+#    #+#             */
/*   Updated: 2021/11/08 16:14:21 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*copy;

	copy = (char *)ft_memalloc(sizeof(char) * len);
	if (!copy)
		return (NULL);
	return (ft_memcpy(dst, ft_memcpy(copy, src, len), len));
}
