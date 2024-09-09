
  /*AQUI ESTÁ DEFINIDO:
combate
empilhamento de animais
turnos
nome do time
*/
#include "fila.h"
#include "listade.h"
#include "personagens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ADJETIVOS 6
#define MAX_SUBSTANTIVOS 5
#define MAX_PERSONAGENS 21
#define MAX_NOME_TIME 50

void nomedoTime(char *adjetivo, char *substantivo, char *nome) {
  char *adjetivos[MAX_ADJETIVOS] = {"Baratino","Disgramado", "Migueloso","Malandro", "Barril", 	"La ele"};
  char *substantivos[MAX_SUBSTANTIVOS] = {"Guerreiro", "Herói", "Aventureiro",
"Explorador", "Cavaleiro"};

  int escolha_adjetivo, escolha_substantivo;

  printf("Escolha um adjetivo:\n");
  for (int i = 0; i < MAX_ADJETIVOS; i++) {
	printf("%d. %s\n", i + 1, adjetivos[i]);
  }
  printf("Digite o número do adjetivo escolhido: ");
  scanf("%d", &escolha_adjetivo);

  while (escolha_adjetivo < 1 || escolha_adjetivo > MAX_ADJETIVOS) {
	printf("Escolha inválida. Digite um número entre 1 e %d: ", MAX_ADJETIVOS);
	scanf("%d", &escolha_adjetivo);
  }

  printf("Escolha um substantivo:\n");
  for (int i = 0; i < MAX_SUBSTANTIVOS; i++) {
	printf("%d. %s\n", i + 1, substantivos[i]);
  }
  printf("Digite o número do substantivo escolhido: ");
  scanf("%d", &escolha_substantivo);

  while (escolha_substantivo < 1 || escolha_substantivo > MAX_SUBSTANTIVOS) {
	printf("Escolha inválida. Digite um número entre 1 e %d: ",
       	MAX_SUBSTANTIVOS);
	scanf("%d", &escolha_substantivo);
  }

  strcpy(adjetivo, adjetivos[escolha_adjetivo - 1]);
  strcpy(substantivo, substantivos[escolha_substantivo - 1]);

  printf("Digite o nome do time: ");
  scanf(" %[^\n]",
    	nome);
}
void digitarNomeTime(char *nomeTime) {
  printf("Digite o nome do time: ");
  scanf("%s", nomeTime);
}

void gravarCombate(Jogador *jogador, Jogador *inimigo, const char *nomeArquivo, const char *adjetivo, const char *substantivo, const char *nomeTime) {
	FILE *arquivo = fopen(nomeArquivo, "a");
	if (arquivo == NULL) {
    	printf("Erro ao abrir arquivo para gravar os detalhes do combate.\n");
    	return;
	}
	fprintf(arquivo, "DUELO:\n");
	fprintf(arquivo, "Nome do time: %s %s %s\n", nomeTime, substantivo, adjetivo);
 
	for (int i = 0; i < MAX_EQUIPE; i++) {
    	if (jogador->equipe[i].nome[0] != '\0' && inimigo->equipe[i].nome[0] != '\0') {
      	fprintf(arquivo,"Jogador: %s, Vida: %d, Ataque: %d VS Inimigo: %s, Vida: %d, " "Ataque: %d\n",jogador->equipe[i].nome, jogador->equipe[i].vida,jogador->equipe[i].ataque, inimigo->equipe[i].nome,inimigo->equipe[i].vida, inimigo->equipe[i].ataque);
}
	}
	fprintf(arquivo, "Número de troféus após combate: %d\n", jogador->trofeus);
	fprintf(arquivo, "Vida do jogador após combate: %d\n", jogador->vidaj);
	if (jogador->trofeus == 10) {
    	fprintf(arquivo, "Jogador venceu o jogo");
	}
fprintf(arquivo, "---------------------\n");
fclose(arquivo);
}

