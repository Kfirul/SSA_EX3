.PHONY: clean all

CC = gcc
AR = ar -rcs
FLAGS = -Wall -g

#Making O files
isort.o: isort.c 
	$(CC) $(FLAGS) -c isort.c 

txtfind.o: txtfind.c 
	$(CC) $(FLAGS) -c txtfind.c 

#Making mains files
isort: isort.o 
	$(CC) $(FLAGS) isort.o -o isort 

txtfind: txtfind.o 
	$(CC) $(FLAGS) txtfind.o -o txtfind 

#

all: isort txtfind

clean: 
	rm -f *.o isort txtfind
	