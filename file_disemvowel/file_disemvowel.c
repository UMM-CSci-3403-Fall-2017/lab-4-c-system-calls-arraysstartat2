#include <stdlib.h>
#include <stdio.h>
#include "file_disemvowel.h"
#include <stdbool.h>

#define BUF_SIZE 1024

int is_vowel(char c) {
 char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','\0'};
 for (int i = 0; i < 10; i++){
 	if(c==vowels[i]){
		return 1;
	}
 }
 return 0;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int copyCount = 0;
	for (int i = 0; i<num_chars;i++){
 		if(is_vowel(in_buf[i])==1){
			out_buf[copyCount] = in_buf[i];
			copyCount++;	
		}
 	}
	return copyCount;	
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* in_buf = calloc(BUF_SIZE, sizeof(char));
	char* out_buf = calloc(BUF_SIZE, sizeof(char));
	fopen(inputFile, "w+");
	fopen(outputFile, "w+");
	while(fgets(in_buf,sizeof(in_buf),inputFile)){
		printf("%s\n",in_buf);
	}
	fread(in_buf, 1024, 1, inputFile);
	
	
}


int main(int argc, char *argv[]) {
 FILE *inputFile;
 FILE *outputFile;

//disemvowel(inputFile, outputFile);
 
 return 0;
}




