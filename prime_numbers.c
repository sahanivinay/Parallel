#include <stdio.h>
#include <omp.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 100000;
    int prime_count = 0;

    // Serial version
    double start  = omp_get_wtime();
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }
    double end  = omp_get_wtime();
    printf("Serial version: Primes found = %d, time = %f seconds\n", prime_count, end-start);

    // Parallel version
     prime_count = 0;
    start  = omp_get_wtime();
    #pragma omp parallel for reduction(+:prime_count) schedule(dynamic)
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }
    end  = omp_get_wtime();
    
    printf("Parallel version: Primes found = %d, time = %f seconds\n", prime_count, end-start);

    return 0;
}
