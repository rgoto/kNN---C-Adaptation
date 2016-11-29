#include <stdio.h>
#include <stdlib.h>

// declaracao do TAD TPonto
typedef struct{
    int x, y;
}TPonto;

// declaracao do TAD TListaPonto
typedef struct{
    TPonto *elementos; // vetor de pontos
    int maximo; // quantidade maxima de pontos no vetor de pontos
    int qtdAtual; // quantidade atual de pontos no vetor de pontos
}TListaPonto;

// declaracao de funcoes
TListaPonto *Init( int N );
void Desaloca( TListaPonto *lista);
void insereFinal( TListaPonto *lista, TPonto p);
void imprimeListaPontos( TListaPonto *lista );
int AdicionarPontos(TListaPonto * Lista, TPonto P, int k);
int RemoverPonto (TListaPonto *lista, int k);
void lertxt (TListaPonto *lista, TPonto p);
int gravartxt (TListaPonto *lista, TPonto p);

int i;

int main(){
    // declarando Lista de Pontos;
    TListaPonto *lista;
    TPonto p;
	char opc;

    lista = Init( 1000 ); //cria um vetor de pontos com 1000 posicoes
	
    // faz o menu de opcoes
    do{
        printf("1 - adicionar no final\n"
               "2 - adicionar em uma dada posicao\n"
               "3 - Remover Ponto em uma dada posição\n"
               "4 - Informar Quantos Pontos tem na lista\n"
               "5 - Ler arquivo.txt\n"
               "6 - Gravar arquivo txt com atualizações\n"
               "7 - sair\n");
        opc = getchar();

        if( opc == '1'){ //adicionar no final
            TPonto p;
            printf("digite os valores de x,y (separados por virgula):");
            scanf("%d,%d",&p.x,&p.y);
            printf("\nlista de pontos:");
            insereFinal(lista,p);
        }
        
         if( opc == '2'){ //adicionar no final
            int k;
            printf ("Digite a posição que deseja colocar o ponto:");
            scanf ("%d", &k);
			printf ("digite os valores de x,y (separados por virgula):");
            scanf ("%d,%d", &p.x ,&p.y);
            printf ("\nlista de pontos:");
            AdicionarPontos (lista, p , k);
        }
        
        if( opc == '3'){ //adicionar no final
            int k;
            TPonto p;
            printf ("Digite a posição que deseja remover o ponto:");
            scanf ("%d", &k);
            RemoverPonto (lista, k);
		}
		
		
		if( opc == '4'){ //adicionar no final
        	if (lista->qtdAtual == 0)
        		printf ("\tNão existem pontos na lista!\n");
        	else
        		printf ("\tNesse Momento Existem %d pontos na lista\n", lista->qtdAtual);
		}
		
		
		if( opc == '5'){ //adicionar no final
           lertxt (lista, p);
        }
        
        if( opc == '6'){ //adicionar no final
            gravartxt (lista, p);
        }
        
        imprimeListaPontos( lista );
    }while (opc != '7');

    printf("\nfim do programa\n");
    // libera a lista de pontos

    Desaloca(lista);
}
// Função cria e devolve uma nova estrutura TListaPontos, inicializa os atributos da estrutura.
TListaPonto *Init( int N ){

    TListaPonto *lista;

    lista = (TListaPonto*) calloc(1,sizeof(TListaPonto));
    lista->qtdAtual = 0;
    lista->maximo   = N;

    // aloca um vetor de pontos
    lista->elementos = (TPonto*) calloc(N,sizeof(TPonto));

    return lista;
}
// Função desaloca a memoria utilizada por *listaPontos
void Desaloca( TListaPonto *lista){
    // libera o vetor
    free(lista->elementos);
    // libera a estrutura
    free(lista);
}

// insere um ponto no final da lista de pontos
void insereFinal( TListaPonto *lista, TPonto p){

    if( lista->qtdAtual < lista->maximo){
	    lista->elementos[lista->qtdAtual] = p;
        (lista->qtdAtual)++;
   
    }
    
	else printf("\nlista lotada\n");


}
// imprime a lista de pontos
void imprimeListaPontos( TListaPonto *lista ){
    int i;
    for(i=0;i<lista->qtdAtual;i++)
        printf("(%d,%d) ", lista->elementos[i].x,lista->elementos[i].y);
    printf("\n\n");
}

int AdicionarPontos (TListaPonto * Lista, TPonto P, int k){
	
	if (Lista->qtdAtual == Lista->maximo) {
		printf("Lista lotada\n");
		return -1;
	}
		
	if (Lista->qtdAtual < k) {
		printf("Impossivel Adicionar\n");
		return -1;
	}
	
		
	for (i = Lista->maximo-1; i >= k; i--){
		Lista->elementos[i] = Lista->elementos[i-1];
	}
	
	Lista->elementos[k-1] = P;
	(Lista->qtdAtual)++;
	
return 1;

}

int RemoverPonto (TListaPonto *lista, int k){
	
	if (lista->qtdAtual == lista->maximo){
		printf("Lista Lotada\n");
		return -1;
	
	} if (lista->qtdAtual < k){
		printf("Impossivel Remover\n");
		
		return -1;
	}
	
	for (i = k-1; i < lista->qtdAtual; i++){
		lista->elementos[i] = lista->elementos[i+1];
		(lista->qtdAtual)--;
		
		return 1;
	}
	
}

void lertxt (TListaPonto *lista, TPonto p){
	int num;
	
	FILE *open = fopen ("pontos.txt", "r");
	
	if (!open) printf ("Arquivo não encotrado");
	else {
	fscanf (open, "%d", &num);
	
	lista->qtdAtual = num;
		
		for (i = 0; i < num; i++){		
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
