/*
	Bárbara de Oliveira Souza 3039
	Caio Augusto Moreira 3042
	Jose Grigorio Neto 3046

*/



#ifndef __APP__
#define __APP__

#include <gtk/gtk.h>
#include <string.h>

#include "arvore.h"

#define UI_DEFINITIONS_FILE "glade/bfind.glade"

#define GET_UI_ELEMENT(TYPE, ELEMENT)   TYPE *ELEMENT = (TYPE *) app_get_ui_element(app, #ELEMENT);

typedef struct app_ {
    GtkBuilder *definitions;
    GSList *objects;

    TPagina *Arvore;
} App;

void app_init (App * );
GObject * app_get_ui_element (App * , const gchar * );

#endif