#include <stdio.h>
#include "pilha.h"
 
/*Protótipo da função */
int parenthesis_balance (char* s) {
    int i = 0;
    char t = s[0];
    Pilha* p = pilha_cria();
    while (t != '\0') {   
        if (t == '(') {
            pilha_push(p, 1);
        } else if (t == ')') {
            if (pilha_vazia(p)) {
                printf("incorrect\n");
                return 0;
            };
            pilha_pop(p);
        }
        
        t = s[++i];
    }
    
    if (!pilha_vazia(p)) {
        printf("incorrect\n");
        return 0;
    } else {
        printf("correct\n");
        return 1;
    }
    
};  

int main() {

    return 0;
}