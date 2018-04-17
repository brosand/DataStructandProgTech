##
# Homework 6
#
# @file
# @version 0.1

CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: shrink

shrink: shrink.o openHash.o #array.o
	$(CC) $(CFLAGS) -o $@ $^
	echo "shrink built"

shrink.o: shrink.c shrink.h
# intChainHash.o: intChainHash.c intChainHash.h
array.o: array.c array.h

openHash.o : openHash.c openHash.h

test: shrink
	./shrink.c

clean:
	$(RM) shrink *.o
# end
