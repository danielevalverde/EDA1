#include <stdlib.h>
#include <stdio.h>

/* 

Cada elemento aponta para seu sucessor e antecessor na lista
Usa um ponteiro especial para o primeiro elemento da lsita e uma indicação de final de lista nos dois sentidos
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
	 char nome[40];
	 float n1, n2, n3;
};

typedef struct elemento * Lista;

struct elemento {
	struct elemento *ant;
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista * cria_lista(){
	Lista *li = (Lista*)malloc(sizeof(Lista));
	if(li==NULL) return 0;
	*li=NULL;
	return li;
}


void libera_lista( Lista* li){
	if(li!=NULL){
		Elem *no;
		while((*li)!=NULL){
			no=*li;
			(*li)=(*li)->prox;
			free(no);
		}
	free(li);
	}
}

int tamanho_lista(Lista *li){
	if(li==NULL) return 0;
	int cont =0;
	Elem *no;
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}

int lista_vazia(Lista *li){
	if(li==NULL || *li ==NULL) return 1;
	return 0;

}
int insere_inicio(Lista *li , struct aluno al){
	if (li==NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	no->prox=*li;
	no->ant=NULL;
	if(*li!=NULL)
		(*li)->ant=no;
	// se lista não vazia, colocar a primeira célcula(*li) para apontar para no;
	*li=no;
	return 1;

}


int insere_final(Lista *li , struct aluno al){
	if (li==NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	no->prox=NULL;
	if(*li!=NULL){
		no->ant=NULL;
		*li=no;
	}
	else{
		Elem *aux = *li;
		while(aux->prox!=NULL)
			aux=aux->prox;

		aux->prox=no;
		no->ant=aux;
	}

	return 1;

}


int insere_orden(Lista *li , struct aluno al){
	if (li==NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no==NULL)return 0;
	no->dados=al;
	if(lista_vazia(li)){
		no->ant=NULL;
		no->prox=NULL;
		*li=no;
		return 1;
	}
	else{
		Elem *ante,*atual = *li;
		while(atual!=NULL && atual->dados.matricula<al.matricula)
			ante=atual;
			atual=atual->prox;
		if(atual==*li){// insere no inicio
			no->ant=NULL;
			(*li)->ant=no;
			no->prox=*li;
			*li=no;
		}
		else{
			no->prox=ante->prox;
			no->ant=ante;
			ante->prox=no;
			if(atual!=NULL)
				atual->ant=no;
		}
	}

	return 1;

}

int remove_inicio( Lista *li){
	if (li==NULL || (*li)==NULL) return 0;
	Elem *no = *li;
	*li=no->prox;
	if(no->prox!=NULL)
		no->prox->ant=NULL;// se a lista não tiver vazia, faz o segundo elemento apontar para null
	free(no);
	return 1;
}


int remove_end( Lista *li){
	if (li==NULL || (*li)==NULL) return 0;
	Elem *no = *li;
	while(no->prox!=NULL)
		no=no->prox;
	if(no->ant==NULL)// remove o promeiro e único
		*li=no->prox;
	else
		no->ant->prox=NULL;
	free(no);
	return 1;
}


int remove_lista( Lista *li, int mat){
	if (li==NULL || (*li)==NULL) return 0;
	Elem *no = *li;
	while(no!=NULL && no->dados.matricula!=mat)
		no=no->prox;
	if(no==NULL)// não encontrado
		return 0;
	if(no->ant==NULL)//remover o primeiro
		*li=no->prox;
	else
		no->ant->prox=no->prox;
	if(no->prox!=NULL)
		no->prox->ant=no->ant;
	free(no);
	return 1;
}

int consulta_lista_pos( Lista* li, int pos, struct aluno *al){
	if(li==NULL || pos<=0) return 0;
	Elem *no = *li;
	int i =1;
	while(no !=NULL && i<pos){
		no = no->prox;
		i++;
	}
	if(no==NULL) return 0;
	else
		*al = no->dados;
		return 1;
}

int consulta_lista_mat( Lista* li, int mat, struct aluno *al){
	if(li==NULL ) return 0;
	Elem *no = *li;
	int i =1;
	while(no !=NULL && no->dados.matricula !=mat){
		no = no->prox;
	}
	if(no==NULL) return 0;
	else
		*al = no->dados;
		return 1;
}