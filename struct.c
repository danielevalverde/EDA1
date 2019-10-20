#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados
	{
		int idade, numero;
		char nome[40];
	};

int main () {
	
	char nome[40];
	int idade;
	struct dados p;

	p.idade = 31; 
	// atribuição de struct
	scanf("%d", &p.numero) ;
	//comando de leitura;
	scanf("%s", p.nome) ; // comando de leitura
	p.numero= p.numero+p.idade - 100;
	printf("%s\n",p.nome );

	// atribuição
	 strcpy(p.nome,"Kara");
	 
	// OUTRA FORMA DE DECLARAR
	struct dados p2 = {31 , 101,"Ricardo"}; 
	// Ou seja, podemos passar como em um array
	// preste atenção que precisa ser passado na mesma ordem
	// Caso você não coloque em um dos campos, este assume valor 0 ou string vazia.
	// Você só pode deixar os últimos campos em branco
	
	struct dados pes[3];
	pes[0].idade = 21; 
   	return(0);
}