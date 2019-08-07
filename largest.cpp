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
#define BUFFSIZ 1024
void sort(int[], char*[], int numOfFiles);
int main(int argc, char **argv)
{ 
  struct stat filestat;
  int totalBytes=0;
  int max=0;
  int maxs[BUFFSIZ];
  char *names[BUFFSIZ];
  int k =0;
  int number=0;
  if(argc == 1)
    {
	number=1;
	
	  struct dirent *de;    
	  DIR *dr = opendir("."); 

	  while ((de = readdir(dr)) != NULL)
	    {	     
	      if(de->d_type == DT_REG)
		{
		  //k++; // holds number of regular files.
		  int fd = open(de->d_name, O_RDONLY);
		  fstat(fd, &filestat);
		  maxs[k] = filestat.st_size;		 
		  names[k] = de->d_name;        
		  k++;
		}	      
	    }

	  sort(maxs, names, k);	

	  if(number == 1)
	    {
	      printf("%s: %d\n", names[0], maxs[0]);
	    }

	  //closedir(dr);     
     // cout << "Please pass in at least 2 arguments" << endl;    
    }

  else if(argc > 2) //./largest -n #
    {
     // int number=0;
      if(strcmp(argv[1],"-n") == 0)
	{	  
	  number = atoi(argv[2]);
	    
	  struct dirent *de;    
	  DIR *dr = opendir("."); 

	  while ((de = readdir(dr)) != NULL)
	    {	     
	      if(de->d_type == DT_REG)
		{
		  //cout << de->d_name << endl;
		  //k++;
		  int fd = open(de->d_name, O_RDONLY);
		  fstat(fd, &filestat);
		  maxs[k] = filestat.st_size;		 
		  names[k] = de->d_name;        
		 k++;
		}	      
	    }

	sort(maxs, names, k);
	  printf("k is: %d and number is: %d", k, number);
	  if(number < k)
	  {
		for(int j=0; j< number; j++)
		   printf("%s: %d\n", names[j], maxs[j]);
	  }
	  
	  else if(number > k)
	  {
	   	    
	      for(int i=0; i < k; i++)
		 printf("%s: %d\n",names[i], maxs[i]);
	  }
	

	//  closedir(dr);     
	  return 0; 
	}      
     
    }
}

void sort(int maxs[], char* names[], int k)
{
	
	  for(int j=0; j < k ;j++)
	    {
	      for(int t=0; t < k; t++)
		{
		  if(maxs[j] > maxs[t])
		    {
		      int temp = maxs[j];
		      char *temp2 = names[j];
		      maxs[j] = maxs[t];
		      names[j] = names[t];
		      maxs[t] = temp;
		      names[t] = temp2;
		      
		    }
		}
	    }

}
