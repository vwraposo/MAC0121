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

#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct caixa {
    int cont;
    struct caixa *prox;   
};

typedef struct caixa celula;

struct no {
    char *str;
    celula *list;
    struct no *esq;
    struct no *dir;    
};
typedef struct no noh; 
    
typedef noh *arvore;

/* Devolve a altura da �rvore bin�ria cuja raiz � r.*/

int altura (arvore r);

/* A fun��o recebe uma �rvore de busca r e uma 
// folha novo que n�o pertence � �rvore.
// A fun��o insere a folha na �rvore 
// de modo que a �rvore continue sendo de busca
// e devolve o endere�o da �rvore resultante. */

arvore insere (arvore r, noh *novo) ;

/* Recebe uma string k e uma �rvore de busca r.
// Devolve um n� cuja string � k;
// se tal n� n�o existe, devolve NULL. */

noh *find (arvore r, char *k);

/* Recebe a raiz r de uma �rvore bin�ria.
// Imprime os conte�dos dos n�s em ordem e-r-d
// em um arquivo saida; */

void imprime (arvore r, FILE* saida);

/* Recebe uma arvore r;
// Da free em todos os n�s e seus conteudos */

void limpa_arvore (arvore r);

/* Recebe a raiz r de uma �rvore binaria. 
// Devolve o numero de n�s da arvore r */

int contanoh (arvore r);

#endif 