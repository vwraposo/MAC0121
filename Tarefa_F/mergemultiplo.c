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
// Data: 2015-10-5
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "simplorio.h"
#include "sofisticado.h"

/* Funcao que recebe o arquivo de saida e verifica se ele esta em ordem 
// crescente */
void verifica (FILE *saida, int total);

int 
main (int argnum, char *argv[]) 
{
    int k, i, total;
    FILE **arquivo;
    FILE *saida;
    double start, finish, elapsed;

    k = argnum - 3;
    arquivo = malloc ((k + 1) * sizeof (FILE *));
    for (i = 2; i < argnum - 1; i++)
        arquivo[i - 1] = fopen (argv[i], "r");
    saida = fopen (argv[argnum - 1], "w");

    start = (double) clock () / CLOCKS_PER_SEC;
    if (strcmp (argv[1], "-s") == 0)
       total = simplorio (arquivo, saida, k);
    else
        total = sofisticado (arquivo, saida, k);
    finish = (double) clock () / CLOCKS_PER_SEC;
    elapsed = finish - start;

    printf ("Tempo decorrido: %f\n", elapsed);
    printf ("Numero de arquivos: %d\n", k);
    printf ("Quantidade de numeros: %d\n", total);

    for (i = 1 ; i <= k; i++)
        fclose (arquivo[i]);
    free (arquivo);

    saida = freopen (argv[argnum - 1], "r", saida);
    verifica (saida, total);
    fclose (saida);

    return 0;        
}

void 
verifica (FILE *saida, int total)
{
    int num, ant = INT_MIN, count = 0;
    while (fscanf (saida, "%d", &num) != EOF) {
        count++;
        if (num < ant) {
            printf ("O arquivo de saida nao esta em ordem crescente!\n");
        }
        ant = num;
    }
    if (count != total) 
        printf("A quantidade de numeros lidos difere de do total recebido!\n");

}
