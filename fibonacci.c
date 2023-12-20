#include <stdio.h>
#include <omp.h>

int main() {
    printf("Enter the number of elements\n");
    int n = 0;
    scanf("%d" , &n);
    int fib[n];

    // Initialize the first two Fibonacci numbers.
    fib[0] = 0;
    fib[1] = 1;


        int i;
        #pragma omp parallel for schedule(dynamic)
        for (i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    

    // Print the Fibonacci numbers.
    printf("Fibonacci Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}
