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

using namespace std;
void compareTimes(char *filename, time_t time);
int main(int argc, char **argv)
{ 
  char *filename;
  struct stat filestat;
  int totalBytes=0;
  time_t max=0;
  char *maxFile;
  if(argc == 1)
    {
      cout << "Please pass in at least 2 arguments" << endl;    
    }

  else if(argc > 3)
    {
      if(strcmp(argv[1], "-a") == 0)
	{
	  for(int i=2; i < argc; i++)
	    {
	      filename = argv[i];
	      int fd = open(filename, O_RDONLY);
	      fstat(fd, &filestat);
	      cout << "Access time of the file " << filename << " is: " << ctime(&filestat.st_atime) << "\n";
	      if(filestat.st_atime > max)
		{
		  max = filestat.st_atime;
		  maxFile=filename;
		}
	    }
	  cout << "Most recently accessed file is: " << maxFile << " with " << ctime(&max) << endl;
	}
      else if(strcmp(argv[1], "-m") == 0)
	{
	  for(int i=2; i < argc; i++)
	    {
	      filename = argv[i];
	      int fd = open(filename, O_RDONLY);
	      fstat(fd, &filestat);
	      cout << "Modify time of the file " << filename << " is: " << ctime(&filestat.st_mtime) << "\n";
	      if(filestat.st_mtime > max)
		{
		  max = filestat.st_mtime;
		  maxFile=filename;
		}
	    }

	  cout << "Most recently modified file is: " << maxFile << " with " << ctime(&max) << endl;
	}

      else if(strcmp(argv[1], "-c") == 0)
	{
	  for(int i=2; i < argc; i++)
	    {
	      filename = argv[i];
	      int fd = open(filename, O_RDONLY);
	      fstat(fd, &filestat);
	      cout << "Modify time of the file " << filename << " is: " << ctime(&filestat.st_ctime) << "\n";
	      if(filestat.st_ctime > max)
		{
		  max = filestat.st_ctime;
		  maxFile=filename;
		}
	    }

	  cout << "Most recently changed file is: " << maxFile << " with " << ctime(&max) << endl;
	}
    }
}

