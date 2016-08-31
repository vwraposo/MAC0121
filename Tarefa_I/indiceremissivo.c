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
// Data: 2015-11-23
// 
// Este arquivo faz parte da tarefa I
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "dicionario.h"
#include "btree.h"

/* A função lg recebe um inteiro N > 0 
// e devolve o piso de log N. */

int lg (int N);

int main (int argnum, char *argv[]) {
    FILE *entrada, *saida;
    double start, finish, elapsed;
    arvore r;
    int n, lgn, h;
    entrada = fopen (argv[1], "r");
    saida = fopen (argv[2], "w");
    start = (double) clock () / CLOCKS_PER_SEC;

    r = constroiDic (entrada);

    finish = (double) clock () / CLOCKS_PER_SEC;
    elapsed = finish - start;
    printf ("Tempo Decorrido: %.3f\n", elapsed);
    imprime (r, saida);
    n = contanoh (r);
    lgn = lg (n);
    h = altura (r);
    printf ("Numero de nos: %d\n", n);
    printf ("Piso do lgn: %d\n", lgn);
    printf ("Altura da arvore: %d\n", h);


    fclose (entrada);
    fclose (saida);
    limpa_arvore (r);

    return 0;
}

int lg (int N) {  
    int i = 0, n = N;
    while (n > 1) {
        n = n / 2;
        i += 1;
    }
    return i;    
}