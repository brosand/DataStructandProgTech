#!/usr/bin/env bash
FILES="/mnt/c/Users/brosa/OneDrive/Yale/Sopho/Semester_2/CS223/Hwk4/testFiles/*.in"
for f in $FILES
do
echo "Processing $f file..."
valgrind --leak-check=full --log-file=valsh.out --error-exitcode=1 ./testDeck < $f > valshDeck.out
ret=$?
if [ $ret -eq 1 ]
then echo "check failed";
else echo "check passed";
fi
# echo $f
# take action on each file. $f store current file name
# cat $f
done
