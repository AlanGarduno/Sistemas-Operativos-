#include<stdio.h>
#include<stdlib.h>
#include "matriz_cal.c"
#include<string.h>


int main(void){
    Matriz *mat1,*mat2,*res;
    char resultado[300];
    char buffer[6]={};
    int i,j;
    mat1 = creaMatriz(10);
    mat2 = creaMatriz(10);
    res = creaMatriz(10);
    mat1 = llenarMatriz();
    mat2 = llenarMatriz();
    res = restaMatriz(mat1,mat2);
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


	crearArchivo(resultado,"resta.txt");
    exit(0);
}