CFLAGS=-Wall -Werror -Wextra
CC=gcc


all: build


build: parse.o stack.o token.o graph.o draw.o check_string.o postfix.o
	$(CC) -Wall -Werror -Wextra parse.o stack.o token.o graph.o draw.o check_string.o postfix.o -lm -o graph

parse.o:
	$(CC) -c -Wall -Werror -Wextra parse.c
stack.o:
	$(CC) -c -Wall -Werror -Wextra stack.c
	
token.o:
	$(CC) -c -Wall -Werror -Wextra token.c

graph.o:
	$(CC) -c -Wall -Werror -Wextra graph.c

draw.o:
	$(CC) -c -Wall -Werror -Wextra draw.c

check_string.o:
	$(CC) -c -Wall -Werror -Wextra check_string.c

postfix.o:
	$(CC) -c -Wall -Werror -Wextra postfix.c

clean:
	rm -rf parse.o stack.o token.o graph.o draw.o check_string.o postfix.o ./graph

rebuild: clean all
