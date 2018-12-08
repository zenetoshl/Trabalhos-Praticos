/* Interface de Usuário (UI) */

/* Todas as entradas de escolha são lidas com fgets mesmo com elas sendo apenas de um caractere, isso é para evitar
    que o usuário insira caracteres a mais acidentalmente que poderiam comprometer os fluxos de execução da interface.
    Isso funciona pois o fgets captura todos os caracteres até o fim da linha (inclusive) ou até o tamanho máximo
    estipulado, que não é esperado ser execedido normalmente, pois trata-se de uma entrada muito simples.*/

#include "interface.h"

/* Imprimir Cabeçalho
    Limpa a tela e imprime a decoração do cabeçalho. */
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
    printf("       ===============================\n             D I C I O N Á R I O\n       ===============================\n\n");
}

/* Imprimir Cabeçalho das Ordenaçãoes
    Limpa a tela e imprime a decoração do cabeçalho das ordenações. */
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
    printf("      D I C I O N Á R I O   O R D E N A D O\n");
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
    Nesta tela o usuário pode escolher uma entre seis opções, que serão executadas por outros
    métodos correspondentes. Caso o usuário insira uma entrada inválida, o menu volta no início. */
void UI_MenuPrincipal(TDicionario *dicionario)
{
    char escolha[MAXCHARESCOLHA];

    while (1)
    {
        UI_ImprimirCabecalho();
        printf("	   Bem-vind@ ao Dicionário!\n\n");
        if (DICQuantidadePalavras(dicionario))
            printf("   < Atualmente consta com %d palavra%s >\n\n",DICQuantidadePalavras(dicionario),(DICQuantidadePalavras(dicionario)>1)?"s":"");
        printf("Qual operação deseja realizar?\n");
        printf("1 - Ler arquivo\n");
        printf("2 - Inserir palavra\n");
        printf("3 - Remover palavra\n");
        printf("4 - Exibir palavras de uma letra\n");
        printf("5 - Exibir todo o dicionário\n");
        printf("6 - Ordenações\n");
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
            printf("Operação inválida. Pressione ENTER para voltar.\n");
            getchar();
            break;
        }
    }
}

/* 1 - Ler Arquivo
    Permite ao usuário ou sobrescrever o Dicionario atual com um novo arquivo ou adicionar as palavras desse novo
    arquivo no Dicionario atual. O usuário tem a opção de inserir o caminho completo até o arquivo ou inserir apenas
    o nome do arquivo, caso este esteja dentro da pasta do programa. No caso da adição de arquivos, o usuário pode optar
    por ler vários arquivos. */
void UI_LerArquivo(TDicionario *dicionario)
{
    /* Duas variáveis de controle para regular os fluxos das interações do usuário com o programa. */
    int controleOperacao = CTRL_REPETIR; /* Esta controla a decisão de sobrescrever ou adicionar. */
    int controleArquivo = CTRL_REPETIR; /* Esta controla a inserção do nome do aquivo */

    FILE *entrada = NULL;
    char nomeArquivo[MAXCHARDIRETORIO];

    char escolha[MAXCHARESCOLHA];

    while (controleOperacao == CTRL_REPETIR)
    {
        UI_ImprimirCabecalho();
        printf("Deseja sobrescrever ou adicionar o arquivo ao Dicionário? (S/A)\n");

        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);

        if (escolha[0] == 'A' || escolha[0] == 'S')
        {

            while (controleArquivo == CTRL_REPETIR)
            {
                UI_ImprimirCabecalho();
                printf("Qual arquivo deseja ler para %so Dicionário?\n",(escolha[0]=='A')?"adicionar a":"sobrescrever ");
                printf("(Digite o caminho completo com barras separando os diretórios\nou digite apenas o nome do arquivo, caso esteja na mesma pasta do programa.)\n");
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
            printf("\nOperação inválida. Pressione ENTER para continuar.\n");
            getchar();
        }
    }
}

/* 2 - Inserir Palavra no Dicionário
    Insere uma nova palavra no Dicionário de acordo com a entrada do usuário, que deve digitar a palavra em si
    e em qual(is) linha(s) do texto ela apareceria. Usando os códigos retornados por DICInserirPalavra, mensagens informativas
    são exibidas para o usuário para avisar se uma nova palavra foi inserida, ou apenas um novo número de linha foi inserido
    ou se nada foi feito. Permite a inserção de várias palavras ao perguntar para o usuário no final da inserção se deseja ou
    não inserir outra palavra e também permite que o usuário insira vários números de linha de uma vez, na mesma palavra,
    separando-os com espaços. */
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
        printf("Qual palavra deseja adicionar ao Dicionário?\n");
        scanf("%s",novaPalavra);
        fgets(escolha,MAXCHARESCOLHA,stdin);

        printf("Em qual(is) linha(s) \"%s\" aparece?\n(Separe os números de linha com espaços)\n",novaPalavra);
        while (scanf("%d",&novoNLinha)!=EOF)
        {
            aviso = DICInserirPalavra(dicionario,novaPalavra,novoNLinha);

            if (aviso == OP_NOVAPALAVRA)
                printf("\nNova palavra, \"%s\", inserida com sucesso, com o número de linha %d!\n",novaPalavra,novoNLinha);
            else if (aviso == OP_SUCESSO)
                printf("\nNovo número de linha, %d, inserido na palavra \"%s\" com sucesso!\n",novoNLinha,novaPalavra);
            else
                printf("\nNenhuma nova palavra ou novo número de linha foi inserido.\n");

            novoNLinha = 0;
            if (getchar()=='\n')
                break;
        }

        printf("\nDeseja inserir outra palavra no Dicionário? (S/N)\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'N')
            controle = CTRL_PROSSEGUIR;

    }
}

