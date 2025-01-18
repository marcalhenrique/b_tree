# BTree

## Descrição
Implementar uma BTree em C++.

## Rodar o Projeto
Instale as dependências:
```bash
sudo apt update
sudo apt install g++
sudo apt install build-essential
```
Depois compile o projeto utilizando o arquivo run.sh:
```bash
./run.sh
```
Esse arquivo compila, executa e limpa o projeto.

## Notas
É possível fazer a intercalação dos blocos com o Quicksort, a implementação é mais facil entretanto todos os elementos são carregados na memória.  
Utilizando o Min-Heap somente os menores elementos ativos são armazenados.  
Estrutura da intercalação utilizando o Min-Heap:
* Inserir o menor elemento de cada bloco no min-heap.
* Remova o menor valor
* Insira o próximo valor do bloco que continha o valor removido.
* Repita até que todos os blocos estejam vazios.

## TODOs
~~1. Criar MakeFile para compilar o projeto.~~  
~~2. Implementar o arquivo de dados.~~  
~~3. Criar os blocos de dados para serem ordenados em memória.~~  
~~4. Escrever os blocos em arquivos temporários.~~  
5. Ordenar os blocos de dados em memória utilizando o QuickSort.
