# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 19:05:04 by thakala           #+#    #+#              #
#    Updated: 2021/11/28 18:24:40 by thakala          ###   ########.fr        #
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
	ft_itoa

FUNCTIONS2 = \
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
	ft_memdup \
	ft_isspace \
	ft_strpbrk \
	ft_strsep \
	ft_strspn

FUNCTIONS_ALL = \
	$(FUNCTIONS) \
	$(FUNCTIONS2) \
	$(FUNCTIONS_BONUS)

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

FUNCTIONS_DEBUG = $(foreach ft, $(FUNCTIONS), $(addsuffix _debug, $(ft)))

CLANG = gcc

CPL_FLG = -Wall -Wextra -Werror

CPL_FLG_EXTRA = -Wconversion

CPL_FLAGS = $(CPL_FLG) $(CPL_FLG_EXTRA)

CPL_DEBUG = -g $(CPL_FLG)

LIB_NAME = libft

LIB_ROOT = ../$(LIB_NAME)

PRG_DIR = _programs

.PHONY: $(FUNCTIONS) all subsystem norminette evaldirectories foreach \
	foreach_debug

all: subsystem \
	norminette \
	evaldirectories \
	$(FUNCTIONS)

debug: subsystem \
	norminette \
	evaldirectories \
	$(FUNCTIONS_DEBUG)

#Compile libft.a
subsystem:
	$(MAKE) -C $(LIB_ROOT)

norminette:
	norminette $(LIB_ROOT)
#	norminette $(foreach s, $(SRCS), $(addprefix $(LIB_ROOT)/, $(s)))
#	$(shell norminette $(foreach s, $(SRCS), $(addprefix $(LIB_ROOT)/, $(s))))

evaldirectories:
	mkdir -p $(foreach f, $(FUNCTIONS_ALL), $(addprefix $(PRG_DIR)/, $(f)))

foreach: subsystem
	$(foreach ft, $(FUNCTIONS), \
	$(CLANG) $(CPL_FLG) $(ft)/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/$(ft)/$(ft);)
ft_memset: subsystem ft_memset/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memset.c ft_memset/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memset/ft_memset

ft_bzero: subsystem ft_bzero/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_bzero/ft_bzero

ft_memcpy: subsystem ft_memcpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcpy/ft_memcpy

ft_memccpy: subsystem ft_memccpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memccpy/ft_memccpy

ft_memmove: subsystem ft_memmove/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memmove/ft_memmove

ft_memchr: subsystem ft_memchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memchr/ft_memchr

ft_memcmp: subsystem ft_memcmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcmp/ft_memcmp

ft_strlen: subsystem ft_strlen/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlen/ft_strlen

ft_strdup: subsystem ft_strdup/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdup/ft_strdup

ft_strcpy: subsystem ft_strcpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcpy/ft_strcpy

ft_strncpy: subsystem ft_strncpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncpy/ft_strncpy

ft_strcat: subsystem ft_strcat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcat/ft_strcat

ft_strncat: subsystem ft_strncat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncat/ft_strncat

ft_strlcat: subsystem ft_strlcat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlcat/ft_strlcat

ft_strchr: subsystem ft_strchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strchr/ft_strchr

ft_strrchr: subsystem ft_strrchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strrchr/ft_strrchr

ft_strstr: subsystem ft_strstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strstr/ft_strstr

ft_strnstr: subsystem ft_strnstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnstr/ft_strnstr

ft_strcmp: subsystem ft_strcmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcmp/ft_strcmp

ft_strncmp: subsystem ft_strncmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncmp/ft_strncmp

ft_atoi: subsystem ft_atoi/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_atoi/ft_atoi

ft_isalpha: subsystem ft_isalpha/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalpha/ft_isalpha

ft_isdigit: subsystem ft_isdigit/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isdigit/ft_isdigit

ft_isalnum: subsystem ft_isalnum/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalnum/ft_isalnum

