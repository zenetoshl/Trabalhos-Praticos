/* Interface de Usu�rio (UI) */

/* Todas as entradas de escolha s�o lidas com fgets mesmo com elas sendo apenas de um caractere, isso � para evitar
    que o usu�rio insira caracteres a mais acidentalmente que poderiam comprometer os fluxos de execu��o da interface.
    Isso funciona pois o fgets captura todos os caracteres at� o fim da linha (inclusive) ou at� o tamanho m�ximo
    estipulado, que n�o � esperado ser execedido normalmente, pois trata-se de uma entrada muito simples.*/

#include "interface.h"

/* Imprimir Cabe�alho
    Limpa a tela e imprime a decora��o do cabe�alho. */
void UI_ImprimirCabecalho()
{
    UI_LimparTela();
    printf("      __...--~~~~~-._   _.-~~~~~--...__\n");
    printf("    //               `V'               \\\\ \n");
    printf("   //                 |                 \\\\ \n");
    printf("  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\ \n");
    printf(" //__.....----~~~~._\\ | /_.~~~~----.....__\\\\\n");
    printf("====================\\\\|//====================\n");
    printf("                    '---'\n\n");
    printf("       ===============================\n             D I C I O N � R I O\n       ===============================\n\n");
}

/* Imprimir Cabe�alho das Ordena��oes
    Limpa a tela e imprime a decora��o do cabe�alho das ordena��es. */
void UI_ImprimirCabecalhoOrd()
{
    UI_LimparTela();
    printf("  ______________________________________________\n");
    printf(" ||--------------------------------------------||\n");
    printf(" ||.---.    .-._            .----.             ||\n");
    printf(" |||===|____| |=|___.---.___|\"\"\"\"|-----.--.___ ||\n");
    printf(" ||| A |====| | |-#-|+++|=-=|_  _|-=+=-|==|---|||\n");
    printf(" |||===|    |C| |   |   | N |_\\/_|  S  |  | ^ |||\n");
    printf(" |||   |    | | | H | J |=-=|_/\\_|-=+=-|  | Z |||\n");
    printf(" |||   |    | | |   |   |   |    |     |  | ^ |||\n");
    printf(" |||===|====| |=|-#-|+++|=-=|\"\"\"\"|-=+=-|==|---|||\n");
    printf(" ||`---^----^-^-^---'---^---^----^-----^--^---^||\n");
    printf(" ||--------------------------------------------||\n");
    printf(" ||____________________________________________||\n\n");
    printf("   ===========================================\n");
    printf("      D I C I O N � R I O   O R D E N A D O\n");
    printf("   ===========================================\n\n");
}

/* Limpar Tela
    Limpa a tela, usando o comando correto de acordo com o sistema operacional. */
