#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int id =0 , rank = 0, cont = 0;

	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &id);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0) {        
        printf("Processo %d\n", cont++);
        MPI_Send(&cont, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
    } 
    else {
        MPI_Recv(&cont, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if(cont == rank) {
            printf("Processo %d\n", cont++);
      if(rank < id - 1)
        MPI_Send(&cont, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
    }
  }

    MPI_Finalize();

	return 0;
}