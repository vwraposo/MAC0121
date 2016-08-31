/* O vetor dic[0..n-1] armazenara o dicionario e as frequencias 
// das palavras. O vetor e alocado dinamicamente e tem capacidade
// para N palavras e N frequencias. */
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

#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <stdio.h>

char **dic;
int n; 
int B;

/* Funçao que ira listar as palavras de um arquivo em um 
// dicionario num novo arquivo. Ela recebe como parametro os 
// os  nomes dados pelo usario para os arquivos */
void listapalavras (char *in, char *out);

/* Constroi o dicionario dic[0..n-1] de um arquivo de texto. 
// (As variaveis dic e n sao globais.) */
void constroiDicionario (FILE *entrada);

/* Le a proxima palavra do arquivo, e devolve essa palavra. 
// Se o arquivo estiver esgotado, devolve NULL. */
char *proximaPalavra (FILE *entradan);

/* Insere a string pal no dicionario dic[0..n-1] (se ela nao 
// estiver la) e atualiza o valor de n. O dicionario dic 
// permanece em ordem lexicografica se estiver em ordem 
// lexicografica antes da insercao. (As variaveis dic e n 
// sao globais.) */
void inserePalavra (char *palavra);

/* Cria um arquivo, com o nome determinado pelo usuario, com as 
// strings do vetor dic[0..n-1]*/
void imprimeDicionario (double start, char *out);

/* Expande o vetor de caracteres buffer[0..B-1] de modo que ele
// tenha o dobro da capacidade (portanto, o valor de B dobra)*/
void expandeBuffer ();

/* Expande o vetor de struct lista dic[0..N-1] demodo que ele 
//tenha o dobro da capacidade (portanto, o valor de N dobra).*/
void expandeDic ();

#endif