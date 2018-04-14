#!/usr/bin/env bash
FILES="/home/accts/br384/cs223/Hwk7/testFiles/*.in"
for f in $FILES
do
echo "Processing $f file..."
valgrind --leak-check=full --log-file=valsh.out --error-exitcode=1 ./testArray < $f > valshDeck.out
ret=$?
if [ $ret -eq 1 ]
then echo "check failed";
else echo "check passed";
fi
# echo $f
# take action on each file. $f store current file name
# cat $f
done
