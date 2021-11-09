# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 19:05:04 by thakala           #+#    #+#              #
#    Updated: 2021/11/09 21:14:05 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS = \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strlen \
	ft_strdup \
	ft_strcpy \
	ft_strncpy \
	ft_strcat \
	ft_strncat \
	ft_strlcat \
	ft_strchr \
	ft_strrchr \
	ft_strstr \
	ft_strnstr \
	ft_strcmp \
	ft_strncmp \
	ft_atoi \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_toupper \
	ft_tolower \
	ft_memalloc \
	ft_memdel \
	ft_strnew \
	ft_strdel \
	ft_strclr \
	ft_striter \
	ft_striteri \
	ft_strmap \
	ft_strmapi \
	ft_strequ \
	ft_strnequ \
	ft_strsub \
	ft_strjoin \
	ft_strtrim \
	ft_strsplit \
	ft_itoa \
	ft_putchar \
	ft_putstr \
	ft_putendl \
	ft_putnbr \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_lstnew \
	ft_lstdelone \
	ft_lstdel \
	ft_lstadd \
	ft_lstiter \
	ft_lstmap


FUNCTIONS_BONUS = \
	ft_lstnew \
	ft_lstdelone \
	ft_lstdel \
	ft_lstadd \
	ft_lstiter \
	ft_lstmap

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

CLANG = gcc

CPL_FLG = -Wall -Wextra -Werror -Wconversion

LIB_NAME = libft-0

SRC_DIR = ../$(LIB_NAME)

LIB_DIR = _test_ft

PRG_DIR = _programs

LIB_ROOT = ../$(LIB_NAME)

.PHONY: $(FUNCTIONS)

all: subsystem \
	norminette \
	$(FUNCTIONS)

#Compile libtest.a
subsystem:
	$(MAKE) -C $(LIB_DIR)

norminette:
	norminette $(foreach s, $(SRCS), $(addprefix $(SRC_DIR)/, $(s)))
#	$(shell norminette $(foreach s, $(SRCS), $(addprefix $(SRC_DIR)/, $(s))))

foreach:
	$(foreach ft, $(FUNCTIONS), \
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/$(ft).c $(ft)/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft -o $(PRG_DIR)/$(ft)/$(ft);)

ft_memset: $(SRC_DIR)/ft_memset.c ft_memset/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memset.c ft_memset/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memset/ft_memset

ft_bzero: $(SRC_DIR)/ft_bzero.c ft_bzero/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_bzero.c ft_bzero/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_bzero/ft_bzero

ft_memcpy: $(SRC_DIR)/ft_memcpy.c ft_memcpy/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memcpy.c ft_memcpy/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memcpy/ft_memcpy

ft_memccpy: $(SRC_DIR)/ft_memccpy.c ft_memccpy/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memccpy.c ft_memccpy/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memccpy/ft_memccpy

ft_memmove: $(SRC_DIR)/ft_memmove.c ft_memmove/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memmove.c ft_memmove/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memmove/ft_memmove

ft_memchr: $(SRC_DIR)/ft_memchr.c ft_memchr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memchr.c ft_memchr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memchr/ft_memchr

ft_memcmp: $(SRC_DIR)/ft_memcmp.c ft_memcmp/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memcmp.c ft_memcmp/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memcmp/ft_memcmp

ft_strlen: $(SRC_DIR)/ft_strlen.c ft_strlen/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strlen.c ft_strlen/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strlen/ft_strlen

ft_strdup: $(SRC_DIR)/ft_strdup.c ft_strdup/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strdup.c ft_strdup/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strdup/ft_strdup

ft_strcpy: $(SRC_DIR)/ft_strcpy.c ft_strcpy/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strcpy.c ft_strcpy/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strcpy/ft_strcpy

ft_strncpy: $(SRC_DIR)/ft_strncpy.c ft_strncpy/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strncpy.c ft_strncpy/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strncpy/ft_strncpy

