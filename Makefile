# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 19:05:04 by thakala           #+#    #+#              #
#    Updated: 2021/11/11 17:12:50 by thakala          ###   ########.fr        #
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
	ft_isascii\
	ft_isprint \
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

LIB_NAME = libft

LIB_ROOT = ../$(LIB_NAME)

PRG_DIR = _programs

.PHONY: $(FUNCTIONS) all subsystem norminette evaldirectories foreach

all: subsystem \
	norminette \
	evaldirectories \
	$(FUNCTIONS)

#Compile libft.a
subsystem:
	$(MAKE) -C $(LIB_ROOT)

norminette:
	norminette $(foreach s, $(SRCS), $(addprefix $(LIB_ROOT)/, $(s)))
#	$(shell norminette $(foreach s, $(SRCS), $(addprefix $(LIB_ROOT)/, $(s))))

evaldirectories:
	mkdir -p $(foreach f, $(FUNCTIONS), $(addprefix $(PRG_DIR)/, $(f)))

foreach:
	$(foreach ft, $(FUNCTIONS), \
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/$(ft).c $(ft)/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/$(ft)/$(ft);)

foreach2:
	$(foreach ft, $(FUNCTIONS), \
	$(CLANG) $(CPL_FLG) $(ft)/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/$(ft)/$(ft);)

ft_memset: $(LIB_ROOT)/ft_memset.c ft_memset/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memset.c ft_memset/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memset/ft_memset

ft_bzero: $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_bzero/ft_bzero

ft_memcpy: $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcpy/ft_memcpy

ft_memccpy: $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memccpy/ft_memccpy

ft_memmove: $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memmove/ft_memmove

ft_memchr: $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memchr/ft_memchr

ft_memcmp: $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcmp/ft_memcmp

ft_strlen: $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlen/ft_strlen

ft_strdup: $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdup/ft_strdup

ft_strcpy: $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcpy/ft_strcpy

ft_strncpy: $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncpy/ft_strncpy

ft_strcat: $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcat/ft_strcat

ft_strncat: $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncat/ft_strncat

ft_strlcat: $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlcat/ft_strlcat

ft_strchr: $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strchr/ft_strchr

ft_strrchr: $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strrchr/ft_strrchr

ft_strstr: $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strstr/ft_strstr

ft_strnstr: $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnstr/ft_strnstr

ft_strcmp: $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcmp/ft_strcmp

ft_strncmp: $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncmp/ft_strncmp

ft_atoi: $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_atoi/ft_atoi

ft_isalpha: $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalpha/ft_isalpha

ft_isdigit: $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isdigit/ft_isdigit

ft_isalnum: $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalnum/ft_isalnum

ft_isascii: $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isascii/ft_isascii

ft_isprint: $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isprint/ft_isprint

ft_toupper: $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_toupper/ft_toupper

ft_tolower: $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_tolower/ft_tolower

ft_memalloc: $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memalloc/ft_memalloc

ft_memdel: $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdel/ft_memdel

ft_strnew: $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnew/ft_strnew

ft_strdel: $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdel/ft_strdel

ft_strclr: $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strclr/ft_strclr

ft_striter: $(LIB_ROOT)/ft_striter.c ft_striter/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_striter.c ft_striter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striter/ft_striter

ft_striteri: $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striteri/ft_striteri

ft_strmap: $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmap/ft_strmap

ft_strmapi: $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmapi/ft_strmapi

ft_strequ: $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strequ/ft_strequ

ft_strnequ: $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnequ/ft_strnequ

ft_strsub: $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsub/ft_strsub

ft_strjoin: $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strjoin/ft_strjoin

ft_strtrim: $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strtrim/ft_strtrim

ft_strsplit: $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsplit/ft_strsplit

ft_itoa: $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_itoa/ft_itoa

ft_putchar: $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar/ft_putchar

ft_putstr: $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr/ft_putstr

ft_putendl: $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl/ft_putendl

ft_putnbr: $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr/ft_putnbr

ft_putchar_fd: $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar_fd/ft_putchar_fd

ft_putstr_fd: $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr_fd/ft_putstr_fd

ft_putendl_fd: $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl_fd/ft_putendl_fd

ft_putnbr_fd: $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr_fd/ft_putnbr_fd

ft_lstnew: $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstnew/ft_lstnew

ft_lstdelone: $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdelone/ft_lstdelone

ft_lstdel: $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdel/ft_lstdel

ft_lstadd: $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstadd/ft_lstadd

ft_lstiter: $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstiter/ft_lstiter

ft_lstmap: $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstmap/ft_lstmap
