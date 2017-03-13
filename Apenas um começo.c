#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// declaracao do TAD TPonto
typedef struct {
	int x, y;
	float dist;
} TPonto;

// declaracao do TAD TListaPonto
typedef struct {
	TPonto *elementos; // vetor de pontos
	int maximo; // quantidade maxima de pontos no vetor de pontos
	int qtdAtual; // quantidade atual de pontos no vetor de pontos
} TListaPonto;

typedef struct {
	TPonto *elementos; // vetor de pontos
	int maximo; // quantidade maxima de pontos no vetor de pontos
	int qtdAtual; // quantidade atual de pontos no vetor de pontos
} TLista;

// declaracao de funcoes
TListaPonto *Init( int N );
TLista *Calc(TListaPonto *lista);
void Desaloca( TListaPonto *lista, TLista *calc);
void insereFinal( TListaPonto *lista, TPonto p);
void imprimeListaPontos( TListaPonto *lista );
int AdicionarPontos(TListaPonto * Lista, TPonto P, int k);
int RemoverPonto (TListaPonto *lista, int k);
void lertxt (TListaPonto *lista, TPonto p);
int gravartxt (TListaPonto *lista, TPonto p);
void calculo (TListaPonto *lista, TPonto p, TLista *calc);
void printdist (TLista *calc);
void bubble (TLista *calc);


int i, j;

int main() {
	// declarando Lista de Pontos;
	TListaPonto *lista;
	TLista *calc;
	TPonto p;
	char opc;

	lista = Init( 1000 ); //cria um vetor de pontos com 1000 posicoes
	// faz o menu de opcoes
	do {
		printf("\t1 - Distancia entre pontos\n\n"
		       "\t2 - adicionar no final\n"
		       "\t3 - adicionar em uma dada posicao\n"
		       "\t4 - Remover Ponto em uma dada posição\n"
		       "\t5 - Informar Quantos Pontos tem na lista\n\n"
		       "\t8 - Ler arquivo.txt\n"
		       "\t9 - Gravar arquivo txt com atualizações\n\n"
		       "\t0 - Sair\n");
		opc = getchar();

		if( opc == '1') { //adicionar no final
			system ("cls");
			printf("Digite os valores de x,y (separados por virgula):");
			scanf("%d,%d",&p.x,&p.y);
			calculo(lista, p, calc);
			sleep (8);
			system ("cls");
		}


		if( opc == '2') { //adicionar no final
			system ("cls");
			printf("digite os valores de x,y (separados por virgula):");
			scanf("%d,%d",&p.x,&p.y);
			printf("\nlista de pontos:");
			insereFinal(lista,p);
			system ("cls");
			printf ("\tPonto adicionado com sucesso\n");
			sleep (2);
			system ("cls");
		}

		if( opc == '3') { //adicionar no final
			int k;
			system ("cls");
			printf ("Digite a posição que deseja colocar o ponto:");
			scanf ("%d", &k);
			printf ("digite os valores de x,y (separados por virgula):");
			scanf ("%d,%d", &p.x ,&p.y);
			printf ("\nlista de pontos:");
			AdicionarPontos (lista, p , k);
			system ("cls");
			printf ("\tPonto adicionado com sucesso\n");
			sleep (2);
			system ("cls");
		}

		if( opc == '4') { //adicionar no final
			int k;
			TPonto p;
			system ("cls");
			printf ("Digite a posição que deseja remover o ponto:");
			scanf ("%d", &k);
			RemoverPonto (lista, k);
			system ("cls");
			printf ("\tPonto Removido com sucesso\n");
			sleep (2);
			system ("cls");
		}


		if( opc == '5') { //adicionar no final
			system ("cls");

			if (lista->qtdAtual == 0) {
				printf ("\tNão existem pontos na lista!\n");
				sleep (2);
			} else {
				printf ("\tNesse Momento Existem %d pontos na lista\n", lista->qtdAtual);
				sleep (2);
			}
		}

		system ("cls");
		if( opc == '8') { //adicionar no final8
			lertxt (lista, p);
		}

		if( opc == '9') { //adicionar no final
			system ("cls");
			gravartxt (lista, p);
			system ("cls");
		}

		imprimeListaPontos( lista );
	} while (opc != '0');

	// libera a lista de pontos

	Desaloca(lista, calc);
}
// Função cria e devolve uma nova estrutura TListaPontos, inicializa os atributos da estrutura.
TListaPonto *Init( int N ) {

	TListaPonto *lista;

	lista = (TListaPonto*) calloc(1,sizeof(TListaPonto));
	lista->qtdAtual = 0;
	lista->maximo   = N;

	// aloca um vetor de pontos
	lista->elementos = (TPonto*) calloc(N,sizeof(TPonto));

	return lista;
}

