# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 19:05:04 by thakala           #+#    #+#              #
#    Updated: 2021/11/12 13:16:29 by thakala          ###   ########.fr        #
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
	ft_tolower

FUNCTIONS2 = \
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
	norminette $(foreach s, $(SRCS), $(addprefix $(LIB_ROOT)/, $(s)))
#	$(shell norminette $(foreach s, $(SRCS), $(addprefix $(LIB_ROOT)/, $(s))))

evaldirectories:
	mkdir -p $(foreach f, $(FUNCTIONS), $(addprefix $(PRG_DIR)/, $(f)))

foreach: subsystem
	$(foreach ft, $(FUNCTIONS), \
	$(CLANG) $(CPL_FLG) $(ft)/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/$(ft)/$(ft);)

foreach_debug: subsystem
	$(foreach ft, $(FUNCTIONS), \
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/$(ft).c $(ft)/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/$(ft)/$(ft);)

ft_memset: ft_memset/main.c
	$(CLANG) $(CPL_FLG) ft_memset/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memset/ft_memset

ft_bzero: ft_bzero/main.c
	$(CLANG) $(CPL_FLG) ft_bzero/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_bzero/ft_bzero

ft_memcpy: ft_memcpy/main.c
	$(CLANG) $(CPL_FLG) ft_memcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcpy/ft_memcpy

ft_memccpy: ft_memccpy/main.c
	$(CLANG) $(CPL_FLG) ft_memccpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memccpy/ft_memccpy

ft_memmove: ft_memmove/main.c
	$(CLANG) $(CPL_FLG) ft_memmove/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memmove/ft_memmove

ft_memchr: ft_memchr/main.c
	$(CLANG) $(CPL_FLG) ft_memchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memchr/ft_memchr

ft_memcmp: ft_memcmp/main.c
	$(CLANG) $(CPL_FLG) ft_memcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcmp/ft_memcmp

ft_strlen: ft_strlen/main.c
	$(CLANG) $(CPL_FLG) ft_strlen/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlen/ft_strlen

ft_strdup: ft_strdup/main.c
	$(CLANG) $(CPL_FLG) ft_strdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdup/ft_strdup

ft_strcpy: ft_strcpy/main.c
	$(CLANG) $(CPL_FLG) ft_strcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcpy/ft_strcpy

ft_strncpy: ft_strncpy/main.c
	$(CLANG) $(CPL_FLG) ft_strncpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncpy/ft_strncpy

ft_strcat: ft_strcat/main.c
	$(CLANG) $(CPL_FLG) ft_strcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcat/ft_strcat

ft_strncat: ft_strncat/main.c
	$(CLANG) $(CPL_FLG) ft_strncat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncat/ft_strncat

ft_strlcat: ft_strlcat/main.c
	$(CLANG) $(CPL_FLG) ft_strlcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlcat/ft_strlcat

ft_strchr: ft_strchr/main.c
	$(CLANG) $(CPL_FLG) ft_strchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strchr/ft_strchr

ft_strrchr: ft_strrchr/main.c
	$(CLANG) $(CPL_FLG) ft_strrchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strrchr/ft_strrchr

ft_strstr: ft_strstr/main.c
	$(CLANG) $(CPL_FLG) ft_strstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strstr/ft_strstr

ft_strnstr: ft_strnstr/main.c
	$(CLANG) $(CPL_FLG) ft_strnstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnstr/ft_strnstr

ft_strcmp: ft_strcmp/main.c
	$(CLANG) $(CPL_FLG) ft_strcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcmp/ft_strcmp

ft_strncmp: ft_strncmp/main.c
	$(CLANG) $(CPL_FLG) ft_strncmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncmp/ft_strncmp

ft_atoi: ft_atoi/main.c
	$(CLANG) $(CPL_FLG) ft_atoi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_atoi/ft_atoi

ft_isalpha: ft_isalpha/main.c
	$(CLANG) $(CPL_FLG) ft_isalpha/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalpha/ft_isalpha

ft_isdigit: ft_isdigit/main.c
	$(CLANG) $(CPL_FLG) ft_isdigit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isdigit/ft_isdigit

ft_isalnum: ft_isalnum/main.c
	$(CLANG) $(CPL_FLG) ft_isalnum/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalnum/ft_isalnum

ft_isascii: ft_isascii/main.c
	$(CLANG) $(CPL_FLG) ft_isascii/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isascii/ft_isascii

ft_isprint: ft_isprint/main.c
	$(CLANG) $(CPL_FLG) ft_isprint/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isprint/ft_isprint

ft_toupper: ft_toupper/main.c
	$(CLANG) $(CPL_FLG) ft_toupper/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_toupper/ft_toupper

ft_tolower: ft_tolower/main.c
	$(CLANG) $(CPL_FLG) ft_tolower/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_tolower/ft_tolower

ft_memalloc: ft_memalloc/main.c
	$(CLANG) $(CPL_FLG) ft_memalloc/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memalloc/ft_memalloc

