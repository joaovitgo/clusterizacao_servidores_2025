# RESPOSTAS DA ATIVIDADE EXTRA MININET - Exercícios Rápidos

---
**Aluno:** João Vitor de Souza Gonçalves
**Disciplina:** NF2 - Aplicação de Clusterização em Servidores Virtuais
**Professor:** Luis Vinicius Costa Silva
**Data:** 23/09/2025
---

### 1. Como a topologia em estrela influencia a comunicação?
Na topologia em estrela todos os hosts se conectam a um switch central, que atua como ponto de intermediação. Isso garante que a comunicação entre dois hosts sempre passe pelo switch, o que simplifica a gerência e facilita a detecção de falhas. Porém, se o switch falhar, toda a rede fica comprometida.

### 2. Vantagens e limitações da topologia Star?
Vantagens:
- Fácil de instalar, configurar e expandir;
- Gerência centralizada através do switch;
- Isolamento de falhas: se um host cair, não afeta os demais;
- Bom desempenho para redes pequenas e médias.

Limitações:
- Dependência do switch: se ele falhar, toda a rede para;
- Custo maior em cabos, já que cada host precisa de um link dedicado;
- Escalabilidade limitada pelo número de portas do switch.

### 3. Qual host foi mais eficiente na execução MPI?
De acordo com os resultados dos experimentos com o script "mpi_experiment.py":
- O host que apresentou menor tempo de execução foi considerado mais eficiente.  
- Em geral, a carga pode não ser totalmente equilibrada entre os hosts, resultando em diferenças no tempo de processamento.
- Caso a topologia tenha mais hosts, é esperado que a carga seja dividida de forma mais balanceada.
