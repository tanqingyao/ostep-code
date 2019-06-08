#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char *argv[] )  
{
   if( argc == 3 )
   {
      int size, runtime;
      sscanf(argv[1], "%d", &size);
      sscanf(argv[2], "%d", &runtime);
      printf("待分配的内存，时间： %d Mb, %d s \n", size, runtime);
      size = 1024 * 1024 * size / 4;

      int arr[size];
      time_t start;
      start = time(NULL);
      printf("pid: %d, start time: %ld, now running...\n", (int)getpid(), start);
      while(time(NULL) - start < runtime)
      {
	      for(int i = 0; i < size ; i++)
		      arr[i] = 0;	      
      }
      printf("OK....");
   }
   else if( argc > 3 )
   {
      printf("Too many arguments supplied.\n");
   }
   else
   {
      printf("One argument expected.\n");
   }
}
