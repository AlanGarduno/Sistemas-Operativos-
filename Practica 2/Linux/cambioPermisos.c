#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>

#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#endif

int main(){
    int op,res;
    char path[] = "/home/alan/Escritorio/Semestre";
    char*filePath = (char*)malloc(sizeof(char)*50);
    printf("Cambio de perimisos a archivos \nSeleccione el archivo para cmabiar sus perimisos\n");
    do{
        printf("\n1.doc0\n2.doc1\n3.doc2\n4.doc3\n5.doc4\n6.doc5\n7.doc6\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                strcat(filePath,path);
                strcat(filePath,"/doc0.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            case 2:
                strcat(filePath,path);
                strcat(filePath,"/doc1.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            case 3:
                strcat(filePath,path);
                strcat(filePath,"/doc2.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            case 4:
                strcat(filePath,path);
                strcat(filePath,"/doc3.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            case 5:
                strcat(filePath,path);
                strcat(filePath,"/doc4.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            case 6:
                strcat(filePath,path);
                strcat(filePath,"/doc5.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            case 7:
                strcat(filePath,path);
                strcat(filePath,"/doc6.txt");
                printf("Path de archivo 0 %s \n",filePath);
                printf("Cambiando los permisos de doc0\n");
                chmod(filePath, S_IWOTH);
            break;
            default:
                printf("Opcion no valida");
            break;
        }
        printf("Deseas hacer algun otro cmabio\n1.SI\t2.NO\n");
        scanf("%d",&res);
        if(SO == "Linux")
            system("clear");
        else
            system("cls");
    }while(res != 2);
return 0;
}
