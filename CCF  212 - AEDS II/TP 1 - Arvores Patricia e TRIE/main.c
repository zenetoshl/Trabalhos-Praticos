/// Barbara de Oliveira Souza - 3039
/// Caio Augusto Moreira Campos - 3042
/// Jose Grigorio Neto - 3046

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "patricia.h"




int  main()
{
    FILE *arquivo;
    FILE *arquivo2;
    Celula *TSTraiz;
    TipoArvore nova_arvore;

    char arqui[30],  novaPalavra[50];
    int numComp,numPlvTexto = 0, numCompSucessoTsT = 0, CompSemSucessoTsT=0;
    int qtComp = 0,qntCompNSuc = 0,qntCompSuc = 0;
    int qtNosExternosPat =0, qtNosInternosPat = 0;
    int menu = 90;
    int hMPalEncont=-1,hMPalNaoEncont=-1,i=-1;
    int hMPalEncontTst = -1,hMPalNEncontTst = -1;


      //--------------------------------------------------------------------//
     //----------------------Inicializa o dicionario-----------------------//
    //--------------------------------------------------------------------//
    Inicializar(&nova_arvore);
    inicializaTST(&TSTraiz);
     arquivo = fopen("dicionario.txt","rt");
    if(arquivo == NULL)
    {
    printf("ERRO NA LEITURA");
    }
    while(fscanf(arquivo,"%s", novaPalavra)!= EOF)
    {
        strlwr(novaPalavra);
        inserir(&TSTraiz, novaPalavra);
        nova_arvore = Insere(novaPalavra, &nova_arvore);

    }
    fclose(arquivo);
    qtNos(nova_arvore,&qtNosInternosPat,&qtNosExternosPat);


    //--------------------------------------------------------------------//
   //---------------------------Interface--------------------------------//
  //--------------------------------------------------------------------//
 while(menu!=0){///zero encerra o programa
        menu=1;///menu=1 aqui dentro para não haver problemas no retorno ao menu principal
        /*menu principal*/

        fflush(stdin);
        printf("***************************************************************\n");
        printf("***************************  Dicionario  **********************\n");
        printf("***************************************************************\n"
               "   1 - Ler arquivo\n   2 - Pesquisar TST \n   3 - Pesquisar PATRICIA\n  "
               " 4 - Comparaçoes entre arvores\n   0 - Encerrar\n  "
               "\n***************************************************************\nEscolha: ");
        scanf("%d",&menu);
        switch(menu){

            case 1:
            {
                printf("insira o nome do arquivo\n");
                scanf("%s",arqui);

            }break;
            case 2:{

                arquivo2 = fopen(arqui,"rt");
                if(arquivo2 == NULL)
                {
                    printf("ERRO NA LEITURA");
                }
                while(fscanf(arquivo2,"%s", novaPalavra)!= EOF)
                {
                    i=-1; numComp=0;
                    strlwr(novaPalavra);
                    printf("--------------------------\n");
                    printf("%s\n", novaPalavra);


                    if (pesquisaTST (TSTraiz, novaPalavra, &numPlvTexto, &numComp,&i)==1)
                    {
                        printf("Palavra encontrada\n");
                        numCompSucessoTsT+=numComp;
                        if(i>hMPalEncontTst)
                            hMPalEncontTst = i;
                    }else
                        {
                            printf("palavra nao encontrada\n");
                            CompSemSucessoTsT+=numComp;
                            if(hMPalNEncontTst < i)
                                hMPalNEncontTst = i;
                        }

                    printf("numero de comparacoes: %d\n", numComp);
    }

            } fclose(arquivo2); break;

            case 3:{

                arquivo2 = fopen(arqui,"rt");
                if(arquivo2 == NULL)
                {
                    printf("ERRO NA LEITURA");
                }

                while(fscanf(arquivo2,"%s", novaPalavra)!= EOF)
                {
                    strlwr(novaPalavra);
                    printf("--------------------------\n");
                    printf("%s\n", novaPalavra);

                    if(pesquisa(novaPalavra,nova_arvore,&qtComp,&i)==1)
                    {
                        printf("Palavra encontrada \n");
                        qntCompSuc+=qtComp;
                        if(i>hMPalEncont)
                            hMPalEncont = i;
                    }else{
                        printf("Palavra nao encontrada \n");
                        qntCompNSuc+=qtComp;
                        if(i>hMPalNaoEncont)
                            hMPalNaoEncont = i;
                    }
                    printf("numero de comparacoes: %d\n",qtComp);
                    qtComp = 0;
                    i=0;
                }



            } break;
            case 4:{

                printf("Numero de palavras na arvore : %d\n", externoQuantPalavras(TSTraiz));
                printf("Numero de palava no texto : %d\n", numPlvTexto);
                printf("-------------------------------------------------------\n");
                printf("-----------------------TST-----------------------------\n");
                printf("-------------------------------------------------------\n");
                printf("H maior palavra encontrada : %d\n",hMPalEncontTst);
                printf("H maior palavra nao encontrada : %d\n",hMPalNEncontTst);
                printf("Numero de comparacoes com sucesso totais : %d\n", numCompSucessoTsT);
                printf("Numero de comparacoes sem sucesso totais : %d\n", CompSemSucessoTsT);
                printf("Numero de nos : %d\n",externoContaNos(TSTraiz));
                printf("Altura da TST : %d\n",altura(TSTraiz));

                printf("-------------------------------------------------------\n");
                printf("----------------------PATRICIA-------------------------\n");
                printf("-------------------------------------------------------\n");
                printf("H maior palavra encontrada: %d\n", hMPalEncont);
                printf("H maior palavra nao encontrada: %d\n", hMPalNaoEncont);
                printf("Numero de comparocoes com sucesso totais : %d\n", qntCompSuc);
                printf("Numero de comparocoes sem sucesso totais : %d\n", qntCompNSuc);
                printf("Numero de nos internos: %d\n",qtNosInternosPat);
                printf("Numero de nos externos: %d\n",qtNosExternosPat);
                printf("Altura da Patricia: %d\n", alturaPat(nova_arvore));
                printf("-------------------------------------------------------\n");
                printf("-------------------------------------------------------\n");



            } break;

            case 0:{///Encerrar
                printf("Encerrando...\n");

            }break;

            default: printf("Comando não reconhecido, tente novamente.\n");break;
            }
            fflush(stdin);
            system("pause");
            system("cls");
        }


        return 0;


   /* arquivo = fopen("teste.txt","rt");
    if(arquivo == NULL)
    {
    printf("ERRO NA LEITURA");
    }

    while(fscanf(arquivo,"%s", novaPalavra)!= EOF)
    {
        strlwr(novaPalavra);
        inserir(&TSTraiz, novaPalavra);
        nova_arvore = Insere(novaPalavra, &nova_arvore);

    }
    fclose(arquivo);

    printf("insira o nome do arquivo\n");
    scanf("%s",arqui);
    arquivo2 = fopen(arqui,"rt");
    if(arquivo2 == NULL)
    {
    printf("ERRO NA LEITURA");
    }
    else{
    printf("LIDO COM SUCESSO\n");
    }
    while(fscanf(arquivo2,"%s", novaPalavra)!= EOF)
    {
        i=-1;
        numComp=0;
        strlwr(novaPalavra);
        printf("_____%s____\n", novaPalavra);
        if (pesquisaTST (TSTraiz, novaPalavra, &numPlvTexto, &numComp,&i)==1){
            printf("Palavra encontrado   ");
            numCompSucessoTsT+=numComp;
        }else{
            printf("palavra nao encontrado   ");
            CompSemSucessoTsT+=numComp;
        }
        if(menorPalavraEncontrada == -2)
            menorPalavraEncontrada = i;
        if(i > maiorPalavraEncontrada)
            maiorPalavraEncontrada = i;
        else if(i<menorPalavraEncontrada)
            menorPalavraEncontrada = i;

        printf(" numero de comparações: %d\n", numComp);




    }
    printf("\n");
    fclose(arquivo2);
    printf("H maior palavra encontrada: %d\n",maiorPalavraEncontrada);
    printf("H menor palavra encontrada: %d\n",menorPalavraEncontrada);
    printf("Numero de palava no texto: %d\n", numPlvTexto);
    printf("Numero de comparocoes com sucesso totais : %d\n", numCompSucessoTsT);
    printf("Numero de comparocoes sem sucesso totais : %d\n", CompSemSucessoTsT);


    printar(TSTraiz);
    printf("%d\n",externoContaNos(TSTraiz));
    printf("%d\n",altura(TSTraiz));

    printf("Numero de palavras na arvore: %d\n", externoQuantPalavras(TSTraiz));

  */

    return 0;
}


