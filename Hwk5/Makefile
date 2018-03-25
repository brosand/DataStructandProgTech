##
# Homework 5
#
# @file
# @version 0.1

CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: ants

ants: ants.o intChainHash.o
	$(CC) $(CFLAGS) -o $@ $^
	echo "ants built"

ants.o: ants.c ants.h
intChainHash.o: intChainHash.c intChainHash.h

test: ants
	./ants.c

clean:
	$(RM) ants *.o
# end
