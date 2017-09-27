#include <stdio.h>
#include "pila.h"

int evaluar(char[]);

int posfijo(char[],char[]);

int aEntero(char[]);

int aCaracter(int);

int vaciarN(char[],struct pilaC*,int*);

int main(){
    char c[100],p[100];
    int resultado=0;
    printf("Introduce una expresión matematica a evaluar\n");
    scanf("%s",c);
    posfijo(c,p);
    resultado=evaluar(p);
    printf("Resultado de la expresion: %d\n",resultado ); return 0;
}

int posfijo(char c[],char p[]){
    int r=0;
    int i=0,j=0;
    struct pilaC *operador=NULL;
    struct pilaC *parentesis=NULL;
    newC(&operador);
    newC(&parentesis);
    while(c[i]!='\0'){
        if(c[i]=='('){
        pushC(parentesis,c[i]);
    }else{
        if(c[i]>='0' && c[i]<='9'){
        p[j]=c[i];
        j++;
    }else{
        if(c[i]=='+' || c[i]=='-' || c[i]=='/' || c[i]=='*'){
             p[j]=' ';
        j++;
    pushC(operador,c[i]);
        }
    else{
        if(c[i]==')'){
            p[j]=' ';
            j++
            p[j]=topC(operador);
            j++;
            popC(parentesis);
            popC(operador);
            }
        }   
    }
}
    i++;
}
    while(!isemptyC(operador)){
    p[j]=' ';
    j++;
    p[j]=topC(operador);
    j++;
    popC(operador);

    }
    if(isemptyC(parentesis)){
        p[j]='\0';

    }else{
        printf("Error\n");
        p[j]='\0';

}

    return r;
}

int evaluar(char p[]){

    int i=0,j=0;

    int numero=0;

    char aux[10];

    struct pila *operacion=NULL;

    new(&operacion);

    while(p[i]!='\0'){

        if(p[i]>='0' && p[i]<='9'){

        aux[j]=p[i];

        j++;

        }else{

            if(p[i]=='+' || p[i]=='-' || p[i]=='*' || p[i]=='/'){ 
                numero=top(operacion);
                pop(operacion);
                if(p[i]=='+'){
                numero=numero+top(operacion);
                pop(operacion);
                push(operacion,numero);

            }else{
                if(p[i]=='-'){
                numero=top(operacion)-numero;
                pop(operacion);
                push(operacion,numero);
            }else{
                if(p[i]=='*'){
                    numero*=top(operacion);
                    pop(operacion);
                    push(operacion,numero);
                }else{
                    if(p[i]=='/'){
                    numero=top(operacion)/numero;
                    pop(operacion);
                    push(operacion,numero);

                }

            }

        }   

    }

}else{

        if(p[i]==' '){
        aux[j]='\0';
        if(j!=0){
        push(operacion,aEntero(aux));

        }

    j=0;

                }

            }

        }

    i++;

    }

    return top(operacion);

}

int aEntero(char entero[]){
    int i=0,aux=0,res=0;
    while(entero[i]!='\0'){
    aux=entero[i]-'0';
    res=(res*10)+aux;
    i++;
    }   
    return res;

}
