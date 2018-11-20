#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int com = 10, rank, contador = 0, aux = 0;

	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &com);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	aux = (rank + 1) % 2;

	while(contador < com) {
   	if (rank == contador % 2) {
            contador++;
            MPI_Send(&contador, 1, MPI_INT, aux, 0, MPI_COMM_WORLD);
            printf("%d Envia para %d. Iteracao: %d\n", rank, aux, contador);
        }
        else {
            MPI_Recv(&contador, 1, MPI_INT, aux, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%d Recebe a bola de %d\n", rank, aux);
        }
    }

    MPI_Finalize();

	return 0;
}