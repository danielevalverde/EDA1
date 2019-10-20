#include <stdio.h>
#include <stdlib.h>

/* 
Tipo de lista onde cada elemento aponta para o seu sucessor na lista. 
Usa um ponteiro especial para o primeiro elemetno da lista e uma indicação de final de lista

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
	char nome [30];
	float n1,n2,n3;
};

typedef struct elemento* Lista;
// a minha variável lista vai ser um ponteiro do tipo struct com os campos de elemento

struct elemento {
	struct aluno dados; // um campo com a struct de dados, poderia ser uma simples variável também
	// significa que eu preciso de todos os campos da struct aluno preenchidos
	struct elemento *prox; // um ponteiro que vai guardar o endereço da próxima celula
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

void libera_lista(Lista* li){
	if(li!=NULL){
		Elem* no;
		while((*li)!=NULL){
			no =*li;
			// no pega o endereço que li aponta
			// li aponta para o primeiro elemento inicialmente
			*li = (*li)->prox;
			// bota li pra apontar para o enderço do próximo
			free(no);
			// libera o endereço que li apontava
		}
		free(li);
	}
}

int tamanho_lista(Lista* li){
	if(li==NULL) return 0;
	int cont =0;
	Elem* no = *li;
	// usamos o no e não o li para que não percamos o inicio da lista
	// mas o primeiro nó, possui o endereço de li. Se ligou?
	// a ttreta é que sempre atualizamos o no, porque ele é apenas uma variável auxiliar
	// enquanto o nosso li é a cabeça que aponta para o inicio da lista
	while(no!=NULL){
		cont++;
		no=no->prox;
	}
	return cont;
}

int lista_vazia(Lista* li ){
	if(li==NULL)
		return 1;
	if (*li==NULL)
		return 1;
	return 0;
}


int insere_lista_inicio( Lista *li, struct aluno al) {
	if(li==NULL) return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem)); 
	if (no==NULL) return 0;
	no->dados = al;
	no->prox=(*li);
	// se é o primeiro elemento, li aponta para null
	// logo, no aponta para null também
	*li=no;
	// lembre-se, li apontava para null
	// agora, ele vai apontar para o primeiro elemento da célula
	return 1;
}

int insere_lista_final(Lista *li, struct aluno al){
	if(li== NULL) return 0;
	Elem* no= (Elem*) malloc(sizeof(Elem));
	// Elem é a sua estrutura
	// li é um ponteiro para a estrutura Elem
	// Nesse caso, li vai apontar para o primeiro elemento da lista
	if(no==NULL) return 0;
	no->dados=al;
	no->prox=NULL;
	if((*li==NULL)){
		// se a lista estiver vazia, iremos inserir no inicio
		*li=no;
	}
	else{
		Elem *aux =*li;
		// pega o conteúdo de li, ou seja o endereço de onde li aponta
		// se fosse sem o * em li, eu estaria pegando o endereço de li
		while(aux->prox!=NULL){
			aux=aux->prox;
			// procure até encontrar a célula que aponta para o vazio
		}
		aux->prox=no;
		//o aux é um ponteiro de ponteiro que começou em li(inicio da lista)
		// desta forma, ele irá alterar o conteúdo da lista por referencia
	}
	return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al){
	if(li== NULL) return 0;
	Elem* no= (Elem*) malloc(sizeof(Elem));
	if(no==NULL) return 0;
	no->dados=al;
	if(lista_vazia(li)){
		// se a lista estiver vazia, iremos inserir no inicio
		no->prox=(*li);
		*li=no;
		// muda o conteúdo para onde li aponta
	}
	else{
		Elem *ant, *atual =*li;
		
		while(atual!=NULL && atual->dados.matricula < al.matricula){
			ant=atual;
			atual=atual->prox;
			
		}
		if(atual==*li){// insere no inicio
			no->prox=(*li);
			*li=no;
		}
		else{//insere no meio ou no final
			no->prox=ant->prox;
			ant->prox=no;
		}
		
	}
	return 1;
}


int remove_lista_inicio(Lista* li){
	if(li==NULL) return 0;
	if((*li)==NULL) return 0;
	Elem *no = *li;
	free(no);
	return 1;
}

int remove_lista_final( Lista *li){
	if(li==NULL) return 0;
	if((*li)==NULL) return 0;
	Elem *ant, *no=*li;
	while(no->prox!=NULL){
		ant=no;
		no=no->prox;
	}
	if(no==(*li))
		*li=no->prox;
	else
		ant->prox=no->prox;
	free(no);
	return 1;
}


int remove_lista( Lista *li, int mat){
	if(li==NULL) return 0;
	Elem *ant, *no=*li;
	while(no=NULL && no->dados.matricula !=mat){
		ant=no;
		no=no->prox;
	}
	if(no==NULL) return 0;
		*li=no->prox;
	if(no== *li) return 0;
		*li=no->prox;	
	else
		ant->prox=no->prox;
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