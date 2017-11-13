#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "matriz_cal.h"
#include<string.h>
#include <windows.h>
#include<stdbool.h>
#define BUFFERSIZE 700


Matriz *creaMatriz(int n){
Matriz *mat;
int i;
	mat=(Matriz *)malloc(sizeof(Matriz));
	mat->n=n;
	mat->mat=(double **)malloc(sizeof(double *) * n);
	for(i=0; i< n;i++)
        	mat->mat[i]=(double *)malloc(sizeof(double)*n);
        return mat;
}
void imprimeMatriz(Matriz *a){
int i,j; 
        printf("\n");
	for(i=0; i< a->n;i++){
		for(j=0; j < a->n;j++)
			printf("%.2f ", a->mat[i][j]);
		printf("\n");
	}
        printf("\n");
}
Matriz *copiaMatriz(Matriz *a){
int i,j;
Matriz *copy=creaMatriz(a->n);
	for(i=0; i< a->n;i++){
		for(j=0; j < a->n;j++)
			copy->mat[i][j]=a->mat[i][j];
	}
return copy;	
}

Matriz *sumaMatriz(Matriz *a, Matriz *b){
Matriz *c;
int i,j;
        c=creaMatriz(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++)
			c->mat[i][j]=a->mat[i][j]+b->mat[i][j];
	return c;
}


Matriz *restaMatriz(Matriz *a, Matriz *b){
Matriz *c;
int i,j;
        c=creaMatriz(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++)
			c->mat[i][j]=a->mat[i][j]-b->mat[i][j];
	return c;
}
Matriz *multiMatriz(Matriz *a, Matriz *b){
Matriz *c;
int i,j, k; 
double acu;
        c=creaMatriz(a->n);
	for(i=0; i< a->n;i++)
		for(j=0; j < a->n;j++){
			acu=0;
			for(k=0; k < a->n;k++){
                         
				acu=acu+a->mat[i][k]*b->mat[k][j];
				//printf("<%f,%f,%f> ",a->mat[i][k],b->mat[k][j],acu);
                        }             
                        //printf("\n");
			c->mat[i][j]=acu;
		}
	return c;
}

/*
void invierteMatriz(Matriz *orig, Matriz *inv/*, double determ/) {
// Algoritmo para la eliminación simple de Gauss
	int i, j, k;
	double factor;
	double **L, *D, *X;
        double determ;
        double **a=copiaMatriz(orig)->mat;
        double **ainv=inv->mat;   
        int n=orig->n;
	X=(double*)malloc(sizeof(double)*n); D=(double*)malloc(sizeof(double)*n);
	L =(double**)malloc(sizeof(double *)*n);	
	for (j = 0; j < n; j++) 
		L[j] =(double*)malloc(sizeof(double)*n);
	for (k = 0; k < n - 1; k++) {		
		for (i = k+1; i < n;  i++) {
			factor = a[i][k]/a[k][k];          
                        //printf("fact=<%f> ", factor);
			for (j = k+1; j < n + 1; j++) {
				a[i][j] = a[i][j] - factor * a[k][j];
			}
		}
	}
// Cálculo del determinante
        determ = 1;
	for (i = 0; i < n; i++) {
		determ = determ * a[i][i];
	}
if (determ != 0) {
// Rutina para determinar las matrices L (inferior) y U (superior) de la 
// descomposición LU
        for (i = 0; i < n; i++) {
               for (j = 0; j < n; j++) {
                  if (i > j) { 
                      L[i][j] = a[i][j]/a[j][j];
                      a[i][j] = 0;
                   }
               }
        }
       for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  L[j][j] = 1;
            }
        }
// Implementación de la rutina para el cálculo de la inversa
 for (k = 0; k < n; k++) {
// Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L
          for (i = 0; i < n; i++) {
               if (i == k) L[i][n] = 1;
               else  L[i][n] = 0;
           }
// Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n]
// que produce la rutina anterior
  double sum;
  D[0] = L[0][n];

  for (i = 1; i < n; i++) {
       sum = 0;
       for (j = 0; j < i; j++) {
            sum = sum + L[i][j]*D[j];
       }

        D[i] = L[i][n] - sum;
   }
// Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U
  for (i = 0; i < n; i++) {
          a[i][n] = D[i];
  }
// Rutina que aplica la sustitución hacia atras
 X[n-1] = a[n-1][n]/a[n-1][n-1];
 // Determinación de las raíces restantes
  for (i = n - 2; i > -1; i--) {
        sum = 0;
        for (j = i+1; j < n; j++) {
              sum = sum + a[i][j]*X[j];
         }
         X[i] = (a[i][n] - sum)/a[i][i];
   }
// Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa
  for (i = 0; i < n; i++) {
         ainv[i][k] = X[i];
  }
 }   // llave de cierre del for para k
 	inv->mat = ainv;
}   // cierre del if
else if(determ == 0){
	printf("No es posible calcular la inversa de esta matriz por su determinante %d\n",determ);
	return;
}
	free(L); free(D); free(X);
}*/

double Determinante(Matriz *a, int n){
	Matriz *aux;
	double s = 1, det = 0;
	int i, j, k, m, x;
	if(n == 1){
		return a->mat[0][0];
	}
	else{
		for (k = 0; k < n; k++)
    {
      m = 0;
      x = 0;
      for (i = 0; i < n; i++)
      {
        for (j = 0; j < n; j++)
        {
          aux->mat[i][j] = 0;
          if (i != 0 && j != k)
          {
            aux->mat[m][x] = a->mat[i][j];
            if (x < (n - 2))
            {
              x++;
            }
			else
            {
              x = 0;
              m++;
            }
          }
        }
      }
    }
    det = det + s * (a->mat[0][k] * Determinante(aux, n-1));
    s *= -1;
  }
  return det;
}

