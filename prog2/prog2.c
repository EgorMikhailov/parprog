include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
        MPI_Init(&argc, &argv);
        int size, rank;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        long N = 1000000000; //setting value of N manually
        long N_range = 100000000; // range for every process
        long ans =0;
        long sum = 0;
        long upperLimit = (rank + 1) * N_range; //upper limit for every process
        long i;
        for(i = (rank * N_range + 1); i <= upperLimit; i++){//calculations
                sum = sum + i;
        }
	MPI_Send(&sum, 1, MPI_LONG, size-1, 10, MPI_COMM_WORLD);//sending results to the main process
        if (rank == (size-1)) {
                ans = sum; //add result of the main process to the answer
                MPI_Status status;
                int i;
                for(i = 0; i < (size -1); i++) { // add results of other processes to the answer
                        MPI_Recv(&sum, 1, MPI_LONG,i,  10, MPI_COMM_WORLD, &status);
                        ans = ans + sum;
                }
                printf("%ld", ans);
        }
	MPI_Finalize();
        return 0;
}


