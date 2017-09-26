
#include <stdio.h>
#include <stdlib.h>

void Han(int,char,char,char);

int main(){
    int x;
    char A,B,C;
    A='A';
    B='B';
    C='C';

    printf("%10s TORRES DE HANOI\n"," ");
    printf("Cuantos discos: ");
    scanf("%d",&x);
    printf("Para ganar, sigue los siguientes pasos:\n"); Han(x,A,B,C);

}

void Han(int N,char O,char A,char D){
    if(N==1){
        printf("Mover disco %d de %c a %c\n",N,O,D);
    }
    else{
        Han(N-1,O,D,A);
        printf("Mover disco %d de %c a %c\n",N,O,D); Han(N-1,A,O,D);
    }
}
