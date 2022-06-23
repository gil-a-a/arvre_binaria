#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//nó da árvore
typedef struct node{
	int info;
	struct node *esq;
	struct node *dir;
}Node;

int a = 0; //var global pra testar

//funções
struct node* cria_no();
void percorre_arv(Node *raiz);
struct node* insere_na_arv(Node *no, int num)
{
	if (no == NULL){
		no = cria_no(num);
		return no;
	}
	
	if (num < no->info)
		insere_na_arv(no->esq, num);
	else
		insere_na_arv(no->dir, num);
}

struct node* coloca_nums_na_arv(Node *raiz)
{
	int aux, i;
	srand(time(NULL));
	
	raiz = cria_no(rand() % 11);
	printf("%d ", raiz->info);
	
	i = 1;
	while (i <= 3){
		aux = rand() % 11;
		printf("%d ", aux);
		
		if (aux < raiz->info){
			raiz->esq = insere_na_arv(raiz->esq, aux);
		}
		else{
			raiz->dir = insere_na_arv(raiz->dir, aux);
		}
		
		i++;
	}
	
	return raiz;
}


int main ()
{
	Node *raiz;
	
	raiz = coloca_nums_na_arv(raiz);
	
	percorre_arv(raiz);
	
	return 0;
}

struct node* cria_no(int info)
{
	Node *aux;
	
	aux = (struct node *) malloc(sizeof(struct node));
	aux->info = info;
	aux->esq = NULL;
	aux->dir = NULL;
	
	return aux;
}

void percorre_arv(Node *raiz)
{
	if (raiz != NULL){
		printf("%d ", raiz->info);
		percorre_arv(raiz->esq);
		percorre_arv(raiz->dir);
	}
}

