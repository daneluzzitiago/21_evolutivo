#ifndef BARALHO_H
#define BARALHO_H

//.h

typedef struct baralho BARALHO;


//Retorna tipo baralho com memória alocada
BARALHO* iniciaBaralho();
//Free no vetor cartas e no baralho
void liberaBaralho(BARALHO *b);
//Insere tipo carta em um baralho, definindo seus atributos através dos parâmetros
void insereCarta(BARALHO *b, int valor, char *naipe);
//Acessa todos os elementos da lista e printa na tela seus atributos
void printaBaralho(BARALHO *b);
//Insere o baralho de 54 cartas, Ás até Rei dos 4 naipes
void insereBaralhoComum(BARALHO *b);
//Remove carta do baralho, passando seus atributos como parâmetro
void removeCarta(BARALHO *b, int valor, char *naipe);
//Cria um novo baralho, inserindo elementos aleatórios de B em um novo baralho, fazendo a raiz do baralho apontar para esse novo baralho
void embaralha(BARALHO *b,int seed);
//Retorna o tamanho de um baralho
int tamanhoBaralho(BARALHO *b);
//Ordena baralho de 2 a Ás, paus a copas, com insertion sort
void ordena(BARALHO* b);
//Pega a primeira carta de a e insere em b
void pegaCarta(BARALHO *a, BARALHO *b);
//Tira todas as cartas do baralho (útil para cada fim de "mão"
void tiraCartas(BARALHO *b);
//Retorna valor total das cartas de um baralho
int montante(BARALHO *b);
//Analisa as cartas do baralho e retorna inteiro referente a situação para poder tomar decisão
int situacao(BARALHO *b);
//Retorna valor da primeira carta do baralho
int valorPrimeira(BARALHO *b);


#endif
