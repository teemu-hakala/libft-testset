/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segfaults.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:34:37 by thakala           #+#    #+#             */
/*   Updated: 2021/11/14 16:41:41 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEGFAULTS_H
# define FT_SEGFAULTS_H

# include <setjmp.h>
# define _LIBC_MSG " libc"
# define LIBFT_MSG "libft"

char	*g_message;
int		g_std_segfault;
jmp_buf	g_buffer;
int		g_print;

int	ft_segfault_memset(void);
int	ft_segfault_bzero(void);
int	ft_segfault_memcpy(void);
int	ft_segfault_memccpy(void);
int	ft_segfault_memmove(void);
int	ft_segfault_memchr(void);
int	ft_segfault_memcmp(void);
int	ft_segfault_strlen(void);
int	ft_segfault_strdup(void);
int	ft_segfault_strcpy(void);
int	ft_segfault_strncpy(void);
int	ft_segfault_strcat(void);
int	ft_segfault_strncat(void);
int	ft_segfault_strlcat(void);
int	ft_segfault_strchr(void);
int	ft_segfault_strrchr(void);
int	ft_segfault_strstr(void);
int	ft_segfault_strnstr(void);
int	ft_segfault_strcmp(void);
int	ft_segfault_strncmp(void);
int	ft_segfault_atoi(void);
int	ft_segfault_isalpha(void);
int	ft_segfault_isdigit(void);
int	ft_segfault_isalnum(void);
int	ft_segfault_isascii(void);
int	ft_segfault_toupper(void);
int	ft_segfault_tolower(void);

int	ft_sigabrt_memdel(void);

#endif
