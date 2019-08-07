#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h> 
#include <errno.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

using namespace std;

int main(int argc, char **argv)
{
  char *filename;
  struct dirent *filedir;
  DIR *drc = opendir(".");

   while ((filedir = readdir(drc)) != NULL)
     printf("%s\n", filedir->d_name); 
  
    //closedir(drc);     
   return 0; 
}

