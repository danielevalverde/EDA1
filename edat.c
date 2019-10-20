#include <stdlib.h>
#include <stdio.h>

int main(int argc , char *argv[]){
	int cont = 0;
	FILE *f;
	f=fopen(argv[2],"r");

	int k = atoi(argv[1]);

	//queue * fila =cria_fila();
	int a;
	//if(fila!=NULL){

		while (!feof(f) ){
			fflush(f);
			fscanf(f, "%d", &a);
			//push(fila,a);
			printf("%d",a );
		}
	//}

	int inserir_cache(queue* q, int x){
	cell * aux;
	int inicio = q->inicio->elemento;
	int encontrou =0;
	if(q->final->elemento == x) return 0;
	if(q->inicio->elemento==x){
		aux = pop(q);
		push(q, aux->elemento);
		return 1;
	}
	do {
		if(q->inicio->elemento == x){
			pop(q);
			encontrou = 1;
			printf("Achei!\n");
		} else {
			aux=pop(q);
			push(q, aux->elemento);
		}
	} while (q->inicio->elemento!=inicio);	
	push(q,x);
	return encontrou; 
}


	fclose(f);

}