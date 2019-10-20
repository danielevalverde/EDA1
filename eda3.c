

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc , char *argv[]){



	FILE *f;
	f=fopen(argv[2],"r");
	int a,b,tam=0, soma=0,cont=0 ;

	int k = atoi(argv[1]);
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);

	return 0;
}

