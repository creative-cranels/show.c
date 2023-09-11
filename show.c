#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("No path provided");
    return -1;
  }

  char *path=argv[1];
  printf("Listing files and directories in: %s\n", path);


  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }

  return 0;
}
