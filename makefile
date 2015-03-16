# Searches Makefile
# March 10th, 2015

CC=g++
CFLAGS= -c -g

all: driver

driver: Driver.o Searches.o
	$(CC) -o Driver Driver.o Searches.o

Driver.o: Driver.cpp
	$(CC) $(CFLAGS) Driver.cpp

Searches.o: Searches.cpp
	$(CC) $(CFLAGS) Searches.cpp

clean:
	rm -rf *.o Driver