TLista *Calc(TListaPonto *lista) {

	TLista *calc;

	calc = (TLista*) calloc(1, sizeof(TLista));
	calc->qtdAtual = lista->qtdAtual;
	calc->maximo   = lista->qtdAtual;

	// aloca um vetor de pontos
	calc->elementos = (TPonto*) calloc(lista->qtdAtual, sizeof(TPonto));

	return calc;
}
// Função desaloca a memoria utilizada por *listaPontos
void Desaloca( TListaPonto *lista, TLista *calc ) {
	// libera o vetor
	free (lista->elementos);
	free (calc->elementos);
	// libera a estrutura
	free (lista);
	free (calc);
}
// insere um ponto no final da lista de pontos
void insereFinal( TListaPonto *lista, TPonto p) {

	if( lista->qtdAtual < lista->maximo) {
		lista->elementos[lista->qtdAtual] = p;
		(lista->qtdAtual)++;

	}

	else printf("\nlista lotada\n");


}
// imprime a lista de pontos
void imprimeListaPontos( TListaPonto *lista ) {
	printf ("\tLista de pontos:\n");
	for(i=0; i<lista->qtdAtual; i++)
		printf("\t(%d,%d) ", lista->elementos[i].x,lista->elementos[i].y);
	printf("\n\n");
}

int AdicionarPontos (TListaPonto * Lista, TPonto P, int k) {

	if (Lista->qtdAtual == Lista->maximo) {
		printf("Lista lotada\n");
		return -1;
	}

	if (Lista->qtdAtual < k) {
		printf("Impossivel Adicionar\n");
		return -1;
	}


	for (i = Lista->maximo-1; i >= k; i--) {
		Lista->elementos[i] = Lista->elementos[i-1];
	}

	Lista->elementos[k-1] = P;
	(Lista->qtdAtual)++;

	return 1;

}

int RemoverPonto (TListaPonto *lista, int k) {

	if (lista->qtdAtual == lista->maximo) {
		printf("Lista Lotada\n");
		return -1;

	}
	if (lista->qtdAtual < k) {
		printf("Impossivel Remover\n");

		return -1;
	}

	for (i = k-1; i < lista->qtdAtual; i++) {
		lista->elementos[i] = lista->elementos[i+1];
		(lista->qtdAtual)--;

		return 1;
	}

}

void lertxt (TListaPonto *lista, TPonto p) {
	int num;

	FILE *open = fopen ("pontos.txt", "r");

	if (!open) printf ("Arquivo não encotrado");
	else {
		fscanf (open, "%d", &num);

		lista->qtdAtual = num;

		for (i = 0; i < num; i++) {
			fscanf (open, "%d,%d", &p.x, &p.y);
			lista->elementos[i] = p;
		}

		fclose (open);
	}
}

int gravartxt (TListaPonto *lista, TPonto p) {
	int Atual = lista->qtdAtual;

	FILE *open = fopen ("pontos.txt", "r+");

	if (!open) printf ("Arquivo não encotrado");

	else {
		fprintf (open, "%d\n", Atual);

		for (i = 0; i < Atual; i++)
			fprintf (open, "%d,%d\n", lista->elementos[i].x, lista->elementos[i].y);

		fclose (open);

		return 1;
	}

	return -1;
}

void calculo (TListaPonto *lista, TPonto p, TLista *calc) {
	float dist;
	calc = Calc(lista);

	for (i = 0; i < lista->qtdAtual; i++) {
		dist = sqrt ((pow ((lista->elementos[i].x - p.x), 2)) +  (pow ((lista->elementos[i].y - p.y), 2)));

		calc->elementos[i].x = lista->elementos[i].x;
		calc->elementos[i].y = lista->elementos[i].y;
		calc->elementos[i].dist = dist;

	}

	bubble (calc);

	for (i = 0; i < calc->qtdAtual; i++) {
		printf ("\t(%d,%d) Distancia: %.2f\n\n", calc->elementos[i].x, calc->elementos[i].y, calc->elementos[i].dist);
	}
}

void printdist (TLista *calc) {

	for (i = 0; i < calc->qtdAtual; i++) {
		printf("\t(%d,%d) distancia: %f\n", calc->elementos[i].x, calc->elementos[i].y, calc->elementos[i].dist);
		printf("\n\n");

	}
}

void bubble (TLista *calc) {
	TListaPonto *aux = Init(calc->qtdAtual);

	for (i = 0; i < calc->qtdAtual; i++) {
		for (j = 0; j < calc->qtdAtual-1; j++) {
			if (calc->elementos[j].dist > calc->elementos[j+1].dist) {
				aux->elementos[0].dist = calc->elementos[j].dist;
				calc->elementos[j].dist = calc->elementos[j+1].dist;
				calc->elementos[j+1].dist = aux->elementos[0].dist;
			}
		}
	}

}
