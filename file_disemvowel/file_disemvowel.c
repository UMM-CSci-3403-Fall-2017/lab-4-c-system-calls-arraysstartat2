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

void disemvowelOneArg(FILE* inputFile) {
	char* in_buf = calloc(BUF_SIZE, sizeof(char));
	char* out_buf = calloc(BUF_SIZE, sizeof(char));
	fopen(inputFile, "r");
	while(fgets(in_buf,sizeof(in_buf),inputFile)){
		
	}
	
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* in_buf = calloc(BUF_SIZE, sizeof(char));
	char* out_buf = calloc(BUF_SIZE, sizeof(char));
	//fopen(inputFile, "r");
	//fopen(outputFile, "w+");
	while(fgets(in_buf,sizeof(in_buf),inputFile) != NULL){
		printf("%s\n",in_buf);
	
	
		
	
	int count = 0;
	while(in_buf[count] != '\0'){
		count++;
	}
	copy_non_vowels(count, in_buf, out_buf);
	//fread(in_buf, 1024, 1, inputFile);
	if(outputFile != NULL){
		printf("%s\n","putting stuff");
		fputs(out_buf, outputFile);
		
	}
}
fclose(outputFile);
}



// fix definition of input/output files, need to be full file names not single characters.
int main(int argc, char *argv[]) {
 printf("%s\n",argv[1]);
 FILE *inputFile;
 FILE *outputFile;
if(argc > 2){
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w+");
	//argv[1] = inputFile;
	//argv[2] = outputFile;
	disemvowel(inputFile, outputFile);
} else if(argc == 2){
	argv[1] = inputFile;
	disemvowel(inputFile, inputFile);
}
 return 0;
}




