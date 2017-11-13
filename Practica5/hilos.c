#include<windows.h>
#include<stdio.h>

DWORD WINAPI funcionHilo(LPVOID lpParam);

typedef struct info{
    int val_1;
    int val_2;
}info;
int main(void){
    DWORD idHilo;
    HANDLE manHilo;
    info arg;
    arg.val_1 = 10;
    arg.val_2 = 100;

    //Creacion del hilo
    manHilo = CreateThread(NULL,0,funcionHilo,&arg,0,&idHilo);
    WaitForSingleObject(manHilo,INFINITE);

    printf("Valores al salir del hilo %d %d\n",arg.val_1, arg.val_2);
    CloseHandle(manHilo);
    return 0;
}

DWORD WINAPI funcionHilo(LPVOID lpParam){
    info *datos = (info*)lpParam;
    printf("Valores al entrar al hijo %d %d\n ",datos->val_1,datos->val_2);
    datos->val_1*=2;
    datos->val_2*=2;
    return 0;
}