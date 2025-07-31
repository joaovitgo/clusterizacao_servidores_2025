#include <stdio.h>
#include <mpi.h>

/*
// Relatório Aula 20-07

Alunos:
- João Vitor de Souza Gonçalves
- Eduardo Coelho Gontijo

Na aula foi realizado a instalação do WSL, juntamente com a versão linux Ubuntu para realizar as operações desejadas. Usamos o GCC para clonar o repositório do GIT. Foi encontrado dificuldade em relação à sintaxe do linux, o que atrapalhou na instalação das bibliotecas.

Comando de Instalação GCC:
$ sudo apt install gcc

Comando de clonar o repositório:
$ git clone -b master

Após isso, criamos um arquivo C (olamundo) para editar e inserir o algoritmo.
$ nano olamundo.c 

Dentro do arquivo colocamos o seguinte algoritmo C:
#include <stdio.h>
int main () {
	printf("Olá mundo");
}

Por fim foi separado a quantidade de núcleos (simulando uma operação em clusterização), para executar a tarefa.
$ mpirun --oversubscribe  -np 4 ./ola_mundo
Olá do processo 3 de 4
Olá do processo 0 de 4
Olá do processo 1 de 4
Olá do processo 2 de 4
Nota-se com a resposta, que nem sempre a ordem de execução será a mesma. Na realidade elas são executadas paralelamente e a ordem final é definida por vários fatores como recursos específicos de hardware, velocidade de inicialização, agendamento, carga de CPU e tempos de sincronização entre processos. Na execução das tarefas, também foi feito testes em relação ao número de núcleos. Quando inserido em certos valores, demorou bastante para emitir uma resposta como no caso de 80 núcleos. Mas em casos ainda maiores, como os de 9999 núcleos, não teve memória suficiente para executar a tarefa e realizar a emissão de uma resposta.
*/

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv); // Inicializa MPI
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Número total de processos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // ID do processo atual

    printf("Olá do processo %d de %d\n", rank, size);

    MPI_Finalize(); // Finaliza MPI
    return 0;
}
