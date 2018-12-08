#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "piramide.h"
#include "CidadeQuadriculada.h"


int main()
{
    LARGE_INTEGER tempoInicial, tempoFinal, freq;
    float tempoTotal;
    piramide p;
    Cidade m;
    //srand(time(NULL));
    int menu=90;

    while(menu!=0){
        menu=1;
        fflush(stdin);
        printf("********************Programacao Dinamica********************\n");
        printf("***************************************************************\n"
               "  1 - Obras na Estrada\n  2 - Piramide- Traz pra frente\n  3 - Piramide-Recursivida\n"
                    "  4 - Piramide-Memoization\n  0 - Encerra programa "
               "\n***************************************************************\nEscolha: ");
        scanf("%d",&menu);
        switch(menu){
            case 0:
                printf("\nEncerrando...\n\n");break;
            case 1:{
                LerArqC(&m, "cidade.txt");
                QueryPerformanceCounter(&tempoInicial);
                printf("%d",CidadeQuad(&m));
                QueryPerformanceCounter(&tempoFinal);
                QueryPerformanceFrequency(&freq);
                tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
                printf("\n\nTempo total: %f s\n",tempoTotal);


            } break;
            case 2:{
                LerArq(&p, "teste.txt");
                QueryPerformanceCounter(&tempoInicial);
                TrazPraFrente (&p);
                printarResultado (&p);
                QueryPerformanceCounter(&tempoFinal);
                QueryPerformanceFrequency(&freq);
                tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
                printf("\n\nTempo total: %f s\n",tempoTotal);

            } break;
            case 3:{
                LerArq(&p, "teste.txt");
                QueryPerformanceCounter(&tempoInicial);
                ResolveRecursivo(&p);
                printarResultado (&p);
                QueryPerformanceCounter(&tempoFinal);
                QueryPerformanceFrequency(&freq);
                tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
                printf("\n\nTempo total: %f s\n",tempoTotal);

            } break;
            case 4:{
                LerArq(&p, "teste.txt");
                QueryPerformanceCounter(&tempoInicial);
                ResolveMemoization(&p);
                printarResultado (&p);
                QueryPerformanceCounter(&tempoFinal);
                QueryPerformanceFrequency(&freq);
                tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
                printf("\n\nTempo total: %f s\n",tempoTotal);

            }break;

            default: printf("Comando não reconhecido, tente novamente.\n");break;
        }
        fflush(stdin);
        system("pause");
        system("cls");
    }



    return 0;
}






