#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor, key;
    struct Arv * arvd;
    struct Arv * arve;
} arv;


arv* cria_arv_vazia() {
    return NULL;
}

arv* cria_arv(int valor, int chave, arv* arvore_direita, arv* arvore_esquerda) {
    arv* nova_arvore = (arv *)malloc(sizeof(arv));
    
    nova_arvore->valor = valor;
    nova_arvore->key = chave;
    nova_arvore->arvd = arvore_direita;
    nova_arvore->arve = arvore_esquerda;
    
    return nova_arvore;
}

arv * busca_arv(int key, arv * arvore){
    if(arvore == NULL || arvore->key == key){
        return arvore;
    }    
    if(arvore-> key > key){
        return busca_arv(key, arvore->arve);
    }if(arvore-> key < key){
    return busca_arv(key, arvore->arvd);
    }
}

arv* inserir_valor(int valor, int chave, arv * arvore){
   arv * place = busca_arv(chave, arvore);
   place = cria_arv(valor, chave, NULL, NULL);
   
   return arvore;

}

void teste(int valor, int chave, arv* arvore) {
    arvore->arve = cria_arv(valor, chave, NULL, NULL);
    arvore->arvd = NULL;
}


int main()
{
    arv* tree = cria_arv(
        5,5,
        cria_arv(
            6,6, cria_arv(7,7,NULL, NULL), NULL
            ),
        cria_arv(3,3, cria_arv(2,2,NULL,NULL),NULL)
        );
        
    arv* new_tree = cria_arv(4,4, NULL, NULL);
    teste(3,3, new_tree);
    
    printf("%d", new_tree->arve->key);
}
