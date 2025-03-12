//////////////////////////////////
// Interface do TAD Estudante   //
//////////////////////////////////

typedef struct estudante Estudante;

// Funcao para criar um estudante
Estudante* criaEstudante(const char *nome, int idade, float coef_rendimento);

// Funcao para destruir um estudante
void destroiEstudante(Estudante *e);

// Funcao para retornar o nome de um estudante
char* getNome(Estudante *e);

// Funcao para retornar a idade de um estudante
int getIdade(Estudante *e);

// Funcao para retornar o CR de um estudante
float getCoeficiente(Estudante *e);

//-----------------Novas funções-------------------
// Funcao imprime estudante - implementar
void imprimeEstudante(Estudante *e);