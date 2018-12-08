#include "Pesquisa.h"



int main() {
    int i, a;
    int tamanho = 10000;
    int pesquisa = 1000;
    double tempo1, tempo2, tempo3, tempo4;
    clock_t Ticks[2];
    FILE *arquivoPSequencial, *arquivoPBinaria;
    arquivoPSequencial = fopen("LogPesquisaSequencial.txt","w");
    arquivoPBinaria = fopen("LogPesquisaBinaria.txt","w");


    while(tamanho <= 100000) {
        item ordShellSeq[tamanho], ordInsertSeq[tamanho], ordMergeSeq[tamanho], ordRadixSeq[tamanho];
        item ordShellBin[tamanho], ordInsertBin[tamanho], ordMergeBin[tamanho], ordRadixBin[tamanho];

        time_t t;
        srand((unsigned) (&t));

        for (i = 0; i < tamanho; i++) {
            a = (rand() % tamanho);
            ordShellSeq[i].chave = a;
            ordInsertSeq[i].chave = a;
            ordMergeSeq[i].chave = a;
            ordRadixSeq[i].chave = a;


            ordShellBin[i].chave = a;
            ordInsertBin[i].chave = a;
            ordMergeBin[i].chave = a;
            ordRadixBin[i].chave = a;
        }


        printf("\n\n=============%10s=============\n", "InsertSort");
        //inicio
        Ticks[0] = clock();
        InsertSort(ordInsertSeq, tamanho);
        //PesquisaTodasSomas(ordInsertSeq, pesquisa, tamanho);
        if(PesquisaSomas(ordInsertSeq, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo1 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo1);
        printf("===================================\n");

        printf("\n=============%s=============\n", "ShellSort");
        //inicio
        Ticks[0] = clock();
        ShellSort(ordShellSeq, tamanho);
        //PesquisaTodasSomas(ordShellSeq, pesquisa, tamanho);
        if(PesquisaSomas(ordShellSeq, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo2 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
         //fim

        printf("\nTempo gasto: %g ms.\n", tempo2);
        printf("===================================\n");


        printf("\n=============%s=============\n", "MergeSort");
        //inicio
        Ticks[0] = clock();
        MergeSort(ordMergeSeq, 0, tamanho-1);
        //PesquisaTodasSomas(ordMergeSeq, pesquisa, tamanho);
        if(PesquisaSomas(ordMergeSeq, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo3 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo3);
        printf("===================================\n");

        printf("\n=============%s=============\n", "RadixSort");
        //inicio
        Ticks[0] = clock();
        RadixSort(ordRadixSeq, tamanho);
        //PesquisaTodasSomas(ordMergeSeq, pesquisa, tamanho);
        if(PesquisaSomas(ordRadixSeq, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo4 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo4);
        printf("===================================\n");

        fprintf(arquivoPSequencial,"%10d ; %13lf ; %10lf ; %10lf ; %10lf\n", tamanho, tempo1, tempo2, tempo3, tempo4);




        printf("\n\n=============%10s=============\n", "InsertSort");
        //inicio
        Ticks[0] = clock();
        InsertSort(ordInsertBin, tamanho);
        //PesquisaTodasSomas(ordInsertBin, pesquisa, tamanho);
        if(PesquisaBinaria(ordInsertBin, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo1 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo1);
        printf("===================================\n");

        printf("\n=============%s=============\n", "ShellSort");
        //inicio
        Ticks[0] = clock();
        ShellSort(ordShellBin, tamanho);
        //PesquisaTodasSomas(ordShellBin, pesquisa, tamanho);
        if(PesquisaBinaria(ordShellBin, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo2 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo2);
        printf("===================================\n");


        printf("\n=============%s=============\n", "MergeSort");
        //inicio
        Ticks[0] = clock();
        MergeSort(ordMergeBin, 0, tamanho-1);
        //PesquisaTodasSomas(ordMergeBin, pesquisa, tamanho);
        if(PesquisaBinaria(ordMergeBin, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo3 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo3);
        printf("===================================\n");

        printf("\n=============%s=============\n", "RadixSort");
        //inicio
        Ticks[0] = clock();
        RadixSort(ordRadixBin, tamanho);
        //PesquisaTodasSomas(ordMergeSeq, pesquisa, tamanho);
        if(PesquisaBinaria(ordRadixBin, pesquisa, tamanho))
            printf("sim\n");
        Ticks[1] = clock();
        tempo4 = (Ticks[1] - Ticks[0]) * 1000.00 / CLOCKS_PER_SEC;
        //fim

        printf("\nTempo gasto: %g ms.\n", tempo4);
        printf("===================================\n");

        fprintf(arquivoPBinaria,"%10d ; %13lf ; %10lf ; %10lf ; %10lf\n", tamanho, tempo1, tempo2, tempo3, tempo4);

        tamanho = tamanho + 10000;
    }
    fclose(arquivoPSequencial);
    fclose(arquivoPBinaria);

    return 0;


}
