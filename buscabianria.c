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

    if (arvore-> key > key) {
        return busca_arv(key, arvore->arve);
    } else {
        return busca_arv(key, arvore->arvd);
    }
}

arv* inserir_valor(arv * arvore, arv * nova_arvore){
    if (arvore == NULL)
        return nova_arvore;

    if (arvore->key > nova_arvore->key)
        arvore->arve = inserir_valor(arvore->arve, nova_arvore);
    else
        arvore->arvd = inserir_valor(arvore->arvd, nova_arvore);

    return arvore;
}

arv* remover_valor(arv * arvore) {
    arv * pai, * filho;

    if (arvore->arve == NULL) {
        filho = arvore->arvd;
        free(arvore);
        return filho;
    }

    pai = arvore;
    filho = arvore->arve;

    while (filho->arvd != NULL) {
        pai = filho;
        filho = filho->arvd;
    }

    if (pai != arvore) {
        pai->arvd = filho->arve;
        filho->arve = arvore->arve;
    }

    filho->arvd = arvore->arvd;
    free(arvore);

    return filho;
}

int main()
{
    arv* tree = cria_arv(
            5,
            5,
            cria_arv(
                    6,
                    6,
                    cria_arv(
                            7,
                            7,
                            NULL,
                            NULL),
                    NULL),
            cria_arv(
                    3,
                    3,
                    NULL,
                    cria_arv(
                            2,
                            2,
                            NULL,
                            NULL))
    );
}
