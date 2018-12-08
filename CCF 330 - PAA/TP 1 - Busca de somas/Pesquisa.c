//
// Created by flym on 19/09/18.
//

#include "Pesquisa.h"

void PesquisaTodasSomas(item *vetor, int pesquisa, int tamanho){
    int i = 0, j = 0;
    for(i = 0; i < tamanho; i++){
        if (vetor[i].chave > pesquisa)
            break;
        for(j = i + 1; j < tamanho; j++){
            if(vetor[i].chave + vetor[j].chave == pesquisa){
                if (vetor[j].chave > pesquisa)
                    break;
                if (j != i)
                    printf("%2d + %2d = %2d\n", vetor[i].chave, vetor[j].chave, pesquisa);

            }
        }

    }
    return;
}

int PesquisaSomas(item *vetor, int pesquisa , int tamanho){
    int i = 0;
    int resultado;
    int pesq;
    for (i = 0; i < tamanho; i++){
        if (vetor[i].chave > pesquisa)
            pesq = vetor[i].chave - pesquisa;
        else
            pesq = pesquisa - vetor[i].chave;
        resultado = PesquisaDiferencas(vetor, pesq, i, tamanho);

        if (resultado)
            return resultado;
    }
    return resultado;
}

int PesquisaDiferencas(item *vetor, int pesquisa, int indiceX , int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i].chave == pesquisa && i != indiceX)
            return 1;
    }
}


int PesquisaBinaria(item *vetor, int x, int tamanho)
{ int i, Esq, Dir;
        Esq = 1;
        Dir = tamanho;
        do
        { i = (Esq + Dir) / 2;
            if (x > vetor[i].chave)
                Esq = i + 1;
            else Dir = i - 1;
        } while (x != vetor[i].chave && Esq <= Dir);
        if (x == vetor[i].chave) return 1; else return 0;
}