ft_isascii: subsystem ft_isascii/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isascii/ft_isascii

ft_isprint: subsystem ft_isprint/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isprint/ft_isprint

ft_toupper: subsystem ft_toupper/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_toupper/ft_toupper

ft_tolower: subsystem ft_tolower/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_tolower/ft_tolower

ft_memalloc: subsystem ft_memalloc/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memalloc/ft_memalloc

ft_memdel: subsystem ft_memdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdel/ft_memdel

ft_strnew: subsystem ft_strnew/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnew/ft_strnew

ft_strdel: subsystem ft_strdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdel/ft_strdel

ft_strclr: subsystem ft_strclr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strclr/ft_strclr

ft_striter: subsystem ft_striter/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_striter.c ft_striter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striter/ft_striter

ft_striteri: subsystem ft_striteri/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striteri/ft_striteri

ft_strmap: subsystem ft_strmap/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmap/ft_strmap

ft_strmapi: subsystem ft_strmapi/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmapi/ft_strmapi

ft_strequ: subsystem ft_strequ/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strequ/ft_strequ

ft_strnequ: subsystem ft_strnequ/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnequ/ft_strnequ

ft_strsub: subsystem ft_strsub/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsub/ft_strsub

ft_strjoin: subsystem ft_strjoin/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strjoin/ft_strjoin

ft_strtrim: subsystem ft_strtrim/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strtrim/ft_strtrim

ft_strsplit: subsystem ft_strsplit/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsplit/ft_strsplit

ft_itoa: subsystem ft_itoa/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_itoa/ft_itoa

ft_putchar: subsystem ft_putchar/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar/ft_putchar

ft_putstr: subsystem ft_putstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr/ft_putstr

ft_putendl: subsystem ft_putendl/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl/ft_putendl

ft_putnbr: subsystem ft_putnbr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr/ft_putnbr

ft_putchar_fd: subsystem ft_putchar_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar_fd/ft_putchar_fd

ft_putstr_fd: subsystem ft_putstr_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr_fd/ft_putstr_fd

ft_putendl_fd: subsystem ft_putendl_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl_fd/ft_putendl_fd

ft_putnbr_fd: subsystem ft_putnbr_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr_fd/ft_putnbr_fd

ft_lstnew: subsystem ft_lstnew/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstnew/ft_lstnew

ft_lstdelone: subsystem ft_lstdelone/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdelone/ft_lstdelone

ft_lstdel: subsystem ft_lstdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdel/ft_lstdel

ft_lstadd: subsystem ft_lstadd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstadd/ft_lstadd

ft_lstiter: subsystem ft_lstiter/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstiter/ft_lstiter

ft_lstmap: subsystem ft_lstmap/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstmap/ft_lstmap

ft_memdup: subsystem ft_memdup/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memdup.c ft_memdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdup/ft_memdup

ft_isspace: subsystem ft_isspace/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isspace.c ft_isspace/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isspace/ft_isspace

ft_strpbrk: subsystem ft_strpbrk/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strpbrk.c ft_strpbrk/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strpbrk/ft_strpbrk

ft_strsep: subsystem ft_strsep/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsep.c ft_strsep/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsep/ft_strsep

ft_strspn: subsystem ft_strspn/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strspn.c ft_strspn/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strspn/ft_strspn

ft_memset_debug: $(LIB_ROOT)/ft_memset.c ft_memset/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memset.c ft_memset/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memset/ft_memset

ft_bzero_debug: $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_bzero/ft_bzero

ft_memcpy_debug: $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcpy/ft_memcpy

ft_memccpy_debug: $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memccpy/ft_memccpy

ft_memmove_debug: $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memmove/ft_memmove

ft_memchr_debug: $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memchr/ft_memchr

ft_memcmp_debug: $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcmp/ft_memcmp

ft_strlen_debug: $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlen/ft_strlen

ft_strdup_debug: $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdup/ft_strdup

ft_strcpy_debug: $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcpy/ft_strcpy

