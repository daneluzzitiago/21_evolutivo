//.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "baralho.h"

struct baralho{
	struct carta *primeira;
	int tam;
};

typedef struct carta{
	struct carta *prox;
	int valor;
	char *naipe;
}carta;

BARALHO* iniciaBaralho(){
	BARALHO *b = (BARALHO*)malloc(sizeof(BARALHO));
	b->tam = 0;
	b->primeira = NULL;
	return b;
}

void liberaBaralho(BARALHO *b){
	free(b);
	return;
}

void insereCarta(BARALHO *b, int valor, char *naipe){
	carta *c = (carta*)malloc(sizeof(carta));
	c->valor = valor;
	if (valor == 'J'){
		valor = 11;
	}else if (valor == 'Q'){
		valor = 12;
	}else if (valor == 'K'){
		valor = 13;
	}else if (valor == 'A'){
		valor = 14;
	}
	c->naipe = naipe;
	c->prox == NULL;
	if(b->primeira == NULL){
		b->primeira = c;
	} else{
		carta *aux = (carta*)malloc(sizeof(carta));
		aux = b->primeira;
		int i;
		for( i = 1 ; i < b->tam; i++){
			aux = aux->prox;
		}
		aux->prox = c;	
		c->prox = NULL;
	}
	b->tam++;	
	return;
}

void printaBaralho(BARALHO *b){
	if(b == NULL || b->tam == 0){
		printf("Baralho vazio\n");
	}
	int i;
	carta *c = (carta*)malloc(sizeof(carta));
	c = b->primeira;
	while (c != NULL){
		if (c->valor == 'J'){
			printf("Valete de %s\n",c->naipe);
		} else if(c->valor == 'Q'){
			printf("Dama de %s\n", c->naipe);
		}else if(c->valor == 'K'){
			printf("Rei de %s\n", c->naipe);
		}else if(c->valor == 'A'){
			printf("As de %s\n", c->naipe);
		}else{
			printf("%d de %s\n",c->valor,c->naipe);
		}
		c = c->prox;
	}
	return;
}

void insereBaralhoComum(BARALHO *b){
	insereCarta(b,2,"paus");insereCarta(b,2,"espadas");insereCarta(b,2,"copas");insereCarta(b,2,"ouros");
	insereCarta(b,3,"paus");insereCarta(b,3,"espadas");insereCarta(b,3,"copas");insereCarta(b,3,"ouros");
	insereCarta(b,4,"paus");insereCarta(b,4,"espadas");insereCarta(b,4,"copas");insereCarta(b,4,"ouros");
	insereCarta(b,5,"paus");insereCarta(b,5,"espadas");insereCarta(b,5,"copas");insereCarta(b,5,"ouros");
	insereCarta(b,6,"paus");insereCarta(b,6,"espadas");insereCarta(b,6,"copas");insereCarta(b,6,"ouros");
	insereCarta(b,7,"paus");insereCarta(b,7,"espadas");insereCarta(b,7,"copas");insereCarta(b,7,"ouros");
	insereCarta(b,8,"paus");insereCarta(b,8,"espadas");insereCarta(b,8,"copas");insereCarta(b,8,"ouros");
	insereCarta(b,9,"paus");insereCarta(b,9,"espadas");insereCarta(b,9,"copas");insereCarta(b,9,"ouros");
	insereCarta(b,10,"paus");insereCarta(b,10,"espadas");insereCarta(b,10,"copas");insereCarta(b,10,"ouros");
	insereCarta(b,'J',"paus");insereCarta(b,'J',"espadas");insereCarta(b,'J',"copas");insereCarta(b,'J',"ouros");
	insereCarta(b,'Q',"paus");insereCarta(b,'Q',"espadas");insereCarta(b,'Q',"copas");insereCarta(b,'Q',"ouros");
	insereCarta(b,'K',"paus");insereCarta(b,'K',"espadas");insereCarta(b,'K',"copas");insereCarta(b,'K',"ouros");
	insereCarta(b,'A',"paus");insereCarta(b,'A',"espadas");insereCarta(b,'A',"copas");insereCarta(b,'A',"ouros");
}

