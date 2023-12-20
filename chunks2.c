#include <stdio.h>
#include <omp.h>

int main(){
  
    int n=10;
    #pragma omp parallel for schedule(static,2)
    for(int i=0;i<n;i++){
        int thread_num = omp_get_thread_num(); 
        printf("Thread %d executes instruction %d\n", thread_num, i); 
    }

    return 0; 
}
