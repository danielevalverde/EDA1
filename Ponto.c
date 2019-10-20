#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Ponto.h"

// quando for compilar, coloque gcc Ponto.c -lm 
float* pto_acessa3(Ponto* p, float *a, float *b){
  a=&p->x;
  b=&p->y;
  printf("%p\n",a );
  printf("%p\n",&p->x );
  return a;
  
  // x e y são declarados como ponteiros no arquivo ponto.c
  // por que precisa ser ponteiros ? Porque você vai acessar o endereço de memória 
  // E ter acesso ao conteúdo desse endereço
  //printf("%f\n",*b );
  //printf("%f\n",*x );
}


int main () {

	Ponto *p, *q;
	float d, a, b;
  float x,y;
  int *e;


	p=pto_cria(10.1,12.2);
	q=pto_cria(7.0,3.0);
  d=pto_distancia(p,q);
  printf(" Distancia entre pontos = %f\n",d );

	pto_atribui(p,10.0, 20.0);
	d=pto_distancia(p,q);
	printf(" Distancia entre pontos = %f\n",d );

pto_acessa( q, &a, &b);
// passando as variáveis a e b por referência(endereço das variáveis), porque queremos acessra duas variáveis
// e o comando return só returnaria o valor de um
// na função pto_acessa, os valores de a e b serão modificados

  pto_acessa2( q,x, y);
  printf("%f\n",a);
    printf("%f\n",b);
  //printf("%f\n",q->x);

 /* printf("%f\n",*a );
  printf("%p\n",a );

   printf("%f\n",x );
  printf("%f\n",y);*/
 
// 	pto_acessa( q,x, y);

  	pto_libera(q);

  	pto_libera(p);

  	return 0;
	

}