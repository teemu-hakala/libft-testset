#!/bin/bash

i=0;
for function in "$@";
do
	((i++));
	#echo $i;
done

echo "{"
echo "	\"version\": \"2.0.0\","
echo "	\"tasks\": ["

for ft in "$@"; do
	echo "		{"
	echo "			\"type\": \"cppbuild\","
	echo "			\"label\": \"C/C++: clang build $ft\","
	echo "			\"command\": \"/usr/bin/clang\","
	echo "			\"args\": ["
	echo "				\"-g\","
	echo "				\"-Wall\","
	echo "				\"-Werror\","
	echo "				\"-Wextra\","
	echo "				\"-Wconversion\","
	echo "				\"\${workspaceFolder}/libft-testset/$ft/main.c\","
	echo "				\"\${workspaceFolder}/libft/$ft.c\","
	echo "				\"-L\${workspaceFolder}/libft\","
	echo "				\"-lft\","
	echo "				\"-o\","
	echo "				\"\${workspaceFolder}/libft-testset/_programs/$ft/$ft\""
	echo "			],"
	echo "			\"options\": {"
	echo "				\"cwd\": \"\${workspaceFolder}\""
	echo "			},"
	echo "			\"problemMatcher\": ["
	echo "				\"\$gcc\""
	echo "			],"
	echo "			\"group\": \"build\","
	echo "			\"detail\": \"compiler: /usr/bin/clang\""
	((i--));
	if ((i != 0)); then
		echo "		},"
	else
		echo "		}"
	fi
	echo ""
done

echo "	]"
echo "}"
