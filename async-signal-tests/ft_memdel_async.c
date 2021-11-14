/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_async.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:24:18 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 16:24:20 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_test(char *s)
{
	char	*string;
	char	*string_copy;
	size_t	length;

	string = strdup(s);
	length = strlen(string);
	string_copy = string;
	if (0)
		ft_putstr_len(string, length);
	ft_memdel((void **)&string);
	if (0)
		ft_putstr_len(string_copy, length);
	//free(string_copy); // define handler for SIGABRT
	if (!string)
		return (1);
	return (0);
}
