#include <mpi.h>
#include <stdio.h>

int main() {
    MPI_Init(NULL, NULL);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Each process uses its rank as the data
    int data = world_rank;
    
    // Arrays to store results for each process
    int max_vals[world_size];
    int min_vals[world_size];
    int sum_vals[world_size];
    int prod_vals[world_size];

    // Allreduce to find the maximum value
    MPI_Allreduce(&data, &max_vals, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);

    // Allreduce to find the minimum value
    MPI_Allreduce(&data, &min_vals, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);

    // Allreduce to find the sum of all values
    MPI_Allreduce(&data, &sum_vals, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    // Allreduce to find the product of all values
    MPI_Allreduce(&data, &prod_vals, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

    // Each process prints its results
    printf("Process %d - Max: %d, Min: %d, Sum: %d, Product: %d\n", 
            world_rank, max_vals[world_rank], min_vals[world_rank], sum_vals[world_rank], prod_vals[world_rank]);

    MPI_Finalize();
    return 0;
}

