#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sDisciplina
{
    char codigo[10];
    char nome[20];
    int creditos;
    int cargahor;
}Disciplina;

typedef struct sNo
{
    Disciplina info;
    struct sNo *prox;
}NO;

typedef struct sLista
{
    NO *inicio;
    int tam;
}Lista;

NO* lista_inicializar(NO* Lista)
{
    Lista = NULL;
    return Lista;
}

NO* alocarNO()
{
    return(NO*) malloc(sizeof(NO));
}

void desalocarNo(NO* q)
{
    free(q);
}

int lista_vazia(NO* Lista)
{
    if(Lista == NULL){
        return 1;
    }else{
        return 0;
    }
}

NO* inserir_fim(NO* Lista, Disciplina elem)
{   NO *novo;
    NO *aux;
    novo = alocarNO();
    if(novo!=NULL){
        novo->info = elem;
        novo->prox = NULL;
        if(lista_vazia(Lista))
            Lista = novo;
    else{
        aux = Lista;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return Lista;
    }
    else{
        printf("Erro na alocacao do no\n");
            return NULL;
    }
}

NO* pesquisar(NO* Lista, char x[])
{
    NO* aux;
    aux = Lista;
    if(!lista_vazia(Lista)){
        while(aux != NULL){
            if(strcmp(aux -> info.codigo, x)==0)
                return aux; // encontrou o no
            aux = aux ->prox;
        }
    }
    return NULL; // nao encontrou o no
}

NO* remover_inicio(NO* Lista)
{   NO *q;
    q = Lista;
    if(!lista_vazia(Lista)){
        Lista = q->prox;
        desalocarNo(q);
        return Lista;
    }else{
        printf("Erro: lista vazia\n");
        return NULL;
    }
}

NO* remover_valor(NO* Lista, char x[])
{
    NO* aux;
    NO* q;
    if((q = pesquisar(Lista, x)) != NULL){
        aux = Lista;
        if(aux == q){ // no esta no inicio
            remover_inicio(Lista);
        }else{ // percorrer a lista
            while(aux -> prox != q)
                aux = aux -> prox;
                aux -> prox = q -> prox;
                desalocarNo(q);
        }
        return Lista; // removeu o elementoS
    }
        return NULL; // nao removeu o elemento
}

void imprimirlista(NO* Lista)
 {
    NO* aux;
    aux = Lista;
    if(lista_vazia(Lista))
        printf("Lista vazia\n");
    while(aux!= NULL){
                printf(" %s - %s", aux->info.nome, aux->info.codigo);
                aux = aux -> prox;
        }

}

void imprimirlista2(NO* Lista)
{
    NO* aux;
    aux = Lista;
    NO* info;
    if(!lista_vazia(Lista)){
             while(aux != NULL){
                if(aux->info.codigo[0] == 's' && aux->info.codigo[1] == 'i' && aux->info.codigo[2] == 'n' && aux->info.cargahor > 60)
                printf(" %s - %s", aux->info.nome, aux->info.codigo);
                aux = aux -> prox;
        }
    }else{
        printf("Lista vazia");
    }
}

void Menu (){
printf("\n [1]- Insira um disciplina no final da lista\n");
printf("\n [2]- Remova uma disciplina pelo codigo\n");
printf("\n [3]- Imprimir lista\n");
printf("\n [4]- Imprimir as disciplinas de SI com carga horaria maior que 60\n");
printf("\n [0]- Sair\n");
}

int main (){
    int escolha;
    char x[7];
    NO* Lista;
    NO* lista_aux;
    Disciplina elem;
    Lista = lista_inicializar(Lista);
    do{
         Menu();
        printf("Digite uma opcao valida: \n");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls");
        switch(escolha){
            case 0:;
            return 0;
            case 1:
                fflush(stdin);
                printf("Digite o nome da disciplina: \n");
                gets(elem.nome);
                fflush(stdin);
                printf("Digite o codigo da disciplina: \n");
                gets(elem.codigo);
                fflush(stdin);
                printf("Digite o numero de creditos: \n");
                scanf("%d", &elem.creditos);
                fflush(stdin);
                printf("Digite a carga horaria: \n");
                scanf("%d", &elem.cargahor);
                lista_aux = inserir_fim(Lista,elem);
                if(lista_aux != NULL){
                    Lista = lista_aux;
                }
                break;
            case 2:
                fflush(stdin);
                printf(" Digite o codigo da disciplina que quer remover: \n");
                gets(x);
                lista_aux = remover_valor(Lista, x);
                    if(lista_aux != NULL){
                        Lista = lista_aux;
                    }
                break;
            case 3:
               imprimirlista(Lista);
               break;
            case 4:
                imprimirlista2(Lista);
                break;
            default: printf("Saindo\n");
    }
    }while(escolha!=5);
 return 0;
}