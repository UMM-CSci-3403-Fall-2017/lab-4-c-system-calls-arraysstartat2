#include <stdlib.h>
#include <stdio.h>
#include "file_disemvowel.h"
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
 char vowels = {'a','e','i','o','u','A','E','I','O','U'};
 for (int i = 0; i < 10; i++){
 	if(c==vowels[i]){
		return true;
	}
 }
 return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int copyCount = 0;
	for (int i = 0; i<num_chars;i++){
 		if(is_vowel(int_buf[i])){
			out_buf[copyCount] = in_buf[i];
			copyCount++;	
		}
 	}
	return copyCount;	
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* in_buf = calloc(BUF_SIZE, sizeof(char));
	char* out_buf = calloc(BUF_SIZE, sizeof(char));
	inFile = fopen(inputFile, "w+");
	outFile = fopen(outputFile, "w+");
	while(char c != '\0'){
		
	}
	fwrite(
	fwrite(inputFile,	
}


int main(int argc, char *argv[]) {
 FILE *inputFile;
 FILE *outputFile;

 disemvowel(inputFile, outputFile);
 
 return 0;
}




