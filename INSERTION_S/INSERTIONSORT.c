#include <stdio.h>


void insertionSort(int *vet, int ind){//achei complicado
    int atual , j;
    
    for(int i = 1; i < ind; i++){
        atual = vet[i];//armazena a atual insercao
        j = i - 1;//"sublista ordenada"
        while(j >= 0 && vet[j] >= atual){//percorre e desloca elementos ate que o j seja menor que o i
            vet[j+1] = vet[j]; 
            j--;
        }
        vet[j + 1] = atual;//insere o i
    }
}


int main(){
    int vet[] = {3,4,1,5,10};
    insertionSort(vet, 5);
    for(int i = 0; i < 5; i ++){
        printf("%d ", vet[i]);
    }
}