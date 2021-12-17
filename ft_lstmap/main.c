/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:58:54 by thakala           #+#    #+#             */
/*   Updated: 2021/12/17 11:09:44 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../ft_tests.h"
#include <stdio.h>

static void	ft_erase_node(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

static t_list	*ft_linklst(char **nodes)
{
	t_list	*head;
	t_list	*current;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head = ft_lstnew(*nodes, strlen(*nodes++));
	current = head;
	while (*nodes)
	{
		head->next = ft_lstnew(*nodes, strlen(*nodes++));
		if (!head->next)
		{
			ft_lstdel(&head, ft_erase_node);
			return (NULL);
		}
		nodes++;
	}
	return (head);
}

static int	ft_test(const void **arr)
{
	t_list	*head;
	t_list	*mapped;

	head = ft_linklst(arr);
	mapped = ft_lstmap(head);
	if (!mapped)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	return (0);
}

int	main(void)
{
	if (ft_test((char *[]){"A", "B", "C", "D", "E", "F", "G", "H", "I", NULL})
		|| ft_test())
	{

	}
}
