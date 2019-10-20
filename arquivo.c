#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main( ){

	FILE *f;
	f=fopen("funcoes.c","w");
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

	char texto[20]="Meu Programa em C";
	int i;
	for(i =0 ; i <strlen(texto);i++){
		fputc(texto[i],f);
		fputc(' ',f);

	}
		/*
		fputc()
			escreve um caractere em um arquivo
			em caso de erro, retorna a constante EOF
			em caso de sucesso retorna o próprio caractere
		*/

		fclose(f);

	return 0;


}
