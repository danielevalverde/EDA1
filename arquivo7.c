#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct cadastro {
	char nome[40], endereco[30];
	int idade;
};


int main( ){

	FILE *f;
	f=fopen("vetor2.txt","w");

	if(f==NULL){
		printf("Erro na abertura!\n");;
		exit(1);
	}
	else
		printf("Arquivo Aberto\n");

	int a =5;
	fprintf(f, "%d%d", a,a );
 
	/*
		fprintf( fIle *f , "tipos de saida", variaveis)
	*/

		fclose(f);

	return 0;


}