Matriz* cofactores(Matriz*a,int n, double determinante){
	int q, m, i, j, k, l;
  Matriz* m2, *matrizFactores, *aux, *inversa;
  m = 0; q = 0;
  for (l = 0; l < n; l++)
  {
    for (k = 0; k < n; k++)
    {
      for (i = 0; i < n; i++)
      {
        for (j = 0; j < n; j++)
        {
          if ( i != l && j != k)
          {
            m2->mat[m][q] = a->mat[i][j];
            if (q < (n-2))
            {
              q++;
            }
			else {
				    q = 0; m++;
            }
          }
        }
      }
      matrizFactores->mat[l][k] = (pow(-1, l + k)* Determinante (m2, n-1));
    }
  }
  for (i = 0; i < a->n; i++)
  {
    for (j = 0; j < a->n; j++)
    {
      aux->mat[i][j] = matrizFactores->mat[j][i];
    }
  }
  for (i = 0; i < a->n; i++)
  {
    for (j = 0; j < a->n; j++)
    {
      inversa->mat[i][j] = aux->mat[i][j] / determinante;
    }
}

return inversa;

}


Matriz* llenarMatriz(){
	int i,j;
	Matriz* aux;
	aux= creaMatriz(10);
	for(i = 0; i<9;i++){
		for(j=0;j<9;j++){
			aux->mat[i][j] = rand()%100; 
		}
	}
	return aux;
}

Matriz* transpuesta(Matriz*a){
	int i,j;
	Matriz *aux = creaMatriz(10);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			aux->mat[i][j] = a->mat[j][i];
		}
	}
	return aux;
}

void crearArchivo( char *resultado, char* archivo)
{
	char *username = getenv( "USERNAME" );
	char direccion[100];
	strcpy(direccion,"C:\\Users\\");
	strcat(direccion,username);
	strcat(direccion,"\\Desktop\\");
	strcat(direccion,archivo);
	HANDLE hFile; //Archivo a manejar
	DWORD dwBytesToWrite; //Numero de bytes a escribir
	DWORD dwBytesWritten = 0; //Numero de bytes escritos
	bool bErrorFlag = FALSE; //Bandera de error
	//dwBytesToWrite = (DWORD)strlen(resultado);
	dwBytesToWrite = (DWORD)sizeof(resultado)*25;
	printf("%i\n",dwBytesToWrite);
	printf("\n\tSe ha guardado el archivo en:\n\t%s\n",direccion);
	
	hFile = CreateFile(direccion, // Dirección del archivo
	GENERIC_WRITE, // Apertura para escritura
	0, // No compartir
	NULL, // Seguridad por defecto
	CREATE_ALWAYS, // Sobreescribe el archivo en caso de que exite, si no, crea uno nuevo
	FILE_ATTRIBUTE_NORMAL, // Archivo normal
	NULL); // Sin plantillas de atributos
	
	bErrorFlag = WriteFile(
	hFile, // Abrir archivo a manejar
	resultado, // Información a escribir
	dwBytesToWrite, // Numero de bytes a escribir
	&dwBytesWritten, // Numero de bytes que fueron escritos
	NULL); // Ninguna estructura superpuesta
	if(!bErrorFlag)
		printf("\tError al crear el archivo :(\n\n");
	else
		printf("\tSe escribieron %lu bytes en %s exitosamente.\n\n",dwBytesWritten, direccion);
	CloseHandle(hFile);//Cierra el archivo
}

void leerArchivo(char* direccion)
{
	HANDLE hFile;								//Manejador de Archivo
    DWORD  dwBytesRead = 0;						//Numero de bytes a leer
    char   ReadBuffer[BUFFERSIZE] = {0};		//Arreglo para guardar el texto a leer
	
	hFile = CreateFile (direccion,             // Direccion del archivo
                       GENERIC_READ,          // Apertura para lectura
                       0,     				  // Compartir para lectura
                       NULL,                  // Seguridad por defect
                       OPEN_EXISTING,         // Archivo existente únicamente
                       FILE_ATTRIBUTE_NORMAL, // archivo normal
                       NULL);                 // Sin atributos
	 
	if (hFile == INVALID_HANDLE_VALUE) 
    { 
        printf("Error: no se pudo abrir el archivo %s para lectura.\n", direccion);
		return;
    }
	
	// Lee un caracter menos que el tamaño del buffer para guardar espacio
    // para el caracter NULL de fin 
    
	if( FALSE == ReadFile(hFile, ReadBuffer, BUFFERSIZE-1, &dwBytesRead, NULL) )
    {
        printf("Error: No se pudo leer el archivo.\n GetLastError=%08lu\n", GetLastError());
        CloseHandle(hFile);
        return;
    }
	
    if (dwBytesRead > 0 && dwBytesRead <= BUFFERSIZE-1)
    {
        ReadBuffer[dwBytesRead]='\0'; // caracter NULL 

        printf("Se leyeron %lu bytes del archivo", dwBytesRead);
        printf("\n\n%0.f\t\n\n", ReadBuffer);
    }
    else if (dwBytesRead == 0)
    {
        printf("Ne se leyo informacion de %s\n", direccion);
    }
    else
    {
        printf("\n ** Valor inesperado para dwBytesRead ** \n");
    }
    
    CloseHandle(hFile);
}