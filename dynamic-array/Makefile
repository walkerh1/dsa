CC = gcc
CCFLAGS = -Wall -Werror -std=c11

vector-test : vector-test.o vector.o
	$(CC) -o vector-test vector-test.o vector.o

vector-test.o : vector-test.c vector.h
	$(CC) $(CCFLAGS) -c vector-test.c

vector.o : vector.c vector.h
	$(CC) $(CCFLAGS) -c vector.c

clean:
	rm -f vector-test *.o