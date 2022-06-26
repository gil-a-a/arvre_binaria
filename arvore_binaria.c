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

////////////////////funções///////////////////////
struct node* cria_no();
void percorre_arv(Node *raiz);
void InsEsq(Node *aux, int x);
void InsDir(Node *aux, int x);
void insere_na_arv(Node **no, int num);
void tem_repetido(Node *raiz, int num, int *aux);
void coloca_nums_na_arv(Node **raiz);
int busca(Node *no, int num);
/////////////////////////////////////////////////

int main ()
{
    int num;
	Node *raiz, *raiz_2;
	
	raiz = cria_no(5);
	InsEsq(raiz, 4);
	InsDir(raiz, 7);
	
	InsEsq(raiz->esq, 2);
	InsDir(raiz->esq, 3);
	
	InsEsq(raiz->dir, 6);
	InsDir(raiz->dir, 8);
	
	percorre_arv(raiz);
	printf("\n---------Nova arvore---------\n");
	
	coloca_nums_na_arv(&raiz_2);
	printf("\nArvore pre-ordem: ");
	percorre_arv(raiz_2);
	
	printf("\nInsira o numero para buscá-lo na árvore: ");
	    scanf("%d", &num);
	if (busca(raiz_2, num))
	    printf("\nNumero encontrado");
	else
	    printf("\nNumero nao encontrado");
    
	return 0;
}

/////////////////////////////////////////////////
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

void InsEsq(Node *aux, int x)
{
    if (aux->esq != NULL)
        printf("Operacao ilegal\n");
    else
        aux->esq = cria_no(x);
}

void InsDir(Node *aux, int x)
{
    if (aux->dir != NULL)
        printf("Operacao ilegal\n");
    else
        aux->dir = cria_no(x);
}

void insere_na_arv(Node **no, int num)
{
	if (*no == NULL){
	    *no = cria_no(num);
	    return;
	}
	
	if (num <= (*no)->info)
		insere_na_arv(&(*no)->esq, num);
	else
		insere_na_arv(&(*no)->dir, num);
}

void tem_repetido(Node *raiz, int num, int *aux)
{
    if (raiz == NULL)
        return;
    else if (raiz->esq != NULL || raiz->dir != NULL){
        tem_repetido(raiz->esq, num, aux);
        tem_repetido(raiz->dir, num, aux);
    }
    if (raiz->info == num)
        *aux = 1;
    else
        return;
}

void coloca_nums_na_arv(Node **raiz)
{
	int i, aux, aux_2;
	srand(time(NULL));
	
	*raiz = cria_no(rand() % 31);
	printf("Elemento da raiz: %d\n", (*raiz)->info);
	
	i = 1;
	while (i <= 5){
		do{
		    aux_2 = 0;
		    aux = rand() % 31;
		    tem_repetido(*raiz, aux, &aux_2);   //coloquei uma flag por referência, pq foi mais fácil fazer assim
		}while(aux_2);
		printf("Elemento %d: %d\n", i, aux);
		
		if (aux <= (*raiz)->info)
			insere_na_arv(&(*raiz)->esq, aux);
		else
			insere_na_arv(&(*raiz)->dir, aux);
		
		i++;
	}
}

int busca(Node *no, int num)
{
    int x;
    
    if (no == NULL)
        return 0;
    
    if (num == no->info)
        return 1;
    else if (num < no->info)
        x = busca(no->esq, num);
    else if (num > no->info)
        x = busca(no->dir, num);
    
    return x;
}

/////////////////////////////////////////////////

