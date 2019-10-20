#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct aluno {
	int matricula;
	char nome [30];
	float n1,n2,n3;
};
typedef struct aluno al;
typedef struct lista Lista;

struct lista {
	int qtd;
	struct aluno dados[MAX];
};

Lista * cria_lista(){
	Lista *li; // ponteiro do tipo lista
	li=(Lista*) malloc(sizeof(struct lista));
	if(li!=NULL){
		li->qtd=0;
	}
	return li;
}

void libera_lista( Lista* li){
	free(li);
}

int tamanho_lista( Lista *li){
	if(li==NULL)
		return -1;
	else
		return li->qtd;
}

int lista_cheia( Lista *li){
	if(li==NULL)
		return -1;
	else
		return (li->qtd==MAX);
		// esse pedaço retorna 1 ou 0, verdadeiro ou falso
}

int lista_vazia( Lista *li){
	if(li==NULL)
		return -1;
	else
		return (li->qtd==0);
		// esse pedaço retorna 1 ou 0, verdadeiro ou falso
}

int insere_lista_final(Lista *li, struct aluno al){
	if(li==NULL)
		return -1;
	if(lista_cheia(li))
		return 0;
	li->dados[li->qtd]=al;
	li->qtd++;
	//printf("%s\n",al.nome);
	return 1;

}

int insere_lista_inicio(Lista *li, struct aluno al){
	if(li==NULL)
		return -1;
	if(lista_cheia(li))
		return 0;
	int i;
	for( i=li->qtd-1; i>=0;i--)
		li->dados[i+1] = li->dados[i]; 
		//empurrando tudo para uma posição a mais.
		// "copiando os dados para outra posição para que não sejam sobrescritos"
	li->dados[0]=al;
	li->qtd++;
	printf("%s\n",al.nome);
	return 1;

}


int insere_lista_ordenada(Lista *li, struct aluno al){
	if(li==NULL)
		return -1;
	if(lista_cheia(li))
		return 0;
	int i,k;
	while(i<li->qtd && li->dados[i].matricula<al.matricula)
		i++;
		// a primeira verificação é para determinar que i não chegue ao fim da lista
		// a ordenação será pela matricula, por isso estamos comparando ela
		// perceba que você sempre compara com o proximo elemento. Ex:
		// lista : 2 , 4 , 40 E eu quero add 20
		// eu pergunto : 20 é menor que 2 ? N, proximo. 20 é menor 	que 4 ?N, proximo
		// 20 é menor que 40 ? Não. Então eu add 20 antes de 40.
	for( k=li->qtd-1; k>=i;i--)
		li->dados[k+1] = li->dados[k]; 
		//empurrando tudo para uma posição a mais.
		// "copiando os dados para outra posição para que não sejam sobrescritos"
		// adiciona uma nova posição antes
	li->dados[i]=al;
	li->qtd++;
	printf("%s\n",al.nome);
	return 1;

}

int remove_lista_final(Lista *li ){
	if(li==NULL)
		return -1;
	if(li->qtd==0)
		return 0;
	li->qtd--;
	return 1;
}

int remove_lista_inicio(Lista *li ){
	if(li==NULL)
		return -1;
	if(li->qtd==0)
		return 0;
	int k;
	for(k=0;k<li->qtd-1;k++)
		li->dados[k]=li->dados[k+1];
		//sobrescreve a posição anterior pela posterior
		// e vai descendo a lista 
	li->qtd--;
	return 1;
}


int remove_lista(Lista *li, int mat ){
	if(li==NULL)
		return -1;
	if(li->qtd==0)
		return 0;
	int k,i;
	while(i<li->qtd && li->dados[i].matricula!=mat)
		i++;
	if(i==li->qtd)
		return 0;
	for(k=i;k<li->qtd-1;k++)
		li->dados[k]=li->dados[k+1];
		//sobrescreve a posição atual pela posterior
		// e vai descendo a lista 
	li->qtd--;
	return 1;
}
int consulta_lista_pos(Lista *li, int pos, struct aluno *al ){
	if(li==NULL || pos <0 || pos>li->qtd )
		return 0;
	if (pos>0){
		*al=li->dados[pos];
		printf("%s\n",li->dados[pos].nome);
	}
	else
		printf("%s\n",li->dados[0].nome);
	return 1;
}


int consulta_lista_mat(Lista *li, int mat, struct aluno *al ){
	// essa estrutura "al" é para onde você vai retornar os dados
	// mande uma struct vazia pra cá, mas antes, insira ela na lista
	// lembre-se é passagem por referêncai

	if(li==NULL )
		return 0;
	int i =0;
	while(i<li->qtd &&li->dados[i].matricula !=mat)
		i++;
	if(i==li->qtd)
		return 0;
	*al =li->dados[i];
	return 1;
}
