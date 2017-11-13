#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct infoProces{
    STARTUPINFO si;
    PROCESS_INFORMATION pi; 
}infoProces;
infoProces info;
int main(int argc, char *argv[]){
    int i;
    ZeroMemory(&info.si,sizeof(info.si));
    info.si.cb = sizeof(info.si);
    ZeroMemory(&info.pi,sizeof(info.pi));
    if(!CreateProcess(NULL,argv[1],NULL,NULL,FALSE,0,NULL,NULL,&info.si,&info.pi)){
        printf("Error %s",GetLastError());
        return -1;
    }
    printf("Mi id es (Padre): %d\n",GetCurrentProcessId());
    WaitForSingleObject(info.pi.hProcess, INFINITE);
    CloseHandle(info.pi.hProcess);
    CloseHandle(info.pi.hThread);
    //Primer hijo que crea 5 hijos mas
}