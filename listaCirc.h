#include <stdlib.h>
#include <stdio.h>

/*

Tipo de lista onde cada elemento aponta para o seu sucessor o último elemento aponta para o primeiro
da lista. Usa um ponteiro especial para o primeiro elemento da lista. Não existe uma indicação de final de lista
CAda elemento aponta para o seu sucessor na lista. Usa um ponteiro especial para o primeiro 
	elemento da lista e uma indicação de final de lista
	Cada elemento é tratado como um ponteiro que é alocado dinamicamente, a medida que os dados são inseridos
	Para guardar o primeiro elemento, utilizamos "um pontiero para ponteiro"
	Um "ponteiro para ponteiro" pode guardar o endereço de um "ponteiro"
	Assim, fica fácil mudar quem está no inicio da lista mudando o "conteudo" do "ponteiro para ponteiro"
	a sua " cabeça" guarda o endereço da primeira célula, a cabeça não tem "valor/conteúido" do ponteiro pra potenrio


*/

struct aluno
{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};

typedef struct elemento *Lista;

struct elemento
{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista() {
	Lista* li = (Lista*) malloc(sizeof(Lista));
	// é um ponteiro pra ponteiro, porque o malloc retorna um ponteiro que aponta para o  endereço do espaço alocado
	if(li!=NULL)
		// se li == null, significa que não conseguimos criar a noss alista
		*li =NULL;
		// se o conteúdo do li é null, significa que foi criada e está vazia
	return li;
}

void libera_lista( Lista* li){
	if(li!=NULL && (*li) !=NULL){
		Elem *no=*li, *aux;
		while((*li)!=no->prox){
			aux=no;
			no=no->prox;
			free(aux);
		}
	free(li);
	free(no);
	}
}

int tamanho_lista(Lista *li){
	if(li==NULL || (*li)==NULL )return 0;
	int cont =0;
	Elem *no=*li;
	do{
		cont++;
		no=no->prox;
	}while(no!=*li);
	return cont;
}

int lista_vazia(Lista *li){
	if(li==NULL || *li ==NULL) return 1;
	return 0;

}

// SE FOR O PRIMEIRO ELEMENTO, DEVE APONTAR PRA SI PRÓPRIO. SEM ESSA DE NULL

int insere_inicio(Lista *li , struct aluno al){
	if (li==NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	if(*li==NULL){// se lista for vazia, colocar o no  para apontar para si mesmo;
		*li=no;
		no->prox=no;
	}
	else{
		Elem *aux = *li;
		while(aux->prox!=(*li))// procura o último elemento ." quem aponta para o primeiro elemento"
			aux=aux->prox;
		aux->prox=no;// faz o último elemento apontar para o novo inicio
		no->prox=no;// faz o novo elemento apontar para o antigo inicio
		*li=no;// faz o li(cabeça da lista) apontar para o novo inicio
	}
	
	return 1;

}


int insere_final(Lista *li , struct aluno al){
	if (li==NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	if(*li==NULL){
		*li=no;
		no->prox=no;
	}
	else{
		Elem *aux = *li;
		while(aux->prox!=NULL)
			aux=aux->prox;

		aux->prox=no;
		no->prox=*li;
	}

	return 1;

}


int insere_orden(Lista *li , struct aluno al){
	if (li==NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	if(*li==NULL){
		*li=no;
		no->prox=no;
		return 1;
	}
	else{
		if((*li)->dados.matricula>al.matricula ) {// insere no inicio
			Elem* atual = (*li);
			while(atual->prox!=(*li))
				atual=atual->prox;
			no->prox=*li;
			atual->prox=no;
			*li=no;
			return 1;
		}
		Elem *ant = *li, *atual = (*li)->prox;
		while(atual!=*li && atual->dados.matricula<al.matricula){
			ant = atual;
			atual=atual->prox;
		}
		ant->prox=no;
		no->prox=atual;
		
	}

	return 1;

}

int remove_inicio( Lista *li){
	if (li==NULL || (*li)==NULL) return 0;
	if((*li)==(*li)->prox){
		free(*li);
		*li=NULL;
		return 1;
	}
	Elem *atual = *li;
	while(atual->prox!=(*li))
		atual=atual->prox;
	Elem *no = *li;
	atual->prox=no->prox;
	*li=no->prox;
	free(no);
	return 1;
}

int remove_end( Lista *li){
	if (li==NULL || (*li)==NULL) return 0;
	if((*li)==(*li)->prox){
		free(*li);
		*li=NULL;
		return 1;
	}
	Elem *ant, *no = *li;
	while(no->prox!=(*li)){
		ant=no;
		no=no->prox;	
	}
	ant->prox=no->prox;
	free(no);
	return 1;
}

int remove_lista( Lista *li, int mat ){
	if (li==NULL || (*li)==NULL) return 0;
	Elem *no = *li;
	if(no!=NULL && no->dados.matricula!=mat){
		if((*li)==(*li)->prox){
		free(*li);
		*li=NULL;
		return 1;
		}
		else{
			Elem *ult =*li;
			while(ult->prox!=(*li))
				ult=ult->prox;
			ult->prox=(*li)->prox;
			*li=(*li)->prox;
			free(no);
			return 1;
		}
	}
	Elem *ant=no;
	no=no->prox;
	while(no->prox!=(*li)){
		ant=no;
		no=no->prox;	
	}
	if(no==(*li))return 0;
	ant->prox=no->prox;
	free(no);
	return 1;
}

int consulta_lista_pos( Lista* li, int pos, struct aluno *al){
	if(li==NULL ||(*li)==NULL || pos<=0) return 0;
	Elem *no = *li;
	int i =1;
	while(no->prox!=(*li) && i<pos){
		no = no->prox;
		i++;
	}
	if(i!=pos) return 0;
	else
		*al = no->dados;
		return 1;
}

int consulta_lista_mat( Lista* li, int mat, struct aluno *al){
	if(li==NULL || (*li)==NULL ) return 0;
	Elem *no = *li;
	int i =1;
	while(no->prox!=(*li) && no->dados.matricula !=mat){
		no = no->prox;
	}
	if(no->dados.matricula!=mat) return 0;
	else
		*al = no->dados;
		return 1;
}