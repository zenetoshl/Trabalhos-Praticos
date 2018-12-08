//
// Created by Jose on 08/08/18.
//

#include <printf.h>
#include "Quadro.h"
//checa se havera colisao no caso de desenhar um x
int checkx (arte desenho,int k,int l){
    if (desenho.quadro[l][k] != ' ' ||desenho.quadro[l+1][k+1] != ' ' ||
            desenho.quadro[l-1][k-1] != ' '||desenho.quadro[l-1][k+1] != ' '||
            desenho.quadro[l+1][k-1] != ' ') {
        return 0;
    }else return 1;
}
//checa se havera colisao no caso de desenhar uma espada
int checksw (arte desenho,int k,int l){
    if (desenho.quadro[l][k] != ' '|| desenho.quadro[l][k+1] != ' '||
            desenho.quadro[l + 1][k]!= ' '|| desenho.quadro[l + 2][k] != ' ' ||
            desenho.quadro[l-1][k - 1]!= ' ' || desenho.quadro[l-2][k - 1]!= ' ' ||
            desenho.quadro[l-3][k - 1]!= ' ' ||desenho.quadro[l-1][k + 1] != ' '||
            desenho.quadro[l-2][k + 1] != ' '||desenho.quadro[l-3][k + 1] != ' '||
            desenho.quadro[l-1][k] != ' '||desenho.quadro[l-2][k] != ' '||
            desenho.quadro[l-3][k] != ' '|| desenho.quadro[l][k - 1] != ' '||
            desenho.quadro[l][k - 2] != ' '|| desenho.quadro[l][k+2] != ' '){
        return 0;
    }else return 1;
}
//checa se havera colisao no caso de desenhar um sinal de soma
int checkplus (arte desenho,int k,int l){
    if (desenho.quadro[l][k] != ' ' ||desenho.quadro[l + 1][k] != ' ' ||
            desenho.quadro[l - 1][k] != ' '||desenho.quadro[l][k + 1] != ' '||
            desenho.quadro[l][k - 1] != ' '){
        return 0;
    }else return 1;
}
//desenha uma espada na coordenada gerada
void desenhasw (arte* desenho, int k, int l){
    desenho->quadro[l][k] = 'X';
    desenho->quadro[l][k+1] = '-';
    desenho->quadro[l][k+2] = '-';
    desenho->quadro[l + 1][k] = '|';
    desenho->quadro[l + 2][k] = '|';
    desenho->quadro[l-1][k - 1] = '|';
    desenho->quadro[l-2][k - 1] = '|';
    desenho->quadro[l-3][k - 1] = '|';
    desenho->quadro[l-4][k - 1] = '/';
    desenho->quadro[l-1][k + 1] = '|';
    desenho->quadro[l-2][k + 1] = '|';
    desenho->quadro[l-3][k + 1] = '|';
    desenho->quadro[l-4][k + 1] = '\\';
    desenho->quadro[l-1][k] = '*';
    desenho->quadro[l-2][k] = '*';
    desenho->quadro[l-3][k] = '*';
    desenho->quadro[l-4][k] = '^';
    desenho->quadro[l][k - 1] = '-';
    desenho->quadro[l][k - 2] = '-';
    return;
}
//desenha um x na coordenada gerada
void desenhax (arte* desenho, int k, int l){
    desenho->quadro[l][k] = '*';
    desenho->quadro[l + 1][k + 1] = '*';
    desenho->quadro[l - 1][k - 1] = '*';
    desenho->quadro[l - 1][k + 1] = '*';
    desenho->quadro[l + 1][k - 1] = '*';
    return;
}
//desenha um sinal de soma na coordenada gerada
void desenhaplus (arte* desenho,int k,int l){
    desenho->quadro[l][k] = '*';
    desenho->quadro[l + 1][k] = '*';
    desenho->quadro[l - 1][k] = '*';
    desenho->quadro[l][k + 1] = '*';
    desenho->quadro[l][k - 1] = '*';
    return;
}
//forma o quadro vazio
void desenhaquad (arte* desenho){
    int i,j;
    for(i = 0;i < M; i++){
        for(j = 0; j < N; j++){
            if(i==0||i==(M-1))
                desenho->quadro[i][j] = '-';
            else if (j == 0 || j == (N-1))
                desenho->quadro[i][j] = '|';
            else
                desenho->quadro[i][j] = ' ';
        }
    }
    return;
}
//desenha um asterisco na coordenada gerada
void ast(arte* desenho){
    int k,l;
    while(1) {
        k = 1 + (rand() % (N-2));
        l = 1 + (rand() % (M-2));
        if (desenho->quadro[l][k] == ' ') {
            desenho->quadro[l][k] = '*';
            break;
        }
    }
}
//mostra o quadro pronto na tela
void desenha (arte desenho){
    int i,j;
    for(i = 0;i < M; i++){
        printf("\n");
        for(j = 0; j < N; j++){
            printf("%c",desenho.quadro[i][j]);
        }
    }
}

//gera a coordenada e chama a funcao de checar e a de desenhar para o x
void X(arte* desenho){
    int j = 0, x, y;
    while(j == 0) {
        x = 2 + (rand() % (N-4));
        y = 2 + (rand() % (M-4));
        j = checkx(*desenho,x,y);
        if(j==1){
            desenhax(desenho,x,y);
        }
    }
}
//gera a coordenada e chama a funcao de checar e a de desenhar para o sinal de soma
void plus(arte* desenho){
    int j = 0, x, y;
    while(j == 0) {
        x = 2 + (rand() % (N-4));
        y = 2 + (rand() % (M-4));
        j = checkplus(*desenho,x,y);
        if(j==1){
            desenhaplus(desenho,x,y);
        }
    }
}
//gera a coordenada e chama a funcao de checar e a de desenhar para a espada
void sw(arte* desenho){
    int j = 0, x, y;
    while(j == 0) {
        x = 3 + (rand() % (N-6));
        y = 5 + (rand() % (M-8));
        j = checksw(*desenho,x,y);
        if(j==1){
            desenhasw(desenho,x,y);
        }
    }
}

void fall(arte* desenho){
    int i, j;
    int x, y;
    int op;
    char raio = '|';
    x = 1 + (rand()% N-2);
    for(i = 1; i <= (M-2); i++){
        y=i;
        op = (rand() % 2);
        switch (op){
            case 1:
                    x = x+1;
                    raio = '\\';
                break;
            case 0:
                    x = x-1;
                    raio = '\/';
                break;
        }
        if( x >= 1 && x <= 80)
            desenho->quadro[y][x] = raio;
    }

}


