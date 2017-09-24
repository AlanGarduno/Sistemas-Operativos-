#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void Cdocs(int rdocs,int crmax,char *ruta, char **cadenas);
void llena(char **cadenas, int tam);
void vaciar(char **cadenas);

int main(){
    char **cadenas=(char**)malloc(sizeof(char*)*20);
    char *ruta=(char*)malloc(sizeof(char)*150);
    DIR *dirp;
    llena(cadenas,20);

    puts("Ingresa la ruta a donde se crearan los archivos");
    scanf("%s",ruta);

    dirp=opendir(ruta);
    if(dirp==NULL){
        mkdir(ruta,0777);
        Cdocs(10,10,ruta,cadenas);
    }else{
        puts("El directorio ya existe");
    }
}

void Cdocs(int rdocs,int crmax,char *ruta, char **cadenas){
    char *temp = (char*)malloc(sizeof(char)*100);
    char *numtext = (char*)malloc(sizeof(char)*2);
    srand(time(NULL));
    int i=rand()%rdocs,j=0;
    int fd,tc;

    printf("Se crearon %i documentos\n",i);

    for(int t=0;t<i;t++){
        temp = strcpy(temp,ruta);
        temp = strcat(temp, "/doc");
        sprintf(numtext,"%i",t);
        temp=strcat(temp, numtext);
        temp = strcat(temp, ".txt");
        fd = open(temp,0100|0001, 00600);
        if(fd>-1){
            j=rand()%crmax;
            printf("El documento %i tendra %i cadenas\n",t,j);
            for(tc=0;tc<j;tc++){
                write(fd,cadenas[tc],20);
            }
            fd=close(20);
        }
    }

}

void llena(char **cadenas, int tam){
    int i;
    for(i=0;i<20;i++)
        cadenas[i]=(char*)malloc(sizeof(char)*tam);
    cadenas[0]="estas\n";
    cadenas[1]="van\n";
    cadenas[2]="a ser\n";
    cadenas[3]="las\n";
    cadenas[4]="cadenas\n";
    cadenas[5]="para\n";
    cadenas[6]="la\n";
    cadenas[7]="practica\n";
    cadenas[8]="2 de\n";
    cadenas[9]="sistemas\n";
    cadenas[10]="operativos\n";
    cadenas[11]="para\n";
    cadenas[12]="hacerlas\n";
    cadenas[13]="de una\n";
    cadenas[14]="forma\n";
    cadenas[15]="sencilla\n";
    cadenas[16]="por que\n";
    cadenas[17]="no sabia\n";
    cadenas[18]="que poner\n";
    cadenas[19]="en las cadenas\n";
}

