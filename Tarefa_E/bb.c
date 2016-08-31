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
#include <string.h>
#include "dicionario.h"

int
bb (char *s)
{
    int e, m, d;
    e = 0;
    d = n - 1;
    while (e < d) {
        m = (e + d) / 2;
        if (strcmp (dic[m], s) >= 0)
            d = m;
        else
            e = m + 1;
    }
    if (strcmp (dic[e], s) > 0)
        return e;
    return e + 1;

}
