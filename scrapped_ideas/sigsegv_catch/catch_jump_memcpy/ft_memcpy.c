/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:58:22 by thakala           #+#    #+#             */
/*   Updated: 2021/11/11 11:02:39 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	char	*new_beginning;

	if (n == 0 || (!dst && !src))
		return (dst);
	destination = (char *)dst;
	source = (char *)src;
	new_beginning = destination;
	while (n--)
		*destination++ = *source++;
	return ((void *)new_beginning);
}
