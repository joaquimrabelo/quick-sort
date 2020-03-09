#include <stdio.h>
#include <stdlib.h>

int interacoes;

void quick_sort(int *a, int inicio, int fim);

int main (int argc, char** argv)
{
    int tamanho, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    printf("\n Tamanho do vetor definido para: %d\n", tamanho);
    
    int vetor[tamanho];
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100;
    }

    printf("\nO vetor gerado: \n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ",vetor[i]);
    }

    interacoes = 0;
    quick_sort(vetor, 0, tamanho -1);
    
    printf("\nVetor ordenado: \n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\nInteração: %d\n", interacoes);

    //system("pause");
    return 0;
}

void quick_sort(int *v, int left, int right) {
    int inicio, fim, pivot, y;

    inicio = left;
    fim = right;
    pivot = v[(inicio+fim)/2];

    interacoes++;
    //printf("\nwhile inicio: %d - fim: %d - pivot: %d", inicio, fim, pivot);
    while (inicio <= fim) {
        while (v[inicio] < pivot) {
            inicio++;
        }
        while (v[fim] > pivot) {
            fim--;
        }
        if (inicio <= fim) {
            y = v[inicio];
            v[inicio] = v[fim];
            v[fim] = y;
            inicio++;
            fim--;
        }
    }
    if (fim > left) {
        quick_sort(v, left, fim);
    }
    if (inicio < right) {
        quick_sort(v, inicio, right);
    }
}