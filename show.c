#include <stdio.h> // io library
#include <dirent.h>

/*
  main() - Prints the directory contents in stdout
  argc - number of arguments
  argv - list of arguments
*/ 
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERR: No path provided\n");
    return -1;
  }

  char *path=argv[1];

  DIR *d; // DIR - directory stream type
  d = opendir(path);
  if (d) {
    printf("Listing files and directories in: %s\n", path);
    struct dirent *dir;
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  } else {
    printf("ERR: Path '%s' doesn't exist\n", path);
    return -1;
  }

  return 0;
}
