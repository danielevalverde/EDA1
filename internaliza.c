#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoas {
	char nome[40];
	int idade;
};

int main (){

	char nome[40];
	int idade;
	struct pessoas pessoa;

	idade = 40;
	//nome="alexandre";
	pessoa.idade=idade;
	//strcpy(pessoa.nome,"Kara");
	scanf("%s",pessoa.nome);
	printf("%s\n",pessoa.nome );


}