/* Adjacências
    Conjunto de funções resposáveis por verificar as adjacências, gerar os arranjos,
    além do "TAD" que vai representar as adjacências, através de uma matriz. */

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