void lerCombates(const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
	printf("Erro ao abrir arquivo para ler os detalhes dos combates.\n");
	return;
  }

  char linha[256];
  while (fgets(linha, sizeof(linha), arquivo)) {
	printf("%s", linha);
  }
  fclose(arquivo);
}

  void combate(Jogador *jogador, Jogador *inimigo, const char *adjetivo, const char *substantivo, const char *nomeTime) {
	tp_fila filaJogador, filaInimigo;
	inicializaFila(&filaJogador);
	inicializaFila(&filaInimigo);

	// Inserir os personagens do jogador e do inimigo nas filas
	for (int j = 0; j < MAX_EQUIPE; j++) {
    	if (jogador->equipe[j].vida > 0) {
        	tp_item item;
        	strcpy(item.nome, jogador->equipe[j].nome);
        	item.vida = jogador->equipe[j].vida;
        	item.ataque = jogador->equipe[j].ataque;
        	insereFila(&filaJogador, item);
    	}
    	if (inimigo->equipe[j].vida > 0) {
        	tp_item item;
        	strcpy(item.nome, inimigo->equipe[j].nome);
        	item.vida = inimigo->equipe[j].vida;
        	item.ataque = inimigo->equipe[j].ataque;
        	insereFila(&filaInimigo, item);
    	}
	}

   
	while (!filaVazia(&filaJogador) && !filaVazia(&filaInimigo)) {
    	tp_item pj, pi;

    	acessarPrimeiro(&filaJogador, &pj);
    	acessarPrimeiro(&filaInimigo, &pi);

    	printf("\nDUELO: %s (Vida: %d, Ataque: %d) vs %s (Vida: %d, Ataque: %d)\n",
           	pj.nome, pj.vida, pj.ataque, pi.nome, pi.vida, pi.ataque);

   	 
    	while (pj.vida > 0 && pi.vida > 0) {
        	pj.vida -= pi.ataque;
        	pi.vida -= pj.ataque;

        	if (pj.vida > 0) {
            	printf("%s do jogador continua lutando! (Vida restante: %d)\n", pj.nome, pj.vida);
        	} else {
            	printf("%s desmaiou!\n", pj.nome);
        	}

        	if (pi.vida > 0) {
            	printf("%s do inimigo continua lutando! (Vida restante: %d)\n", pi.nome, pi.vida);
        	} else {
            	printf("%s desmaiou!\n", pi.nome);
        	}
    	}

   	 
    	if (pj.vida <= 0 && pi.vida <= 0) {
        	printf("Empate entre %s e %s!\n", pj.nome, pi.nome);
        	removeFila(&filaJogador, &pj);
        	removeFila(&filaInimigo, &pi);
    	} else if (pj.vida > 0) {
        	removeFila(&filaInimigo, &pi);
    	} else {
        	removeFila(&filaJogador, &pj);
    	}
	}


	if (filaVazia(&filaJogador) && filaVazia(&filaInimigo)) {
    	printf("\nO combate terminou em empate.\n");
	} else if (filaVazia(&filaJogador)) {
    	printf("\nVocê perdeu o combate.\n");
    	jogador->vidaj -= 1;
    	if (jogador->vidaj == 0) {
        	printf("Perdeu playboy.\n");
    	}
	} else {
    	printf("\nVocê venceu o combate.\n");
    	jogador->trofeus += 1;
    	if (jogador->trofeus == 10) {
        	printf("Mission complete, RESPECT+ !\n");
    	}
	}


	gravarCombate(jogador, inimigo, "combates.txt", adjetivo, substantivo, nomeTime);


}

int main() {
  tp_pilha pilha;
  inicializarPilha(&pilha);

  char adjetivo[50];
  char substantivo[50];
  char nomeTime[MAX_NOME_TIME];
 
  nomedoTime(adjetivo, substantivo, nomeTime);
  printf("Nome do time: %s %s %s\n", nomeTime, substantivo, adjetivo);
 
  criarAnimais(MAX_PERSONAGENS, &pilha);

  tp_listad *lista = inicializa_listad();
  Personagens loja[3];

  renovarLoja(loja, &pilha);
  for (int i = 0; i < 3; i++) {
	insere_listad_no_fim(lista, loja[i]);
  }

  Jogador jogador;
  inicializarJogador(&jogador);

  int turno = 1;
  while (jogador.vidaj > 0 && jogador.trofeus < 10) {
	Jogador inimigo;
	inicializarJogador(&inimigo);
	for (int i = 0; i < MAX_EQUIPE; i++) {
  	pop(&pilha, &inimigo.equipe[i]);
	}

	printf("\n----- Turno %d -----\n", turno);
	jogador.ouro = 10;
	printf("Ouro do Jogador: %d\n", jogador.ouro);
	printf("Vida do jogador: %d\n", jogador.vidaj);
	printf("Troféus do jogador: %d\n\n", jogador.trofeus);
	printf("\nTime do jogador:\n");
	for (int i = 0; i < MAX_EQUIPE; i++) {
  	if (jogador.equipe[i].nome[0] != '\0') {
    	printf("%d. %s (Vida: %d, Ataque: %d)\n", i + 1, jogador.equipe[i].nome,
           	jogador.equipe[i].vida, jogador.equipe[i].ataque);
  	}
	}

	exibirLoja(loja);

	int acao;
	do {
  	printf("\n1. Comprar monstro\n2. Vender monstro\n3. Renovar loja\n4. Ir para "
         	"combate\n5. Ver histórico de combates\nEscolha: ");
  	scanf("%d", &acao);
  	if (acao == 1) {
    	int indice;
    	printf("Digite o índice do monstro para comprar (1-3): ");
    	scanf("%d", &indice);
    	if (indice >= 1 && indice <= 3 && loja[indice - 1].ocupado) {
      	comprarPersonagem(&jogador, loja, indice - 1);
      	printf("Ouro do Jogador: %d\n", jogador.ouro);
    	} else {
      	printf("Posição vazia.\n");
    	}
  	} else if (acao == 2) {
    	int indice;
    	printf("Digite o índice do monstro para vender (1-5): ");
    	scanf("%d", &indice);
    	if (indice >= 1 && indice <= 5) {
      	venderPersonagem(&jogador, indice - 1);
      	printf("Ouro do Jogador: %d\n", jogador.ouro);
    	} else {
      	printf("Índice inválido.\n");
    	}
  	} else if (acao == 3) {
    	if (jogador.ouro >= CUSTO_RENOVAR) {
      	jogador.ouro -= CUSTO_RENOVAR;
      	renovarLoja(loja, &pilha);
      	printf("Ouro do Jogador: %d\n", jogador.ouro);
      	exibirLoja(loja);
    	} else {
      	printf("Ouro insuficiente.\n\n");
    	}
  	} else if (acao == 5) {
    	lerCombates("combates.txt");
  	}
	} while (acao != 4);

	combate(&jogador, &inimigo, adjetivo, substantivo, nomeTime);
	turno++;
  }

  return 0;
}