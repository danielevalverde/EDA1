#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct cadastro {
	char nome[40], endereco[30];
	int idade;
};


int main( ){

	FILE *f;
	f=fopen("vetor.txt","wb");

	if(f==NULL){
		printf("Erro na abertura!\n");;
		exit(1);
	}
	else
		printf("Arquivo Aberto\n");

	struct cadastro cad={"kara,","Brotas", 4};
	char str[20]="Hello Word";
	float x =5;
	int total_gravado, v[5]={1,2,3,4,5};
	fwrite(v, sizeof(int),5,f);
	fwrite(str, sizeof(char),20,f);
	fwrite(&f, sizeof(float),1,f);
	fwrite(&cad,sizeof(struct cadastro),1,f);


	

	/*
		int fwrite(void *buffer, int bytes, int count , FILE *p);
		 parâmetros:
		 buffer : poteiro genérico para os dados
		 bytes: tamanho, em bytes, de cada unidade de dado a ser gravada
		 count: total de unidades de dados que devem ser gravadas
		 fp: ponteiro para o arquivo
		 retorno : total de unidades de dados gravadas com sucesos

	
	*/

		fclose(f);

	return 0;


}
