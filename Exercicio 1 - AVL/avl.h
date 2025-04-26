typedef struct avl Avl;

// Raiz apontando para NULL
Avl* Avl_criavazia (void);

Avl* Avl_cria (char c);

// Funcao recursiva para liberar os nos a partir da raiz r
void Avl_libera (Avl* r);

// Busca de acordo com a ordenacao da arvore
Avl* Avl_busca (Avl* r, char c);

// Funcao de insercao
Avl* Avl_insere (Avl* r, char c);

// Funcao de remocao
Avl* Avl_retira (Avl* r, int c);

void Avl_imprime (Avl* r);

// Funcao para rotacao simples a esquerda na arvore AVL
Avl* rotacaoEsquerda(Avl* a);

// Funcao para rotacao simples a direita na arvore AVL
Avl* rotacaoDireita(Avl* a);

