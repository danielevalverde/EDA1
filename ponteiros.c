#include <stdlib.h>
#include <stdio.h>

int main() {

	int x=5;
	int v[4]={10,20,30,40};

	int *p,**p2, *b, a,*p3;
	p =v;
	p2=&p;
	p3=p;
	a=3;
	b=&a;
	*b=5;

	/***p2=*p+1;
	*p2=++p;
	**p2=15;
	*p=17;
	p++;
	*p=*p+2;
	*/



	//p2=v;
	// note a sintaxe de atribuição de um vetor
	// todo vetor é um ponteiro
	// P2 vai receber o valor de cada posição de v
	// e não o endereço.

	//printf("%d\n", *p );
	//printf("%d\n", *p1 );
	//*p=7; // modificando o valor de x
	//printf("%d\n", x );

	for(int i =0 ;i < 4; i++)
	 	printf("%d\n",v[i]);
	 printf("\n");

	 for(int i =0 ;i < 4; i++)
	 	printf("%d\n",*(p+i));
	  printf("\n");

	 for(int i =0 ;i < 4; i++)
	 	printf("%d\n",p[i]);
	  printf("\n");

	   printf("%d\n",a);


}