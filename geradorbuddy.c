#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Q, V=0, E, A=0, P, O, N, H, DES, TOT = 0;
int SO[51] = {11, 10, 9, 8, 7, 6, 2, 0, 1, 4, 3, 0, 4, 6, 2, 5, 1, 3, 0, 1, 2, 4, 5, 4, 1, 2, 3, 4, 1, 2, 0, 1, 0, 1, 0, 2, 1, 2, 3, 1, 3, 7, 3, 4, 6, 5, 5, 4, 2, 1};
typedef struct elemento Elemento;
FILE *IN;

struct elemento{
  int qtde;
  int PID;
  int solic;
  int des;
  Elemento* prox;
};

struct Elemento{
  int info;
  Elemento* prox;
};

Elemento* lista_insere(Elemento* f, int qt, int pid, int so){ //Insere na "ultima" posicao
  Elemento* p;
  p = f;
  Elemento* novo = (Elemento*) malloc(sizeof(Elemento)); //Reserva um espaco para novo
  novo->qtde = qt; //Atribui a novo, o valor passado
  novo->prox = NULL; //Poe o ponteiro para o novo apontando para o elemento anterior da lista
  novo->PID = pid;
  novo->solic = so;
  novo->des = 0;
  if (f == NULL){
    f = novo;
  } else {
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  return f;
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
  int i, q, s, al, j, pid = 0, l;
  Elemento* p;
  p = lista;
  for (i = 0; i<Q; i++){
    printf("For, passo: %i\n", i);
    l = 0+rand()%51;
    q = pow(2.0,(double)(SO[l] + 12));
    if (i > 3){
      s = 0+rand()%2;
    }
    else {
      s = 1;
    }
    if (s > 1){
      s = 1;
    }
    if (TOT > 7000000){
      s = 0;
    }
    //printf("Qtde %i\nSol %i\nNivel %i\n", q, s, (SO[l] + 12));
    if (s == 1){
      lista = lista_insere(lista, q, pid, s);
      pid++;
      TOT = TOT + q;
    }
    else {
      al = 0+rand()%i;
      //printf("A andar %i passos na lista\n", al);
      for (j = 0; j < al; j++) {
        //printf("valor na casa %i = %i\n", i, p->PID);
        p = p->prox;
      }
      if (p->des == 0 && p->solic == 1){
        lista = lista_insere(lista, p->qtde, p->PID, s);
        p->des = 1;
        TOT = TOT - p->qtde;
      }
      else {
        i--;
      }
    }
    p = lista;
  }
  return lista;
}

int main (){
  Elemento* lista;
  Elemento* p;
  int i;
  lista=lista_cria();
  srand (time(NULL));
  IN = fopen("OUT.txt","w");
  printf("=========================================\n");
  printf("Gerador de inteiros aleatorios para buddy\n");
  printf("=========================================\n");
    printf("Indique quantas requisicoes deseja gerar:\n");
    scanf("%i", &Q);
    lista = GeraRand(lista);
    if (lista == NULL){
      printf("0");
    } else {
      for (p = lista; p != NULL; p = p->prox){
        fprintf(IN, "%i %i %i\n", p->solic, p->PID, p->qtde);
      }
    }
  lista = lista_apagar(lista);
  return 0;
}
