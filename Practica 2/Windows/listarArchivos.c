#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<dirent.h>
#include<time.h>
#include <sys/stat.h>


    int main (int c, char *v[]) {
        int len;
        struct dirent *pDirent;
        struct stat *buf = (struct stat*)malloc(10);
        DIR *pDir;

        if (c < 2) {
            printf ("Faltan aruemntos: <Ruta del directorio> \n");
            return 1;
        }
        pDir = opendir (v[1]);
        if (pDir == NULL) {
            printf ("No es posible abrir el directorio '%s'\n", v[1]);
            return 1;
        }

        while ((pDirent = readdir(pDir)) != NULL) {
            printf ("Nombre: %s  Tama%co: %ld bytes Fecha:%s  \n", pDirent->d_name,164,(*buf).st_size,
            ctime((*buf).st_atime));
        }
        closedir (pDir);
        return 0;
    }