ft_memdel: ft_memdel/main.c
	$(CLANG) $(CPL_FLG) ft_memdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdel/ft_memdel

ft_strnew: ft_strnew/main.c
	$(CLANG) $(CPL_FLG) ft_strnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnew/ft_strnew

ft_strdel: ft_strdel/main.c
	$(CLANG) $(CPL_FLG) ft_strdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdel/ft_strdel

ft_strclr: ft_strclr/main.c
	$(CLANG) $(CPL_FLG) ft_strclr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strclr/ft_strclr

ft_striter: ft_striter/main.c
	$(CLANG) $(CPL_FLG) ft_striter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striter/ft_striter

ft_striteri: ft_striteri/main.c
	$(CLANG) $(CPL_FLG) ft_striteri/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striteri/ft_striteri

ft_strmap: ft_strmap/main.c
	$(CLANG) $(CPL_FLG) ft_strmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmap/ft_strmap

ft_strmapi: ft_strmapi/main.c
	$(CLANG) $(CPL_FLG) ft_strmapi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmapi/ft_strmapi

ft_strequ: ft_strequ/main.c
	$(CLANG) $(CPL_FLG) ft_strequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strequ/ft_strequ

ft_strnequ: ft_strnequ/main.c
	$(CLANG) $(CPL_FLG) ft_strnequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnequ/ft_strnequ

ft_strsub: ft_strsub/main.c
	$(CLANG) $(CPL_FLG) ft_strsub/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsub/ft_strsub

ft_strjoin: ft_strjoin/main.c
	$(CLANG) $(CPL_FLG) ft_strjoin/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strjoin/ft_strjoin

ft_strtrim: ft_strtrim/main.c
	$(CLANG) $(CPL_FLG) ft_strtrim/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strtrim/ft_strtrim

ft_strsplit: ft_strsplit/main.c
	$(CLANG) $(CPL_FLG) ft_strsplit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsplit/ft_strsplit

ft_itoa: ft_itoa/main.c
	$(CLANG) $(CPL_FLG) ft_itoa/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_itoa/ft_itoa

ft_putchar: ft_putchar/main.c
	$(CLANG) $(CPL_FLG) ft_putchar/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar/ft_putchar

ft_putstr: ft_putstr/main.c
	$(CLANG) $(CPL_FLG) ft_putstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr/ft_putstr

ft_putendl: ft_putendl/main.c
	$(CLANG) $(CPL_FLG) ft_putendl/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl/ft_putendl

ft_putnbr: ft_putnbr/main.c
	$(CLANG) $(CPL_FLG) ft_putnbr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr/ft_putnbr

ft_putchar_fd: ft_putchar_fd/main.c
	$(CLANG) $(CPL_FLG) ft_putchar_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar_fd/ft_putchar_fd

ft_putstr_fd: ft_putstr_fd/main.c
	$(CLANG) $(CPL_FLG) ft_putstr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr_fd/ft_putstr_fd

ft_putendl_fd: ft_putendl_fd/main.c
	$(CLANG) $(CPL_FLG) ft_putendl_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl_fd/ft_putendl_fd

ft_putnbr_fd: ft_putnbr_fd/main.c
	$(CLANG) $(CPL_FLG) ft_putnbr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr_fd/ft_putnbr_fd

ft_lstnew: ft_lstnew/main.c
	$(CLANG) $(CPL_FLG) ft_lstnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstnew/ft_lstnew

ft_lstdelone: ft_lstdelone/main.c
	$(CLANG) $(CPL_FLG) ft_lstdelone/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdelone/ft_lstdelone

ft_lstdel: ft_lstdel/main.c
	$(CLANG) $(CPL_FLG) ft_lstdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdel/ft_lstdel

ft_lstadd: ft_lstadd/main.c
	$(CLANG) $(CPL_FLG) ft_lstadd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstadd/ft_lstadd

ft_lstiter: ft_lstiter/main.c
	$(CLANG) $(CPL_FLG) ft_lstiter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstiter/ft_lstiter

ft_lstmap: ft_lstmap/main.c
	$(CLANG) $(CPL_FLG) ft_lstmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstmap/ft_lstmap

ft_memset_debug: $(LIB_ROOT)/ft_memset.c ft_memset/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memset.c ft_memset/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memset/ft_memset

ft_bzero_debug: $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_bzero.c ft_bzero/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_bzero/ft_bzero

ft_memcpy_debug: $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memcpy.c ft_memcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcpy/ft_memcpy

ft_memccpy_debug: $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memccpy.c ft_memccpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memccpy/ft_memccpy

ft_memmove_debug: $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memmove.c ft_memmove/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memmove/ft_memmove

ft_memchr_debug: $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memchr.c ft_memchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memchr/ft_memchr

ft_memcmp_debug: $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memcmp.c ft_memcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memcmp/ft_memcmp

ft_strlen_debug: $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strlen.c ft_strlen/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlen/ft_strlen

ft_strdup_debug: $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strdup.c ft_strdup/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdup/ft_strdup