/* 3 - Remover Palavra do Dicionário
    Permite ao usuário remover uma dada palavra do Dicionário. Antes de tentar realizar a operação, o programa pergunta
    ao usuário se ele tem certeza que quer remover a palavra, e depois, com a ajuda dos códigos retornados
    por DICRemoverPalavra, informa se a operação foi bem-sucedida ou não. Permite a remoção de várias palavras ao perguntar
    para o usuário no final da remoção se deseja ou não remover outra palavra. */
void UI_RemoverPalavra(TDicionario *dicionario)
{
    int controle = CTRL_REPETIR;

    char escolha[MAXCHARESCOLHA];
    char removerPalavra[MAXCHARPALAVRA];

    while (controle == CTRL_REPETIR)
    {
        UI_ImprimirCabecalho();
        printf("Qual palavra deseja remover do Dicionário?\n");
        scanf("%s",removerPalavra);
        fgets(escolha,MAXCHARESCOLHA,stdin);

        printf("\nTem certeza que deseja remover \"%s\" do Dicionário? (S/N)\n",removerPalavra);
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'S')
        {
            if (DICRemoverPalavra(dicionario,removerPalavra)==OP_SUCESSO)
                printf("\nPalavra \"%s\" removida com sucesso!\n",removerPalavra);
            else
                printf("\nPalavra \"%s\" não foi encontrada.\n",removerPalavra);
        }
        printf("\nDeseja retirar outra palavra do Dicionário? (S/N)\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'N')
            controle = CTRL_PROSSEGUIR;

    }
}

/* 4 - Exibir uma letra do Dicionário
    Exibe todas as entradas de uma dada letra para o usuário. Permite que o usuário insira outras letras para vê-las
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
            printf("\nEntrada inválida.\n");

        printf("\nDeseja exibir outra letra? (S/N)\n");
        fgets(escolha,MAXCHARESCOLHA,stdin);
        escolha[0] = toupper(escolha[0]);
        if (escolha[0] == 'N')
            controle = CTRL_PROSSEGUIR;
    }

}

/* 5 - Exibir Dicionário
    Exibe todas as letras com todas as entradas do Dicionário. */
void UI_ExibirDicio(TDicionario *dicionario)
{
    UI_ImprimirCabecalho();
    DICExibir(dicionario);
    printf("\nPressione ENTER para continuar.\n");
    getchar();
}

/*  6 - Ordenações
    Permite ao usuário escolher os métodos de ordenação e comparar seus tempos de execução, número de movimentações, etc. */
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
        printf("Escolha um algoritmo de ordenação para apresentar o Dicionário ordenado:\n\n");
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
                printf("Deseja visualizar todo o Dicionário ordenado ou apenas um letra? (D/L)\n");

                fgets(escolhaT,MAXCHARESCOLHA,stdin);

                escolhaT[0] = toupper(escolhaT[0]);
                if (escolhaT[0]=='L')
                {
                    printf("\nQual letra deseja visualizar?\n");
                    fgets(escolhaL,MAXCHARESCOLHA,stdin);
                    escolhaL[0] = toupper(escolhaL[0]);
                    if (escolhaL[0] < 'A' || escolhaL[0] > 'Z')
                    {
                        printf("\nEntrada inválida. Pressione ENTER para voltar.\n");
                        getchar();
                        continue;
                    }
                }
                else if (escolhaT[0]!='D')
                {
                    printf("Operação inválida. Pressione ENTER para voltar.\n");
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
                    printf(" <  Dicionário completo ordenado via %s  >\n\n",tiposOrdena[escolhaO[0]-'1']);
                    printf("Total de tempo gasto:   %lf s\tTempo gasto em média:   %lf s\n",tempo,tempo/NLETRAS);
                    printf("Total de comparações:   %8d\tComparações em média:   %8.2lf\n",comp,(comp*1.0)/(NLETRAS*1.0));
                    printf("Total de movimentações: %8d\tMovimentações em média: %8.2lf\n",mov,(mov*1.0)/(NLETRAS*1.0));
                }
                else
                {
                    DICExibirLetra(&copia,escolhaL[0]);
                    printf(" <  Letra %c ordenada via %s  >\n\n",escolhaL[0],tiposOrdena[escolhaO[0]-'1']);
                    printf("Tempo gasto: %lf s\n",tempo);
                    printf("Comparações: %d\n",comp);
                    printf("Movimentações: %d\n",mov);
                }


                printf("\nPressione ENTER para continuar.\n");
                getchar();
                controle = CTRL_PROSSEGUIR;
                break;

            }
        }
        else
        {
            printf("Operação inválida. Pressione ENTER para voltar.\n");
            getchar();
        }

    }
}


/* 7 - Sair do Dicionário
    Pergunta ao usuário se deseja realmente sair do programa e o encerra se a resposta for positiva ou volta ao menu
    caso a resposta seja negativa. */
void UI_Sair()
{
    char escolha[MAXCHARESCOLHA];
    printf("Deseja mesmo sair do Dicionário? (S/N)\n");
    fgets(escolha,MAXCHARESCOLHA,stdin);
    escolha[0] = toupper(escolha[0]);
    if (escolha[0] == 'S')
    {
        printf("Saindo do Dicionário...\nPressione ENTER para sair.\n");
        getchar();
        exit(0);
    }
}