ft_strncpy_debug: $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncpy/ft_strncpy

ft_strcat_debug: $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcat/ft_strcat

ft_strncat_debug: $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncat/ft_strncat

ft_strlcat_debug: $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlcat/ft_strlcat

ft_strchr_debug: $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strchr/ft_strchr

ft_strrchr_debug: $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strrchr/ft_strrchr

ft_strstr_debug: $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strstr/ft_strstr

ft_strnstr_debug: $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnstr/ft_strnstr

ft_strcmp_debug: $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcmp/ft_strcmp

ft_strncmp_debug: $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncmp/ft_strncmp

ft_atoi_debug: $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_atoi/ft_atoi

ft_isalpha_debug: $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalpha/ft_isalpha

ft_isdigit_debug: $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isdigit/ft_isdigit

ft_isalnum_debug: $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalnum/ft_isalnum

ft_isascii_debug: $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isascii/ft_isascii

ft_isprint_debug: $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isprint/ft_isprint

ft_toupper_debug: $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_toupper/ft_toupper

ft_tolower_debug: $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_tolower/ft_tolower

ft_memalloc_debug: $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memalloc/ft_memalloc

ft_memdel_debug: $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdel/ft_memdel

ft_strnew_debug: $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnew/ft_strnew

ft_strdel_debug: $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdel/ft_strdel

ft_strclr_debug: $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strclr/ft_strclr

ft_striter_debug: $(LIB_ROOT)/ft_striter.c ft_striter/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_striter.c ft_striter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striter/ft_striter

ft_striteri_debug: $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striteri/ft_striteri

ft_strmap_debug: $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmap/ft_strmap

ft_strmapi_debug: $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmapi/ft_strmapi

ft_strequ_debug: $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strequ/ft_strequ

ft_strnequ_debug: $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnequ/ft_strnequ

ft_strsub_debug: $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsub/ft_strsub

ft_strjoin_debug: $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strjoin/ft_strjoin

ft_strtrim_debug: $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strtrim/ft_strtrim

ft_strsplit_debug: $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsplit/ft_strsplit

ft_itoa_debug: $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_itoa/ft_itoa

ft_putchar_debug: $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar/ft_putchar

ft_putstr_debug: $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr/ft_putstr

ft_putendl_debug: $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl/ft_putendl

ft_putnbr_debug: $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr/ft_putnbr

ft_putchar_fd_debug: $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar_fd/ft_putchar_fd

ft_putstr_fd_debug: $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr_fd/ft_putstr_fd

ft_putendl_fd_debug: $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl_fd/ft_putendl_fd

ft_putnbr_fd_debug: $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr_fd/ft_putnbr_fd

ft_lstnew_debug: $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstnew/ft_lstnew

ft_lstdelone_debug: $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdelone/ft_lstdelone

ft_lstdel_debug: $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdel/ft_lstdel

ft_lstadd_debug: $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstadd/ft_lstadd

ft_lstiter_debug: $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstiter/ft_lstiter

ft_lstmap_debug: $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstmap/ft_lstmap

ft_memdup_debug: $(LIB_ROOT)/ft_memdup.c ft_memdup/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_memdup.c ft_memdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdup/ft_memdup

ft_isspace_debug: $(LIB_ROOT)/ft_isspace.c ft_isspace/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_isspace.c ft_isspace/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isspace/ft_isspace

ft_strpbrk_debug: $(LIB_ROOT)/ft_strpbrk.c ft_strpbrk/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strpbrk.c ft_strpbrk/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strpbrk/ft_strpbrk

ft_strsep_debug: $(LIB_ROOT)/ft_strsep.c ft_strsep/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strsep.c ft_strsep/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsep/ft_strsep

ft_strspn_debug: $(LIB_ROOT)/ft_strspn.c ft_strspn/main.c
	$(CLANG) $(CPL_FLG) $(LIB_ROOT)/ft_strspn.c ft_strspn/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strspn/ft_strspn
