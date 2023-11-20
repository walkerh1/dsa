CC = gcc
CCFLAGS = -Wall -Werror -std=c11

circular-vector-test : circular-vector-test.o circular-vector.o
	$(CC) -o circular-vector-test circular-vector-test.o circular-vector.o

circular-vector-test.o : circular-vector-test.c circular-vector.h
	$(CC) $(CCFLAGS) -c circular-vector-test.c

circular-vector.o : circular-vector.c circular-vector.h
	$(CC) $(CCFLAGS) -c circular-vector.c

clean:
	rm -f circular-vector-test *.o