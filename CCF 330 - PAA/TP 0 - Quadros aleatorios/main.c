#include "Quadro.h"

//menu
void menu (){
    printf("\n==============================");
    printf("\n PABLO PICASSO SIMULATOR 2018");
    printf("\n==============================");
    printf("\nEscolha o tipo de figura basica a ser usada para criar sua obra de arte:");
    printf("\n1 - asterisco simples.");
    printf("\n2 - simbolo de soma com asteriscos.");
    printf("\n3 - letra X com asteriscos.");
    printf("\n4 - figuras aleatorias.");
    printf("\n5 - raios na tela. (max: 15)");
    printf("\n6 - espadas. (max: 25)");
    printf("\nDigite o tipo de figura basica desejada: ");
}

int main() {
    //declaracao de variaveis
    int i, j, x, y, opcao, numObj, objRdm, repeat = 1, randomFlag = 0;
    arte desenho;
    time_t t;

    //utilizando o tempo
    srand((unsigned) (&t));

    //inicializa o quadro
    desenhaquad(&desenho);
    menu();
    scanf("%d",&opcao);
    printf("\nDigite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    scanf("%d",&numObj);

    //tratando a quantidade de figuras
    if (numObj > 100){
        numObj = 100;
    }
    //repeticao do quadro
    while (repeat) {
        //switch do menu
        if(numObj <= 0 ||randomFlag == 1) {
            numObj = (rand() % 100);
            randomFlag = 1;
        }
        switch (opcao) {
            case 1:
                for (i = 0; i < numObj; i++) {
                    ast(&desenho);
                }
                break;
            case 2:
                //+
                for (i = 0; i < numObj; i++) {
                    plus(&desenho);
                }
                break;
            case 3:
                //com colisao X
                for (i = 0; i < numObj; i++) {
                    X(&desenho);
                }
                break;
            case 4:
                for (i = 0; i < numObj; i++) {
                    objRdm = (rand() % 3);   // 0, 1 ou 2
                    if (objRdm == 0) {
                        ast(&desenho);
                    }
                    if (objRdm == 1) {
                        plus(&desenho);
                    }
                    if (objRdm == 2) {
                        X(&desenho);
                    }
                }
                break;
            case 5:
                if(numObj > 15)
                    numObj = 15;
                for(i = 0; i < numObj;i++) {
                    fall(&desenho);
                }
                break;
            case 6:
                if(numObj > 25)
                    numObj = 25;
                for (i = 0; i < numObj; i++) {
                    sw(&desenho);
                }
                break;
            default:
                repeat = 0;
                break;
        }
        //mostrar obra de arte na tela
        desenha(desenho);
        desenhaquad(&desenho);
        printf("\n\nDigite 0 se deseja parar a repeticao: ");
        scanf("%d",&repeat);
    }
}
