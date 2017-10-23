#!/usr/bin/bash

Directory=$1
cd $Directory

#using find with the . argument allows for recursion. It is given the -type tag with f specified for file. This is then piped to a count, which all is passed to the files variable

files=$(find . -type f|wc -l)

#essentially the same thing is done here, but simply for type d for directories.
directories=$(find . -type d|wc -l)
echo "Processed all the files from $Directory."
echo "There were $directories directories."
echo "There were $files regular files."
