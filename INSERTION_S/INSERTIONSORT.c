#include <stdio.h>


void insertionSort(int *vet, int ind){
    int atual , j;
    
    for(int i = 1; i < ind; i++){
        atual = vet[i];
        j = i - 1;
        while(j>=0 && vet[j] >= atual){
            vet[j+1] = vet[j]; 
            j--;
        }
        vet[j + 1] = atual;
    }
}


int main(){
    int vet[] = {3,4,1,5,10};
    insertionSort(vet, 5);
    for(int i = 0; i < 5; i ++){
        printf("%d ", vet[i]);
    }
}