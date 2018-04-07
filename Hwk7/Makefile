##
# Homework 6
#
# @file
# @version 0.1

CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: testArray

testArray: testArray.o array.o
	$(CC) $(CFLAGS) -o $@ $^
	echo "testArray built"

testArray.o: testArray.c #testArray.h
# intChainHash.o: intChainHash.c intChainHash.h
array.o: array.c array.h

test: testArray
	./testArray.c

clean:
	$(RM) testArray *.o
# end
