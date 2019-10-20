#include <stdio.h>
#include <stdlib.h>

typedef struct fila FILA;
typedef struct elemento CELULA;
typedef enum {FALSE, TRUE} bool;
typedef struct pilha *PILHA;
typedef struct pilha Elem;

struct fila
{
	int MAXSIZE, SIZE;
	struct elemento *inicio;
	struct elemento *final;
};
struct elemento
{
	int dado;
	struct elemento *prox;
};

struct pilha
{
	int dado;
	struct pilha *prox;
}

PILHA *cria_pilha()
{
	PILHA *pi = (PILHA*)malloc(sizeof(PILHA));
	if(pi != NULL)
	{
		*pi = NULL;
	}
	return pi;
}

int insere_pilha(PILHA *pi, int x)
{
	if(pi == NULL)
	{
		return 0;
	}
	Elem *no = (PILHA*)malloc(sizeof(CELULA));
	if(no == NULL
	{
		return 0;
	}
	no->dado = x;
	no->prox = *pi;
	*pi = no;
	return 1;
}

int remove_pilha(PILHA *pi);
{
	if(pi == NULL)
	{
		return 0;
	}
	if((*pi) == NULL)
	{
		return 0;
	}
	Elem *no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

FILA *fi;
FILA *cria_fila(int x)
{
	FILA *fi = (FILA*)malloc(sizeof(FILA));
	if(fi == NULL)
	{
		return 0;
	}
	fi->inicio = NULL;
	fi->final = NULL;
	fi->SIZE = 0;
	fi->MAXSIZE = x;
	return fi;
}
int insere_fila(FILA *fi, int x)
{
	if(fi == NULL)
	{
		return 0;
	}
	CELULA *no = (CELULA*)malloc(sizeof(CELULA));
	if(no == NULL)
	{
		return 0;
	}
	no->dado = x;
	no->prox = NULL; 
	if(fi->final == NULL)
	{
		fi->inicio = no;
	}
	else
	{
		fi->final->prox = no;
	}
	fi->final = no;
	fi->SIZE++;
	return 1;	
}

int remove_fila(FILA *fi)
{
	if(fi == NULL)
	{
		return 0;
	}
	if(fi->inicio == NULL)
	{
		return -1;
	}
	CELULA *no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	if(fi->inicio == NULL)
	{
		fi->final = NULL;
	}
	fi->SIZE--;
	free(no);
	return 1;
}

bool fila_cheia(FILA *fi)
{
	if(fi->SIZE == fi->MAXSIZE)
	{
		return TRUE;
	}
	return FALSE;
}

bool elem_ta_fila(FILA *fi, int x)
{
	CELULA *no = fi->inicio;
	while(no != NULL)
	{
		if(no->dado == x)
		{
			return TRUE;
		}
		no = no->prox;
	}
	return FALSE;
}

int main(int argc, char const *argv[])
{
	int a, i, grtinsere, grtremove, cachemiss=0, cont=0;
	FILE *arq;
	int z = atoi(argv[1]);
	FILA *q = cria_fila(z);
	
	arq = fopen(argv[2],"r");
	if(arq == NULL)
	{
		printf("Erro na abertura! \n");
		exit(1);
	}
	else 
	{
		printf("Arquivo Aberto \n");
	}
	while(!feof(arq))
	{
		fscanf(arq, "%d", &a);
		insere_fila(q, a);
	}
	
	FILA *fi = cria_fila(z);
	
	CELULA *c = q->inicio;
	while(c != NULL)
	{
		if(fila_cheia(fi) != TRUE)
		{
			if(fi->inicio == NULL)
			{
				insere_fila(fi, c->dado);
				cachemiss += 1;
			}
			else
			{
				if(elem_ta_fila(fi, c->dado) == TRUE)
				{
					if(fi->inicio->dado == c->dado)
					{
						remove_fila(fi);
						insere_fila(fi, c->dado);
					}
					else if(fi->final->dado == c->dado)
					{
						
					}
					else
					{
						int vari, j, t;
						t = fi->SIZE;
						for(j=0; j<t; j++)
						{
							if(fi->inicio->dado == c->dado)
							{
								remove_fila(fi);
							}
							else
							{
								vari = fi->inicio->dado;
								remove_fila(fi);
								insere_fila(fi, vari);							
							}
						}
						insere_fila(fi, c->dado);
					}
				}
				else
				{
					insere_fila(fi, c->dado);
					cachemiss += 1;
				}
			}
		}
		else
		{
			if(elem_ta_fila(fi, c->dado) == TRUE)
				{
					if(fi->inicio->dado == c->dado)
					{
						remove_fila(fi);
						insere_fila(fi, c->dado);
					}
					else if(fi->final->dado == c->dado)
					{
						
					}
					else
					{
						int vari, j, t;
						t = fi->SIZE;
						for(j=0; j<t; j++)
						{
							if(fi->inicio->dado == c->dado)
							{
								remove_fila(fi);
							}
							else
							{
								vari = fi->inicio->dado;
								remove_fila(fi);
								insere_fila(fi, vari);							
							}
						}
						insere_fila(fi, c->dado);
					}
				}
				else
				{
					remove_fila(fi);
					insere_fila(fi, c->dado);
					cachemiss += 1;
				}
		}
		c = c->prox;
	}
	
	CELULA *no = fi->inicio;
	PILHA *pi = cria_pilha();
	
	printf("{ ");
	while(no != NULL)
	{
		insere_pilha(pi, no->dado);
		no =  no->prox;
	}
	while(pi != NULL)
	{
		printf(" %d", pi->dado);
		rempve_pilha(pi);
	}
	printf("}");
	printf("Cache miss = %d \n", cachemiss);
}