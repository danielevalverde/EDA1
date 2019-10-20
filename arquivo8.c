#include<stdio.h>
#include <stdlib.h>
#include <string.h>



int main( ){

	FILE *f;
	f=fopen("vetor.txt","r");

	if(f==NULL){
		printf("Erro na abertura!\n");;
		exit(1);
	}
	else
		printf("Arquivo Aberto\n");
	int a,b;
	fscanf(f, "%d%d", &a,&b);

	printf("%d%d\n",a,b );
	 
	/*
		fprintf( fIle *f , "tipos de saida", variaveis)
	*/

		fclose(f);

	return 0;


}
