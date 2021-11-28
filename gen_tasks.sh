#!/bin/bash
s="ft_memset
ft_bzero
ft_memcpy
ft_memccpy
ft_memmove
ft_memchr
ft_memcmp
ft_strlen
ft_strdup
ft_strcpy
ft_strncpy
ft_strcat
ft_strncat
ft_strlcat
ft_strchr
ft_strrchr
ft_strstr
ft_strnstr
ft_strcmp
ft_strncmp
ft_atoi
ft_isalpha
ft_isdigit
ft_isalnum
ft_isascii
ft_isprint
ft_toupper
ft_tolower
ft_memalloc
ft_memdel
ft_strnew
ft_strdel
ft_strclr
ft_striter
ft_striteri
ft_strmap
ft_strmapi
ft_strequ
ft_strnequ
ft_strsub
ft_strjoin
ft_strtrim
ft_strsplit
ft_itoa
ft_putchar
ft_putstr
ft_putendl
ft_putnbr
ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd
ft_lstnew
ft_lstdelone
ft_lstdel
ft_lstadd
ft_lstiter
ft_lstmap
ft_memdup
ft_isspace
ft_strpbrk
ft_strsep
ft_strspn"

for v in $s; do
echo "		{"
echo "			\"type\": \"cppbuild\","
echo "			\"label\": \"C/C++: clang build $v\","
echo "			\"command\": \"/usr/bin/clang\","
echo "			\"args\": ["
echo "				\"-g\","
echo "				\"-Wall\","
echo "				\"-Werror\","
echo "				\"-Wextra\","
echo "				\"-Wconversion\","
echo "				\"\${workspaceFolder}/libft-testset/$v/main.c\","
echo "				\"\${workspaceFolder}/libft/$v.c\","
echo "				\"-L\${workspaceFolder}/libft\","
echo "				\"-lft\","
echo "				\"-o\","
echo "				\"\${workspaceFolder}/libft-testset/_programs/$v/$v\""
echo "			],"
echo "			\"options\": {"
echo "				\"cwd\": \"\${workspaceFolder}\""
echo "			},"
echo "			\"problemMatcher\": ["
echo "				\"\$gcc\""
echo "			],"
echo "			\"group\": \"build\","
echo "			\"detail\": \"compiler: /usr/bin/clang\""
echo "		},"
echo ""
done
