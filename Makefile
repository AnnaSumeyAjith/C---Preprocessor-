
CC = gcc

mypreprocessor: main.o comment_removal.o file_inclusion.o macro_handler.o
	$(CC) main.o comment_removal.o file_inclusion.o macro_handler.o -o mypreprocessor

main.o: main.c
	$(CC) -c main.c

comment_removal.o: comment_removal.c
	$(CC) -c comment_removal.c

file_inclusion.o: file_inclusion.c
	$(CC) -c file_inclusion.c

macro_handler.o: macro_handler.c
	$(CC) -c macro_handler.c

clear:
	@echo "Cleaning up..."
	@rm -v *.o mypreprocessor.exe temp1.c temp2.c
