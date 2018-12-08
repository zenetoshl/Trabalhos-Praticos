/* Adjac�ncias
    Conjunto de fun��es respos�veis por verificar as adjac�ncias, gerar os arranjos,
    al�m do "TAD" que vai representar as adjac�ncias, atrav�s de uma matriz. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **matriz;
    int n;
    int k;
} TAdj;

void ADJInicializar(TAdj *adj);
void ADJResetar(TAdj *adj);
void ADJMudarNumeroDeCores(TAdj *adj,int k);

int ADJPreencher(TAdj *adj,FILE *input);
int ADJVerificar(TAdj adj,int *arranjo);

int PRMArranjos(TAdj adj);
