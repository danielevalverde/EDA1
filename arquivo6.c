#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct cadastro {
	char nome[40], endereco[30];
	int idade;
};


int main( ){

	FILE *f;
	f=fopen("vetor.txt","wr");

	if(f==NULL){
		printf("Erro na abertura!\n");;
		exit(1);
	}
	else
		printf("Arquivo Aberto\n");

	int total_lido, v[5];
	total_lido=fread(v, sizeof(int),5,f);
	if(total_lido!=5)
		printf("Erro na LEitura\n");
	fclose(f);
	int i ;
	for(i = 0 ; i < 5 ; i++){
		printf("%d\n",v[i] );
	}

	

	return 0;


}
