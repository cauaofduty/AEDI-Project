#include <stdio.h> //referencia: SZWARCFITER, Jayme L.; MARKENZON, Lilian. Estruturas de Dados e Seus Algoritmos. 3. ed. Rio de Janeiro: LTC, 2010. E-book. p.161. ISBN 978-85-216-2995-5. Disponível em: https://integrada.minhabiblioteca.com.br/reader/books/978-85-216-2995-5/. Acesso em: 19 mar. 2025.
#define MAX 100
typedef struct ls{
    int dados[MAX];
    int index;
}ls;

void bubbleSortrRec(ls *lista, int ind){//ind e o ultimo indice da lista que possui elementos (RECURSIVA PARA FINS DE ABOLIR ESTE METODO)
    int temp;
    for(int i = 0; i < ind - 1; i++){
        if(lista->dados[i] > lista->dados[i+1]){
            temp = lista->dados[i + 1];
            lista->dados[i + 1] = lista->dados[i];
            lista->dados[i] = temp;
        }    
    }
    bubbleSortrRec(lista, --ind);
}

void bubbleSort(ls *lista){//otimizada para casos de lista quase ordenada
    int troca = 1;//para fins de reduzir as comparações desnecessarias 
    int limite = lista->index, temp, i, ultimaTroca;
    while (troca){
        troca = 0;
        for(i = 0; i < limite; i++){
            if(lista->dados[i] > lista->dados[i+1]){
                temp = lista->dados[i + 1];
                lista->dados[i + 1] = lista->dados[i];
                lista->dados[i] = temp;//troca feita
                troca = 1;//reiterara o loop
                ultimaTroca = i + 1;
            }
        }
        limite = ultimaTroca;//diminui o indice ate onde o loop ira percorrer
    }
}
