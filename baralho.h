#ifndef BARALHO_H
#define BARALHO_H

//.h

typedef struct baralho BARALHO;


//Retorna tipo baralho com mem�ria alocada
BARALHO* iniciaBaralho();
//Free no vetor cartas e no baralho
void liberaBaralho(BARALHO *b);
//Insere tipo carta em um baralho, definindo seus atributos atrav�s dos par�metros
void insereCarta(BARALHO *b, int valor, char *naipe);
//Acessa todos os elementos da lista e printa na tela seus atributos
void printaBaralho(BARALHO *b);
//Insere o baralho de 54 cartas, �s at� Rei dos 4 naipes
void insereBaralhoComum(BARALHO *b);
//Remove carta do baralho, passando seus atributos como par�metro
void removeCarta(BARALHO *b, int valor, char *naipe);
//Cria um novo baralho, inserindo elementos aleat�rios de B em um novo baralho, fazendo a raiz do baralho apontar para esse novo baralho
void embaralha(BARALHO *b,int seed);
//Retorna o tamanho de um baralho
int tamanhoBaralho(BARALHO *b);
//Ordena baralho de 2 a �s, paus a copas, com insertion sort
void ordena(BARALHO* b);
//Pega a primeira carta de a e insere em b
void pegaCarta(BARALHO *a, BARALHO *b);
//Tira todas as cartas do baralho (�til para cada fim de "m�o"
void tiraCartas(BARALHO *b);
//Retorna valor total das cartas de um baralho
int montante(BARALHO *b);
//Analisa as cartas do baralho e retorna inteiro referente a situa��o para poder tomar decis�o
int situacao(BARALHO *b);
//Retorna valor da primeira carta do baralho
int valorPrimeira(BARALHO *b);


#endif
