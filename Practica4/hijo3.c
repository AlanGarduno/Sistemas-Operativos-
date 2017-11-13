#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct infoProces{
    STARTUPINFO si;
    PROCESS_INFORMATION pi; 
}infoProces;
infoProces info[3];

int main(){
    int i;
    //printf("Mi Process id es: %d\n",GetCurrentProcessId());
    printf("Mi id (Hijo 5): %d\n",GetCurrentProcessId());
    for(i=0;i<3;i++){
        ZeroMemory(&info[i].si,sizeof(info[i].si));
        info[i].si.cb = sizeof(info[i].si);
        ZeroMemory(&info[i].pi,sizeof(info[i].pi));
        if(!CreateProcess(NULL,"print.exe",NULL,NULL,FALSE,0,NULL,NULL,&info[i].si,&info[i].pi)){
            printf("Error %s",GetLastError());
        }
    }
      //  printf("Mi id (Hijo 3): %d\n",GetCurrentProcessId());
        for(i=0;i<3;i++){
            WaitForSingleObject(info[i].pi.hProcess, INFINITE);
            CloseHandle(info[i].pi.hProcess);
            CloseHandle(info[i].pi.hThread);
        }
        //printf("Mi id (Hijo 3): %d\n",GetCurrentProcessId());
    exit(0);
}