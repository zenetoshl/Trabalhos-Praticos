// LList -> Linked List, lista encadeada, para inteiros

#include "list.h"

//Inicializa a lista
LList LListCriar() {
	LList lista;
    lista.cabeca = (LListCel *)malloc(sizeof(LListCel));
    lista.cabeca->proximo = NULL;
    lista.ultimo = lista.cabeca;
    lista.tamanho = 0;
    return lista;
}

// Insere no final
int LListInserir(LList *lista, int i, int j) {
    lista->ultimo->proximo = (LListCel *)malloc(sizeof(LListCel));

    if (lista->ultimo->proximo == NULL)
        return 0;

    lista->ultimo->proximo->item.i = i;
    lista->ultimo->proximo->item.j = j;
    lista->ultimo->proximo->proximo = NULL;

    lista->ultimo = lista->ultimo->proximo;
    lista->tamanho++;
    return 1;
}

//Retira do começo
Indices LListRetirar(LList *lista) {
	LListCel *aux = lista->cabeca;
	Indices retirado = { -1, -1 };

	if (lista->tamanho != 0) {
        retirado = lista->cabeca->proximo->item;
        lista->cabeca = lista->cabeca->proximo;
        lista->tamanho--;
        free(aux);
    }
	
	return retirado;
}

// Retorna o tamanho da lista
int LListTamanho(LList lista) {
	return lista.tamanho;
}

// Desaloca todas as células da lista, incluindo a célula cabeça
//  (útil para evitar desperdício de memória)
void LListEsvaziar(LList *lista) {
	LListCel *atual = lista->cabeca;
    LListCel *anterior = NULL;
    while (atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }
    lista->cabeca = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void LListImprimir(LList *lista){
    LListCel *atual = lista->cabeca;
    while (atual->proximo != NULL) {
        printf("(%d, %d) ", atual->proximo->item.i, atual->proximo->item.j);
        atual = atual->proximo;
    }
    printf("\n");
}