void UI_LimparTela()
{
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* Menu Principal
    Nesta tela o usu�rio pode escolher uma entre seis op��es, que ser�o executadas por outros
    m�todos correspondentes. Caso o usu�rio insira uma entrada inv�lida, o menu volta no in�cio. */
void UI_MenuPrincipal(TDicionario *dicionario)
{
    char escolha[MAXCHARESCOLHA];

    while (1)
    {
        UI_ImprimirCabecalho();
        printf("	   Bem-vind@ ao Dicion�rio!\n\n");
        if (DICQuantidadePalavras(dicionario))
            printf("   < Atualmente consta com %d palavra%s >\n\n",DICQuantidadePalavras(dicionario),(DICQuantidadePalavras(dicionario)>1)?"s":"");
        printf("Qual opera��o deseja realizar?\n");
        printf("1 - Ler arquivo\n");
        printf("2 - Inserir palavra\n");
        printf("3 - Remover palavra\n");
        printf("4 - Exibir palavras de uma letra\n");
        printf("5 - Exibir todo o dicion�rio\n");
        printf("6 - Ordena��es\n");
        printf("7 - Sair\n\n");

        fgets(escolha,MAXCHARESCOLHA,stdin);

        switch (escolha[0])
        {
        case '1':
            UI_LerArquivo(dicionario);
            break;
        case '2':
            UI_InserirPalavra(dicionario);
            break;
        case '3':
            UI_RemoverPalavra(dicionario);
            break;
        case '4':
            UI_ExibirLetra(dicionario);
            break;
        case '5':
            UI_ExibirDicio(dicionario);
            break;
        case '6':
            UI_Ordenacoes(dicionario);
            break;
        case '7':
            UI_Sair();
            break;
        default:
            printf("Opera��o inv�lida. Pressione ENTER para voltar.\n");
            getchar();
            break;
        }
    }
}

/* 1 - Ler Arquivo
    Permite ao usu�rio ou sobrescrever o Dicionario atual com um novo arquivo ou adicionar as palavras desse novo
    arquivo no Dicionario atual. O usu�rio tem a op��o de inserir o caminho completo at� o arquivo ou inserir apenas
    o nome do arquivo, caso este esteja dentro da pasta do programa. No caso da adi��o de arquivos, o usu�rio pode optar
    por ler v�rios arquivos. */
void UI_LerArquivo(TDicionario *dicionario)
{
    /* Duas vari�veis de controle para regular os fluxos das intera��es do usu�rio com o programa. */
    int controleOperacao = CTRL_REPETIR; /* Esta controla a decis�o de sobrescrever ou adicionar. */
    int controleArquivo = CTRL_REPETIR; /* Esta controla a inser��o do nome do aquivo */

    FILE *entrada = NULL;
    char nomeArquivo[MAXCHARDIRETORIO];

    char escolha[MAXCHARESCOLHA];

    while (controleOperacao == CTRL_REPETIR)
    {
        UI_ImprimirCabecalho();
        printf("Deseja sobrescrever ou adicionar o arquivo ao Dicion�rio? (S/A)\n");

        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);

        if (escolha[0] == 'A' || escolha[0] == 'S')
        {

            while (controleArquivo == CTRL_REPETIR)
            {
                UI_ImprimirCabecalho();
                printf("Qual arquivo deseja ler para %so Dicion�rio?\n",(escolha[0]=='A')?"adicionar a":"sobrescrever ");
                printf("(Digite o caminho completo com barras separando os diret�rios\nou digite apenas o nome do arquivo, caso esteja na mesma pasta do programa.)\n");
                fgets(nomeArquivo,MAXCHARDIRETORIO,stdin);
                nomeArquivo[strlen(nomeArquivo)-1] = '\0';

                entrada = fopen(nomeArquivo,"rt");

                if (escolha[0] == 'S' && entrada != NULL)
                    DICEsvaziar(dicionario);

                if (DICLerArquivo(dicionario,entrada) == OP_SUCESSO)
                {
                    fclose(entrada);
                    printf("\nArquivo \"%s\" lido com sucesso!\n",nomeArquivo);
                    if (escolha[0] == 'A')
                    {
                        printf("\nDeseja ler outro arquivo? (S/N)\n");
                        fgets(escolha,MAXCHARESCOLHA,stdin);
                        escolha[0] = toupper(escolha[0]);
                        if (escolha[0] == 'N')
                            controleArquivo = CTRL_PROSSEGUIR;
                    }
                    else
                    {
                        printf("\nPressione ENTER para continuar.\n");
                        getchar();
                        controleArquivo = CTRL_PROSSEGUIR;
                    }

                }
                else
                {
                    printf("\nFalha ao abrir \"%s\".\nDeseja tentar ler outro arquivo? (S/N)\n",nomeArquivo);
                    fgets(escolha,MAXCHARESCOLHA,stdin);
                    escolha[0] = toupper(escolha[0]);
                    if (escolha[0] == 'N')
                        controleArquivo = CTRL_PROSSEGUIR;
                }
            }
            controleOperacao = CTRL_PROSSEGUIR;
        }
        else
        {
            printf("\nOpera��o inv�lida. Pressione ENTER para continuar.\n");
            getchar();
        }
    }
}

/* 2 - Inserir Palavra no Dicion�rio
    Insere uma nova palavra no Dicion�rio de acordo com a entrada do usu�rio, que deve digitar a palavra em si
    e em qual(is) linha(s) do texto ela apareceria. Usando os c�digos retornados por DICInserirPalavra, mensagens informativas
    s�o exibidas para o usu�rio para avisar se uma nova palavra foi inserida, ou apenas um novo n�mero de linha foi inserido
    ou se nada foi feito. Permite a inser��o de v�rias palavras ao perguntar para o usu�rio no final da inser��o se deseja ou
    n�o inserir outra palavra e tamb�m permite que o usu�rio insira v�rios n�meros de linha de uma vez, na mesma palavra,
    separando-os com espa�os. */
