#include <stdio.h> 
#include <time.h>
//referencia: SZWARCFITER, Jayme L.; MARKENZON, Lilian. Estruturas de Dados e Seus Algoritmos. 3. ed. Rio de Janeiro: LTC, 2010. 3 # E-book. p.161. ISBN 978-85-216-2995-5. Disponível em: https://integrada.minhabiblioteca.com.br/reader/books/978-85-216-2995-5/. Acesso em: 19 mar. 2025.

void bubbleSort(int vet[], int ind){//otimizada para casos de lista quase ordenada
    int troca = 1;//para fins de reduzir as comparações desnecessarias 
    int limite = ind, temp, i, ultimaTroca;
    while (troca){
        troca = 0;
        for(i = 0; i < limite; i++){
            if(vet[i] > vet[i+1]){
                temp = vet[i + 1];
                vet[i + 1] = vet[i];
                vet[i] = temp;//troca feita
                troca = 1;//reiterara o loop
                ultimaTroca = i + 1;
            }
        }
        limite = ultimaTroca;//diminui o indice ate onde o loop ira percorrer
    }
}
/* A saída de cada programa deve estar no seguinte formato.

Lista de N elementos
Algoritmo A : X milesegundos

OBS 1: A medição do tempo de execução de cada programa pode ser realizada pelo comando time (do terminal do linux). */
int main(){
    int N;
    time_t inicio = time(NULL);
    FILE *file = fopen("10.txt", "r");
    time_t fim = time(NULL);
    double tempo = difftime(fim, inicio);//tempo gasto no programa
    printf("Lista de %d elementos\nAlgoritmo Bubble Sort: %f milssegundos\n", N, tempo);
}
