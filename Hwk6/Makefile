##
# Homework 6
#
# @file
# @version 0.1

CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: treeSort

treeSort: treeSort.o tree.o
	$(CC) $(CFLAGS) -o $@ $^
	echo "treeSort built"

treeSort.o: treeSort.c treeSort.h
# intChainHash.o: intChainHash.c intChainHash.h
tree.o: tree.c tree.h

test: treeSort
	./treeSort.c

clean:
	$(RM) treeSort *.o
# end
