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

using namespace std;

int main(int argc, char **argv)
{ 
  char *filename;
  struct stat filestat;
  int totalBytes=0;
  if(argc == 1)
    {
      cout << "Please pass in at least 2 arguments" << endl;
    
    }

  else if(argc >= 2)
    {
      for(int i=1; i < argc; i++)
	{
	  filename = argv[i];
	  int fd = open(filename, O_RDONLY);
	  fstat(fd, &filestat);
	  
	  cout << "Number of bytes in file " << filename << " is: " <<  filestat.st_size << endl;
	  totalBytes += filestat.st_size;
	}
	 
      cout << "Total bytes are: " << totalBytes << endl;
    }
}
