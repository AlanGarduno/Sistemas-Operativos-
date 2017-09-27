#include "pila.h"

int push(struct pila *p, int c){
	struct nodo *n=(struct nodo *)malloc(sizeof(struct nodo));
	struct nodo *aux=NULL;
	if(p==NULL){
		return -1;
	}
	n->dato=c;
	if(p->primero==NULL){
		n->siguiente=NULL;
		p->primero=n;
		return 1;
	}else{
		aux=p->primero;
		n->siguiente=aux;
		p->primero=n;
		return 1;

	}
}

int new(struct pila **p){
	(*p)=(struct pila*)malloc(sizeof(struct pila));
	(*p)->primero=NULL;
	return 1;
}

int top(struct pila *p){
	if(p==NULL){
		return -1;
	}
	if(p->primero==NULL){
		printf("Pila vacia\n");
	}else{
		return p->primero->dato;
	}

}

int pop(struct pila *p){
	struct nodo *aux=NULL;
	if(p==NULL){
		return -1;
	}
	if(p->primero==NULL){
		return 1;
	}else{
		aux=p->primero;
		p->primero=aux->siguiente;
		free(aux);
	}
}

int mostrar(struct pila *p){
	struct nodo *aux=NULL;
	if(p==NULL){
		return -1;
	}
	if(p->primero==NULL){
		printf("Pila vacia\n");
		return 1;
	}else{
		aux=p->primero;
		do{
			printf("%d\n",aux->dato);
			aux=aux->siguiente;
		}while(aux!=NULL);
	}

}

int pushC(struct pilaC *p, char c){
	struct nodoC *n=(struct nodoC *)malloc(sizeof(struct nodoC));
	struct nodoC *aux=NULL;
	if(p==NULL){
		return -1;
	}
	n->dato=c;
	if(p->primero==NULL){
		n->siguiente=NULL;
		p->primero=n;
		return 1;
	}else{
		aux=p->primero;
		n->siguiente=aux;
		p->primero=n;
		return 1;
	}
}

int newC(struct pilaC **p){
	(*p)=(struct pilaC*)malloc(sizeof(struct pilaC)); 
	(*p)->primero=NULL;
	return 1;
}

char topC(struct pilaC *p){
	if(p==NULL){
	return -1;
	}
	if(p->primero==NULL){
		printf("Pila vacia\n");
		return 0;
	}else{
		return p->primero->dato;
		return 1;
	}
}

int popC(struct pilaC *p){
	struct nodoC *aux=NULL;
	if(p==NULL){
		return -1;
	}
	if(p->primero==NULL){
		return 1;
	}else{
		aux=p->primero;
		p->primero=aux->siguiente;
		free(aux);
	}
}

int mostrarC(struct pilaC *p){
	struct nodoC *aux=NULL;
	if(p==NULL){
		return -1;
	}
	if(p->primero==NULL){
		printf("Pila vacia\n");
		return 1;
	}else{
		aux=p->primero;
		do{
			printf("%c\n",aux->dato);
			aux=aux->siguiente;
		}while(aux!=NULL);
	}
}

int isemptyC(struct pilaC *p){
	if(p==NULL){
		return -1;
	}
	if(p->primero==NULL){
		return 1;
	}else{
		return 0;
	}
}
