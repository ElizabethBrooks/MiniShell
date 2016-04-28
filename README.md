#MiniShell
Mini shell for performing basic terminal functions.

##The shell has the following features:
1. exit [n] terminates the shell program.
2. mkdir [dir] uses the mkdir() standard library to create a DEFAULT directory. If a
parameter (dir) is provided, the directory with the given name (dir) will be considered.
3. ls lists the content of the current directory.
4. cmp <filename1> <filename2> compares two files and returns the first byte where a difference occurs, if any.

##To compile:
1. $ gcc -o test MiniShell.cpp
2. $ ./test

####Name: Elizabeth Brooks
####Date Modified: April 28, 2016
####File: CS470 Lab1
