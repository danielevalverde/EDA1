#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union tipo {
	// estrutura de memória compartilhada
	// reserva na memória o espaço para o tipo de maior número de bits
	short int x; 
	unsigned char c;
	// transforma no numero da tabela ASCII

};


int main () {

	union tipo u;
	u.x= 0;
	u.c='A';

	printf("%c\n",u.c );

	printf("%d\n",u.x );

}