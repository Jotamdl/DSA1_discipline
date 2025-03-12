/*TAD Pilha */

typedef struct pilha Pilha;

float pilha_pop (Pilha* p);
void pilha_push (Pilha* p, float v);
Pilha* pilha_cria (void);
int pilha_vazia (Pilha *p);