#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int pesquisabinaria(int valor, int vetor[], int tamanho)
{
    int fim = tamanho - 1;
    int inicio = 0;
    int meio;
    while(inicio <= fim)
    {
        meio = inicio + (fim - inicio) / 2;
        if(vetor[meio] == valor)
        {
            return meio;
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
    return -1;
}
int main(void)
{   
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    int valor;
    int resultado;
    int vetor[9] = {0,11,18,23,31,46,69,94,101};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("%s", "Escreva o valor que quer buscar: ");
    scanf("%d", &valor);
    resultado = pesquisabinaria(valor, vetor, tamanho);
    if(resultado != -1)
    {
        printf("Valor encontrado na posi��o ");
        printf("%d", resultado);
    }
    else
    {
        printf("%s", "Valor n�o foi encontrado");
    }
}
