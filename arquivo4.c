#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main( ){

	FILE *f;
	f=fopen("funcoes2.c","r");
	/* 
	f=fopen("funcoes.c","w");
		Escrita do arquivo Texto
		Cria o arquivo. Se já tiver criado, vai apagar o conteúdo do mesmo
	f=fopen("funcoes.c","r");
		Leitura do arquivo texto
		O arquivo tem que existir
	f=fopen("funcoes.c","rb");
		Leitura de Arquivo Binário
	f=fopen("funcoes.c","wb");
		Escrita de Arquivo Binário

	*/
	if(f==NULL){
		printf("Erro na abertura!\n");;
		exit(1);
	}
	else
		printf("Arquivo Aberto\n");
	char str[20];
	char *result= fgets(str,12,f);
	if(result==NULL)
		printf("Erro na  LEITURAo\n");
	else 
	printf("%s\n",str );

	/*
		fgets

			le o arquivo inteiro 
			em caso de erro, retorna aNULL
			em caso de sucesso retorna um ponteiro para o primeiro caracter da string
		*/

		fclose(f);

	return 0;


}
