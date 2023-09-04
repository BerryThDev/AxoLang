all:
	gcc main.c lexer.c token.c -o main 

clean:
	rm -rf main

