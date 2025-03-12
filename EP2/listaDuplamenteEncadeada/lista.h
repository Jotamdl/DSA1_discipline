//////////////////////////////////
// Interface do TAD Lista       //
//////////////////////////////////

#include "estudante.h"


// Estrutura da lista
typedef struct lista Lista;

// Função para criar uma lista
Lista* criaLista();

// Função para destruir a lista
void destroiLista(Lista *l);

// Função para inserir um estudante na lista
Lista* insere(Lista *l, Estudante *e);

// Função para remover um estudante da lista por nome
Lista* retira(Lista *l, const char *nome);

//-----------------Novas funções-------------------
// Implementar função para imprimir toda a lista de estudantes
void imprime(Lista *l);

// Implementar função para imprimir somente um nó da lista de estudantes apontado por p
void imprimeNo(Lista *p);

// Implementar função de busca um estudante pelo nome, retorna o ponteiro para o nó, se encontrado e, NULL, caso contrário
Lista* busca(Lista *l, char* nome);

// Implementar função de retorna o comprimento da lista
int tamanho(Lista *l);