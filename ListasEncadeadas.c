#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;
FILE *IN;

struct elemento{
  int info;
  Elemento* prox;
};

struct Elemento{
  int info;
  Elemento* prox;
};

Elemento* lista_insere(Elemento* lista, int val){
  Elemento* p;
  Elemento* q;
  p = lista;
  Elemento* novo = (Elemento*) malloc(sizeof(Elemento)); //Reserva um espaço para novo
  novo->info = val; //Atribui a novo, o valor passado
  if (lista == NULL){
    novo->prox = NULL; //Poe o ponteiro para o novo apontando para o elemento anterior da lista
    return novo;
  }
  if (p->info >= val){ //Menor ou igual ao primeiro valor da lista !! Trocar para <= ordena para descrescente
    novo->prox = p;
    return novo;
  }
  q = p;
  p = p->prox;
  if (p == NULL){ //Se string so tem um valor
    q->prox = novo;
    novo->prox = NULL;
    return lista;
  }
  while (p->info < val){ //Enquanto for maior que o valor pula pro proximo !!Trocar para > ordena em decrescente
    q = p;
    p = p->prox;
    if (p == NULL){
      q->prox = novo;
      novo->prox = NULL;
      return lista;
    }
  }
  q->prox = novo;
  novo->prox = p;
  return lista;
}

/*Elemento* lista_insere(Elemento* lista, int val){ //Antigo metodo de insercao
  Elemento* novo = (Elemento*) malloc(sizeof(Elemento)); //Reserva um espaço para novo
  novo->info = val; //Atribui a novo, o valor passado
  novo->prox = lista; //Põe o ponteiro para o novo apontando para o elemento anterior da lista
  return novo;
}*/

Elemento* lista_leituraarquivo (Elemento* lista){
  int i=0, U;
  IN = fopen("IN.txt","r");
  while (!feof(IN))
  {
    fscanf (IN, "%i\n", &U);
    lista = lista_insere(lista, U);
    i++;
    printf ("Inserido - %i\n", U);
  }
  printf ("Elementos adicionados: %i\n", i);
  fclose(IN);
  return lista;
}

Elemento* lista_cria(){ //Retorna Null, criação de listas
  return NULL;
}

void lista_imprime (Elemento* lista){ //Varre e imprime
  Elemento* p;
  if (lista == NULL){
    printf("Lista Vazia\n");
  }
  for (p = lista; p != NULL; p = p->prox){
    printf("Valor = %i\n",p->info);
  }
}

void lista_imprimearquivo(Elemento* lista){
  Elemento* p;
  IN = fopen("OUT.txt","w");
  if (lista == NULL){
    fprintf(IN, "Lista Vazia\n");
  }
  for (p = lista; p != NULL; p = p->prox){
    fprintf(IN, "%i\n", p->info);
  }
}

Elemento* lista_remove (Elemento* lista, int V){ //Varre e remove
  Elemento* p;
  Elemento* q;
  if (lista == NULL){
    printf("Lista vazia\n");
    return 0;
  }
  if (lista->info == V) {
    q = lista;
    lista = q->prox;
    free(q);
    return lista;
  }
  for (p=lista; p!=NULL; p=p->prox){
    q = p->prox;
    if (q->info == V) {
      p->prox = q->prox;
      free(q);
      return lista;
    }
    if (q->prox == NULL){
      printf("Elemento nao encontrado\n");
      return lista;
    }
  }
}

Elemento* lista_apagar (Elemento* lista){
  Elemento* p;
  Elemento* q;
  int U = 0;
  if (lista == NULL){
    return NULL;
  }
  p = lista;
  while(U == 0){
    q = p->prox;
    free(p);
    p = q;
    if (p == NULL)
      U = 1;
  }
  return NULL;
}

int lista_procura (Elemento* lista, int V){
  Elemento* p;
  int A=1;
  for (p=lista; p!=NULL; p=p->prox){
    if (p->info == V) {
      printf("Elemento - %i\n", V);
      A=0;
    }
  }
  return A;
}

int main (){ //Listas simplesmente encadeadas
  Elemento* lista;
  int O, V=0, E, A=0;
  lista=lista_cria();
  printf("-----------------------------------\n");
  printf("   LISTAS SIMPLESMENTE ENCADEADAS\n");
  printf("-----------------------------------\n");
  while(A==0){
    printf("-----------------------------------\n");
    printf("Selecione alguma das opcoes abaixo:\n");
    printf("-----------------------------------\n");
    printf(" 0 - Inserir Elemento\n");
    printf(" 1 - Remover Elemento\n");
    printf(" 2 - Procurar Elemento\n");
    printf(" 3 - Imprimir Lista\n");
    printf(" 4 - Zerar Lista\n");
    printf(" 5 - Leitura de Arquivo\n");
    printf(" 6 - Escrita em Arquivo\n");
    printf(" 7 - Encerrar Programa\n");
    printf("-----------------------------------\n");
    scanf("%i", &O);
    printf("-----------------------------------\n");
    switch (O) {
      case 0:
        printf("Insira o elemento que deseja inserir na lista:\n");
        scanf("%i", &V);
        lista=lista_insere(lista, V);
        break;
      case 1:
        printf("Insira o elemento que deseja remover na lista:\n");
        scanf("%i", &V);
        lista=lista_remove(lista, V);
        break;
      case 2:
        printf("Insira o elemento que deseja procurar na lista:\n");
        scanf("%i", &V);
        E=lista_procura(lista, V);
        if (E==1) {
          printf("Elemento nao encontrado\n");
        }
        break;
      case 3:
        lista_imprime(lista);
        break;
      case 4:
        lista = lista_apagar(lista);
        break;
      case 5:
        lista = lista_leituraarquivo(lista);
        break;
      case 6:
        lista_imprimearquivo(lista);
        break;
      case 7:
        A=1;
        lista = lista_apagar(lista);
        break;
      default:
        printf("Opcao Invalida\n");
    }
  }
  return 0;
}
