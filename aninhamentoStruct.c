#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct endereco{
	char nome[40];
	int numero;
};

struct pessoa {
	char nome[40];
	int idade;
	struct endereco ender;
};


int main () {

	struct pessoa p;
	p.idade=31;
	p.ender.numero=21;

	return 0;
}