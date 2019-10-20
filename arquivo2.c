#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main( ){

	FILE *f;
	f=fopen("funcoes.c","r");
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

	char c=fgetc(f);
	int i;
	/*for(i =0 ; i <=10;i++){
		c=fgetc(f);
		printf("%c ",c);

	}

	*/

	while(c!=EOF){
		printf("%c",c );
		c=fgetc(f);
	}

	printf("\nFim\n");

		/*
			escreve um caractere em um arquivo
			em caso de erro, retorna a constante EOF
			em caso de sucesso retorna o próprio caractere
		*/

		fclose(f);

	return 0;


}
