#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct ponto {
	float x;
	float y;
};
typedef struct ponto Ponto; 

Ponto* pto_cria(float x, float y) {
	//pense como se fosse um int*
	//Se fosse int, retornaria um inteiro, correto?
	//Sendo int *, retornaria um ponteiro apra inteiro
	// Sendo ponto* , retorna um ponteiro para um espaço alocado para a ESTRUTURA(struct) Ponto
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	// aloca um espaço da memória para que seja guardado x e y
	// Pense no que você quer alocar. Você quer espaço para alocar x e y, correto ? 
	// tem que ser alocado do tipo da estrutura
	// alocamos espaço para "Ponto"
	// Ponto é um ponteiro que irá guardar o endereço de da estrutura que será acessada pelo p
	// Por que a função tem que ser do tipo ponteiro ? E porque nossa estrutura se transforma em um ponteiro ? 
	// Porque a função malloc retorna um ponteiro com o endereço do início do espaço de memória alocado
	// Aí usa o nosso novo tipo, No caso o Ponto. Toda vez que você for alocar algo, será retornado um ponteiro
	//precisamos passar o endereço de memória alocado para que este sja acessado pelo usuário

	if(p!=NULL){
		p->x = x;
		p->y = y;
	}
	return p;
}


void pto_libera(Ponto *p){
	free(p);
}

void pto_acessa(Ponto* p, float *a, float *b){
	// porque o * ? Porque temos que informar que o valor será passado por referência 
	*b=p->y;
	*a=p->x;
	// modificamos o valor por 
	// x e y são declarados como ponteiros no arquivo ponto.c
	// por que precisa ser ponteiros ? Porque você vai acessar o endereço de memória 
	// E ter acesso ao conteúdo desse endereço
	//printf("%f\n",*b );
	//printf("%f\n",*x );
}


//PODE SER FEITO DESSA FORMA. FAÇA DESSA FORMA: 
void pto_acessa2(Ponto* p, float x, float y){
	x = p->x;
	y = p->y;
	printf("%f\n",y );
	printf("%f\n",x );
	printf("%p\n",&y );
	printf("%p\n",&x );

}

void pto_atribui(Ponto* p, float x, float y){
	p->x = x;
	p->y = y;

}
float pto_distancia(Ponto* p1, Ponto* p2 ){
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	//return sqrt(dx*dx + dy*dy);
}

