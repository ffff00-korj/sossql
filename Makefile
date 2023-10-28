build:
	gcc -Wall -g -c db.c
	gcc -Wall -g -c cli/tools.c
	gcc db.o tools.o -o db
	rm tools.o
	rm db.o
