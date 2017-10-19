#include <stdlib.h>
#include <stdio.h>
#include "file_disemvowel.h"
#include <stdbool.h>

#define BUF_SIZE 1024


// checks if the current character is a value will return 1, if the current character is a vowel and 0 otherwise.
int is_vowel(char c) {
 char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','\0'};
 for (int i = 0; i < 10; i++){
 	if(c==vowels[i]){
		return 1;
	}
 }
 return 0;
}

// takes an integer (the length of the string passed in), an in string, and an out string.  
// this function copies all the characters from the instring that are not vowels, into the out string.
int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int copyCount = 0;
	for (int i = 0; i<num_chars;i++){
 		if(is_vowel(in_buf[i])==0){
			out_buf[copyCount] = in_buf[i];
			copyCount++;	
		}
 	}
	out_buf[copyCount] = '\0';
	return copyCount;	
}
// function that takes a file as an argument, to read from, then prints out the
// resulting file without any vowels.
void disemvowelOneArg(FILE* inputFile) {
	char* in_buf = calloc(BUF_SIZE, sizeof(char));
	char* out_buf = calloc(BUF_SIZE, sizeof(char));
	while(fgets(in_buf,sizeof(in_buf),inputFile) != NULL){
		int count = 0;
		while(in_buf[count] != '\0'){
			count++;
		}
		copy_non_vowels(count, in_buf, out_buf);
		printf("%s", out_buf);
	}
free(in_buf);
free(out_buf);
fclose(inputFile);
}
// takes both a file to read from, and a new file to write to.  Will write
// a new file with the input files text, without the vowels
void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* in_buf = calloc(BUF_SIZE, sizeof(char));
	char* out_buf = calloc(BUF_SIZE, sizeof(char));
	while(fgets(in_buf,sizeof(in_buf),inputFile) != NULL){
	int count = 0;
	while(in_buf[count] != '\0'){
		count++;
	}
	copy_non_vowels(count, in_buf, out_buf);
	if(outputFile != NULL){
		fputs(out_buf, outputFile);
		
	}
}
free(in_buf);
free(out_buf);
fclose(outputFile);
fclose(inputFile);
}



// Method that handles the following argument cases
// 2 arguments, one inputfile and one output file
// 1 argument, a file to read from
// no arguments, strings are read from the command line.
int main(int argc, char *argv[]) {
 FILE *inputFile;
 FILE *outputFile;
if(argc > 2){
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w+");
	disemvowel(inputFile, outputFile);
} else if(argc == 2){
	inputFile = fopen(argv[1], "r");
	disemvowelOneArg(inputFile);
} else if(argc == 1){
	char* line;
	size_t size;
	char* noVowels;
	size = BUF_SIZE;
	noVowels = (char*) calloc(BUF_SIZE + 1, sizeof(char));
	line = (char*) calloc(BUF_SIZE + 1, sizeof(char));
	while(getline(&line, &size, stdin) > 0){
		int count = 0;
		while(line[count]!='\0'){
                        count++;
                }
		copy_non_vowels(count,line,noVowels);
		printf("%s",noVowels);
	}
	free(noVowels);
	free(line);
	

}
 return 0;
}




