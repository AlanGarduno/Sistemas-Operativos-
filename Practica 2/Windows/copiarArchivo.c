#include<stdio.h>
#include<stdio.h>
#include<windows.h>
int main(){
    char originen [] = "";
    char destino [] = "";
    char *mostrarArchivo = (char*)malloc(sizeof(char));
    int op, ar;
    printf("1.Mostrar Arcivo\n2.Copiar Archvios\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            printf("Mostrar Archivo\nIngresa el nombre del archivo a mostrar:")
            scanf("%s",mostrarArchivo);
            
        break;
        case 2:
            printf("Cuantos archvivos quieres copiar:\n");
            scanf("%d",&ar);
        break;
        default:
            printf("Opcion no valida\n");
            return 1;
    }

    return 0;
}