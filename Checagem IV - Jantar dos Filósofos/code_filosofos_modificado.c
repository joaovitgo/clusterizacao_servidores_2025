#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 5
enum { THINKING, HUNGRY, EATING };

int estado;

int esquerda(int rank) { return (rank + N - 1) % N; }
int direita(int rank) { return (rank + 1) % N; }

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != N) {
        if (rank == 0) printf("Execute com exatamente %d processos.\n", N);
        MPI_Finalize();
        return 0;
    }

    srand(time(NULL) + rank);
    estado = THINKING;

    // TRECHO PARA TEMPO DE ESPERA

    double acumulador_tempo = 0.0;

    int tentativas = 10;

    for (int step = 0; step < tentativas; step++) {

        printf("Filósofo %d pensando.\n", rank);
        sleep(rand() % 2);

        estado = HUNGRY;
        printf("Filósofo %d com fome.\n", rank);

        int estado_esq = THINKING, estado_dir = THINKING;
        MPI_Request requisicoes[4];

        MPI_Irecv(&estado_esq, 1, MPI_INT, esquerda(rank), 0, MPI_COMM_WORLD, &requisicoes[0]);
        MPI_Irecv(&estado_dir, 1, MPI_INT, direita(rank), 0, MPI_COMM_WORLD, &requisicoes[1]);

        double inicio = MPI_Wtime();

        if (rank % 2 == 0) {
            MPI_Isend(&estado, 1, MPI_INT, esquerda(rank), 0, MPI_COMM_WORLD, &requisicoes[2]);
            MPI_Isend(&estado, 1, MPI_INT, direita(rank), 0, MPI_COMM_WORLD, &requisicoes[3]);
        } else {
            MPI_Isend(&estado, 1, MPI_INT, direita(rank), 0, MPI_COMM_WORLD, &requisicoes[2]);
            MPI_Isend(&estado, 1, MPI_INT, esquerda(rank), 0, MPI_COMM_WORLD, &requisicoes[3]);
        }

        MPI_Waitall(4, requisicoes, MPI_STATUSES_IGNORE);

        if (estado_esq != EATING && estado_dir != EATING) {
            estado = EATING;

            double fim = MPI_Wtime();
            double tempo_rodada = fim - inicio;
            acumulador_tempo += tempo_rodada;

            printf("Filósofo %d está comendo. Esperou %.3f segundos nesta tentativa.\n", rank, tempo_rodada);
            sleep(rand() % 2);
        } else {
            printf("Filósofo %d aguardando.\n", rank);
        }

        estado = THINKING;
        MPI_Barrier(MPI_COMM_WORLD);
    }

    printf("Filósofo %d: tempo médio de espera = %.3f segundos\n", rank, acumulador_tempo / tentativas);

    MPI_Finalize();
    return 0;
}
