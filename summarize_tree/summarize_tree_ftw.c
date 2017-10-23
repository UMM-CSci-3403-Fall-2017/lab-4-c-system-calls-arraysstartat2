#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ftw.h>
int dirCount = 0;
int fileCount = 0;

//function to be recursed in the ftw command, and increments the file and directory variables, and returns 0 to ensure error is not read into ftw.
static int callback(const char *fpath, const struct stat *sb, int typeflag) {
	
        //The typeflag argument is an int that has several possible values. The FTW_D being for type directory, and FTW_F being for file. Essentially, the respective global count variable is incremented depending on what is found.	
	if(typeflag==FTW_D){
		dirCount++;
		return 0; 		
	}
	if(typeflag==FTW_F){
		fileCount++;
		return 0;
	}
	return 0;
}

#define MAX_FTW_DEPTH 16

//method that runs ftw to recursively call callback for each folder in the directory given.
int main(int argc, char** argv) {

	ftw(argv[1], callback, MAX_FTW_DEPTH);
	printf("Processed all the files from %s. \n",argv[1]);
	printf("There were %d directories. \n",dirCount);
	printf("There were %d regular files. \n", fileCount);

	return 0;
}
