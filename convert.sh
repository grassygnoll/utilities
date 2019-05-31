#!/bin/bash

infile=$1

function showUsage() {
   echo "USAGE: $0 <file>"
   echo 
   echo "Accepts images.html (and images(2).html) input from Cellebrite HTML output report"
   echo "and converts them to multiple line (versus one long line) and removes \"<img\" tags"
   echo 
   exit 1
}

if [ -z $infile ] 
then
   echo "ERROR: no input file supplied"
   showUsage
fi

dos2unix -n $infile $infile.d2u
cat $infile.d2u | sed -e 's/<table>/\n<table>\n/g' -e 's/<\/table>/\n<\/table>\n/g' \
                      -e 's/<img src=[[:print:]]*\"middle\" \/>//g' > $infile.new

exit 0
