/*Aqui está definido a estrutura dos personagens */

#ifndef PERSONAGENS_H
#define PERSONAGENS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"

#define MAX_PERSONAGENS 21
#define MAX 100
#define MAX_EQUIPE 5
#define CUSTO_PERSONAGEM 3
#define CUSTO_RENOVAR 1

typedef struct {
  char nome[50];
  int vida;
  int ataque;
  int ocupado;
  int vida_original;
} Personagens;

typedef struct {
  int topo;
  Personagens item[MAX];
} tp_pilha;

typedef struct {
  Personagens equipe[MAX_EQUIPE];
  int vidaj;
  int ouro;
  int trofeus;
} Jogador;

void inicializarPilha(tp_pilha *p) { p->topo = -1; }

int pilhaVazia(tp_pilha *p) {
  if (p->topo == -1)
	return 1;
  return 0;
}

int pilhaCheia(tp_pilha *p) {
  if (p->topo == MAX - 1)
	return 1;
  return 0;
}

int push(tp_pilha *p, Personagens e) {
  if (pilhaCheia(p) == 1)
	return 0;
  p->topo++;
  p->item[p->topo] = e;
  return 1;
}

int pop(tp_pilha *p, Personagens *e) {
  if (pilhaVazia(p) == 1)
	return 0;
  *e = p->item[p->topo];
  p->topo--;
  return 1;
}

int top(tp_pilha *p, Personagens *e) {
  if (pilhaVazia(p))
	return 0;
  *e = p->item[p->topo];
  return 1;
}

void imprimePilha(tp_pilha p) {
  Personagens e;
  printf("\n");
  while (!pilhaVazia(&p)) {
	pop(&p, &e);
	printf("Nome: %s, Vida: %d, Ataque: %d\n", e.nome, e.vida, e.ataque);
  }
}

int alturaPilha(tp_pilha *p) { return p->topo + 1; }


	void criarAnimais(int numPersonagens, tp_pilha *p) {
  	Personagens personagem[MAX_PERSONAGENS];
  	srand(time(NULL)); // função usada para randomizar o nome dos personagens

  	for (int i = 0; i < MAX_PERSONAGENS; i++) {
    	switch (i) {
    	// código de inicialização dos personagens]
    	}
    	personagem[i].ocupado = 1;
  	}

  	for (int i = 0; i < MAX_PERSONAGENS; i++) {
    	int randnum = rand() % MAX_PERSONAGENS;
    	push(p, personagem[randnum]);

	switch (i) {
	case 0:
  	strcpy(personagem[i].nome, "Slifer, o Dragão Celeste");
  	personagem[i].vida = 10;
  	personagem[i].ataque = 5;
  	break;
	case 1:
  	strcpy(personagem[i].nome, "Dragao Branco de Olhos Azuis");
  	personagem[i].vida = 8;
  	personagem[i].ataque = 8;
  	break;
	case 2:
  	strcpy(personagem[i].nome, "Obelisco, o Atormentador");
  	personagem[i].vida = 9;
  	personagem[i].ataque = 7;
  	break;
	case 3:
  	strcpy(personagem[i].nome, "Exodia, O Proibido");
  	personagem[i].vida = 9;
  	personagem[i].ataque = 8;
  	break;
	case 4:
  	strcpy(personagem[i].nome, "Cyber Dragao");
  	personagem[i].vida = 6;
  	personagem[i].ataque = 4;
  	break;
	case 5:
  	strcpy(personagem[i].nome, "Jinzo - Returner");
  	personagem[i].vida = 5;
  	personagem[i].ataque = 3;
  	break;
	case 6:
  	strcpy(personagem[i].nome, "O Dragão Alado de Rá");
  	personagem[i].vida = 9;
  	personagem[i].ataque = 4;
  	break;
	case 7:
  	strcpy(personagem[i].nome, "Caveira Invocada Toon");
  	personagem[i].vida = 2;
  	personagem[i].ataque = 3;
  	break;
	case 8:
  	strcpy(personagem[i].nome, "Mago Negro");
  	personagem[i].vida = 5;
  	personagem[i].ataque = 5;
  	break;
	case 9:
  	strcpy(personagem[i].nome, "Dragão Negro de Olhos Vermelhos");
  	personagem[i].vida = 6;
  	personagem[i].ataque = 2;
  	break;
	case 10:
  	strcpy(personagem[i].nome, "O Cavaleiro do Pesadelo");
  	personagem[i].vida = 7;
  	personagem[i].ataque = 3;
  	break;
	case 11:
  	strcpy(personagem[i].nome, "Bubbleman");
  	personagem[i].vida = 4;
  	personagem[i].ataque = 2;
  	break;
	case 12:
  	strcpy(personagem[i].nome, "Soldado do Lustro Negro");
  	personagem[i].vida = 5;
  	personagem[i].ataque = 2;
  	break;
	case 13:
  	strcpy(personagem[i].nome, "Dragão Armado LV10");
  	personagem[i].vida = 7;
  	personagem[i].ataque = 3;
  	break;
	case 14:
  	strcpy(personagem[i].nome, "Dark Magician Girl");
  	personagem[i].vida = 5;
  	personagem[i].ataque = 3;
  	break;
	case 15:
  	strcpy(personagem[i].nome, "Neos");
  	personagem[i].vida = 5;
  	personagem[i].ataque = 2;
  	break;
	case 16:
  	strcpy(personagem[i].nome, "Avian");
  	personagem[i].vida = 4;
  	personagem[i].ataque = 2;
  	break;
	case 17:
  	strcpy(personagem[i].nome, "Mago Negro");
  	personagem[i].vida = 8;
  	personagem[i].ataque = 5;
  	break;
	case 18:
  	strcpy(personagem[i].nome, "Gaia, o Cavaleiro Impetuoso");
  	personagem[i].vida = 4;
  	personagem[i].ataque = 5;
  	break;
	case 19:
  	strcpy(personagem[i].nome, "Stardust Dragon");
  	personagem[i].vida = 6;
  	personagem[i].ataque = 3;
  	break;
	case 20:
  	strcpy(personagem[i].nome, "Kuriboh Alado");
  	personagem[i].vida = 3;
  	personagem[i].ataque = 1;
  	break;
	}
  }

  for (int i = 0; i < MAX_PERSONAGENS; i++) {
	int randnum = rand() % MAX_PERSONAGENS;
	push(p, personagem[randnum]);
  }
}
// Inventário do jogador
void inicializarJogador(Jogador *jogador) {
	jogador->vidaj = 5;
	jogador->trofeus = 0;
	jogador->ouro = 10;
	for (int i = 0; i < MAX_EQUIPE; i++) {
    	jogador->equipe[i].nome[0] = '\0';
    	jogador->equipe[i].vida = 0;
    	//jogador->equipe[i].vida_original = 0;
    	jogador->equipe[i].ataque = 0;
	}
}


