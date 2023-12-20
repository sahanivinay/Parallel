#include <mpi.h>
#include <stdio.h>

int main() {
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    if (world_rank == 0) {
        // The root process sets the number to be broadcasted
        number = 42;
        printf("Process 0 broadcasting number %d to all processes\n", number);
    }

    // All processes call MPI_Bcast, which broadcasts the value from root to everyone
    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Now all processes have the number
    printf("Process %d received number %d\n", world_rank, number);

    MPI_Finalize();
    return 0;
}

