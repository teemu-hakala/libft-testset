#!/bin/bash

i=0;
for function in "$@";
do
	((i++));
done

echo "{"
echo "	// Use IntelliSense to learn about possible attributes."
echo "	// Hover to view descriptions of existing attributes."
echo "	// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387"
echo "	\"version\": \"0.2.0\","
echo "	\"configurations\": ["

cat mainlaunch

for function in "$@"; do
	echo "		{"
	echo "			\"name\": \"clang - $function build and debug\","
	echo "			\"type\": \"cppdbg\","
	echo "			\"request\": \"launch\","
	echo "			\"program\": \"\${workspaceFolder}/libft-testset/_programs/$function/$function\","
	echo "			\"args\": [],"
	echo "			\"stopAtEntry\": false,"
	echo "			\"cwd\": \"\${workspaceFolder}\","
	echo "			\"environment\": [],"
	echo "			\"externalConsole\": false,"
	echo "			\"MIMode\": \"lldb\","
	echo "			\"preLaunchTask\": \"C/C++: clang build $function\""
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
