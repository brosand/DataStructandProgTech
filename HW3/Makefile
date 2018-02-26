##
# HW3 -- Num
#
# @file
# @version 0.1
CC=gcc
CFLAGS=-g3 -Wall -ansi -pedantic

all:

test: test-num
	./test-num
	@echo OK!

test-num: test-num.o tester.o num.o
	$(CC) $(CFLAGS) -o $@ $^

test-num.o: num.h tester.h
num.o: num.h

# end
# 
