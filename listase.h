#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

typedef char tp_item;

typedef struct tp_no{
    tp_item info;
    struct tp_no *prox;
}tp_listase;

int listase_vazia(tp_listase *lista){
    if (lista==NULL) return 1;
    return 0;
}

tp_listase *aloca_listase(){
    tp_listase *novo_no;
    novo_no = (tp_listase*) malloc(sizeof (tp_listase));
    novo_no->prox = NULL;
    novo_no->info = NULL;
    return novo_no;
}

int insere_listase_no_fim (tp_listase **l, tp_item e){
    tp_listase *novo_no, *atu;
    novo_no = aloca_listase();
    if (novo_no==NULL) return 0;
    novo_no -> info = e;
    novo_no -> prox = NULL;

    if (listase_vazia(*l)) {
        *l = novo_no;
    }
    else {
        atu = *l;
        while (atu -> prox != NULL) {
            atu = atu -> prox;
        }
        atu -> prox = novo_no;
    }
    return 1;
}

void imprime_listase (tp_listase *lista){
    tp_listase *atu;
    atu = lista;

    while (atu!=NULL) {
        printf("%c\n", atu->info);
        atu = atu -> prox;
    }
}

int tamanho_listase (tp_listase *lista) {
    int cont = 0;
    tp_listase *atu;
    atu = lista;
    while (atu != NULL){
        cont++;
        atu = atu -> prox;
    }
    return cont;
}

tp_listase *busca_listase(tp_listase *lista, tp_item e){
    tp_listase *atu;
    atu=lista;
    while((atu!=NULL)&&(atu->info!=e)){
        atu=atu->prox;
    }
    if (atu==NULL) return NULL;
    return atu;
}

int remove_listase(tp_listase **lista,tp_item e){
    tp_listase * ant, *atu;
    atu=*lista;
    ant=NULL;
    while ((atu!=NULL)&&(atu->info!=e)){
        ant=atu;
        atu=atu->prox;
    }

    if (atu==NULL) return 0; // não foi encontrado o elemento
    if (ant==NULL){// se for retirado o primeiro termo
        *lista=atu->prox; // fazendo a lista apontar para o termo subsequente que foi retirado
    }
    else{
        ant->prox=atu->prox; //fazendo a interligação entre o termo anterior e o termo subsequente ao termo retirado
    }

    free(atu);
    atu=NULL;
    return 1;
}

void destroi_listase(tp_listase **l){
    tp_listase *atu;
    atu=*l;
    while (atu!=NULL){
        *l=atu->prox;
        free(atu);
        atu=*l;
    }
    *l=NULL;
}



#endif //LISTASE_LIBRARY_H