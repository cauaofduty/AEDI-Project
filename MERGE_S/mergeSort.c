#include <stdio.h>
#include <stdlib.h> 
/* CONSIDERACOES FINAIS PARA O  RELATORIO
Essa foi a lógica mais contraintuitiva que eu já vi na vida. A abstração para esse código utiliza uma linguagem que beira não condizer com o que é feito na realidade. Travei bastante no entendimento de tal, sem falar na confusão com índices e atribuições. Faz uso extremo de uma maestria absurda com sintaxe e lógica de programação, e é ao uso das recursões que me refiro. Pelo que entendi, as recursões criarão essas partições abstratas da lista e farão comparações de "listas unitárias", recolocando-as de volta no seu vetor original ordenadas de partição em partição, que julguei algo impossível demais para mensurar, de acordo com a abstração classicamente difundida. Um adendo à confusão com índices no momento em que é preciso recolocar os valores no array original. Dito isso aprendi que recursões sempre podem ter seu grau de complexidade elevado, e que as chamadas são terminadas da mais nova à mais antiga. 
PS: Menção honrosa ao monitor de AED I da professora Priscilla que me deu assistência significativa na apreensão do algoritmo.*/

void merge( int vet[], int left, int mid, int right){
       int tamLeft = mid  - left + 1;//tamando do array esquerdo
       int tamRight = right -  mid;//tamanho do array direito
       int vetLeft[tamLeft], vetRight[tamRight];//cria os arrays auxiliares para inserir elementos de vet
      for(int i = 0; i < tamLeft; i++){//copia a parte esquerda para vetLeft
           vetLeft[i] = vet[left + i];
       }
       for(int i = 0; i < tamRight; i++){//copia a parte direita para vetRight
           vetRight[i] = vet[mid + i + 1];
       }
       int l = 0, r = 0, f = left; //indices para left right e final (arrays)

       while(l < tamLeft && r < tamRight){//compara cada indice de vetLeft e vetRight
           if(vetLeft[l] <= vetRight[r]){
            vet[left + f] = vetLeft[l];
            l++,f++;
            }
           else{ 
            vet[f] = vetRight[r];
            f++,r++;
           }
       }
       while( l < tamLeft) {
           vet[f]= vetLeft[l];//recebe o restante caso vetLeft tenha sobrado elementos
           f++,l++;
       }
       while(r < tamRight) {
             vet[f] = vetRight[r];//recebe o restante caso vetRight tenha sobrado elementos      
             r++,f++;
         }
      }

void mergeSort(int vet[], int left, int right){
    if(left<right){//caso base da lista unitaria
        int mid = left + (right - left) /  2; //meio do array
       mergeSort(vet, left, mid);//faz a divisao de particoes da esquerda para o meio
       mergeSort(vet, mid + 1, right);//faz a divisao de particoes da direita para o final
       merge(vet, left, mid, right);//faz o merge a partir de cada array unitario preenchendo os arrays1/2 e por fim esvazia-os de volta no array original
       }
   }
   
int main(){
	int vetor[]= {3, 1, 5, 2, 9, 8};
	mergeSort(vetor, 0, 5);
	
	for(int i = 0; i < 6 ; i++){
	    printf("%d ", vetor[i]);
	}
    }