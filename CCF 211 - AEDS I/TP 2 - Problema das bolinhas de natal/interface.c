/* Interface
    Contém funções que vão permitir a interação do usuário com o programa. */

#include "interface.h"

void UI_LimparTela()
{
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void UI_Menu(TAdj *adj,TTimer *timer)
{
    char escolha[MAXCHARESCOLHA];

    while (1)
    {
        UI_Cabecalhos(CAB_MENU);
        printf("Qual operação  deseja realizar?\n");
        printf("1 - Testar casos\n");
        printf("2 - Mudar as cores\n");
        printf("3 - Sair\n\n");

        fgets(escolha,MAXCHARESCOLHA,stdin);

        switch (escolha[0])
        {
        case '1':
            UI_TestarCasos(adj,timer);
            break;
        case '2':
            UI_MudarCores(adj);
            break;
        case '3':
            UI_Sair();
            break;
        default:
            printf("Operação inválida. Pressione ENTER para voltar.\n");
            getchar();
            break;
        }
    }
}


void UI_TestarCasos(TAdj *adj,TTimer *timer)
{
    char escolha[MAXCHARESCOLHA];
    char nomeArquivo[MAXCHARDIRETORIO];
    char modelos[] = "adjX.txt";

    int resultado = 0;

    FILE *input = NULL;

    while (1)
    {
        UI_Cabecalhos(CAB_CASOS);

        fgets(escolha,MAXCHARESCOLHA,stdin);

        if (escolha[0]>='1' && escolha[0]<='4')
        {
            if (escolha[0]>='1' && escolha[0]<='3')
            {
                modelos[3] = escolha[0];
                input = fopen(modelos,"rt");
            }
            else
            {
                while (1)
                {
                    UI_Cabecalhos(CAB_CASOCUSTOM);
                    printf("Qual arquivo deseja carregar?\n");
                    printf("(Digite o caminho completo com barras separando os diretórios\nou digite apenas o nome do arquivo, caso esteja na mesma pasta do programa.)\n");
                    fgets(nomeArquivo,MAXCHARDIRETORIO,stdin);
                    nomeArquivo[strlen(nomeArquivo)-1] = '\0';
                    input = fopen(nomeArquivo,"rt");
                    if (input != NULL)
                    {
                        printf("\nArquivo \"%s\" lido com sucesso!\n",nomeArquivo);
                        printf("\nSua árvore será analisada. Pressione ENTER para continuar.\n");
                        getchar();
                        break;
                    }
                    else
                    {
                        printf("\nFalha ao abrir \"%s\".\nDeseja tentar ler outro arquivo? (S/N)\n",nomeArquivo);
                        fgets(escolha,MAXCHARESCOLHA,stdin);
                        escolha[0] = toupper(escolha[0]);
                        if (escolha[0] == 'N')
                            break;
                    }
                }
            }

            if (input==NULL)
                break;

            printf("Analisando... ");
            ADJPreencher(adj,input);
            TimerIniciar(timer);
            resultado = PRMArranjos(*adj);
            TimerParar(timer);
            printf("\n\nRESULTADO:\n");
            printf("Árvore de %d espaços\n",adj->n);
            printf("%d cores de bolinhas\n",adj->k);
            printf("%d arranjos possíveis\n",resultado);
            TimerMostrar(timer);

            printf("\nPressione ENTER para continuar.\n");
            getchar();
            break;
        }
        else
        {
            printf("Operação inválida. Pressione ENTER para tentar novamente.\n");
            getchar();
        }

    }
}

void UI_MudarCores(TAdj *adj)
{
    char escolha[MAXCHARESCOLHA];

    while (1)
    {
        UI_Cabecalhos(CAB_CORES);
        printf("Atualmente usando %d cores.\nQuantas cores de bolinha deseja utilizar?\n",adj->k);

        fgets(escolha,MAXCHARESCOLHA,stdin);

        if (atoi(escolha)>=2)
        {
            adj->k = atoi(escolha);
            printf("\nNúmero de cores trocado para %d!\nPressione ENTER para prosseguir.\n",adj->k);
            getchar();
            break;
        }
        else
        {
            printf("\nEntrada inválida.\n");
            printf("(Pelo menos 2 cores são necessárias para gerar arranjos válidos.)\n");
            printf("Pressione ENTER para tentar de novo.\n");
            getchar();
        }

    }

}

void UI_Sair()
{
    char escolha[MAXCHARESCOLHA];
    printf("Deseja mesmo sair? (S/N)\n");
    fgets(escolha,MAXCHARESCOLHA,stdin);
    escolha[0] = toupper(escolha[0]);
    if (escolha[0] == 'S')
    {
//        printf("Saindo...\nPressione ENTER para sair.\n");
//        getchar();
        exit(0);
    }
}

void UI_Cabecalhos(int c)
{
    UI_LimparTela();
    switch (c)
    {
    case CAB_MENU:
        printf("              ,\n");
        printf("            _/^\\_\n");
        printf("           <     >\n");
        printf("            /.-.\\\n");
        printf("            `/&\\`\n");
        printf("           ,@.*;@,\n");
        printf("          /_o.I %%_\\\n");
        printf("         (`'--:o(_@;\n");
        printf("        /`;--.,__ `')\n");
        printf("       ;@`o %% O,*`'`&\\\n");
        printf("      (`'--)_@ ;o %'()\\  \tPBN\n");
        printf("      /`;--._`''--._O'@;\tProblema das Bolinhas de Natal\n");
        printf("     /&*,()~o`;-.,_ `\"\"`)\n");
        printf("     /`,@ ;+& () o*`;-';\\\n");
        printf("    (`\"\"--.,_0 +%% @' &()\\\n");
        printf("    /-.,_    ``''--....-'`)\n");
        printf("    /@%%;o`:;'--,.__   __.'\\\n");
        printf("   ;*,&(); @ %% &^;~`\"`o;@();\n");
        printf("   /(); o^~; & ().o@*&`;&%%O\\\n");
        printf("   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n");
        printf("__.----.(\\-''#####---...___...-----._\n\n");
        break;
    case CAB_CASOS:
        printf("\t\t\t\t           .\n");
        printf("\t\t\t\t         _.|,_\n");
        printf("\t\t\t\t          '|`\n");
        printf("\t\t\t\t          / \\\n");
        printf("\t\t\t\t         /`,o\\\n");
        printf("Deseja carregar um dos modelos\t        /_* ~_\\\n");
        printf("de árvore de Natal...\t\t        / o .'\\\n");
        printf("\t\t\t\t       /_,~' *_\\\n");
        printf("\t\t\t\t       /`. *  *\\\n");
        printf("\t\t     .|,\t      /o  `~. o \\\n");
        printf("\t\t     -*-\t     /_ *    `~,_\\\n");
        printf("\t\t    '/'\\`\t     /   o  *  ~'\\\n");
        printf("\t\t    /`'o\\\t    / *    .~~'  o\\\n");
        printf("\t\t   /#,o'`\\\t   /_,.~~'` o  *  _\\\n");
        printf("      !	\t  o/`\"#,`\\o\t   /`~..  o    o   \\\n");
        printf("    -~*~-\t  /`o``\"#,\\\t  / *   `'~..   * o \\\n");
        printf("     /!\\\t o/#,`'o'`\\o\t /_o    o    ``~~.,,_\\\n");
        printf("    /%%;@\\\t /o`\"#,`',o\\\t /  *      *   o ..~'\\\n");
        printf("   o/@,%%\\o\to`-._`\"#_.-'o\t/*    o   _..~~`'*   o\\\n");
        printf("   /%%;`@,\\\t    _|\"|_\t`-.__.~'`'   *  o___.-'\n");
        printf("  o/@'%%',\\o\t    \\=%%=/\t      \":-------:\"\n");
        printf("  '^^^H^^^`\t     \"\"\"\t        \\_____/\n\n");
        printf("1) 10 espaços   2) 20 espaços         3) 30 espaços\n\n");
        printf("...ou deseja 4) montar sua própria árvore a partir de um arquivo?\n\n");
        break;
    case CAB_CASOCUSTOM:
        printf("\n           ( * )\n");
        printf("            /.\\\n");
        printf("           /..'\\\n");
        printf("           /'.'\\\n");
        printf("          /.''.'\\\tMonte sua própria árvore!\n");
        printf("          /.'.'.\\\n");
        printf("         /'.''.'.\\\n");
        printf("         ^^^[_]^^^\n\n");

        break;
    case CAB_CORES:
        printf("       ()\n");
        printf("      vvvv\n");
        printf("    .-\"  \"-.\n");
        printf("  .'___     `.\n");
        printf(" / /_/_/      \\     ____\n");
        printf("| /_/_/        |  .%%%%%%%%%%%%.\n");
        printf("|              | /%%/_/%%%%%%%%\\_\n");
        printf(" \\         .::::.%%%%%%%%%%%%%%%%(_{}-o\n");
        printf("  `.     .::::::::%%%%%%%%%%%%%%%%/\n");
        printf("    `-._/:/_/::::::\\%%%%%%%%%%'\n");
        printf("    o-3_)::::::::::|\"\"\"\"\n");
        printf("        \\::::::::::/\n");
        printf("         `::::::::'\n");
        printf("           `````'\n\n");
        break;
    }
}