void removeCarta(BARALHO *b, int valor, char *naipe){
	carta *aux = (carta*)malloc(sizeof(carta));
	aux = b->primeira;
	//Caso em que a carta está na primeira posição
	if (b->primeira->valor == valor && strcmp(b->primeira->naipe,naipe) == 0){
		b->primeira = b->primeira->prox;
		free(aux);	
		b->tam--;
		return;
	}else{
		int iterador = b->tam-1;
		while (iterador > 0){
			if ( aux->prox->valor == valor && strcmp( (aux->prox->naipe) , (naipe) ) == 0){ //testa se a próxima carta é o que procura
				//printf("%d de %s eh igual a %d de %s\n",aux->prox->valor,aux->prox->naipe,valor,naipe);
				//Caso em que a carta está na última posição
				if (aux->prox->prox == NULL){
					free(aux->prox);
					b->tam--;
					return;
				}else{
					//Caso em que está entre outras duas cartas
					carta *temp = (carta*)malloc(sizeof(carta));
					temp = aux->prox;
					aux->prox = temp->prox;
					free(temp);
					b->tam--;
					return;
				}
			}
			//printf("%d de %s eh diferente de %d de %s\n",aux->prox->valor,aux->prox->naipe,valor,naipe);
			aux = aux->prox;
			iterador--;
		}
		//Só vai sair do while se a carta não existir. Nesse caso printa uma mensagem de erro
		printf("Carta nao encontrada\n");
		return;
	}
	

	
	
}

carta* aleatoria(BARALHO *b){
	
	
}

void embaralha(BARALHO *b, int seed){
	BARALHO *a = iniciaBaralho();
	int i,j;
	carta 	*aux = (carta*)malloc(sizeof(carta));
	int aux_tam = b->tam;
	for 	( i = 0 ; i < aux_tam ; i++){
		aux = b->primeira;
		j = seed%b->tam;
		while ( j > 0 ){
			aux = aux->prox;
			j--;
		}
		insereCarta(a,aux->valor,aux->naipe);
		removeCarta(b,aux->valor,aux->naipe);
	}
	b->primeira = a->primeira;
	b->tam = a->tam;
	free(a);
	return;
}

int tamanhoBaralho	(BARALHO* b){
	return b->tam;
}

void ordena(BARALHO *b){
	if (b->tam <= 1) {	//Com 1 elemento ou nenhum elemento não há nada a se fazer, já está ordenado
		return;
	}
	BARALHO *a = iniciaBaralho();
	carta *aux = (carta*)sizeof(carta);
	aux = b->primeira;
	
	int *valores  = (int*)	malloc(sizeof (int)	 *b->tam);
	char **naipes = (char**)malloc(sizeof (char*)*b->tam);
	int i,j;
	
	for ( i = 0; i < b->tam; i++){
		if (aux->valor == 'J'){
			valores[i] = 11;
		} else if(aux->valor == 'Q'){
			valores[i] = 12;
		} else if(aux->valor == 'K'){
			valores[i] = 13;
		} else if(aux->valor == 'A'){
			valores[i] = 14;
		} else{
			valores[i] = aux->valor;
		}
		naipes[i]  = aux->naipe;	
		if (aux->prox != NULL){
			aux = aux->prox;
		}
	}
	int menor,aux_v;
	char *aux_n;
	for ( i = 0; i < b->tam; i++){
		menor = i;
		for ( j = i+1 ; j < b->tam ; j++){
			if ( valores[j] < valores[menor]){
				menor = j;
				//printf("Debugger: %d eh menor que %d\n",valores[j],valores[i]);
			} else if (valores[j] == valores[menor]){
				if ( strcmp(naipes[j],"paus" ) == 0){
					menor = j;
				}else if ( strcmp(naipes[j],"copas") == 0 && strcmp(naipes[menor],"paus") != 0){
					menor = j;
				}else if ( strcmp(naipes[j],"espadas") == 0 && strcmp(naipes[menor],"paus") != 0 && strcmp(naipes[menor],"copas") != 0){
					menor = j;
				}
				// i = 0
				// j = 2
				// menor = 0 
				// 0 1 2 3 4 5 6 7 8 9 posicao
				// 3 7 3 2 7 3 8 5 2 6 valores
				// p c c o e e c p c e naipes
				
			}
		}
		aux_v 		= valores	[i];
		aux_n 		= naipes	[i];
		
		valores	[i] = valores	[menor];
		naipes	[i] = naipes	[menor];
		
		valores	[menor]	= aux_v;
		naipes	[menor] = aux_n;
	}
	for ( i = 0; i < b->tam; i++){
		if (valores[i] == 11){
			valores[i] = 'J';
		} else if (valores[i] == 12){
			valores[i] = 'Q';
		} else if (valores[i] == 13){
			valores[i] = 'K';
		} else if (valores[i] == 14){
			valores[i] = 'A';
		} 
	}
	for (i = 0; i < b->tam ; i++){
		removeCarta(b,valores[i],naipes[i]);
		insereCarta(b,valores[i],naipes[i]);
	}
}

void pegaCarta(BARALHO *a, BARALHO *b){
	if(a->tam == 0){
		return;
	}else{
		insereCarta(b,a->primeira->valor,a->primeira->naipe);
		removeCarta(a,a->primeira->valor,a->primeira->naipe);
	}
	
}

void tiraCartas(BARALHO *b){
	while (b->tam > 0){
		removeCarta(b,b->primeira->valor,b->primeira->naipe);
	}
}

