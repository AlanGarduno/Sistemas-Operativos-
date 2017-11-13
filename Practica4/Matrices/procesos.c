#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


int main(int args, char* argv[]){
	STARTUPINFO si;		        	/* Estructura de información inicial para Windows */
    PROCESS_INFORMATION pi;         /* Estructura de información del adm. de procesos */
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    int j;
    argv[1] = "suma.exe";
	argv[2] = "resta.exe";
	//argv[3] = "multi.exe";
	argv[3] = "trans.exe";
	argv[4] = "inv.exe";
	argv[5] = "muestra.exe";
	
	for(j = 1 ; j <= 4 ; j++ )
	{
		if(!CreateProcess(NULL, argv[j], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
			printf( "Fallo al invocar CreateProcess( %lu )\n", GetLastError() );
			return -1;
		}
	}
	for(j = 1 ; j <= 4 ; j++ )
	{
	
		WaitForSingleObject(pi.hProcess, INFINITE); /* Espera a que cada proceso hijo concluya en forma secuencial */
	}
	if(!CreateProcess(NULL, argv[5], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf( "Fallo al invocar CreateProcess( %lu )\n", GetLastError() );
		return -1;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}