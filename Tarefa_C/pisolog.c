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
// Data: 2015-08-15
// 
// Este arquivo faz parte da tarefa Piso de Log 
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/*///// Esse programa recebe um valor de B e um de K. Calcula
//o log na base 2 de B¹, B² ..... B^k e imprime em uma tabela.
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <limits.h>

// Funcoes:

/* A funcao "logaritimo" recebe um valor N e retorna o piso do
//logaritimo de B na base 2 
///////////////////////////////////////////////////////////////*/
int logaritimo (int N) {
    int count = 0;
    while (N > 1) {
        // Nesse ponto count e o numero de divisoes por dois 
        // feitas, que e o maximo e o logaritimo na base 2
        count++;
        N = N / 2; 
    }
    return count;
}

// Main :

int main (int argc, char *arg[]) {
    int B, K, i, pot;
    B = atoi (arg[1]);
    K = atoi (arg[2]);
    pot = B;
    printf ("Potencia | Logaritimo\n");
    printf ("---------------------\n"); 
    for (i = 1; i < K; i++) {
        printf ("%d | %d \n", i, logaritimo(pot));
        if (pot >= INT_MAX / B)   
            break;   
        pot *= B;
    }

    return 0;
}
