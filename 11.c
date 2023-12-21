#include <mpi.h>
#include <stdio.h>

int main() {
    MPI_Init(NULL, NULL);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Each process uses its rank as the data
    int data = world_rank;
    
    // Arrays to store results for the root process
    int max_val, min_val, sum_val, prod_val;

    // Reduce to find the maximum value
    MPI_Reduce(&data, &max_val, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    // Reduce to find the minimum value
    MPI_Reduce(&data, &min_val, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    // Reduce to find the sum of all values
    MPI_Reduce(&data, &sum_val, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Reduce to find the product of all values
    MPI_Reduce(&data, &prod_val, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    // Print results only from the root process
    if (world_rank == 0) {
        printf("Process %d - Max: %d, Min: %d, Sum: %d, Product: %d\n", 
                world_rank, max_val, min_val, sum_val, prod_val);
    }

    MPI_Finalize();
    return 0;
}

