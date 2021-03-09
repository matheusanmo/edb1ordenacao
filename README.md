# ORDENACAO

# Autoria
- Aluno: Matheus Andrade Monteiro (matheusanmo@gmail.com)
- Professor: Selan Rodrigues dos Santos
- Turma DIM0119 - ESTRUTURA DE DADOS BÁSICAS I T01 (2020.2)

## Compilação
`ordenacao` foi desenvolvido e testado em uma máquina Ubuntu 20.04. Compilar `ordenacao` depende do CMake e de um compilador C++ com suporte a C++11. Segue o processo de compilação do programa:
- Crie um diretório para o CMake trabalhar usando o comando `mkdir build`.
- Vá para o diretório criado usando o comando `cd build`.
- Configure o projeto e prepare o Makefile com o comando `cmake ../`.
- Construa o programa com o comando `cmake --build .`.

## Pontos implementados
Os seguintes pontos listados na descrição do projeto foram implementados:
- Gera vetores de `uints` aleatórios seguindo os cenários pedidos (elementos em ordem não crescente, elementos em ordem não decrescente, elementos em ordem aleatória, alguns elementos já ordenados). Essas funções estão implementadas em `vecfacilities.cpp`.
- Roda uma dada ordenação `n` vezes em diferentes arranjos de tamanho `size` e calcula a média em milisegundos de tempo de execução do algoritmo. Esta é a função `time_sorts_mean` implementada no `sortfacilities.cpp`.
- Os algoritmos de ordenação implementados e testados são: insertion sort, bubble sort, selection sort.

