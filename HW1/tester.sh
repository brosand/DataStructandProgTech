#!/bin/bash
test="test"
for i in $(ls *.in); do
	./a.out <$i> "$i$test"
done
