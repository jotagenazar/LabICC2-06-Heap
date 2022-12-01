#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) { //coloca o elemento no endereço de b dentro do endereço de a e vice-versa
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapify(int *array, int size, int pai) {
    int maior = pai;
    int filhoEsq = 2 * pai + 1;
    int filhoDir = filhoEsq + 1;

    //se filho da esquerda existe e é maior que o pai
    if(filhoEsq < size && array[filhoEsq] > array[maior])
        maior = filhoEsq;

    //se o filho da direita existe e é maior que o maior até agora
    if(filhoDir < size && array[filhoDir] > array[maior])
        maior = filhoDir;

    //se o pai nao é o maior, troca e testa as subarvores
    if(maior != pai) {
        troca(&array[pai], &array[maior]);
        heapify(array, size, maior);
    }
}

void heapSort(int *array, int size) {
    //maxHeapify
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    
    //ordenação colocando o maior elemento da iteração atual ao final do tamanho atual
    for(int i = size - 1; i >= 0; i--) {
        troca(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    //leitura do tamanho do vetor
    int n;
    scanf(" %d", &n);

    //leitura de cada elemento do vetor
    int array[n];
    for(unsigned int i = 0; i < n; ++i) {
        scanf(" %d", &array[i]);
    }

    //ordenação
    heapSort(array, n);

    //impressão do vetor ordenado
    for(unsigned int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}