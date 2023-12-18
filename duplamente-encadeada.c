#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sNo
{
    float info;
    struct sNo *dir;
    struct sNo *esq;
}NO;

void inicializar(NO **lista)
{
    *lista = NULL;
}

NO* AlocarNO()
{
    NO *novo = (NO*)malloc(sizeof(NO));
    if(novo != NULL){
        return novo;
    }
    else{
        printf("Erro ao alocar o no\n");
        exit(1);
    }
}

void desalocarNO(NO *q)
{
    free(q);
}

int lista_vazia(NO **ptrlista)
{
    if(*ptrlista == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

float ler_numeros(float numero)
{
    printf("Digite algum numero: \n");
    scanf("%f", &numero);
    return numero;
}

void inserir_fim(NO **lista)
{
    int elem = ler_numeros(elem);
    NO *novo = AlocarNO();
    NO *aux;
    novo -> info = elem;
    novo -> dir = NULL;
    novo -> esq = NULL;
    if(lista_vazia(lista)){
        *lista = novo;
    }
    else{
        aux = *lista;
        while(aux -> dir != NULL){
            aux = aux -> dir;
        }
        aux -> dir = novo;
        novo -> esq = aux;
    }
}

void remover_inicio(NO **lista)
{
    NO *q;
    q = *lista;
        if(!lista_vazia(*lista)){
            *lista = q -> dir;
            (*lista) -> esq = NULL;
            desalocarNO(q);
        }
        else{
            printf("Erro: lista vazia\n");
            exit(1);
        }
}

void remover_fim(NO **lista)
{
    NO *q;
    q = *lista;
        if(lista_vazia(*lista)){
           printf("Erro: lista vazia\n");
           exit(1);
        }
        else{
            if((*lista) -> dir == NULL){
                remover_inicio(*lista);
            }
            else{
                while(q -> dir != NULL){
                    q = q -> dir;
                }
                (q -> esq) -> dir = q -> dir;
                    free(q);
            }
        }
}

void ordem_inversa(NO **lista)
{
    NO *q;
    q = *lista;
        while(q -> dir != NULL){
            q = q -> dir;
        }
        while(q != NULL){
            printf("%f \n", q -> info);
            q = q -> esq;
        }
}

void exibe_soma(NO **lista)
{
    float soma = 0;
    NO *q;
        for(q = *lista; q != NULL; q = q -> dir)
        {
            soma = soma + q -> info;
        }
        printf("A soma de todos os elementos eh: %f\n", soma);
        printf("\n");
}

void imprime_lista(NO *lista)
{
    while(lista != NULL){
        printf("%.f", lista -> info);
        lista = lista -> dir;
    }
    printf("\n");
}

void Menu()
{
    printf("[1]: Inserir final\n");
    printf("[2]: Remover final\n");
    printf("[3]: Imprimir na ordem inversa\n");
    printf("[4]: Exibir a soma de todos os elementos\n");
    printf("[5]: Imprimir lista\n");

}

int main(){
    int escolha;
    NO *ptrlista;
    NO *elem;
    inicializar(&ptrlista);

    do{
        Menu();
        printf("Escolha uma opcao valida: \n");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls");
        switch(escolha){
            case 1:
            inserir_fim(&ptrlista);
            break;

            case 2:
            remover_fim(&ptrlista);
            break;

            case 3:
            printf("Exibindo elementos na forma inversa: \n");
            ordem_inversa(&ptrlista);
            break;

            case 4:
            printf("Exibindo a soma dos elementos: \n");
            exibe_soma(&ptrlista);
            break;

            case 5:
            printf("Exibindo a lista: \n");
            imprime_lista(ptrlista);
            break;

            default:
            printf("Opcao invalida.\n");
            break;
        }
    }while(escolha != 6);

    return 0;
}