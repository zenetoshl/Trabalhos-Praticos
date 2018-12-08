/*
	Bárbara de Oliveira Souza 3039
	Caio Augusto Moreira 3042
	Jose Grigorio Neto 3046

*/



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "APP.h"


void arquiv_clicked_cb(GtkButton *Button, App *app)
{
 	GET_UI_ELEMENT (GtkWidget, saida);
 	GET_UI_ELEMENT (GtkWidget, entry2);
 	FILE *entrada;
 	char caracter[30];
 	char buffer[300];
 	strcpy(caracter,gtk_entry_get_text(GTK_ENTRY(entry2)));
 	entrada = fopen(caracter,"r");
 	if(entrada == NULL)
  	{
    	sprintf(buffer, "Arqquivo não encontrado");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
  	}
  	else
  	{   //Atento ao X.chave   			                  
  		while (fscanf(entrada,"%d",&x.Chave) != EOF)
  			//Insere
  	}
 }


void remover_clicked_cb(GtkButton *Button, App *app)
{
 	GET_UI_ELEMENT (GtkWidget, saida);
 	GET_UI_ELEMENT (GtkWidget, entry1);
	char caracter[30];
 	char buffer[300];
 	strcpy(caracter,gtk_entry_get_text(GTK_ENTRY(entry1)));

 	if //REgistro existe e foi removido
 		sprintf(buffer, "Removido com sucesso");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
    }
    if //Se nao remove pq nao tem 
 		sprintf(buffer, "Matrícula não encontrada");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
    }
  	
}


void inserir_clicked_cb(GtkButton *Button, App *app)
{
 	GET_UI_ELEMENT (GtkWidget, saida);
 	GET_UI_ELEMENT (GtkWidget, entry1);
	char caracter[30];
 	char buffer[300];
 	strcpy(caracter,gtk_entry_get_text(GTK_ENTRY(entry1)));

 	if //Se inseriu 
 		sprintf(buffer, "Inserido com sucesso");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
    }
    if //SE ja tem e nao insere
     	sprintf(buffer, "Matricula ja se encontra na arvore");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
    }
  	
}



void pesquisa_clicked_cb(GtkButton *Button, App *app)
{
 	GET_UI_ELEMENT (GtkWidget, saida);
 	GET_UI_ELEMENT (GtkWidget, entry1);
	char caracter[30];
 	char buffer[300];
 	strcpy(caracter,gtk_entry_get_text(GTK_ENTRY(entry1)));

 	if //(pesquisa==0){
 		sprintf(buffer, "Matricula não encontrada");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
    }
    if //(pesquisa==1){
 		sprintf(buffer, "Matricula encontrada");
    	gtk_label_set_text(GTK_LABEL(saida),buffer);
    }
  	
}



        
            