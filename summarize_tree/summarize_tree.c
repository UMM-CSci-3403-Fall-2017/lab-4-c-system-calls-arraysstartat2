#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
  /*
   * Use the stat() function (try "man 2 stat") to determine if the file
   * referenced by path is a directory or not.  Call stat, and then use
   * S_ISDIR to see if the file is a directory. Make sure you check the
   * return value from stat in case there is a problem, e.g., maybe the
   * the file doesn't actually exist.
   *
   */
	struct stat statbuf;
	if (stat(path, &statbuf) != 0){
		return false;
	}
	return S_ISDIR(statbuf.st_mode);
		
}

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
int* process_path(const char*, int numDir, int numReg);

void process_directory(const char* path, int numDir, int numReg) {
  /*
   * Update the number of directories seen, use opendir() to open the
   * directory, and then use readdir() to loop through the entries
   * and process them. You have to be careful not to process the
   * "." and ".." directory entries, or you'll end up spinning in
   * (infinite) loops. Also make sure you closedir() when you're done.
   *
   * You'll also want to use chdir() to move into this new directory,
   * with a matching call to chdir() to move back out of it when you're
   * done.
   */	DIR *dirp;
	dirp = opendir(path);
	struct dirent *entry;

	if (is_dir(path)) {
		numDir++;
		opendir(path);
		while(entry = readdir()){
		if(entry->d_type==DT_DIR){
			if (strcmp(entry ->d_name, ".") ==0|| strcmp(entry->d_name, "..")==0){
				continue;
			}
		numDir++;
		process_directory(path,numDir,numReg);
	}
	else {
		process_file(path, numReg);
	}
		}
	closedir(dirp);	
	
}

void process_file(const char* path, int numReg) {
  /*
   * Update the number of regular files.
   */
DIR* dirp;
dirp = opendir(path);
struct dirent * entry;

while((entry = readir(dirp)) != NULL) {
	if (entry -> d_type == DT_REG) {
		numReg++;
	}
}
closedir(dirp);
	
}

int* process_path(const char* path, int numDir, int numReg) {
  if (is_dir(path)) {
    process_directory(path, numDir, numReg);
  } else {
    process_file(path, numReg);
  }
  int* returnArr = {numDir, numReg};
  return returnArr;
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;
  int* returnArr;
  returnArr = process_path(argv[1], num_dirs, num_regular);

  printf_ISDIR(statbuf.st_mode);

("There were %d directories.\n", returnArr[0]);
  printf("There were %d regular files.\n", returnArr[1]);

  return 0;
}
