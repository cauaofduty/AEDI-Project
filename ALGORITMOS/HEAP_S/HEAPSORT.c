#include <stdio.h>

/* CONSIDERAÇÕES FINAIS - Cauã
Algoritmo bastante intuitivo. Pode confundir, mas é o esperado tratando-se de algoritmos complexos.
 Mesmo que faça o uso de um loop que diminui o limite a ser ordenado, isso não ajuda tanto em termos de eficiência
 devido ao número necessário de trocas para realizar a ordenação. 

 Embora seja satisfatório de visualizar e possua constância no pior caso,
 tende a ser mais lento que outros algoritmos com a mesma complexidade. */

void swap(int *a, int *b){//troca valores
    int aux = *a;
    *a = *b;
    *b = aux; 
}

void heapify(int vet[], int i, int n){
    //assume o indice atual como maior (pai) e dita seus filhos
    int maior = i;
    int filho_esquerdo = 2*i + 1;
    int filho_direito = 2*i + 2;
    
    //compara qual maior
    if(filho_esquerdo < n && vet[maior] < vet[filho_esquerdo])
        maior = filho_esquerdo;
    if(filho_direito < n && vet[maior] < vet[filho_direito])
        maior = filho_direito;
    
    //se maior ainda for i, a função acaba (caso base), se não, troca maior atribuido por i, e chama a função a partir do maior para maior eficiência
    if(maior != i){
        swap(&vet[maior], &vet[i]);
        heapify(vet, maior, n);
    }
}
void heapsort(int vet[], int n){
    //heap maximo:
    //heapify inicia do indice maximo que existem filhos (a equação para o pai dada na aula) em ordem decrescente
    //com o intuito de colocar o maior valor no indice 0 (propriedade do heapmax, o pai sempre ser maior que seus filhos)
    for(int i = (n / 2) - 1; i >= 0; i--){
        heapify(vet,i, n);
    }

    //aqui ocorre de fato o heapsort a partir do max heap estruturado, colocando o maior valor no fim da lista 
    //e chamando heapify 
    for(int i = n - 1; i > 0 ; i--){
        swap(&vet[0], &vet[i]);//raiz ordenada colocada para fora do heap
        heapify(vet, 0, i);//i diminui a cada iteração, representando o valor já ordenado que deverá estar no fim do vetor após a troca
    }
}