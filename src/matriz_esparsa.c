#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <stdlib.h>
// Define função para limpeza conforme sistema operacional utilizado
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Estrutura que representa uma Lista Encadeada (uma Matriz Esparsa e seus elementos)
typedef struct Nodo {
float numero;
int lin;
int col;
struct Nodo * prox;
}
MatrizEsparsa;

typedef struct ListaMatrizes {
int id; // Ex: 1, 2, 3
int quantLin;
int quantCol;
MatrizEsparsa * n; // Ponteiro para o início da lista de elementos
struct ListaMatrizes * prox;
} ListaMatrizes;

int contador_id = 0 ;
// Aloca memória para cada nodo criado para uma Lista Encadeada
MatrizEsparsa * criar_nodo();

// Inicializa Lista Encadeada da Matriz Esparsa
void inicializar_lista(MatrizEsparsa ** matriz_esparsa);

// Insere na Lista Encadeada um nodo alocado
void inserir_nodo(MatrizEsparsa ** matriz_esparsa, float numero, int lin, int col);

// Insere um numero na matriz lendo do teclado valida e depois manda no inserir nodo -Y
void inserirMatriz(ListaMatrizes * matriz);

// Pesquisa simples que imprime se achou um numero na matriz quais posições e quantas vezes -Y
void busca_elemento(MatrizEsparsa * N, float dado);

// pesquisa para impressao retorna o numero que depois utiliza na impressao ele recebe a lista de elementos n e as cordenadas se ele encotrar um no onde a linha e coluna coiciden ele retorna o numero desse n senão retorna 0
float buscaParaImpressao (MatrizEsparsa *n, int linha , int coluna);

// função de impressao usa dois for aninhados com a quantidades de linhas e colunas i e j e para cada posição chama a buscaParaImpressao que vai retornar um numero ou zero - Y
void imprimirMatriz(ListaMatrizes *matriz);

//A função de criação de matriz aloca um cabeçalho dinâmico com ID e dimensões, inicializa a lista de dados como vazia e o vincula ao início de um  banco de matrizes. -Y
void criarMatriz( ListaMatrizes ** banco);

//função similar a impressao so que lista as matrizes feitas no sistema tmb é chamada na função trocarMatriz para o user saber qual matriz ele quer trocar por ser boolean usamos para controlar o fluxo da case 9 deletar matriz -Y
bool listarMatrizes(ListaMatrizes *banco);

//Função do proprio tipo da struct permite a troca de matrizes um while que percorre o banco se achar o id correspondente devolve essa matriz com esse id senão printa um erro e returna NULL -Y
ListaMatrizes* trocarMatriz(ListaMatrizes *banco , int id_desejado);

//função que limpa todos os elementos diferentes de zero chamada antes de deletar matriz
void limparMatriz (MatrizEsparsa *n);

//função de deletar matriz deleta a matriz atual
void deletaMatriz(ListaMatrizes **banco , ListaMatrizes **atual );

