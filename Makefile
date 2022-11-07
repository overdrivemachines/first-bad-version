
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

first-bad-version: first-bad-version.o
	$(CC) $(CFLAGS) -o first-bad-version first-bad-version.o

first-bad-version.o: first-bad-version.cpp
	$(CC) $(CFLAGS) -c first-bad-version.cpp

clean:
	rm -rf first-bad-version first-bad-version.o