int montante(BARALHO *b){
	if (b->tam == 0){
		return 0;
	} else{
		int a_counter = 0;
		carta *aux = (carta*)malloc(sizeof (carta));
		aux = b->primeira;
		int i;
		int total = 0;
		for ( i = 0 ; i < b->tam ; i++ ){
			if (aux->valor == 'J' || aux->valor == 'Q' || aux->valor == 'K' ){
				total += 10;
			} else if( aux->valor == 'A' ){
				a_counter++;
			} else {
				total += aux->valor;
			}
			if (i < b->tam-1){
				aux = aux->prox;
			}
		}
		while (a_counter > 0){
			total += 11;
			if (total > 21){
				total -=10;
			}
			a_counter--;
		}
		return total;		
	}
}

int situacao(BARALHO *b){
	if (b->tam == 2){
		//printf("2 cartas na mao\n");
		//printaBaralho(b);
		if (b->primeira->valor == 2 && b->primeira->prox->valor == 2){
			return 0;
		} else if (b->primeira->valor == 3 && b->primeira->prox->valor == 3){
			return 1;
		}  else if (b->primeira->valor == 4 && b->primeira->prox->valor == 4){
			return 2;
		}  else if (b->primeira->valor == 5 && b->primeira->prox->valor == 5){
			return 3;
		}  else if (b->primeira->valor == 6 && b->primeira->prox->valor == 2){
			return 4;
		}  else if (b->primeira->valor == 7 && b->primeira->prox->valor == 2){
			return 5;
		}  else if (b->primeira->valor == 9 && b->primeira->prox->valor == 2){
			return 6;
		}  else if ( (b->primeira->valor == 'J' || b->primeira->valor == 'Q' || b->primeira->valor == 'K' )&& (b->primeira->prox->valor == 'J' || b->primeira->prox->valor == 'Q' || b->primeira->prox->valor == 'K')){
			return 7;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 'A' ) || ( b->primeira->valor == '8' && b->primeira->prox->valor == '8' ) ){
			return 8;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 2 ) || ( b->primeira->valor == 2 && b->primeira->prox->valor == 'A' ) ){
			return 9;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 3 ) || ( b->primeira->valor == 3 && b->primeira->prox->valor == 'A' ) ){
			return 10;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 4 ) || ( b->primeira->valor == 4 && b->primeira->prox->valor == 'A' ) ){
			return 11;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 5 ) || ( b->primeira->valor == 5 && b->primeira->prox->valor == 'A' ) ){
			return 12;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 6 ) || ( b->primeira->valor == 6 && b->primeira->prox->valor == 'A' ) ){
			return 13;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 7 ) || ( b->primeira->valor == 7 && b->primeira->prox->valor == 'A' ) ){
			return 14;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 8 ) || ( b->primeira->valor == 8 && b->primeira->prox->valor == 'A' ) ){
			return 15;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 9 ) || ( b->primeira->valor == 9 && b->primeira->prox->valor == 'A' ) ){
			return 15;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 10 ) || ( b->primeira->valor == 10 && b->primeira->prox->valor == 'A' ) ){
			return 15;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 'J') || ( b->primeira->valor == 'J' && b->primeira->prox->valor == 'A' ) ){
			return 15;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 'Q' ) || ( b->primeira->valor == 'Q' && b->primeira->prox->valor == 'A' ) ){
			return 15;
		}  else if ( ( b->primeira->valor == 'A' && b->primeira->prox->valor == 'K' ) || ( b->primeira->valor == 'K' && b->primeira->prox->valor == 'A' ) ){
			return 15;
		}	
	} 
	int val = -1;
	switch (montante(b)){
		case 5:
			val = 16;
			break;
		case 6:
			val = 16;
			break;
		case 7:
			val = 16;
			break;
		case 8:
			val = 16;
			break;
		case 9:
			val = 17;
			break;
		case 10:
			val = 18;
			break;
		case 11:
			val = 19;
			break;
		case 12:
			val = 20;
			break;
		case 13:
			val = 21;
			break;
		case 14:
			val = 22;
			break;
		case 15:
			val = 23;
			break;
		case 16:
			val = 24;
			break;
		default:
			val = 25;
			break;
	}
	if (val == -1){
		printf("CARALHOOOO");		
	}
	return val;
}


int valorPrimeira(BARALHO *b){
	if (b->tam == 0){
		return 0;
	} else{
		carta *aux = (carta*)malloc(sizeof (carta));
		aux = b->primeira;
		if (aux->valor == 'J' || aux->valor == 'Q' || aux->valor == 'K' ){
			return 8;
		} else if( aux->valor == 'A' ){
			return 9;
		} else {
			return aux->valor-2;
		}
	}
}