int main() {
// Cria um ponteiro local que irá apontar para o início da Lista
MatrizEsparsa *matriz_esparsa;
int opcao = -1;
int numero = 0;
float busca = 0 ;
int id_desejado = 0 ;
bool inicializou = false;
int status = 0;
ListaMatrizes *matrizAtual = NULL ;
ListaMatrizes *lista_matrizes = NULL;
ListaMatrizes *trocar_Matriz = NULL ;

while (opcao != 0) {

printf("\n--- MENU: MATRIZES ESPARSAS ---\n");
if(matrizAtual==NULL)
printf("Matriz Selecionada : nenhuma \n"); 
else 
printf("Matriz Selecionada: Matriz(%d) \n" , matrizAtual->id);

 printf("1 - Criar/Preencher Matriz (Filtra Zeros)\n");
 printf("2 - Buscar Elemento Específico\n");
 printf("3 - Imprimir Matriz Inteira (com zeros)\n");
 printf("4 - Somar Matrizes (A + B)\n");
 printf("5 - Subtrair Matrizes (A - B)\n");
 printf("6 - Multiplicar Matrizes (A * B)\n");
 printf("7 - Gerar Matriz Transposta\n");
 printf("8 - Imprimir Diagonal Principal\n");
 printf("9 - Deletar Matriz atual (Liberar Memória)\n"); 
 printf("10 - Listar Matrizes \n");
 printf("11 - Trocar matriz atual \n");
 printf("0 - Sair do Programa\n");
 printf("--> Opção: ");
 scanf(" %d", & opcao);
int c;
while ((c = getchar()) != '\n' && c != EOF) {} // Limpa o buffer do teclado
system(CLEAR); // Limpa a tela do terminal

// Garante que Lista esteja inicializada para realizar operações sobre ela
// Permite que opções fora do intervalo do menu passem para encerramento
if (!inicializou && opcao != 1 && (opcao > 0 && opcao <= 10)) {
printf("\nErro: Nenhuma matriz! Crie uma Matriz e tente novamente.\n");
continue;
}

switch (opcao) {
case 1:
criarMatriz(&lista_matrizes);
matrizAtual = lista_matrizes ;
printf("\nLista inicializada com sucesso!\n");
inserirMatriz(matrizAtual);
inicializou = true ;

break;

case 2:  
    printf("Qual valor quer buscar na Matriz %d \n" , matrizAtual->id);
    scanf(" %f" , &busca);
    busca_elemento(matrizAtual->n, busca);

break;

case 3:
    imprimirMatriz(matrizAtual);

break;

case 4:

break;

case 5:

break;

case 6:

break;

case 7:

break;

case 8:

break;

case 9:
   deletaMatriz(&lista_matrizes, &matrizAtual);
   
   if (!listarMatrizes(lista_matrizes)) {
    printf("Como não há Matrizes restantes será criado uma nova \n");
    criarMatriz(&lista_matrizes);
    matrizAtual = lista_matrizes ;
    inserirMatriz(matrizAtual);
   } else {
        while (matrizAtual==NULL) {
        
        
        printf("Com base na lista de id de Matrizes acima digite o id da matriz para estabelecer a matriz atual \n") ;
        scanf(" %d", &id_desejado);
        trocar_Matriz = trocarMatriz(lista_matrizes,id_desejado);

        if (trocar_Matriz !=NULL) {
        matrizAtual = trocar_Matriz ;
        printf("A troca foi um sucesso Matriz %d agora é a Matriz atual \n", matrizAtual->id);
        } else {
        printf("Falha na troca de Matrizes \n");
        }
        }
    }

break;

case 10:
    listarMatrizes(lista_matrizes) ;

break;

case 11:
   listarMatrizes(lista_matrizes);
   printf("Com base na lista de id de Matrizes acima digite o id da matriz que queira trocar \n") ;
   scanf(" %d", &id_desejado);

   trocar_Matriz = trocarMatriz(lista_matrizes,id_desejado);

   if (trocar_Matriz !=NULL) {
        matrizAtual = trocar_Matriz ;
        printf("A troca foi um sucesso Matriz %d agora é a Matriz atual \n", matrizAtual->id);
   } else {
        printf("Falha na troca de Matrizes \n");
   }


break;

default:
printf("\nOpcao invalida! Tente novamente.\n");
printf("\nPressione Enter para voltar ao menu...");
getchar();
getchar();
break;
}
}

return 0;
}

// Retorna a criação do ponteiro de um nodo com memória alocada
MatrizEsparsa * criar_nodo() {
// Cria o ponteiro para o novo nodo
MatrizEsparsa * nova_matriz;

// malloc(): Aloca a quantidade de bytes de memória para conter um novo tipo `Nodo`
// O ponteiro armazena o endereço de memória alocada que foi convertida através de casting
nova_matriz = (MatrizEsparsa * ) malloc(sizeof(MatrizEsparsa));

// Sai do programa caso memória não consiga mais ser alocada
// Um endereço vazio tem como valor padrão NULL
if (nova_matriz == NULL) {
printf("Problema de alocação");
exit(1); // Informa que houve um erro de alocação
}

// Inicializa os campos do próximo Nodo. É uma boa prática
nova_matriz -> numero = 0;
nova_matriz -> lin = 0;
nova_matriz -> col = 0;
nova_matriz -> prox = NULL;

return nova_matriz;
}

// Define o ponteiro apontando para uma Lista ainda não inicializada (sem referência)
void inicializar_lista(MatrizEsparsa ** matriz_esparsa) {
* matriz_esparsa = NULL;
}

void inserir_nodo(MatrizEsparsa ** matriz_esparsa, float numero, int lin, int col) {
MatrizEsparsa * nova_matriz;

nova_matriz = criar_nodo();
nova_matriz -> numero = numero;

// O nó desse novo elemento será o início da lista. Portanto, o próximo nó será
// o elemento que estava anteriormente na primeira posição e agora ficará na segunda
// Aponta para o nó do primeiro lugar anterior
nova_matriz -> prox = * matriz_esparsa;
// Define o nó criado como o endereço de início da lista
* matriz_esparsa = nova_matriz;
nova_matriz -> lin = lin;
nova_matriz -> col = col;
}

void inserirMatriz(ListaMatrizes * matriz) {
float valor = -1;
int posiX = 0, posiY = 0 ;

while(valor != 0){
printf("\n--- Inserindo dados na Matriz %d ---\n", matriz->id); 
printf("Digite o valor do elemento para adicionalo ou 0 para sair do preenchimento \n");
scanf("%f", & valor);

if (valor == 0)
{
printf("Saindo");
return ;
}


 int Xvalido = 0 , Yvalido = 0;

while(Xvalido != 1) { 
            printf("Digite o valor da posição X(Linha) do elemento note que tem que estar em um intervalo de 1 a %d: ", matriz->quantLin );
            scanf("%d", &posiX);
            if(posiX < 0 || posiX > matriz->quantLin) printf("Posição Invalida!\n");
            else {
                Xvalido = 1;
                posiX -- ;
            }
            
        }
while(Yvalido != 1) { 
            printf(" Digite o valor da posição Y (Coluna) do elemento note que tem que estar em um intervalo de 1 a %d : ", matriz->quantCol );
            scanf("%d", &posiY);
            if(posiY < 0 || posiY > matriz->quantCol) printf(" Posição Invalida!\n");
            else {
                Yvalido = 1;
                posiY -- ;
            } 
        }        

inserir_nodo(&(matriz->n), valor, posiX, posiY);
printf("Elemento inserido com sucesso ! \n");
} 
}