ft_strcat: $(SRC_DIR)/ft_strcat.c ft_strcat/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strcat.c ft_strcat/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strcat/ft_strcat

ft_strncat: $(SRC_DIR)/ft_strncat.c ft_strncat/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strncat.c ft_strncat/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strncat/ft_strncat

ft_strlcat: $(SRC_DIR)/ft_strlcat.c ft_strlcat/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strlcat.c ft_strlcat/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strlcat/ft_strlcat

ft_strchr: $(SRC_DIR)/ft_strchr.c ft_strchr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strchr.c ft_strchr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strchr/ft_strchr

ft_strrchr: $(SRC_DIR)/ft_strrchr.c ft_strrchr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strrchr.c ft_strrchr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strrchr/ft_strrchr

ft_strstr: $(SRC_DIR)/ft_strstr.c ft_strstr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strstr.c ft_strstr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strstr/ft_strstr

ft_strnstr: $(SRC_DIR)/ft_strnstr.c ft_strnstr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strnstr.c ft_strnstr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strnstr/ft_strnstr

ft_strcmp: $(SRC_DIR)/ft_strcmp.c ft_strcmp/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strcmp.c ft_strcmp/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strcmp/ft_strcmp

ft_strncmp: $(SRC_DIR)/ft_strncmp.c ft_strncmp/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strncmp.c ft_strncmp/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strncmp/ft_strncmp

ft_atoi: $(SRC_DIR)/ft_atoi.c ft_atoi/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_atoi.c ft_atoi/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_atoi/ft_atoi

ft_isalpha: $(SRC_DIR)/ft_isalpha.c ft_isalpha/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_isalpha.c ft_isalpha/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_isalpha/ft_isalpha

ft_isdigit: $(SRC_DIR)/ft_isdigit.c ft_isdigit/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_isdigit.c ft_isdigit/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_isdigit/ft_isdigit

ft_isalnum: $(SRC_DIR)/ft_isalnum.c ft_isalnum/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_isalnum.c ft_isalnum/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_isalnum/ft_isalnum

ft_isascii: $(SRC_DIR)/ft_isascii.c ft_isascii/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_isascii.c ft_isascii/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_isascii/ft_isascii

ft_isprint: $(SRC_DIR)/ft_isprint.c ft_isprint/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_isprint.c ft_isprint/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_isprint/ft_isprint

ft_toupper: $(SRC_DIR)/ft_toupper.c ft_toupper/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_toupper.c ft_toupper/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_toupper/ft_toupper

ft_tolower: $(SRC_DIR)/ft_tolower.c ft_tolower/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_tolower.c ft_tolower/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_tolower/ft_tolower

ft_memalloc: $(SRC_DIR)/ft_memalloc.c ft_memalloc/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memalloc.c ft_memalloc/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memalloc/ft_memalloc

ft_memdel: $(SRC_DIR)/ft_memdel.c ft_memdel/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_memdel.c ft_memdel/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_memdel/ft_memdel

ft_strnew: $(SRC_DIR)/ft_strnew.c ft_strnew/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strnew.c ft_strnew/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strnew/ft_strnew

ft_strdel: $(SRC_DIR)/ft_strdel.c ft_strdel/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strdel.c ft_strdel/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strdel/ft_strdel

ft_strclr: $(SRC_DIR)/ft_strclr.c ft_strclr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strclr.c ft_strclr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strclr/ft_strclr

ft_striter: $(SRC_DIR)/ft_striter.c ft_striter/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_striter.c ft_striter/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_striter/ft_striter

ft_striteri: $(SRC_DIR)/ft_striteri.c ft_striteri/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_striteri.c ft_striteri/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_striteri/ft_striteri

ft_strmap: $(SRC_DIR)/ft_strmap.c ft_strmap/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strmap.c ft_strmap/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strmap/ft_strmap

