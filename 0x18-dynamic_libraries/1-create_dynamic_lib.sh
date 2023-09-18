#!/bin/bash
# Script to create a dynamic library from all .c files in the current directory

# Compile all .c files into object files
gcc -c -fPIC -Wall -Werror -Wextra -pedantic *.c

# Create a dynamic library from all object files
gcc -shared -o liball.so *.o
