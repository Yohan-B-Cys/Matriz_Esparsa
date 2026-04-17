#include <inttypes.h>
#include <stdio.h> 
#include <stdlib.h>

typedef struct nodo {
    int dado;             // A carga (o número que você quer guardar)
    struct nodo *prox;    // A corrente (ponteiro que aponta para um vagão do mesmo tipo)
} nodo ;


int iniciar_lista( nodo **N){

    *N = NULL ;
    printf("lista iniciada \n");
    return 1 ;
}

nodo * Cria_Nodo( )
{
nodo *p;
p = (nodo *) malloc(sizeof(nodo));
if(!p)
{
printf("Problema de alocação");
exit(0);
}
return p;
}

void insere_inicio(nodo **N, int dado){

    nodo * novo ;
    novo = Cria_Nodo();
    novo->dado= dado;
    novo->prox= *N;
    *N = novo ;
}

void insere_fim(nodo **N, int dado){

    nodo *novo ,*aux ;

    novo = Cria_Nodo();
    novo->dado = dado ;
    novo->prox =NULL ;
    if (*N == NULL)
      *N = novo ;
    else
    {
        aux = *N;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo ;
    }



}

void insere_meio(nodo **N,int dado){

    nodo *novo , *aux , *ant = NULL ;

    novo = Cria_Nodo();
    novo->dado= dado;
  
    

        aux = *N ;
        

        while (aux != NULL && aux->dado < dado){
            ant = aux ;
            aux = aux->prox ;
        }

        if (ant == NULL) {
            novo->prox = aux ;
            *N = novo ;
        
        } else {
            novo->prox = aux ;
            ant->prox = novo ;
        }

      
    
}

void remove_inicio(nodo **N){

    nodo *aux;
    aux = *N;

    if(*N==NULL){
    printf("LISTA VAZIA \n");
    return;
    }
    *N = aux->prox;
    free(aux);
    

}

void remove_fim(nodo **N){

    nodo *aux, *ant ;
    aux =*N;

    if(*N==NULL){
        printf("LISTA VAZIA");
        return;
    }

    if (aux->prox==NULL){
        free(aux);
        *N= NULL ;
        return ;
    } else {

        while (aux->prox!=NULL) {
            ant = aux ;
            aux = aux->prox ;
        
        }
        ant->prox = NULL ;
        free(aux);
    }



}

void remove_elemento (nodo **N, int dado){

    nodo   *aux, *ant = NULL ;
    

    aux = *N ;
   

    if(*N ==NULL){
        printf("LISTA VAZIA");
        return;
    }

    while(aux!=NULL && aux->dado !=dado){

        ant = aux ;
        aux = aux->prox;
    }

        if (aux == NULL) {
            printf("ELEMENTO NAO ENCONTRADO \n");
            return;
        
        }
        if (ant == NULL){
            *N= aux->prox ;
        } else {
            ant->prox = aux->prox ;
        }

        free(aux);
        printf("Elemento removido com sucesso \n");
        
        
    

}

void quantidade_lista (nodo **N){

    nodo *aux ;
    int contador = 0 ; 
    aux = *N;


    while (aux!=NULL) {
        contador ++ ;
        aux = aux->prox ;
    
    }

    printf("Sua lista tem %d elementos \n", contador);
    
}

void imprime_lista (nodo**N){

    nodo *aux ;
    aux = *N ;

   if(*N == NULL){
    printf("Lista vazia !");
    return;
   }

    while (aux != NULL) {
        printf("%d, " , aux->dado) ;
        aux = aux->prox ;
    
    }
}

void busca_elemento (nodo **N , int dado){

    nodo *aux ;
    int posicao = 1 , vezes_achado = 0 ;

    aux = *N ;

    if (*N== NULL){
        printf("Lista vazia !");
        return ;
    }

    while (aux!=NULL) {
        
       

       
        if (aux->dado == dado) {
            printf("Elemento %d encontrado na posição %d \n" , dado , posicao);
            vezes_achado ++ ;
            
        
        } 
         posicao ++;
         aux = aux ->prox ;

    
    }
     if (vezes_achado == 0) {
         printf("elemento não encontrado ! \n");
     } else {
        printf("--> O elemento apareceu um total de %d vez(es) na lista.\n", vezes_achado);
     }
    

    
}

void deleta_lista (nodo **N){

    nodo *aux , *ant ;

    aux = *N ; 

    if (*N==NULL){
        printf("Lista ja está vazia ! \n");
        return ;
    } else {

        while (aux!=NULL) {
            ant = aux ;
            aux = aux->prox ;
            free(ant);
        
        }

        
        *N = NULL ;
        printf("Lista deletada com sucesso ! \n");
    }
}





int main () {

    int opcao = -1;
    int valor; // Variável para ler os inputs do usuário
    nodo *lista = NULL;

    while (opcao != 0) {
        
         system("clear"); // Descomente isso se quiser que a tela limpe a cada rodada (no Linux)
        
        printf("\n--- Trabalho da Disciplina Matriz Esparça ---\n");
        printf("Selecione a opcao desejada:\n");
        printf(" 1- Iniciar Lista\n");
        printf(" 2- Inserir no inicio\n");
        printf(" 3- Inserir no Fim\n");
        printf(" 4- Inserir no meio (Ordenado)\n");
        printf(" 5- Remove do inicio\n");
        printf(" 6- Remove do fim\n");
        printf(" 7- Remover Elemento especifico\n");
        printf(" 8- Buscar Elemento especifico\n");
        printf(" 9- Imprime Elementos da lista\n");
        printf(" 10- Deleta a lista\n");
        printf(" 11- Quantidade de elementos\n");
        printf(" 0- Sair\n");
        printf("--> ");
        
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                 if (lista != NULL) {
                    deleta_lista(&lista);
                 
                 }
                iniciar_lista(&lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar(); 
                break;
                
            case 2:
                printf("Digite o valor para inserir no INICIO: ");
                scanf("%d", &valor);
                insere_inicio(&lista, valor);
                printf("Elemento inserido!\n");
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 3:
                printf("Digite o valor para inserir no FIM: ");
                scanf("%d", &valor);
                insere_fim(&lista, valor);
                printf("Elemento inserido!\n");
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 4:
                printf("Digite o valor para inserir no MEIO: ");
                scanf("%d", &valor);
                insere_meio(&lista, valor);
                printf("Elemento inserido!\n");
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 5:
                remove_inicio(&lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 6:
                remove_fim(&lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 7:
                printf("Digite o valor do elemento que deseja REMOVER: ");
                scanf("%d", &valor);
                remove_elemento(&lista, valor);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 8:
                printf("Digite o valor do elemento que deseja BUSCAR: ");
                scanf("%d", &valor);
                busca_elemento(&lista, valor);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 9:
                printf("--- Imprimindo Lista ---\n");
                imprime_lista(&lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 10:
                deleta_lista(&lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 11:
                quantidade_lista(&lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
                
            case 0:
                printf("\nSaindo do programa...\n");
                deleta_lista(&lista); // Regra de ouro: limpar a memória antes de fechar!
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;
        }
    }

    return 0;
}