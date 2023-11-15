#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int escolher(int opcao, int vetor[], int tamanho)
{
    printf("1-Escrever vetor\n2-Mostrar vetor\n3-Ordenar vetor\n4-Buscar valor no vetor\nEscolha uma opcao:");
    scanf("%d", &opcao);
    switch(opcao) 
    {
        case 1:
            escrever_vetor(vetor, tamanho);
            break;
        case 2:
            mostrar_vetor(vetor, tamanho);
            break;
        case 3:
            ordenar_vetor(vetor, tamanho);
            break;
        case 4:
            pesquisabinaria(vetor, tamanho);
            break;
        default:
            printf("Opcao invalida");
    }
    return opcao;
}
void escrever_vetor(int vetor[], int tamanho)
{
    linha();
    for(int i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
}
void mostrar_vetor(int vetor[], int tamanho)
{
    linha();
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void ordenar_vetor(int vetor[], int tamanho)
{
    int aux = 0;
    for(int i = 0; i < (tamanho - 1); i++)
    {
        for(int j = i+1; j < tamanho; j++)
        {
            if(vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
void pesquisabinaria(int vetor[], int tamanho)
{
    int fim = tamanho - 1;
    int inicio = 0;
    int meio;
    int valor;
    int encontrado = 0;
    linha();
    printf("Digite o valor a ser buscado no vetor: ");
    scanf("%d", &valor);
    while(encontrado == 0 && inicio <= fim)
    {
        meio = inicio + (fim - inicio) / 2;
        if(vetor[meio] == valor)
        {
            encontrado = 1;
        }
        else if(vetor[meio] > valor)
        {
            fim = meio - 1;
        }
        else
        {
           inicio = meio + 1;
        }
    }
    if(encontrado == 1)
    {
        printf("Numero econtrado na posicao %d\n", meio);
    }
    else
    {
        printf("O Numero nao foi encontrado\n");
    }
}
void linha()
{
    printf("==========================\n");
}
int main(void)
{   
    int tamanho = 10;
    int vetor[tamanho];
    int opcao = 0;
    while (opcao != 9)
    {
        linha();
        opcao = escolher(opcao, vetor, tamanho);
    }
}