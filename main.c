#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "baralho.h"

#define POPSIZE 30

#define GERACOES 100
#define MAXFICHAS 100
#define APOSTA 5

int muta(int valor,int seed){
	
}
int main(){
	
	srand	(( unsigned )time(NULL));	//Geracao de números aleatórios
	
	BARALHO *monte = iniciaBaralho();
	BARALHO *dealer = iniciaBaralho();
	BARALHO *jogador = iniciaBaralho();
	
	int DNA[POPSIZE][26][10];
/*			DECISION MAKE CHART
	Stand = 0
	Hit = 1
	Double = 2
	Split = 3
			0	1	2	3	4	5	6	7	8	9
			2	3	4	5	6	7	8	9	10	A
25	17+		S	S	S	S	S	S	S	S	S	S
24	16		S	S	S	S	S	H	H	H	H	H
23	15		S	S	S	S	S	H	H	H	H	H
22	14		S	S	S	S	S	H	H	H	H	H
21	13		S	S	S	S	S	H	H	H	H	H
20	12		H	H	S	S	S	H	H	H	H	H
19	11		D	D	D	D	D	D	D	D	D	H
18	10		D	D	D	D	D	D	D	D	H	H
17	9		H	D	D	D	D	H	H	H	H	H
16	5-8		H	H	H	H	H	H	H	H	H	H
15	A8-10	S	S	S	S	S	S	S	S	S	S
14	A7		S	D	D	D	D	S	S	H	H	H
13	A6		H	D	D	D	D 	H	H	H	H	H
12	A5		H	H	D	D	D	H	H	H	H	H
11	A4		H	H	D	D	D	H	H	H	H	H
10	A3		H	H	H	D	D	H	H	H	H	H
9	A2		H	H	H	D	D	H	H	H	H	H
8	AA,88	SP	SP	SP	SP	SP	SP	SP	SP	SP	SP
7	10,10	S	S	S	S	S	S	S	S	S	S
6	9,9		SP	SP	SP	SP	SP	S	SP	SP	S	S
5	7,7		SP	SP	SP	SP	SP	SP	H	H	H	H
4	6,6		SP	SP	SP	SP	SP	H	H	H	H	H
3	5,5		D	D	D	D	D	D	D	D	H	H
2	4,4		H	H	H	SP	SP	H	H	H	H	H
1	3,3		SP	SP	SP	SP	SP	SP	H	H	H	H
0	2,2		SP	SP	SP	SP	SP	SP	H	H	H	H
			2	3	4	5	6	7	8	9	10	A
*/
																																								
	int iDNA[26][10] = { {0,0,	0,	0,	0,	0,	0,  0,	0, 0} , {0, 0,	0,	0,	0,	0,	1,	1,	1,	1} , {0,	0,	0,	0,	0,	1,	1,	1,	1,	1} , {0,	0,	0,	0,	0,	1,	1,	1,	1,	1} , {0,	0,	0,	0,	0,	1,	1,	1,	1,	1} ,{1,	1,	0,	0,	0,	1,	1,	1,	1,	1} ,{2,	2,	2,	2,	2,	2,	2,	2,	2,	1} ,{2,	2,	2,	2,	2,	2,	2,	2,	1,	1} ,{1,	2,	2,	2,	2,	1,	1,	1,	1,	1} ,{1,	1,	1,	1,	1,	1,	1,	1,	1,	1} ,{0,	0,	0,	0,	0,	0,	0,	0,	0,	0} ,{0,	2,	2,	2,	2,	0,	0,	1,	1,	1} ,{1,	2,	2,	2,	2 ,	1,	1,	1,	1,	1} ,{1,	1,	2,	2,	2,	1,	1,	1,	1,	1} ,{1,	1,	2,	2,	2,	1,	1,	1,	1,	1} ,{1,	1,	1,	2,	2,	1,	1,	1,	1,	1} ,{1,	1,	1,	2,	2,	1,	1,	1,	1,	1} ,{0,	0,	0,	0,	0,	0,	0,	0,	0,	0} ,{0,	0,	0,	0,	0,	0,	0,	0,	0,	0} ,{0,	0,	0,	0,	0,	0,	0,	0,	0,	0} ,{1,	1,	1,	1,	1,	1,	1,	1,	1,	1} ,{1,	1,	1,	1,	1,	1,	1,	1,	1,	1} , {2,	2,	2,	2,	2,	2,	2,	2,	1,	1}, {1,	1,	1,	1,	1,	1,	1,	1,	1,	1}, {1,	1,	1,	1,	1,	1,	1,	1,	1,	1} , {1,	1,	1,	1,	1,	1,	1,	1,	1,	1}  };
	

	int i, j;
	int i_dna;
	int i_pop;
	int i_geracoes;
	
	//Primeira população;
	for ( i_pop = 0 ; i_pop < POPSIZE ; i_pop++){
		for ( i = 0 ; i < 26; i++){
			for ( j = 0 ; j < 10; j++){
				DNA[i_pop][i][j] = rand()%3;
				//printf("Definindo gene %d %d do individuo %d...\n",i,j,i_pop);
			}
		}
		
	}
	int MELHOR[26][10];	//DNA do melhor da geração, sendo o melhor aquele que consegue o maior número de fichas
	int MELHORPOS;	//Posição do melhor da geração
	int RESULT[POPSIZE];//Resultado de cada um dos DNAs da população
	
	int fichas;		//Fichas do jogador. Se zerar o jogo acaba
	int maos;		//Quantidade de rodadas até o término de todas as fichas
	int comprando;	//Flag de controle para decisão de comprar ou não comprar
	int	blackjack;	//Flag de controle para quando o jogador consegue blackjack na primeira mao
	int mutado;		//Flag de controle para mutar DNA apenas uma vez
	int aposta;		//Valor que será acrescentado ou retirado no montante de fichas do jogador
	int vitorias;
	int fichasMax;
	int estouros;
	int vitoriasEstouradas;
	int f,g;
	
	int decisao_y;	//Baseada nas cartas do jogador
	int decisao_x;	//Baseada na carta a mostra do dealer
	//COMEÇO DO EVOLUTIVO
	for ( i_geracoes = 0; i_geracoes < GERACOES ; i_geracoes++){
		for ( f = 0 ; f < 26 ; f++){
			for ( g = 0 ; g < 10; g++ ){
				DNA[0][f][g] = iDNA[f][g];
			}
		}
		//printf("Iniciando geracao %d...\n",i_geracoes);
		for ( i_pop = 0 ; i_pop < POPSIZE ; i_pop++){ //Realiza os testes para cada membro da população
			//printf("Iniciando individuo %d da populacao...",i_pop);
			vitorias = 0;
			vitoriasEstouradas = 0;
			estouros = 0;
			maos = 0;	//Zera maos
			fichas = MAXFICHAS;	//Reinicia máximo de fichas
			RESULT[i_pop] = fichas;	//Valor default é o máximo de fichas
			fichasMax = fichas;
			
			while (fichas > 0 ){ //Condição para o jogador poder continuar jogando. Se não for verdadeira os resultados devem ser compilados
				blackjack = 0;
				maos++;
				insereBaralhoComum(monte); //As, 2-10, J, Q, K, ouros, espadas, copas e paus
				embaralha(monte,rand());
				//Distribuição de cartas
				pegaCarta(monte,jogador);
				pegaCarta(monte,jogador);
				pegaCarta(monte,dealer);
				pegaCarta(monte,dealer);
				
				if( tamanhoBaralho(monte) != 48 || tamanhoBaralho(jogador) != 2 || tamanhoBaralho(dealer) != 2){
					//printf("Erro ao distribuir cartas");
				}
				
				//Início das tomadas de decisões baseada nos critérios
				comprando = 1;
				aposta = APOSTA;
				if(montante(jogador) == 21 && tamanhoBaralho(jogador) == 2 ){
					blackjack = 1;
					comprando = 0;
				}
				while (comprando){
					decisao_y = situacao(jogador);
					decisao_x = valorPrimeira(dealer);
					//printf("Decisao %d %d...\n",decisao_y,decisao_x);
					switch (DNA[i_pop][decisao_y][decisao_x]){
						case 0:
							//printf("stand\n");
							comprando = 0;
							break;
						case 1:
							//printf("hit\n");
							pegaCarta(monte,jogador);
							if(montante(jogador) > 21){
								comprando = 0;
							}
							break;
						case 2:
							//printf("double\n");
							aposta = APOSTA*2;
							pegaCarta(monte,jogador);
							comprando = 0;
							break;
						default:
							printf("Erro na tomada de decisao. DNA[%d][%d][%d] = %d\n",i_pop,decisao_y,decisao_x);
							break;
					}
				}
				if (blackjack != 1 && montante(jogador) <= 21){ //Se o jogador tiver somado 22 ou mais não é necessário fazer nada, o dealer já ganhou
					while (montante(dealer) < montante(jogador)){
						pegaCarta(monte,dealer);
					}	
				}
				if (blackjack == 1 && montante(dealer) != 21){
					//printf("BlackJack\n");
					fichas +=aposta;
					vitorias++;
				}else if( montante(jogador) > 21 || ( montante(jogador) < montante(dealer) && montante(dealer) <= 21) ){ //Condições de vitória do dealer
					//printf("Dealer vence\n");
					fichas -=aposta;
					if(montante (jogador) > 21){
						estouros++;
						if (rand()%3 == 0){
							DNA[i_pop][decisao_y][decisao_x] = 0;
						}
					}
				}else if (montante(jogador) != montante(dealer)){ //Condições de vitória do jogador
					//printf("Jogador vence\n");
					fichas +=aposta;
					vitorias++;
				}
				if (montante(dealer) > 21){
					vitoriasEstouradas++;
					if (rand()%3 == 0){
						DNA[i_pop][decisao_y][decisao_x] = 2;
					}
				}
				if (fichas > RESULT[i_pop]){ //Testa se um resultado melhor foi atingido
					RESULT[i_pop] = fichas;
				}
				if (fichas > fichasMax){
					fichasMax = fichas;
				}
				tiraCartas(monte);
				tiraCartas(jogador);
				tiraCartas(dealer);
				if( tamanhoBaralho(monte) != 0 || tamanhoBaralho(jogador) != 0 || tamanhoBaralho(dealer) != 0){
					//printf("Erro ao limpar os baralhos\n");
				}	
				//printf("Fichas: %d\n",fichas);
			}
			//Fichas acabaram
			//RESULT[i_pop] = maos;
			//RESULT[i_pop] = vitorias;
			
			printf("Jogou %d maos com %d vitorias atingindo %d fichas estourando %d vezes com dealer estourando %d vezes\n",maos,vitorias,fichasMax,estouros,vitoriasEstouradas);
		}
		MELHORPOS = 0;
		for ( i_pop = 1; i_pop < POPSIZE; i_pop++ ){	//Encontra a posição do melhor resultado dentre os membros da geracao
			if (RESULT[i_pop] > RESULT[MELHORPOS]){
				MELHORPOS = i_pop;
			}
		}
		for ( i = 0 ; i < 26 ; i++){  //Copia os atributos do melhor DNA
			for ( j = 0 ; j < 10 ; j++){
				MELHOR[i][j] = DNA[MELHORPOS][i][j];
			}
		}
		printf("Melhor de todos:\n_____|2_3_4_5_6_7_8_9_10_A_\n");
		for ( i = 0; i < 25; i++){
			switch (i){
				case 0:
					printf("17+  |");
					break;
				case 1:
					printf("16   |");
					break;
				case 2:
					printf("15   |");
					break;
				case 3:
					printf("14   |");
					break;
				case 4:
					printf("13   |");
					break;
				case 5:
					printf("12   |");
					break;
				case 6:
					printf("11   |");
					break;
				case 7:
					printf("10   |");
					break;
				case 8:
					printf("9    |");
					break;
				case 9:
					printf("5-8  |");
					break;
				case 10:
					printf("A8-10|");
					break;
				case 11:
					printf("A7   |");
					break;
				case 12:
					printf("A6   |");
					break;
				case 13:
					printf("A5   |");
					break;
				case 14:
					printf("A4   |");
					break;
				case 15:
					printf("A3   |");
					break;
				case 16:
					printf("A2   |");
					break;
				case 17:
					printf("AA,88|");
					break;
				case 18:
					printf("10,10|");
					break;
				case 19:
					printf("9 9  |");
					break;
				case 20:
					printf("7 7  |");
					break;
				case 21:
					printf("6 6  |");
					break;
				case 22:
					printf("5 5  |");
					break;
				case 23:
					printf("4 4  |");
					break;
				case 24:
					printf("3 3  |");
					break;
				case 25:
					printf("2 2  |");
					break;
				default:
					printf("ERRO NA TABELA (1)");
					break;
			}
			for ( j = 0 ; j < 10; j++){
				switch (MELHOR[i][j]){
					case 0:
						printf("s ");
						break;
					case 1:
						printf("h ");
						break;
					case 2:
						printf("d ");
						break;
					default:
						printf("ERRO NA TABELA (2)");
						break;
				}
			}
			printf("\n");
		}
		
		printf("_____|2_3_4_5_6_7_8_9_10_A_\n");
		for ( i_pop = 0; i_pop < POPSIZE ; i_pop++){
			for ( i = 0; i < 26 ; i++){
				for( j = 0; j < 10 ; j++){
		//TRANSAAAAAAA
					if ( rand()%100 < 50){
						DNA[i_pop][i][j] = DNA[i_pop][i][j];
					}else{
						DNA[i_pop][i][j] = MELHOR[i][j];
						
					}
					
		//Mutação filhos
					/*DNA[i_pop][i][j] = MELHOR[i][j] + 1 - rand()%3;
					if (DNA[i_pop][i][j] == -1 ){
						DNA[i_pop][i][j] = 0;
					} else if ( DNA[i_pop][i][j] == 3){
						DNA[i_pop][i][j] = 2;
					}*/
				}		
			}
		}
		
		for ( i_pop = 0; i_pop < POPSIZE ; i_pop++){
			DNA[i_pop][rand()%25][rand()%10] = rand()%3;
		}
		
		
	}	
	liberaBaralho(monte);
	liberaBaralho(dealer);
	liberaBaralho(jogador);
	return 0;
}
