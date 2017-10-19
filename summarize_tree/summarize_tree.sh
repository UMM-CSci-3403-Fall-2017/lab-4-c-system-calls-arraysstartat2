#!/usr/bin/bash

Directory=$1
cd $Directory
files=$(find . -type f|wc -l)
directories=$(find . -type d|wc -l)
echo "Processed all the files from $Directory."
echo "There were $directories directories."
echo "There were $files regular files."
