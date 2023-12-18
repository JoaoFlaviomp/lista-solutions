#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NO{
    char infos;
    float info;
    struct NO* ant;
    struct NO* prox;
}NO;
typedef NO* Lista;

void inicializarlista(Lista*pl){
    *pl = (Lista) malloc (sizeof(NO));
        if(!(*pl)){
            printf("\nErro! Memoria insuficiente!\n");
            exit(1);
        }
        (*pl)->info=0;
        (*pl)->ant=(*pl)->prox=*pl;
}

int listavazia(Lista pl){
    return (pl->info==0);
}