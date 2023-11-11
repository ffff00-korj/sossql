build:
	gcc -Wall -g -c db.c
	gcc -Wall -g -c cli/tools.c
	gcc -Wall -g -c cli/commands.c
	gcc db.o tools.o commands.o -o db
	rm tools.o
	rm db.o
