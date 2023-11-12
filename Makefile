build:
	gcc -Wall -g -c src/main.c
	gcc -Wall -g -c src/tools.c
	gcc -Wall -g -c src/commands.c
	gcc main.o tools.o commands.o -o db
	rm tools.o
	rm commands.o
	rm main.o