void busca_elemento(MatrizEsparsa * N, float dado) {

MatrizEsparsa * aux;
int posiX = 0, posiY = 0, vezes_achado = 0;

aux = N;

if (  N == NULL) {
printf("Matriz vazia !");
return;
}

while (aux != NULL) {

if (aux -> numero == dado) {
posiX = aux -> lin;
posiY = aux -> col;
printf("Elemento %.2f encontrado na posição %d x %d \n", dado, posiX + 1, posiY + 1);
vezes_achado++;

}

aux = aux -> prox;

}
if (vezes_achado == 0) {
printf("elemento não encontrado ! \n");
} else {
printf("--> O elemento apareceu um total de %d vez(es) na lista.\n", vezes_achado);
}
}

float buscaParaImpressao (MatrizEsparsa *n, int linha , int coluna){
    MatrizEsparsa *aux = n;
    while (aux!=NULL) {
        if (aux->lin == linha && aux->col == coluna) {
            return aux->numero ;
        }
        aux= aux->prox ;
    }
 
    return 0 ;
}

void imprimirMatriz(ListaMatrizes *matriz) {
    if (matriz == NULL) {
        printf("Erro: Nenhuma matriz selecionada!\n");
        return;
    }

    printf("\n--- Imprimindo Matriz ID %d (%d x %d) ---\n\n", matriz->id, matriz->quantLin, matriz->quantCol);

    // 1. Cabeçalho das Colunas
    // Começamos com um \t para compensar o índice da linha na lateral
    printf("\t"); 
    for (int j = 1; j <= matriz->quantCol; j++) {
        printf("[%d]\t", j); // Mostra de 1 a N
    }
    printf("\n");

    // 2. Linhas da Matriz
    for (int i = 0; i < matriz->quantLin; i++) {
        // Imprime o índice da linha (1 a N) seguido de um TAB para alinhar
        printf("[%d]\t", i + 1); 
        
        for (int j = 0; j < matriz->quantCol; j++) {
            float valor = buscaParaImpressao(matriz->n, i, j);
            if (valor == 0) 
                printf("0\t") ;
            else 
              printf("%.2f\t", valor);
        }
        printf("\n");
    }
    printf("\n");
}

void criarMatriz( ListaMatrizes ** banco){
ListaMatrizes *nova = (ListaMatrizes*) malloc(sizeof(ListaMatrizes));
if(nova == NULL){
printf("Erro de memoria \n");
return ;
}
nova->id = ++contador_id  ;

printf("--- Criando Matriz %d --- \n" , nova->id);
printf("Digite o numero de linhas (X) \n");
scanf(" %d" , &nova->quantLin);
printf("Digite o numero de colunas (Y) \n");
scanf(" %d" , &nova->quantCol);

nova->n = NULL ;

nova->prox = *banco ;
*banco = nova ;

printf("Matriz %d (%dx%d) adicionada " , nova->id,nova->quantLin,nova->quantCol);
}

bool listarMatrizes(ListaMatrizes *banco){
    ListaMatrizes *aux = banco ;

    if (aux == NULL) {
        printf("\n[!] O banco de matrizes esta vazio.\n");
        return false;
    }

    printf("\n--- MATRIZES DISPONIVEIS NO BANCO ---\n");
    printf("ID\tTAMANHO\n");
    printf("------------------------------------\n");

    while (aux !=NULL) {
        printf("%d\t %d x %d\n",aux->id,aux->quantLin,aux->quantCol);
        aux=aux->prox;
    }

    printf("------------------------------------\n");

    return true;
}

ListaMatrizes* trocarMatriz(ListaMatrizes *banco , int id_desejado){
    ListaMatrizes *aux = banco ;

    while (aux !=NULL) {
        if (aux->id == id_desejado) {
            return aux ;
        }
        aux = aux->prox;
    }
    printf("Id não encontrado ou invalido ! \n");
    return NULL ;
} 

void limparMatriz (MatrizEsparsa *n){
    MatrizEsparsa *aux ;
    while (n!=NULL) {
        aux = n ;
        n= n->prox;
        free(aux);
    }
}

void deletaMatriz(ListaMatrizes **banco , ListaMatrizes **atual ){
    if (*atual == NULL) {
        printf("Não há matriz para deletar \n");
        return;
    }
    ListaMatrizes *aux_banco = *banco;
    ListaMatrizes *ant = NULL;

    while (aux_banco!=NULL && aux_banco!=*atual) {
        ant = aux_banco;
        aux_banco = aux_banco->prox;
    }

    if (aux_banco !=NULL) {
        if (ant == NULL) {
            *banco = aux_banco->prox ;
        }
    } else {
        ant->prox = aux_banco->prox;
    }

    limparMatriz(aux_banco->n);
    free(aux_banco);

    *atual = NULL ;
    printf("Matriz atual deletada com sucesso!\n");
}

