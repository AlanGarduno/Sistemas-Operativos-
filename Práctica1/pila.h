#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>

struct pila{
	struct nodo *primero;
};

struct nodo{
	int dato;
	struct nodo *siguiente;
};

struct pilaC{
	struct nodoC *primero;
};

struct nodoC{
	char dato;
	struct nodoC *siguiente;
};

int push(struct pila*,int);

int top(struct pila*);

int pop(struct pila*);

int mostrar(struct pila*);

int new(struct pila**);

int pushC(struct pilaC*,char);

char topC(struct pilaC*);

int popC(struct pilaC*);

int mostrarC(struct pilaC*);

int newC(struct pilaC**);

int isemptyC(struct pilaC *);

#endif
