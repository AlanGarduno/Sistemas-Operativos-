#include<stdio.h>
#include<stdlib.h>
#include "matriz_cal.c"
#include<string.h>

int main(void){
    printf("Inversa\n");
    Matriz *mat1,*mat2,*res,*res2;
    double det1,det2;
    char resultado[300],resultado2[300];
    char buffer[6]={};
    int i,j;
    mat1 = creaMatriz(10);
    mat2 = creaMatriz(10);
    res = creaMatriz(10);
    res2 = creaMatriz(10);
    mat1 = llenarMatriz();
    mat2 = llenarMatriz();
    det1 = Determinante(mat1,10);
    det2 = Determinante(mat1,10);
    if(det1 == 0){
        printf("La matriz 1 no es invertible\n");
    }
    else if(det2 == 0){
        printf("La matriz 2 no es invertible\n");
    }
    res = cofactores(mat1,10,det1);
    res2 = cofactores(mat2,10,det2);
    for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sprintf(buffer,"%.0lf\t",res->mat[i][j]);
			strcat(resultado,buffer);
			memset(buffer,0,6);
		}
		strcat(resultado,"\r\n");
	}

    crearArchivo(resultado,"inversa1.txt");
    for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sprintf(buffer,"%.0lf\t",res->mat[i][j]);
			strcat(resultado2,buffer);
			memset(buffer,0,6);
		}
		strcat(resultado2,"\r\n");
	}

    crearArchivo(resultado2,"inversa2.txt");
    exit(0);
}