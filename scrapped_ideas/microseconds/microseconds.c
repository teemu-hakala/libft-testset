/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microseconds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:52:52 by thakala           #+#    #+#             */
/*   Updated: 2021/11/12 12:13:39 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	struct timeval	end;

	while (1)
	{
		gettimeofday(&end, NULL);
		printf("Elapsed time: %ld nanoseconds\n",
			1000000 * end.tv_sec + end.tv_usec);
	}
	return (0);
}
