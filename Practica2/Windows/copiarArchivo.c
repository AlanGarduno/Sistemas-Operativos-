#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <tchar.h>
#include<string.h>
DWORD g_BytesTransferred = 0;
void generarArchivos(char * ruta, char *  contenido);
void crearDirectorioConArchivos(char * contenido);

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
    char *mostrarArchivo = (char*)malloc(sizeof(char));
    int op, ar,i;
    HANDLE file;
    DWORD  dwBytesRead = 0;
    char   ReadBuffer[50] = {0};
    OVERLAPPED ol = {0};
    printf("1.Mostrar Arcivo\n2.Copiar Archvios\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            printf("Mostrar Archivo\nIngresa el directorio del archivo a mostrar:");
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
                    printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n", 
                    GetLastError());
                    CloseHandle(file);
                    return 0;
                }

                SleepEx(5000, TRUE);
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
                printf("\nIngrese el directorio del archivo a copiar:\n");
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
                        printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n", 
                        GetLastError());
                        CloseHandle(file);
                        return 0;
                    }
    
                    SleepEx(5000, TRUE);
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
            //Creacion de la copia
            //printf("Ingrese el directorio de la copia:\n");
            //scanf("%s",nombreCopia);
            crearDirectorioConArchivos(ReadBuffer);
            CloseHandle(file);
            }





        break;
        default:
            printf("Opcion no valida\n");
            return 1;
    }

    return 0;
}
void crearDirectorioConArchivos(char * contenido)
{
	int len;
		int crearDir;
		int dir;
		char ruta[100];
		printf("Ingrese la ruta donde seran creadas las copias de los archivos:\n");
		scanf( "%s" , ruta );
		len = strlen(ruta);
		if( ruta[len-1] != '\"' )
			strcat(ruta,"\\");
		dir = SetCurrentDirectory( ruta );			//Regresa un 0 si falla, cualquier valor distinto de 0 en caso contrario
		if( dir != 0 )			//Ya existe el directorio
		{
	    	generarArchivos( ruta, contenido);
		}
		else
		{
			crearDir = CreateDirectory(ruta,NULL);		//Crear el directorio con todos los permisos
			if(crearDir==0)
			{
                printf("\nError\n");
			}
			else
			{
				printf("\nSe ha creado exitosamente el directorio %s :)\n",ruta);
				system("pause");
				generarArchivos( ruta, contenido);
			}	
		}
}

void generarArchivos(char * ruta, char *  contenido)
{
	HANDLE hFile; 					//Archivo a manejar
	DWORD dwBytesToWrite; 			//Numero de bytes a escribir
    DWORD dwBytesWritten = 0; 		//Numero de bytes escritos
	bool bErrorFlag = FALSE; 		//Bandera de error
	char archivo[20];				//Nombre del archivo
	char direccion[150]={};
	system("cls");
	fflush(stdin);
	    strcat(direccion,ruta);
		fflush(stdin);
		printf("\n\nIngresa el nombre del archivo:\t");
		scanf("%[^\n]",&archivo);
		fflush(stdin);
		strcat(direccion,archivo);
		dwBytesToWrite = (DWORD)strlen(contenido);
		hFile = CreateFile(direccion,           // Direcci�n del archivo
                        GENERIC_WRITE,          // Apertura para escritura
                        0,                      // No compartir
                        NULL,                   // Seguridad por defecto
                        CREATE_NEW,             // Solo crear un nuevo archivo
                        FILE_ATTRIBUTE_NORMAL,  // Archivo normal
                        NULL);                  // Sin plantillas de atributos
		bErrorFlag = WriteFile( 
                    hFile,           // Abrir archivo a manejar
                    contenido,          // Informacion a escribir
                    dwBytesToWrite,  // Numero de bytes a escribir
                    &dwBytesWritten, // Numero de bytes que fueron escritos
                    NULL);           // Ninguna estructura superpuesta
		printf("Se escribieron %d bytes exitosamente.\n", dwBytesWritten);
		CloseHandle(hFile);//Cierra el archivo
	system("pause");	
}
