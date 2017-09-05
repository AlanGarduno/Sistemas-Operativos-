#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct Nodo{
    char dato;
    struct Nodo* sig;
    
}Nodo;
typedef struct Pila{
    Nodo *tope;
    int largo;
}Pila;
Nodo* crear_nodo(char c);
void destruir_nodo(Nodo*nodo);
Pila* crear_pila();
void destruir_pila(Pila*pila);
void push(Pila*pila,char c);
void pop(Pila*p);
char tope(Pila*p);
int esta_vacia(Pila*p);
void evaluar(Pila* miPila,char*s);
void vaciar_pila(Pila*miPila);
void inserta(Pila *miPila, char*s);
void balance(Pila *miPila,char*s);
int pE=0,pS=0,lE=0,lS=0,cE=0,cS=0;
int main(){
    Pila* miPila = crear_pila();
    int t, a0; 
    scanf("%d",&t);
    for(a0 = 0; a0 < t; a0++){
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        evaluar(miPila,s);
    }
    return 0;
}
Nodo* crear_nodo(char c){
    Nodo*aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = c;
    aux->sig = NULL;
    return aux;
    
}
void destruir_nodo(Nodo*nodo){
    nodo->sig = NULL;
    free(nodo);
}
Pila* crear_pila(){
    Pila* aux=(Pila*)malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->largo = 0;
    return aux;
}
void destruir_pila(Pila*pila){
    while(!esta_vacia(pila)){
        pop(pila);
    }
    free(pila);
}
void push(Pila*pila,char c){
    Nodo* aux = crear_nodo(c);
    aux->sig = pila->tope;
    pila->tope = aux;
    pila->largo++;
}
void pop(Pila*p){
    if(p->largo > 0)
    {
    Nodo* eliminar = p->tope;
    p->tope = p->tope->sig;
    destruir_nodo(eliminar);
    p->largo--;
    }
    else
    {
        return;
    }
}
char tope(Pila*p){
    return p->tope->dato;
}
int esta_vacia(Pila*p){
     if(p->largo == 0)
         return 1;
    else
        return 0;
}

void evaluar(Pila*miPila,char*s)
{
    inserta(miPila,s);
    balance(miPila,s);
        if(pE == pS && cE == cS && lE == lS){
                printf("YES\n");
            }
            else{
               printf("NO\n");
               vaciar_pila(miPila);
            }
}

void vaciar_pila(Pila*pila)
{
    while(!esta_vacia(pila))
    {
        pop(pila);
    }

}

void inserta(Pila *miPila, char*s)
{
    int j=0;
    pE=0,pS=0,lE=0,lS=0,cE=0,cS=0;
    while(s[j] != '\0'){
            if(s[j] == ')'){
                j++;
                pS++;
            }else if(s[j] == ']'){
                j++;
                cS++;
            }else if(s[j] == '}'){
                j++;
                lS++;
            }
            else if(s[j] == '('){ 
                push(miPila,s[j]);
                j++;
                pE++;
            }else if(s[j] == '['){
                push(miPila,s[j]);
                j++;
                cE++;
            }else if(s[j] == '{'){
                push(miPila,s[j]);
                j++;
                lE++;
            }
        }
}

void balance(Pila *miPila,char*s)
{
    int i = 0;
        while(s[i] != '\0'){
            if(tope(miPila) == '(' && s[i] == ')'){
                pop(miPila);
                i++;
            }else if(tope(miPila) == '[' && s[i] == ']'){
                pop(miPila);
                i++;
            }else if(tope(miPila) == '{' && s[i] == '}'){
                pop(miPila);
                i++;
            }
            else
                i++;
        }
}