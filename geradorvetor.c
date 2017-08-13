#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int Q, V=0, E, A=0, I, F, O, N, H;
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
  Elemento* novo = (Elemento*) malloc(sizeof(Elemento)); //Reserva um espaco para novo
  novo->info = val; //Atribui a novo, o valor passado
  novo->prox = lista; //Poe o ponteiro para o novo apontando para o elemento anterior da lista
  return novo;
}

Elemento* lista_cria(){ //Retorna Null, criacao de listas
  return NULL;
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

Elemento* GeraRand(Elemento* lista){
  int i;
  for (i = 0; i<Q; i++){
    N = I+rand()%F;
    lista = lista_insere(lista, N);
  }
  return lista;
}

int main (){
  Elemento* lista;
  Elemento* p;
  lista=lista_cria();
  srand (time(NULL));
  IN = fopen("OUT.txt","w");
  printf("=========================================\n");
  printf(" Gerador de inteiros aleatorios em vetor\n");
  printf("=========================================\n");
    printf("Indique quantos inteiros deseja gerar:\n");
    scanf("%i", &Q);
    printf("Indique a faixa entre a qual deseja que esses numeros estejam:\nInicio em: ");
    scanf("%i", &I);
    printf("Fim em: ");
    scanf("%i", &F);
    printf("Indique o separador que deseja usar:\n");
    printf("0 - Quebra de linha 1 - Espaco\n");
    printf("2 - Virgula         3 - Ponto e virgula\n");
    printf("4 - Tabulacao       5 - Ponto\n");
    scanf("%i", &O);
    switch (O) {
    case 0:
      lista = GeraRand(lista);
      if (lista == NULL){
        fprintf(IN, "Lista Vazia\n");
      }
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i\n", p->info);
      }
      break;
    case 1:
      lista = GeraRand(lista);
      if (lista == NULL){
        fprintf(IN, "Lista Vazia\n");
      }
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i ", p->info);
      }
      break;
    case 2:
      lista = GeraRand(lista);
      if (lista == NULL){
        fprintf(IN, "Lista Vazia\n");
      }
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i,", p->info);
      }
      break;
    case 3:
      lista = GeraRand(lista);
      if (lista == NULL){
        fprintf(IN, "Lista Vazia\n");
      }
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i;", p->info);
      }
      break;
    case 4:
      lista = GeraRand(lista);
      if (lista == NULL){
        fprintf(IN, "Lista Vazia\n");
      }
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i\t", p->info);
      }
      break;
    case 5:
      lista = GeraRand(lista);
      if (lista == NULL){
        fprintf(IN, "Lista Vazia\n");
      }
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i.", p->info);
      }
      break;
    default:
      printf("Opcao Invalida\n");
  }
  lista = lista_apagar(lista);
  return 0;
}
