#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <tchar.h>
#include<string.h>
#include "matriz_cal.c"

DWORD g_BytesTransferred = 0;

VOID CALLBACK FileIOCompletionRoutine(
    DWORD dwErrorCode,
    DWORD dwNumberOfBytesTransfered,
    LPOVERLAPPED lpOverlapped
);

VOID CALLBACK FileIOCompletionRoutine(
    DWORD dwErrorCode,
    DWORD dwNumberOfBytesTransfered,
    LPOVERLAPPED lpOverlapped )
 {
  _tprintf(TEXT("Error code:\t%x\n"), dwErrorCode);
  _tprintf(TEXT("Number of bytes:\t%x\n"), dwNumberOfBytesTransfered);
  g_BytesTransferred = dwNumberOfBytesTransfered;
 }

 int main(){
    char *username = getenv( "USERNAME" );
	char suma[100]={};
	char resta[100]={};
	char multiplicacion[100]={};
	char transpuesta[100];
	char transpuesta2[100];
	char inversa1[100]={};
	char inversa2[100]={};
	strcpy(suma,"C:\\Users\\");
	strcpy(resta,"C:\\Users\\");
	strcpy(multiplicacion,"C:\\Users\\");
	strcpy(transpuesta,"C:\\Users\\");
	strcpy(transpuesta2,"C:\\Users\\");
	strcpy(inversa1,"C:\\Users\\");
	strcpy(inversa2,"C:\\Users\\");
	strcat(suma,username);
	strcat(resta,username);
	strcat(multiplicacion,username);
	strcat(transpuesta,username);
	strcat(transpuesta2,username);
	strcat(inversa1,username);
	strcat(inversa2,username);
	strcat(suma,"\\Desktop\\suma.txt");
	strcat(resta,"\\Desktop\\resta.txt");
	strcat(multiplicacion,"\\Desktop\\multi.txt");
	strcat(transpuesta,"\\Desktop\\transpuesta1.txt");
	strcat(transpuesta2,"\\Desktop\\transpuesta2.txt");
	strcat(inversa1,"\\Desktop\\inversa1.txt");
	strcat(inversa2,"\\Desktop\\inversa2.txt");
	leerArchivo(suma);
	leerArchivo(resta);
	leerArchivo(multiplicacion);
	leerArchivo(transpuesta);
	leerArchivo(transpuesta2);
	leerArchivo(inversa1);
	leerArchivo(inversa2);
	exit(0);
 }