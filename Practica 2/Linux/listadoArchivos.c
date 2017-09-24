#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<time.h>

int main(){
    struct stat *sb, buf;
    DIR *dir;
    struct dirent *sd;
    printf("Listado de archivos\n");
    dir = opendir("."); //Directorio de acceso a los archivos 
    while((sd = readdir(dir) != NULL)){
        if(sd->d_type  == DT_REG){
            stat(sd->d_name,&buf);
            printf("Nombre:%s Tamaño:&ld Fecha:%s ",sd->d_name, buf.st_size,ctime(&buf.st_atime));
        }
    }
    closedir(dir);
    return 0;
}

