/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_perf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:43:48 by thakala           #+#    #+#             */
/*   Updated: 2021/11/25 13:39:07 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*ft_strjoin_(char const *s1, char const *s2);

static int	ft_test_nested(char *(*ft_strjoin)(const char *, const char *),
	const char *s1, const char *s2, const char *s3, const char *reference)
{
	char	*joined_str;
	char	*nested_str;
	int		result;

	joined_str = ft_strjoin(s1, s2);
	if (!joined_str)
	{
		printf("Memory allocation error\n");
		exit(42);
	}
	nested_str = ft_strjoin(joined_str, s3);
	if (!nested_str)
	{
		printf("Memory allocation error\n");
		exit(42);
	}
	result = strcmp(nested_str, reference);
	free(joined_str);
	free(nested_str);
	return (result);
}

#define AMOUNT 100000000

/*
	100M for ~22 s runtime.
*/

int	main(void)
{
	size_t	i;
	double	startTime;
	double	endTime;
	double	timeElapsed;

	startTime = (double)clock() / CLOCKS_PER_SEC;
	i = 0;
	while (i++ < AMOUNT)
		ft_test_nested(&ft_strjoin,
			"OK: ", "ft_", "strjoin", "OK: ft_strjoin");
	endTime = (double)clock() / CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;
	printf(" : %lf\n", timeElapsed);
	startTime = (double)clock() / CLOCKS_PER_SEC;
	i = 0;
	while (i++ < AMOUNT)
		ft_test_nested_(&ft_strjoin_,
			"OK: ", "ft_", "strjoin", "OK: ft_strjoin");
	endTime = (double)clock() / CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;
	printf("_: %lf\n", timeElapsed);
}
