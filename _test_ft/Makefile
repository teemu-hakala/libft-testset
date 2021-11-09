# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 11:56:50 by thakala           #+#    #+#              #
#    Updated: 2021/11/04 11:14:01 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtest.a

SRC_DIR = srcs

SRCS = $(SRC_DIR)/ft_putchar_test.c $(SRC_DIR)/ft_putstr_test.c \
	$(SRC_DIR)/ft_putnbr_test.c $(SRC_DIR)/ft_strlen_test.c \
	$(SRC_DIR)/ft_strdup_test.c $(SRC_DIR)/ft_strcmp_test.c \
	$(SRC_DIR)/ft_atoi_test.c

HEADER_DIR = includes/

OBJS = ft_putchar_test.o ft_putstr_test.o ft_strlen_test.o \
	ft_putnbr_test.o ft_strdup_test.o ft_strcmp_test.o \
	ft_atoi_test.o

COMP_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(COMP_FLAGS) -c $(SRCS) -I$(HEADER_DIR)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
