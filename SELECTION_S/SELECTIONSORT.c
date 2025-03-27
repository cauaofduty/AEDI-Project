#include <stdio.h>

void selectionSort(int *vet, int ind, int start){//de menor a menor, insere-o no inicio da lista (RECURSIVA PARA FINS DE ABOLIR ESTE METODO)
    int aux, indiceMenor = start;//considera que o inicial da parte desordenada e o menor
    if(start ==  ind )return;//caso base
    for(int i = start + 1; i < ind; i++){//comeca no elemento apos o primeiro da parte derdenada
        if(vet[i] < vet[start]){
            indiceMenor = i;//armazena o indice do menor elemento
        }
    }
    if(start != indiceMenor){
        aux = vet[start];
        vet[start] = vet[indiceMenor];
        vet[indiceMenor] = aux;
    }
    selectionSort(vet, ind, ++start);
}

void 