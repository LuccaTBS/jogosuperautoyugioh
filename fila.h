#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include "personagens.h"
#define MAX 100

typedef struct {
  char nome[50];
  int vida;
  int ataque;
  int indice;
} Personagens1;

typedef Personagens1 tp_item;
typedef struct {
  tp_item item[MAX];
  int ini, fim;
} tp_fila;

// Inicia a fila
void inicializaFila(tp_fila *f) {
  f->ini = f->fim = MAX-1;
}

// Se o início for igual ao fim, significa que a fila está vazia
int filaVazia(tp_fila *f) {
  return f->ini == f->fim;
}

int proximo(int pos) {
  return (pos == MAX-1) ? 0 : ++pos;
}

int filaCheia(tp_fila *f) {
  return proximo(f->fim) == f->ini;
}

int insereFila(tp_fila *f, tp_item Personagens1) {
  if (filaCheia(f))
	return 0; // Diz que não foi possível adicionar na fila
  f->fim = proximo(f->fim);
  f->item[f->fim] = Personagens1;
  return 1;
}

int removeFila(tp_fila *f, tp_item *e) {
  if (filaVazia(f))
	return 0; // Diz que não foi possível remover da fila
  f->ini = proximo(f->ini);
  *e = f->item[f->ini];
  return 1;
}

// Função para acessar o primeiro item da fila sem removê-lo
int acessarPrimeiro(tp_fila *f, tp_item *e) {
  if (filaVazia(f))
	return 0; // Diz que não foi possível acessar o item
  *e = f->item[proximo(f->ini)];
  return 1;
}

void imprimeFila(tp_fila f) {
  tp_item e;
  printf("\n");
  while (!filaVazia(&f)) {
	removeFila(&f, &e);
	printf("%s (Vida: %d, Ataque: %d)\n", e.nome, e.vida, e.ataque);
  }
}

int tamFila(tp_fila *f) {
  if (filaVazia(f)) return 0;
  if (f->ini < f->fim) return f->fim - f->ini;
  return MAX-1 - f->ini + f->fim + 1;
}
#endif