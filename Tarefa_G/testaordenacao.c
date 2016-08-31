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
// Data: 2015-10-13
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "ordenacao.h"

/* Verifica se o vetor v com 40.000 elementos, ordenado por um algoritmo 
// identificado pela variavel "alg", esta em ordem crescente */

void verify (int v[], int alg);

/* Cria um vetor v com 40.000 elementos gerados aleatoriamente */

void new_array (int v[]);

int 
main ()
{
    int v[40005];

    new_array (v);
    insertion_sort (v, 40000);
    verify (v, 1);

    new_array (v);
    merge_sort (v, 40000);
    verify (v, 2);

    new_array (v);
    quick_sort (v, 40000);
    verify (v, 3);

    new_array (v);
    heap_sort (v, 40000);
    verify (v, 4);

    return 0;
}

void 
verify (int v[], int alg)
{
    int i;
    for (i = 1; i < 40000; i++)
        if (v[i] < v[i-1]) {
            printf ("O vetor gerado pelo ");
            switch (alg) {
                case 1:
                    printf ("insertion sort ");
                    break;
                case 2:
                    printf ("merge sort ");
                    break;
                case 3:
                    printf ("quick sort ");
                    break;
                case 4:
                    printf ("heap sort ");
                    break;
            }
            printf ("nao esta em ordem crescente!\n");
            return;
        }
}

void 
new_array (int v[]) 
{
    int r, i;
    srand (time (NULL));
    for (i = 0; i < 40000; i++) {
        r = rand ();
        v[i] = r;
    }
}
