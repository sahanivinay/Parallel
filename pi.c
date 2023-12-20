#include <stdio.h>
#include <omp.h>

#define NUM_STEPS 10000000  // Number of steps/iterations for the approximation
// If segmentation fault occurs , try reducing the value of NUM_STEPS


int main() {
    double pi = 0.0;

    // Serial computation
    double start_time = omp_get_wtime();
    for (int k = 0; k < NUM_STEPS; k++) {
        pi += (4.0 * (k % 2 == 0 ? 1.0 : -1.0)) / (2.0 * k + 1.0);
    }
    double end_time = omp_get_wtime();
    printf("Serial version: pi = %6.12f, time = %f seconds\n", pi, end_time - start_time);

    // Resetting pi for parallel computation
    pi = 0.0;
    
    // Parallel computation
    double sum[NUM_STEPS];
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (int k = 0; k < NUM_STEPS; k++) {
        sum[k] = (4.0 * (k % 2 == 0 ? 1.0 : -1.0)) / (2.0 * k + 1.0);
    }
    for (int k = 0; k < NUM_STEPS; k++) {
        pi += sum[k];
    }
    end_time = omp_get_wtime();
    printf("Parallel version: pi = %6.12f, time = %f seconds\n", pi, end_time - start_time);

    return 0;
}
