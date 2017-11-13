#include <stdlib.h>
#include <stdio.h>   //<stdio.h>
#include<math.h>
 
typedef struct Matrix
{
    float **lpData;
    unsigned int uiRows;
    unsigned int uiCols;
}
MATRIX, *LPMATRIX;
 
LPMATRIX createMatrix(unsigned int uiRows, unsigned int uiCols)
{
    LPMATRIX lpRet = (LPMATRIX)malloc(sizeof(MATRIX));
    int i = 0;
    lpRet->uiCols = uiCols;
    lpRet->uiRows = uiRows;
    lpRet->lpData = (float**)malloc(sizeof(float*) * lpRet->uiRows);
    for (i = 0; i < lpRet->uiRows; i++)
        lpRet->lpData[i] = (float*)malloc(sizeof(float) * lpRet->uiCols);
    return lpRet;
}
MATRIX * llenarMatriz(){
	int i,j;
    MATRIX* aux = createMatrix(10,10);
	for(i = 0; i<9;i++){
		for(j=0;j<9;j++){
			aux->lpData[i][j] = rand()%100; 
		}
	}
	return aux;
}
 
void freeMatrix(LPMATRIX lpMatrix)
{
    int i = 0;
    if (!lpMatrix) return;
    for (i = 0; i < lpMatrix->uiRows; i++)
        free(lpMatrix->lpData[i]);
    free(lpMatrix->lpData);
    free(lpMatrix);
}
 
void showMatrix(LPMATRIX lpMatrix)
{
    int i = 0,
        j = 0;
    if (!(lpMatrix || lpMatrix->lpData)) return;
    for (i = 0; i < lpMatrix->uiRows; i++)
    {
        if (lpMatrix->lpData[i])
        {
            for (j = 0; j < lpMatrix->uiCols; j++)
                printf("\t%.0f", lpMatrix->lpData[i][j]);
            printf("\n");
        }
    }
}
 
int getDeterminant(LPMATRIX lpMatrix, float* lpOutDeterminant)
//  Retorna 0 si todo a ido bien, de lo contrario retorna un numero distinto de 0
{
    float fRet = 0.0f,
          fProduct = 0.0f;
    unsigned int i = 0,
                 j = 0;
    if (!(lpMatrix || lpMatrix->lpData) || (lpMatrix->uiRows < 2) || (lpMatrix->uiCols < 2) || (lpMatrix->uiRows != lpMatrix->uiCols)) return -1;
 
    if (lpMatrix->uiCols == 2)
    {
        if (!(lpMatrix->lpData[0] && lpMatrix->lpData[1])) return -1;
        fRet = lpMatrix->lpData[0][0] * lpMatrix->lpData[1][1] - lpMatrix->lpData[1][0] * lpMatrix->lpData[0][1];
 
    } else {
        for (i = 0; i < lpMatrix->uiRows; i++)
        {
            if (!lpMatrix->lpData[i]) return -1;
            //  Multiplicacion de valores verticales de izquierda a derecha...
            fProduct = 1.0f;
            for (j = 0; j < lpMatrix->uiCols; j++)
                fProduct *= lpMatrix->lpData[(i + j) % lpMatrix->uiCols][j];
            fRet += fProduct;
 
            //  Multiplicacion de valores verticales de derecha a izquierda...
            fProduct = 1.0f;
            for (j = 0; j < lpMatrix->uiCols; j++)
                fProduct *= lpMatrix->lpData[(lpMatrix->uiCols - 1) - ((i + j) % lpMatrix->uiCols)][j];
            fRet -= fProduct;
        }
    }
    if (lpOutDeterminant)
        *lpOutDeterminant = fRet;
 
    return 0;
}
 
int main()
{
    MATRIX * lpMatrix = createMatrix(10,10);
    float fDeterminant = 0.0;
    lpMatrix = llenarMatriz();
    fflush(stdout);
    showMatrix(lpMatrix);
    if (getDeterminant(lpMatrix, &fDeterminant) == 0)
        printf("Determinante = %.0f\n", fDeterminant);
    freeMatrix(lpMatrix);
 
    getchar();
 
    return EXIT_SUCCESS;
}
 