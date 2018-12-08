#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
void cabecalho (int comando);
int main()
{
    TipoRegistro x;
    TipoPagina *D;
    TDados estatistica;
    Inicializa(&D);
    setarDados(&estatistica);
    FILE *entrada;
    int escolha;
    double Falha = 0;
    double Total = 0;
    cabecalho(-1);
    scanf("%d", &escolha);
    while (escolha != 5)
    {
        if(escolha== 0)
        {
            entrada = fopen("entrada.txt","r");
            if(entrada == NULL)
            {
                printf(">>Erro to find FILE!\n");
                return 0;
            }
            cabecalho(0);
            scanf("%d", &escolha);
            while (fscanf(entrada,"%d",&x.Chave) != EOF)
            {
                if(escolha == 0)
                {
                    Insere(x, &D, &(estatistica.altura), &(estatistica.comparacoes), &Falha, &Total);
                    estatistica.nPalavras = Total-Falha;
                    atualizadorHC(D,&estatistica,&(estatistica.altura), &(estatistica.comparacoes));
                }
                else if(escolha == 1)
                {
                    Retira(x.Chave, &D, &(estatistica.altura),&(estatistica.comparacoes), &Falha, &Total);
                    if(estatistica.nPalavras > 0)
                        estatistica.nPalavras -= (Total-Falha);
                    atualizadorHC(D,&estatistica,&(estatistica.altura), &(estatistica.comparacoes));
                }
                else if (escolha == 2)
                {
                    Pesquisa(&x,D,&(estatistica.altura), &(estatistica.comparacoes),&Falha, &Total);
                    atualizadorHC(D,&estatistica,&(estatistica.altura), &(estatistica.comparacoes));
                }
                else if (escolha == 3)
                {
                    setarDados(&estatistica);
                    Insere(x, &D, &(estatistica.altura), &(estatistica.comparacoes), &Falha, &Total);
                    estatistica.nPalavras = Total;
                    H(D,&estatistica);
                    printf("H: %d\n", estatistica.hArvore);
                }
                else
                {
                    cabecalho(666);
                    return 0;
                }
            }
            printf("Porcentagem de Falha: %.2lf\n", Falha/Total);
        }
        else if(escolha == 1 || escolha == 2 || escolha == 3)
        {
            cabecalho(1);
            printf("> ");
            scanf("%d",&x.Chave);
            while (x.Chave != 0)
            {
                if(escolha == 1)
                {
                    Insere(x, &D, &(estatistica.altura), &(estatistica.comparacoes), &Falha, &Total);
                    estatistica.nPalavras = Total-Falha;
                    atualizadorHC(D,&estatistica,&(estatistica.altura), &(estatistica.comparacoes));
                }
                else if(escolha == 2)
                {
                    Retira(x.Chave, &D, &(estatistica.altura),&(estatistica.comparacoes), &Falha, &Total);
                    if(estatistica.nPalavras > 0)
                        estatistica.nPalavras -= (1-Falha);
                    atualizadorHC(D,&estatistica,&(estatistica.altura), &(estatistica.comparacoes));
                    printf("C: %d\n",estatistica.cTotal);
                }
                else
                    Pesquisa(&x,D,&(estatistica.altura), &(estatistica.comparacoes),&Falha, &Total);
                printf("> ");
                scanf("%d",&x.Chave);
            }
            printf("Porcentagem de Falha: %.2lf\n", Falha/Total);
        }
        else if (escolha == 4)
        {
            cabecalho(4);
            printf("MM: %d\n",MM);
            printf("Palavras: %.0lf\n\n",estatistica.nPalavras);
            printf("--------------\n");
            printf("    ALTURA    \n");
            printf("--------------\n");
            printf("Arvore: %d\n",estatistica.hArvore);
            printf("Altura Total Percorrida: %d\n",estatistica.hTotal);
            printf("Maior Altura Percorrida: %d\n",estatistica.hMaior);
            printf("Menor Altura Percorrida: %d\n",estatistica.hMenor);
            printf("Media Altura por Operacao: %.2lf\n\n",estatistica.mediaAltura);

            printf("--------------\n");
            printf("  COMPARACOES \n");
            printf("--------------\n");
            printf("Comparacoes Totais Efetuadas: %d\n",estatistica.cTotal);
            printf("Maior Comparacao Efetuada: %d\n",estatistica.cMaior);
            printf("Menor Comparacao Efetuada: %d\n",estatistica.cMenor);
            printf("Media Comparacao por Operacao: %.2lf\n",estatistica.mediaComparacoes);
        }
        else
        {
            cabecalho(666);
        }
        Total = 0;
        Falha = 0;
        getchar();
        getchar();
        cabecalho(-1);
        scanf("%d", &escolha);
    }
    ///Imprime(D);
    return 0;
}
void cabecalho (int comando)
{
    if(comando == -1)
    {
        system("CLS");
        printf("=======================================\n");
        printf("=======================================\n");
        printf("            ESCOLHA UMA OPCAO          \n");
        printf("=======================================\n");
        printf("=======================================\n");
        printf("0 - Ler Arquivo\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Pesquisar\n");
        printf("4 - Estatistica\n");
        printf("5 - Sair\n");
        printf("_______________________________________\n");
    }
    if(comando == 0)
    {
        system("CLS");
        printf("=======================================\n");
        printf("=======================================\n");
        printf("            FUNCAO DO ARQUIVO          \n");
        printf("=======================================\n");
        printf("=======================================\n");
        printf("0 - Inserir\n");
        printf("1 - Remover\n");
        printf("2 - Pesquisar\n");
        printf("3 - Montar Arvore\n");
        printf("_______________________________________\n");
    }
    if (comando == 666)
    {
        system("CLS");
        printf("_;~)                  (~;_\n");
        printf("(   |                  |   )\n");
        printf(" ~', ',    ,''~'',   ,' ,'~\n");
        printf("     ', ','       ',' ,'\n");
        printf("       ',: {'} {'} :,'\n");
        printf("         ;   /^\   ;\n");
        printf("          ~\  ~  /~\n");
        printf("        ,' ,~~~~~, ',\n");
        printf("      ,' ,' ;~~~; ', ',\n");
        printf("    ,' ,'    '''    ', ',\n");
        printf("  (~  ;               ;  ~)\n");
        printf("   -;_)               (_;-\n");
        printf("\n   COMANDO INEXISTENTE\n");
    }
    else if(comando == 1)
    {
        system("CLS");
        printf("=======================================\n");
        printf("=======================================\n");
        printf("            EDICAO MANUAL              \n");
        printf("=======================================\n");
        printf("=======================================\n");

    }
    else if (comando == 4)
    {
        system("CLS");
        printf("=======================================\n");
        printf("=======================================\n");
        printf("           ESTATISTICA/DADOS           \n");
        printf("=======================================\n");
        printf("=======================================\n\n");
    }
}
    ///scanf("%ld%*[^\n]", &x.Chave);
    ///getchar();
