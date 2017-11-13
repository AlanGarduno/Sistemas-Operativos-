#include<stdio.h>
#include<stdlib.h>
#include "matriz_cal.c"
#include<string.h>


int main(void){
    printf("Transpuesta\n");
    Matriz *mat1,*mat2,*res,*res2;
    char resultado[300], resultado2[300];
    char buffer[6]={};
    int i,j;
    mat1 = creaMatriz(10);
    mat2 = creaMatriz(10);
    res = creaMatriz(10);
    res2 = creaMatriz(10);
    mat1 = llenarMatriz();
    mat2 = llenarMatriz();
    res = transpuesta(mat1);
    res2 = transpuesta(mat2);
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

    crearArchivo(resultado,"transpuesta1.txt");

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

    crearArchivo(resultado2,"transpuesta2.txt");
    exit(0);
}