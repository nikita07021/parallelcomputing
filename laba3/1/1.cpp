#include <pthread.h>
#include <time.h>
#include <omp.h>
#include <stdio.h>

#define MAX 160000

#define MAX_THREAD 4
int a[MAX]={};

  

int main()
{

    clock_t time;
 time = clock();

   int max =0;

    for (int i = 0; i < (MAX); i++){
        
            
            if (a[i] > max)
            {
                max = a[i];
            }
            
      }


    printf("Max is %d ", max);
    time = clock() - time;
    printf("%f", (double)time/CLOCKS_PER_SEC);
    time = clock();

   max =0;
  #pragma omp parallel
  {
  #pragma omp for
    for (int i = 0; i < (MAX); i++){
        
            
            if (a[i] > max)
            {
                max = a[i];
            }
            
   }
   }

    printf("Max is %d ", max);
    time = clock() - time;
    printf("%f", (double)time/CLOCKS_PER_SEC);

   
    return 0;
}
