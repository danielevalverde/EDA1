#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoas
	{
		
		char nome[40], rua[50];
		int idade, numero;

	};


int main () {

	int i;
	struct pessoas p[4];

	for(i = 0 ; i <1 ;i++){
		scanf("%s", p[i].nome);
		scanf("%s", p[i].rua);
		scanf("%d", &p[i].idade);
		scanf("%d", &p[i].numero);
	}
	printf("\n\n");
	printf("%s\n", p[0].nome);
	printf("%d\n", p[0].numero);
	printf("%d\n", p[0].idade);
	printf("%s\n", p[0].rua);


	return (0);
}