ft_strmapi: $(SRC_DIR)/ft_strmapi.c ft_strmapi/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strmapi.c ft_strmapi/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strmapi/ft_strmapi

ft_strequ: $(SRC_DIR)/ft_strequ.c ft_strequ/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strequ.c ft_strequ/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strequ/ft_strequ

ft_strnequ: $(SRC_DIR)/ft_strnequ.c ft_strnequ/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strnequ.c ft_strnequ/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strnequ/ft_strnequ

ft_strsub: $(SRC_DIR)/ft_strsub.c ft_strsub/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strsub.c ft_strsub/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strsub/ft_strsub

ft_strjoin: $(SRC_DIR)/ft_strjoin.c ft_strjoin/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strjoin.c ft_strjoin/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strjoin/ft_strjoin

ft_strtrim: $(SRC_DIR)/ft_strtrim.c ft_strtrim/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strtrim.c ft_strtrim/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strtrim/ft_strtrim

ft_strsplit: $(SRC_DIR)/ft_strsplit.c ft_strsplit/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_strsplit.c ft_strsplit/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_strsplit/ft_strsplit

ft_itoa: $(SRC_DIR)/ft_itoa.c ft_itoa/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_itoa.c ft_itoa/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_itoa/ft_itoa

ft_putchar: $(SRC_DIR)/ft_putchar.c ft_putchar/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putchar.c ft_putchar/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putchar/ft_putchar

ft_putstr: $(SRC_DIR)/ft_putstr.c ft_putstr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putstr.c ft_putstr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putstr/ft_putstr

ft_putendl: $(SRC_DIR)/ft_putendl.c ft_putendl/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putendl.c ft_putendl/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putendl/ft_putendl

ft_putnbr: $(SRC_DIR)/ft_putnbr.c ft_putnbr/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putnbr.c ft_putnbr/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putnbr/ft_putnbr

ft_putchar_fd: $(SRC_DIR)/ft_putchar_fd.c ft_putchar_fd/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putchar_fd.c ft_putchar_fd/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putchar_fd/ft_putchar_fd

ft_putstr_fd: $(SRC_DIR)/ft_putstr_fd.c ft_putstr_fd/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putstr_fd.c ft_putstr_fd/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putstr_fd/ft_putstr_fd

ft_putendl_fd: $(SRC_DIR)/ft_putendl_fd.c ft_putendl_fd/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putendl_fd.c ft_putendl_fd/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putendl_fd/ft_putendl_fd

ft_putnbr_fd: $(SRC_DIR)/ft_putnbr_fd.c ft_putnbr_fd/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_putnbr_fd.c ft_putnbr_fd/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_putnbr_fd/ft_putnbr_fd

ft_lstnew: $(SRC_DIR)/ft_lstnew.c ft_lstnew/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_lstnew.c ft_lstnew/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_lstnew/ft_lstnew

ft_lstdelone: $(SRC_DIR)/ft_lstdelone.c ft_lstdelone/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_lstdelone.c ft_lstdelone/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_lstdelone/ft_lstdelone

ft_lstdel: $(SRC_DIR)/ft_lstdel.c ft_lstdel/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_lstdel.c ft_lstdel/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_lstdel/ft_lstdel

ft_lstadd: $(SRC_DIR)/ft_lstadd.c ft_lstadd/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_lstadd.c ft_lstadd/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_lstadd/ft_lstadd

ft_lstiter: $(SRC_DIR)/ft_lstiter.c ft_lstiter/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_lstiter.c ft_lstiter/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_lstiter/ft_lstiter

ft_lstmap: $(SRC_DIR)/ft_lstmap.c ft_lstmap/main.c
	$(CLANG) $(CPL_FLG) $(SRC_DIR)/ft_lstmap.c ft_lstmap/main.c \
		-L$(LIB_DIR) -ltest -L$(LIB_ROOT) -lft \
		-o $(PRG_DIR)/ft_lstmap/ft_lstmap
