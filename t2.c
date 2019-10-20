#include<stdio.h>
#include <stdlib.h>

int main( ){

	FILE *f;
	f=fopen("vetor.txt","r");

	if(f==NULL){
		printf("Erro na abertura!\n");;
		exit(1);
	}
	else
		printf("Arquivo Aberto\n");
	int a,b,c;
	fscanf(f, "%d%d%d", &a,&b,&c);

	printf("%d%d%d\n",a,b,c);
	 
	/*
		fprintf( fIle *f , "tipos de saida", variaveis)
	*/

		fclose(f);

	return 0;


}
