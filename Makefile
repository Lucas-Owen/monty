all:
	gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -g -o monty
clean:
	rm -rf monty
