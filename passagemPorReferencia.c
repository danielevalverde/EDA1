#include <stdlib.h>
#include <stdio.h>

/* PASSAGEM POR REFERÊNCIA
 
O endereço de onde o dado está armazenado na memória é passado para a função
Assim, a função pode moficiar o valor do parãmetro
Por que o scanf tem o &
Porque estamos passando o endereço da variável que será setada
somaValor(&a);
Parametro por referência: Toda vez que a variável for usado, o operador "*"
Deverá ser usado na frente no nome da variável
void somaValor(int *n ){
 	*n = *n +4;
 	printf("%d\n",*n);
 	//coloca o "*" até no printf dentro da função
}


*/


void somaValor(int *n ){
 	*n = *n +4;
}

void setaValor(int *n ){
 	*n = 5;
}

struct ponto{
	int x, y;
	
};

void atribui ( struct ponto *p){
	 p->x=5;
	 p->y=22;
	 //(*p).y
	 //(*p).x
	 // é a mesma cois
}

int main() {

	int *a;
	int x =5;
	//a =&x;

	// PARA IMPRIMIR O ENDEREÇO APONTADO POR A
	printf("%p\n", &a );
	a+2;
	printf("%p\n", &a );

	printf("Antes da soma x = %d\n",x );
	somaValor(&x);
	//setaValor(a);
	/*se fosse um vetor, não precisaria passar o & 
	 todo valor que for passado por referência, deve ser precedido de um &
	 na função, você deve indicar que vai receber a passagem por referência(que vai receber um ponteiro)
	*/

	printf("Depois da soma x = %d\n",x );
	//printf("Depois da soma x = %d\n",*a );

	struct ponto *az;
	atribui(az);
	printf(" Teste aqui : %d\n",az->x );


	/* 

	OOOOOOU
	Você não declara a struct como ponteiro
	Se não for declarado como ponteiro, deve ser passado o &comercial
	struct ponto az;
	atribui(&az);
	printf(" Teste aqui : %d\n",az.x );


	*/

	return 0;



}
