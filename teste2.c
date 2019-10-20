#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc , char *argv[]){

	FILE *f;
	f=fopen(argv[2],"r");
	
	printf("%s\n",argv[2] );
	printf("%s\n",argv[1] );
	int a=atoi(argv[1]);
	printf("%d\n",a );

}
