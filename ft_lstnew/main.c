/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:52:18 by thakala           #+#    #+#             */
/*   Updated: 2021/11/20 11:24:17 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	ft_test_nul(const void *content, size_t content_size)
{
	t_list	*new_beginning;

	new_beginning = ft_lstnew(content, content_size);
	if (!new_beginning)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	if (new_beginning->content != content || new_beginning->content_size)
	{
		free(new_beginning->content);
		free(new_beginning);
		return (1);
	}
	return (0);
}

static int	ft_test_str(const char *content)
{
	t_list	*new_beginning;
	int		result;

	result = 0;
	new_beginning = ft_lstnew(content, sizeof(char) * (strlen(content) + 1));
	if (!new_beginning)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	result = !!strcmp(new_beginning->content, content);
	free(new_beginning->content);
	free(new_beginning);
	return (result);
}

static void	*free_arr(char **arr, size_t count)
{
	while (count--)
		free(arr[count]);
	free(arr);
	return (NULL);
}

static char	**ft_dup_array(char **original, size_t count)
{
	size_t	i;
	char	**dup;

	dup = (char **)malloc(sizeof(char *) * count);
	if (!dup)
		return (dup);
	i = 0;
	while (i < count)
	{
		dup[i] = strdup(original[i]);
		if (!dup[i++])
		{
			printf("Memory allocation error.\n");
			return (free_arr(dup, count));
		}
	}
	return (dup);
}

static int	ft_test_arr(char **content, size_t str_count)
{
	t_list	*new_beginning;
	int		result;
	size_t	i;
	char	**dup;

	result = 0;
	dup = ft_dup_array(content, str_count);
	if (!dup)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	new_beginning = ft_lstnew(dup, sizeof(char *) * str_count);
	if (!new_beginning)
	{
		free_arr(dup, str_count);
		printf("Memory allocation error.\n");
		return (1);
	}
	i = 0;
	while (i < str_count)
	{
		if (strcmp(((char **)(new_beginning->content))[i], content[i]))
		{
			result = 1;
			break ;
		}
		i++;
	}
	free(new_beginning->content);
	free(new_beginning);
	return (result);
}

int	main(void)
{
	if (ft_test_nul(NULL, 0)
		|| ft_test_nul(NULL, 1)
		|| ft_test_str("")
		|| ft_test_str("42")
		|| ft_test_arr((char *[]){"One", "Night", "in", "Tokyo", " - ",
			"Beast", "in", "Black"}, 8))
	{
		printf("KO: ft_lstnew\n");
		return (1);
	}
	printf("OK: ft_lstnew\n");
	return (0);
}
