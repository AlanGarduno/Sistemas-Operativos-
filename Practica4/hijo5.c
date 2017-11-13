#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct infoProces{
    STARTUPINFO si;
    PROCESS_INFORMATION pi; 
}infoProces;
infoProces info[5];

int main(int argc, char *argv[]){
    int i;
    //printf("Mi Process id es: %d\n",GetCurrentProcessId());
    printf("Mi Process id es (Hijo 1): %d\n",GetCurrentProcessId());
    for(i=0;i<5;i++){
        ZeroMemory(&info[i].si,sizeof(info[i].si));
        info[i].si.cb = sizeof(info[i].si);
        ZeroMemory(&info[i].pi,sizeof(info[i].pi));
        if(!CreateProcess(NULL,"hijo3.exe",NULL,NULL,FALSE,0,NULL,NULL,&info[i].si,&info[i].pi)){
            printf("Error %s",GetLastError());
        }
    }
    //printf("Mi Process id es (Hijo 5): %d\n",GetCurrentProcessId());
    for(i=0;i<5;i++){
        WaitForSingleObject(info[i].pi.hProcess, INFINITE);
        CloseHandle(info[i].pi.hProcess);
        CloseHandle(info[i].pi.hThread);
    }
    exit(0);
    
}