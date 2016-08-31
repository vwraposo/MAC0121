/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Victor Wichmann Raposo 
// Numero USP: 9298020 
// Sigla: VICTORWI
// Data: 2015-09-12
// 
// Este arquivo faz parte da tarefa E
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"
#include "bb.h"

char *getWord ();

int
main (int argc, char *argv[])
{
    char *s;
    int i;
    if (argc != 3) {
        fprintf (stderr, "USAGE: %s <input> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }
    listapalavras (argv[1], argv[2]);
    printf (">");
    s = getWord ();
    while (s != NULL) {
        i = bb (s);
        if (i == n && strcmp (dic[i - 1], s) <= 0)
            printf ("(%d, %s) ( )\n>", i - 1, dic[i - 1]);
        else if (i == 0)
            printf ("( ) (%d, %s)\n>", i, dic[i]);
        else
            printf ("(%d, %s) (%d, %s)\n>", i - 1, dic[i - 1], i, dic[i]);
        free (s);
        s = getWord ();
    }
    free (s);
    for (i = 0; i < n; i++)
        free (dic[i]);
    free (dic);
    return 0;
}

/* Funcao que recebera uma nova palavra do terminal */
char *
getWord ()
{
    int i = 0;
    char c;
    char *pal;
    pal = malloc (B * sizeof (char));
    do {
        c = getc (stdin);
        pal[i++] = tolower (c);
        if (i >= B / 2) {
            char *novapal;
            int i;
            novapal = malloc (2 * B * sizeof (char));
            for (i = 0; i < B; i++)
            novapal[i] = pal[i];
            B *= 2;
            free (pal);
            pal = novapal;
        }
    } while (c != '\n');
    if (pal[0] == '\n') {
        free (pal);
        return NULL;
    }
    pal[i] = '\0';

    return pal;
}