void inserirPersonagemNaEquipe(Jogador *jogador, Personagens *personagem, int indice) {
	jogador->equipe[indice] = *personagem;
	jogador->equipe[indice].vida = personagem->vida_original; // Restaura a vida original
}


void exibirLoja(Personagens *loja) {
  printf("Loja:\n");
  for (int i = 0; i < 3; i++) {
	printf("%d. %s (Vida: %d, Ataque: %d)\n", i + 1, loja[i].nome, loja[i].vida, loja[i].ataque);
  }
}

void comprarPersonagem(Jogador *jogador, Personagens *loja, int indice){
  if (jogador->ouro >= CUSTO_PERSONAGEM) {
	for (int i = 0; i < MAX_EQUIPE; i++) {
  	if (jogador->equipe[i].nome[0] == '\0') {
    	jogador->equipe[i] = loja[indice];
    	jogador->ouro -= CUSTO_PERSONAGEM;
    	loja[indice].ocupado = 0; // Marca a posição na loja como vazia
    	printf("Você adquiriu %s.\n", loja[indice].nome);
    	return;
  	}
	}
	printf("Sua equipe está cheia.\n"); //modificar para algo legal
  } else {
	printf("Ta duro dorme.\n");
  }
}


void venderPersonagem(Jogador *jogador, int indice) {
  if (jogador->equipe[indice].nome[0] != '\0') {
	jogador->ouro += 1;
	printf("Você vendeu %s.\n", jogador->equipe[indice].nome);
	jogador->equipe[indice].nome[0] = '\0';
	jogador->equipe[indice].vida = 0;
	jogador->equipe[indice].ataque = 0;
  } else {
	printf("Cabô pai.\n");
  }
}

void renovarLoja(Personagens *loja, tp_pilha *pilha) {
  for (int i = 0; i < 3; i++) {
	pop(pilha, &loja[i]);
	loja[i].ocupado = 1;
  }
}

void mostrarTime(Jogador jogador) {
	printf("Time do jogador:\n");
	for (int i = 0; i < MAX_EQUIPE; i++) {
    	if (jogador.equipe[i].nome[0] != '\0') {
        	printf("%d. %s (Vida: %d, Ataque: %d)\n", i + 1, jogador.equipe[i].nome, jogador.equipe[i].vida, jogador.equipe[i].ataque);
    	}
	}
}

#endif