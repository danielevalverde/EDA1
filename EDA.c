CTRL + SHIFT +P 
Biblioteca
	stdio.h = biblioteca de entrada e saída de dados
As estruturas de dados definem a organização, métod de acesso e opções de processamento para coleções de itens de informaçã maanipulados pelo programa. Dois tipos de coleções são apresentados:
	Estruturas lineares:
		são aquelas que mantém os seus itens de forma independente de seus conteúdos, ou seja, na qual qualquer tipo de interpretação dos dados que são armazenados é irrelevante para a manutenção da estrutura. 
	Estruturas associativas:
		são aquelas que levam em consideração a interpretação do valor (ou de parte dele) para a manutenção dos itens na estrutura.





BOOLL
typedef enum {FALSE,TRUE} bool;

#define nome 100(valor);
o vetor só pode ser declarado com um tamanho fixo(constante)
int var = 5;
int vetor[nome];
int vetor[100];
int vetor[var]; // NÃO PODE

Tipo de dados :
	define o conjunto de valores (domínio) que uma variável pode assumir
EDA :
	Trata-se de uma relacionamento lógico entre tipos de dados . Ex: struct - nome(string) - idade(int) - altura(float)
Tipo Abstratos de Dados "TAD":
	Incluem as operações para a manipulação de dados. A intenção é criar funções para interagir com seus dados
	Ex:
		Criação de estruturas
		Inclusão de um elemento
		Remoção de um elemento
		Acesso a um elemento
	Vantagens: 
		Encapsulamento e Segurança: BASICAMENTE POO
			Usuário não tem acesso diretos aos dados
		Flexibilidade e Reutilização :
			Podemos alterar o TAD sem alterar as aplicações que o utilizam
A convenção em linguagem C é preparar dois arquivos para implementar um TAD. A intenção é separa o conceito(classe) da sua implementação. Esse procedimento é chamado de modularizaçãos

Arquivo.H:
	Protótipo das funções, tipo de ponteiro, e dados globalmente acessível
Arquivo.C:
	Declaração do tipo de dados e implementação das suas funções 

Estruturas
	Enum : É uma lista de identificadores(constantes)
	enum semana {domingo, segunda... };
	Domingo e segunda são identificadores, mas o que será impresso, será um número
	int main() {
		s=segunda;
		printf("d\n",s);
	}

Funções
	Um array só pode ser retornado se estiver dentro de umas struct,
	sim, podemos retornar uma struct na função.

	Quando se usa void, pode-se colocar o printf na mesma

ARRAY:
	Todo array é um ponteiro
	O nome do array é um ponteiro para o primeiro elemento de array 

Alocação dinâmica

	int *v = malloc(x(Quantidadede) * sizeof(int));
	pode ser int, char, float . O que cê quiser

	int *p = (int *) malloc(x(Quantidadede) * sizeof(int));

Função Math
quando for compilar, coloque gcc nome.c -lm 




Lista dinâmica
		CAda elemento aponta para o seu sucessor na lista. Usa um ponteiro especial para o primeiro 
		elemento da lista e uma indicação de final de lista
		Cada elemento é tratado como um ponteiro que é alocado dinamicamente, a medida que os dados são inseridos
		Para guardar o primeiro elemento, utilizamos "um pontiero para ponteiro"
		Um "ponteiro para ponteiro" pode guardar o endereço de um "ponteiro"
		Assim, fica fácil mudar quem está no inicio da lista mudando o "conteudo" do "ponteiro para ponteiro"
		a sua " cabeça" guarda o endereço da primeira célula, a cabeça não tem "valor/conteúido" do ponteiro pra potenrio


Ponteiros
	guardam enderços de memória
	int *n = NULL

	//significa que o ponteiro aponta para lugar nenhum
	int x=5;
	int *p;
	p =&x;

	*p=7 
	// significa que eu vou alterar o valor de x de 5 para 7

AULA 94 Ponteiro para função
 	 96 Array de ponteiro para ponteiro




COMPLEXIDADE:
	o desempenho de um algoritmo associa a cada entrada d, o custo da execução do algoritmo sob essa entrada.

	Análise Assítotica : É definida pelo crescimento da complecidade para entradas suficientemente grandes
	Usualmente, o cálculo da complexidade concentra-se em determinar a ordem de magnitude do número de operações fundamentais na execução do algorimo
	Cota assíntotica superior (CAS): é uma função que cresce mais rapidamente do que outra: permanece acima a partir de certo ponto 
	Sendo f(n)=n+5 e g(n)=n². Dizemos qu ea linear f(n) é O(g(n)).
	A letra grega O cham-se omicron("O" pequeno). Pode-se ler f(n) é O(g(n)) ou f(n) é pequena para g(n)
	Isso também pode ser escrito como f(n) = O(g(n))
	Mostrar que vale a partir de um determinado n
	A complexidade será dada pelo polinômio de maior grau 

	A letra grega Omega, pode-se ler f(n) é omega g(n) como f(n) é grande para g(n)
	Ou seja, a função g(n) cresce menos rapidamente que a função f(n) em termos de complexidade

	Limite assíntotico exato: se c.g(n)<f(n)<d.g(n);