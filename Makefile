# Makefile
#

compile-transpiler:
	gcc transpiler.c lexer.c parser.c -o transpiler
