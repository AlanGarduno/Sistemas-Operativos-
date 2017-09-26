#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#endif
void retardo(void);

void main() {
    int n,nc;
    int i,j,k=1,a=1;
    int c;
    FILE *archivo; 
            printf("\n\n Ingrese un numero (6 a 78) para realizar la figura: ");
            fflush(stdin);
            scanf("%d",&n);
         if(n<6 || n>78){
                printf("No valido");
                retardo();
                return;
            }
        else{
                if((n%2)!=0){
                printf("No valido");
                retardo();
                return;
            }
            else{
                if((n/2)%2!=1){
                printf("No valido");
                retardo();
                return;
                }
            }
        }
    printf("\nDesea guardar en un archivo?[1)Si/2)No]:");
    scanf("%d",&c);
    if(c==1){
            archivo = fopen("rombo.txt","w");
            if (archivo == NULL){
            printf("\nError de apertura del archivo. \n\n");
            return;
            }
        }
            i=(n/4);
            nc=n/2;
            printf("\n");
        while(nc>=1){
                if(i>=0){
                    for(j=1;j<=i;j++){
                    printf(" ");
                    if(c==1){
                    fprintf(archivo,"%s"," ");
                    }
                }
                printf("*");
                if(c==1){
                fprintf(archivo,"%s","*");
             }
                 if(a!=1){
                    for(j=1;j<=(a-2);j++){
                    printf(" ");
                    if(c==1){
                fprintf(archivo,"%s"," ");
                }
            }
            printf("*");
            if(c==1){
                fprintf(archivo,"%s","*");
                }
            }
            for(j=1;j<=(2*i);j++){
                printf(" ");
                if(c==1){
                fprintf(archivo,"%s"," ");
                }
            }
            for(j=1;j<=a;j++){
                printf("*");
                if(c==1){
                fprintf(archivo,"%s","*");
                }
            }
            if(a==(n/2)){
                a=a-2;
            }
            else{
                a=a+2;
            }
            i--;
            printf("\n");
            if(c==1){
                fprintf(archivo,"%s","\n");
                }
            }
            else{
                for(j=1;j<=k;j++){
                printf(" ");
                if(c==1){
                    fprintf(archivo,"%s"," "); 
                }
            }
            printf("*");
            if(c==1){
                fprintf(archivo,"%s","*");
            }
            if(a!=1){
                for(j=1;j<=(a-2);j++){
                printf(" ");
                if(c==1){
                fprintf(archivo,"%s"," ");
                }
            }
            printf("*");
            if(c==1){
                fprintf(archivo,"%s","*");
                }
            }
            for(j=1;j<=(2*k);j++){
                printf(" ");
                if(c==1){
                fprintf(archivo,"%s"," ");
                }
            }
            for(j=1;j<=a;j++){
                printf("*");
                if(c==1){
                fprintf(archivo,"%s","*");
                }
            }
            k++;
            a=a-2;
            printf("\n");
            if(c==1){
                fprintf(archivo,"%s","\n");
             }
            }
            nc--;
        }
        if(c==1){
            fclose(archivo);
        }
        retardo();
}

void retardo(void){
    int i,j,k; 
    for(i=0;i<=1000;i++){
        for(j=0;j<=1000;j++){
            for(k=0;k<=1000;k++){   
                     }
                 }
            }
    if(SO == "Linux")
        return;
}
