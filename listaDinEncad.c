#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h"

int main () {


	Lista *li;

	li=cria_lista();
	/* um ponteiro para Lista 
	 e Lista é um ponteiro para a struct elemento
	 Elemento contém um struct com os dados do aluno 
	 e um campo com o endereço para a próxima célula da fila
	 Por que precis de um ponteiro pra ponteiro ? Pra poder guardar o endereço de um ponteiro
	 o li será o inicio da sua lista, porque ele guarda SOMENTE o endereço do próximo ponteiro 
	typedef struct elemento* Lista;
	 */


	int x = tamanho_lista(li);


	//libera_lista(li);

	int y= lista_vazia(li);

	struct aluno dados_aluno={12,"kara",1,2,3};
	int in = insere_lista_inicio(li, dados_aluno);

}	