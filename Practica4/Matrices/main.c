#include<stdlib.h>
#include<stdio.h>
#include "matriz_cal.c"

int main(){
    Matriz* mat1,*mat2;
    Matriz* resSuma,*resResta,*resMulti,*resTran1,*resTran2, *resIn1, *resIn2;
    double det1, det2;
    mat1 = creaMatriz(10);
    mat2 = creaMatriz(10);
    resSuma = creaMatriz(10);
    resResta = creaMatriz(10);
    resMulti = creaMatriz(10);
    resTran1 = creaMatriz(10);
    resTran2 = creaMatriz(10);
    resIn1 = creaMatriz(10);
    resIn2 = creaMatriz(10);
    mat1 = llenarMatriz();
    mat2 = llenarMatriz();
    printf("Matriz 1\n");
    imprimeMatriz(mat1);
    printf("Matriz 2\n");
    imprimeMatriz(mat2);
    printf("Suma\n");
    resSuma = sumaMatriz(mat1,mat2);
    imprimeMatriz(resSuma);
    printf("Resta\n");
    resResta = restaMatriz(mat1,mat2);
    imprimeMatriz(resResta);
    printf("Multiplicacion\n");
    resMulti = multiMatriz(mat1, mat2);
    imprimeMatriz(resMulti);
    printf("Transpuesta\n");
    resTran1 = transpuesta(mat1);
    imprimeMatriz(resTran1);
    resTran2 = transpuesta(mat2);
    imprimeMatriz(resTran2);
    printf("Inversa\n");
    det1 = Determinante(mat1,10);
    det2 = Determinante(mat2,10);
    printf("%f\n",det1);
    printf("%f\n",det2);
    resIn1 = cofactores(mat1,10,det1);
    resIn2 = cofactores(mat2,10,det2);
    imprimeMatriz(resIn1);
    imprimeMatriz(resIn2);
    return 0;
}