#include <stdio.h> 
#include <mpi.h> 

int main(int argc, char* argv[])
{
  double soma, soma_local, a[256], b[256];
  int rank, TAM, tg=99, i, n = 256, primeiro, ultimo;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD,&myid);

  primeiro = rank * n/TAM;
  ultimo = (rank + 1) * n/TAM;

  for (i = 0; i < n; i++) {
     a[i] = i * 0.5;
     b[i] = i * 2.0;
  }

  soma_local = 0;

  for (i = primeiro; i < ultimo;i++){
    soma_local = soma_local + a[i]*b[i];
  }

  MPI_Reduce(&soma_local, &soma, 1, MPI_DOUBLE, MPI_SUM,MPI_COMM_WORLD);
  if(rank==0){
     printf ("soma = %f", soma);

     for (i=0; i<n; i++){
        printf ("Vetor a[%n] = %f", i,a[i]);
        printf ("Vetor b[%n] = %f", i,b[i]);
        printf ("Vetor c[%n] = %f", i,c[i]);
     }

  MPI_Finalize();
  }
  
  return 0;
}