ft_strcpy_debug: $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strcpy.c ft_strcpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcpy/ft_strcpy

ft_strncpy_debug: $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strncpy.c ft_strncpy/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncpy/ft_strncpy

ft_strcat_debug: $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strcat.c ft_strcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcat/ft_strcat

ft_strncat_debug: $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strncat.c ft_strncat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncat/ft_strncat

ft_strlcat_debug: $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strlcat.c ft_strlcat/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strlcat/ft_strlcat

ft_strchr_debug: $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strchr.c ft_strchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strchr/ft_strchr

ft_strrchr_debug: $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strrchr.c ft_strrchr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strrchr/ft_strrchr

ft_strstr_debug: $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strstr.c ft_strstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strstr/ft_strstr

ft_strnstr_debug: $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strnstr.c ft_strnstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnstr/ft_strnstr

ft_strcmp_debug: $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strcmp.c ft_strcmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strcmp/ft_strcmp

ft_strncmp_debug: $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strncmp.c ft_strncmp/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strncmp/ft_strncmp

ft_atoi_debug: $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_atoi.c ft_atoi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_atoi/ft_atoi

ft_isalpha_debug: $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_isalpha.c ft_isalpha/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalpha/ft_isalpha

ft_isdigit_debug: $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_isdigit.c ft_isdigit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isdigit/ft_isdigit

ft_isalnum_debug: $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_isalnum.c ft_isalnum/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isalnum/ft_isalnum

ft_isascii_debug: $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_isascii.c ft_isascii/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isascii/ft_isascii

ft_isprint_debug: $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_isprint.c ft_isprint/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_isprint/ft_isprint

ft_toupper_debug: $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_toupper.c ft_toupper/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_toupper/ft_toupper

ft_tolower_debug: $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_tolower.c ft_tolower/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_tolower/ft_tolower

ft_memalloc_debug: $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memalloc.c ft_memalloc/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memalloc/ft_memalloc

ft_memdel_debug: $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_memdel.c ft_memdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_memdel/ft_memdel

ft_strnew_debug: $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strnew.c ft_strnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnew/ft_strnew

ft_strdel_debug: $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strdel.c ft_strdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strdel/ft_strdel

ft_strclr_debug: $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strclr.c ft_strclr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strclr/ft_strclr

ft_striter_debug: $(LIB_ROOT)/ft_striter.c ft_striter/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_striter.c ft_striter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striter/ft_striter

ft_striteri_debug: $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_striteri.c ft_striteri/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_striteri/ft_striteri

ft_strmap_debug: $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strmap.c ft_strmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmap/ft_strmap

ft_strmapi_debug: $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strmapi.c ft_strmapi/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strmapi/ft_strmapi

ft_strequ_debug: $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strequ.c ft_strequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strequ/ft_strequ

ft_strnequ_debug: $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strnequ.c ft_strnequ/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strnequ/ft_strnequ

ft_strsub_debug: $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strsub.c ft_strsub/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsub/ft_strsub

ft_strjoin_debug: $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strjoin.c ft_strjoin/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strjoin/ft_strjoin

ft_strtrim_debug: $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strtrim.c ft_strtrim/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strtrim/ft_strtrim

ft_strsplit_debug: $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_strsplit.c ft_strsplit/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_strsplit/ft_strsplit

ft_itoa_debug: $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_itoa.c ft_itoa/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_itoa/ft_itoa

ft_putchar_debug: $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putchar.c ft_putchar/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar/ft_putchar

ft_putstr_debug: $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putstr.c ft_putstr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr/ft_putstr

ft_putendl_debug: $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putendl.c ft_putendl/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl/ft_putendl

ft_putnbr_debug: $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putnbr.c ft_putnbr/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr/ft_putnbr

ft_putchar_fd_debug: $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putchar_fd.c ft_putchar_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putchar_fd/ft_putchar_fd

ft_putstr_fd_debug: $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putstr_fd.c ft_putstr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putstr_fd/ft_putstr_fd

ft_putendl_fd_debug: $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putendl_fd.c ft_putendl_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putendl_fd/ft_putendl_fd

ft_putnbr_fd_debug: $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_putnbr_fd.c ft_putnbr_fd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_putnbr_fd/ft_putnbr_fd

ft_lstnew_debug: $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_lstnew.c ft_lstnew/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstnew/ft_lstnew

ft_lstdelone_debug: $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_lstdelone.c ft_lstdelone/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdelone/ft_lstdelone

ft_lstdel_debug: $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_lstdel.c ft_lstdel/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstdel/ft_lstdel

ft_lstadd_debug: $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_lstadd.c ft_lstadd/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstadd/ft_lstadd

ft_lstiter_debug: $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_lstiter.c ft_lstiter/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstiter/ft_lstiter

ft_lstmap_debug: $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c
	$(CLANG) $(CPL_DEBUG) $(LIB_ROOT)/ft_lstmap.c ft_lstmap/main.c \
		-L$(LIB_ROOT) -lft -o $(PRG_DIR)/ft_lstmap/ft_lstmap