void UI_InserirPalavra(TDicionario *dicionario)
{
    int controle = CTRL_REPETIR;
    int aviso;

    char escolha[MAXCHARESCOLHA];
    char novaPalavra[MAXCHARPALAVRA];
    int novoNLinha = 0;

    while (controle == CTRL_REPETIR)
    {
        UI_ImprimirCabecalho();
        printf("Qual palavra deseja adicionar ao Dicion�rio?\n");
        scanf("%s",novaPalavra);
        fgets(escolha,MAXCHARESCOLHA,stdin);

        printf("Em qual(is) linha(s) \"%s\" aparece?\n(Separe os n�meros de linha com espa�os)\n",novaPalavra);
        while (scanf("%d",&novoNLinha)!=EOF)
        {
            aviso = DICInserirPalavra(dicionario,novaPalavra,novoNLinha);

            if (aviso == OP_NOVAPALAVRA)
                printf("\nNova palavra, \"%s\", inserida com sucesso, com o n�mero de linha %d!\n",novaPalavra,novoNLinha);
            else if (aviso == OP_SUCESSO)
                printf("\nNovo n�mero de linha, %d, inserido na palavra \"%s\" com sucesso!\n",novoNLinha,novaPalavra);
            else
                printf("\nNenhuma nova palavra ou novo n�mero de linha foi inserido.\n");

            novoNLinha = 0;
            if (getchar()=='\n')
                break;
        }

        printf("\nDeseja inserir outra palavra no Dicion�rio? (S/N)\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'N')
            controle = CTRL_PROSSEGUIR;

    }
}

/* 3 - Remover Palavra do Dicion�rio
    Permite ao usu�rio remover uma dada palavra do Dicion�rio. Antes de tentar realizar a opera��o, o programa pergunta
    ao usu�rio se ele tem certeza que quer remover a palavra, e depois, com a ajuda dos c�digos retornados
    por DICRemoverPalavra, informa se a opera��o foi bem-sucedida ou n�o. Permite a remo��o de v�rias palavras ao perguntar
    para o usu�rio no final da remo��o se deseja ou n�o remover outra palavra. */
void UI_RemoverPalavra(TDicionario *dicionario)
{
    int controle = CTRL_REPETIR;

    char escolha[MAXCHARESCOLHA];
    char removerPalavra[MAXCHARPALAVRA];

    while (controle == CTRL_REPETIR)
    {
        UI_ImprimirCabecalho();
        printf("Qual palavra deseja remover do Dicion�rio?\n");
        scanf("%s",removerPalavra);
        fgets(escolha,MAXCHARESCOLHA,stdin);

        printf("\nTem certeza que deseja remover \"%s\" do Dicion�rio? (S/N)\n",removerPalavra);
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'S')
        {
            if (DICRemoverPalavra(dicionario,removerPalavra)==OP_SUCESSO)
                printf("\nPalavra \"%s\" removida com sucesso!\n",removerPalavra);
            else
                printf("\nPalavra \"%s\" n�o foi encontrada.\n",removerPalavra);
        }
        printf("\nDeseja retirar outra palavra do Dicion�rio? (S/N)\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'N')
            controle = CTRL_PROSSEGUIR;

    }
}

/* 4 - Exibir uma letra do Dicion�rio
    Exibe todas as entradas de uma dada letra para o usu�rio. Permite que o usu�rio insira outras letras para v�-las
    separadamente depois. */
void UI_ExibirLetra(TDicionario *dicionario)
{
    int controle = CTRL_REPETIR;

    char escolha[MAXCHARESCOLHA];

    while (controle == CTRL_REPETIR)
    {
        UI_ImprimirCabecalho();
        printf("Qual letra deseja exibir?\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] >= 'A' && escolha[0] <= 'Z')
            DICExibirLetra(dicionario,escolha[0]);
        else
            printf("\nEntrada inv�lida.\n");

        printf("\nDeseja exibir outra letra? (S/N)\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'N')
            controle = CTRL_PROSSEGUIR;
    }

}

/* 5 - Exibir Dicion�rio
    Exibe todas as letras com todas as entradas do Dicion�rio. */
void UI_ExibirDicio(TDicionario *dicionario)
{
    UI_ImprimirCabecalho();
    DICExibir(dicionario);
    printf("\nPressione ENTER para continuar.\n");
    getchar();
}

/*  6 - Ordena��es
    Permite ao usu�rio escolher os m�todos de ordena��o e comparar seus tempos de execu��o, n�mero de movimenta��es, etc. */
void UI_Ordenacoes(TDicionario *dicionario)
{
    char escolhaO[MAXCHARESCOLHA];
    char escolhaT[MAXCHARESCOLHA];
    char escolhaL[MAXCHARESCOLHA];

    char tiposOrdena[6][12] = {"Bubble Sort","Select Sort","Insert Sort","Shell Sort","Quicksort","Heapsort"};

    int controle = CTRL_REPETIR;

    TDicionario copia;
    double tempo;
    int comp,mov;

    DICInicializar(&copia);

    while (controle == CTRL_REPETIR)
    {
        UI_ImprimirCabecalhoOrd();
        printf("Escolha um algoritmo de ordena��o para apresentar o Dicion�rio ordenado:\n\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Select Sort\n");
        printf("3 - Insert Sort\n");
        printf("4 - Shell Sort\n");
        printf("5 - Quicksort\n");
        printf("6 - Heapsort\n\n");

        fgets(escolhaO,MAXCHARESCOLHA,stdin);

        if (escolhaO[0] >= '1' && escolhaO[0] <= '6')
        {
            while (1)
            {
                UI_ImprimirCabecalhoOrd();
                printf("Deseja visualizar todo o Dicion�rio ordenado ou apenas um letra? (D/L)\n");

                fgets(escolhaT,MAXCHARESCOLHA,stdin);

                escolhaT[0] = toupper(escolhaT[0]);
                if (escolhaT[0]=='L')
                {
                    printf("\nQual letra deseja visualizar?\n");
                    fgets(escolhaL,MAXCHARESCOLHA,stdin);
                    escolhaL[0] = toupper(escolhaL[0]);
                    if (escolhaL[0] < 'A' || escolhaL[0] > 'Z')
                    {
                        printf("\nEntrada inv�lida. Pressione ENTER para voltar.\n");
                        getchar();
                        continue;
                    }
                }
                else if (escolhaT[0]!='D')
                {
                    printf("Opera��o inv�lida. Pressione ENTER para voltar.\n");
                    getchar();
                    continue;
                }

                if (escolhaT[0]=='D')
                    escolhaL[0] = 0;

                DICCriarCopia(&copia,dicionario);
                DICOrdenar(&copia,escolhaO[0],escolhaL[0],&tempo,&comp,&mov);

                UI_ImprimirCabecalhoOrd();

                if (escolhaT[0]=='D')
                {
                    DICExibir(&copia);
                    printf(" <  Dicion�rio completo ordenado via %s  >\n\n",tiposOrdena[escolhaO[0]-'1']);
                    printf("Total de tempo gasto:   %lf s\tTempo gasto em m�dia:   %lf s\n",tempo,tempo/NLETRAS);
                    printf("Total de compara��es:   %8d\tCompara��es em m�dia:   %8.2lf\n",comp,(comp*1.0)/(NLETRAS*1.0));
                    printf("Total de movimenta��es: %8d\tMovimenta��es em m�dia: %8.2lf\n",mov,(mov*1.0)/(NLETRAS*1.0));
                }
                else
                {
                    DICExibirLetra(&copia,escolhaL[0]);
                    printf(" <  Letra %c ordenada via %s  >\n\n",escolhaL[0],tiposOrdena[escolhaO[0]-'1']);
                    printf("Tempo gasto: %lf s\n",tempo);
                    printf("Compara��es: %d\n",comp);
                    printf("Movimenta��es: %d\n",mov);
                }


                printf("\nPressione ENTER para continuar.\n");
                getchar();
                controle = CTRL_PROSSEGUIR;
                break;

            }
        }
        else
        {
            printf("Opera��o inv�lida. Pressione ENTER para voltar.\n");
            getchar();
        }

    }
}


/* 7 - Sair do Dicion�rio
    Pergunta ao usu�rio se deseja realmente sair do programa e o encerra se a resposta for positiva ou volta ao menu
    caso a resposta seja negativa. */
void UI_Sair()
{
    char escolha[MAXCHARESCOLHA];
    printf("Deseja mesmo sair do Dicion�rio? (S/N)\n");
    fgets(escolha,MAXCHARESCOLHA,stdin);
    escolha[0] = toupper(escolha[0]);
    if (escolha[0] == 'S')
    {
        printf("Saindo do Dicion�rio...\nPressione ENTER para sair.\n");
        getchar();
        exit(0);
    }
}
