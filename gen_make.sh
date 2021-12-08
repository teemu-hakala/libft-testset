#!/bin/bash

for v in "$@"; do
	echo "$v: subsystem $v/main.c"
	echo "	\$(CLANG) \$(CPL_FLG) \$(LIB_ROOT)/$v.c $v/main.c \\"
	echo "		-L\$(LIB_ROOT) -lft -o \$(PRG_DIR)/$v/$v"
	echo ""
done


for v in "$@"; do
	#echo "\$(PRG_DIR)/$v/$v: \$(SRC_DIR)/$v.c \\"
	#echo "$v/main.c"
	echo -n "$v"
	echo "_debug: \$(LIB_ROOT)/$v.c $v/main.c"
	echo "	\$(CLANG) \$(CPL_FLG) \$(LIB_ROOT)/$v.c $v/main.c \\"
	echo "		-L\$(LIB_ROOT) -lft -o \$(PRG_DIR)/$v/$v"
	echo ""
done

<< 'MULTILINE-COMMENT'
for v in "$@"; do
	echo "\$(PRG_DIR)/$v/$v \\"
done

for v in "$@"; do
	echo "$v \\"
done
MULTILINE-COMMENT
