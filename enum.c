#include <stdlib.h>
#include <stdio.h>
#include <string.h>


enum semana {segunda, terca, quarta};
enum escapes {retrocesso ='\b',tabulacao='\t', novalinha='\n'};

enum bool { true, false};


int main(){

	enum semana s;
	s=quarta;
	enum escapes e = novalinha;
	printf("Teste %c de %c escrita %c ",e,e,e );

	printf("%d\n",s );

}