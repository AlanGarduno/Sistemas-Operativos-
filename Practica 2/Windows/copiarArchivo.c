#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <tchar.h>
#include<string.h>
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
    char origen [] = "C:/Users/JCVELMON/Desktop/Semestre/";
    char destino [] = "C:/Users/JCVELMON/Desktop/Copia/";
    char *mostrarArchivo = (char*)malloc(sizeof(char));
    char *nombre = (char*)malloc(sizeof(char));
    char *nombreCopia = (char*)malloc(sizeof(char));
    char *aux = (char*)malloc(sizeof(char));
    char *aux2 = (char*)malloc(sizeof(char));
    int op, ar,i;
    HANDLE file;
    DWORD  dwBytesRead = 0;
    char   ReadBuffer[50] = {0};
    OVERLAPPED ol = {0};
    printf("1.Mostrar Arcivo\n2.Copiar Archvios\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            printf("Mostrar Archivo\nIngresa el nombre del archivo a mostrar:");
            scanf("%s",mostrarArchivo);
            file = CreateFile(mostrarArchivo,// file to open
                GENERIC_READ,               // open for reading
                FILE_SHARE_READ,            // share for reading
                NULL,                       // default security
                OPEN_EXISTING,              // existing file only
                FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
                NULL);                                          // no attr. template

                if( FALSE == ReadFileEx(file, ReadBuffer, 50-1, &ol, FileIOCompletionRoutine) )
                {
                    printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n", GetLastError());
                    CloseHandle(file);
                    return 0;
                }

                SleepEx(5000, TRUE);
                //dwBytesRead = 49;
                dwBytesRead = g_BytesTransferred;

                if (dwBytesRead > 0 && dwBytesRead <= 50-1)
                {
                    ReadBuffer[dwBytesRead]='\0'; // NULL character
            
                    _tprintf(TEXT("Data read from %s (%d bytes): \n"), mostrarArchivo, dwBytesRead);
                    printf("%s\n", ReadBuffer);
                }
                else if (dwBytesRead == 0)
                {
                    _tprintf(TEXT("No data read from file %s\n"), mostrarArchivo);
                }
                else
                {
                    printf("\n ** Unexpected value for dwBytesRead ** \n");
                }
            
                CloseHandle(file);
            
        break;
        case 2:
            printf("Cuantos archvivos quieres copiar:\n");
            scanf("%d",&ar);
            for(i =0;i<ar;i++){
                printf("\nIngrese el nombre del archivo a copiar:\n");
                scanf("%s",nombre);
                strcat(aux,origen);
                strcat(aux,nombre); //src path
                printf("Ingrese el nombre de la copia");
                scanf("%s",nombreCopia);
                strcat(aux2,destino);
                strcat(aux2,nombreCopia); //dest path
            }


        break;
        default:
            printf("Opcion no valida\n");
            return 1;
    }

    return 0;
}