#include <stdio.h>
#include <stdlib.h>
#include "pila.c"
//Defines para saber en que sistema operativo se esta ejecutando
#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#endif
//Funciones
int otraVez(); //Funcion que repite el menu hasta que el usuario decida
void balanceo(FILE *ptr); //Fucnion que verifica el balance de los parentesis
void hanoi(int N,const char O[],const char A[],const char D[]); //Funcion que resulelve las torres de hanoi
void asteriscos(int); //Funcion que imprime los asterioscos de la formma especificada

int main(int argc, char const *argv[]) {
  int resp,num,opc,ast; //Variables resp para evaluar que quiere hacer,num numero de discos(Hanoi)
  //opc para saver si se repite el menu o no, ast para el numero de asteriscos
	FILE *ptr; //Puntero a archivo que contiene la cadena a revisar si esta balanceada
	while(opc!=2) // Bucle del menu
	{
		system("cls");
		printf("\n\n\t\t\tMENU\n\n\n");
		printf("1. Balanceo de paréntesis.\n");
		printf("2. Torres de Hanoi.\n");
		printf("3. Asteriscos.\n");
		printf("4. Salir.\n\n");
		scanf("%d",&resp);
		system("cls");
		switch(resp)
		{
			case 1:
				printf("\n\n\t\tBALANCEO:\n\n");
				ptr=fopen("archivo.txt","r");
				balanceo(ptr);
				printf("\n\n\n");
				opc = otraVez();
				break;
			case 2:
				printf ("\nIngrese el n%cmero de discos para las torres de hanoi\n",163);
				scanf ("%d",&num);
				hanoi(num,"Inicio","Auxiliar", "Destino");
				printf("\n\n\n");
				opc = otraVez();
				break;
			case 3:
        printf("\n\nIngrese el numero de asteriscos:\t");
        scanf("%d",&ast);
        asteriscos(ast);
        printf("\n\n\n");
        opc = otraVez();
				break;
			case 4:
          return 0;
				break;
        default:
          printf("Opcion no valida\n");
          opc = otraVez();
		}
}
  return 0;
}

int otraVez(){
  int x; //variable auxiliar para guardar la respuesta del usuario
  printf("\n\n¿Desea hacer alguna otra operación?");
	printf("\n\n1.SI\t\t\t2.NO\n\n");
	scanf("%d",&x);//Se guarda las respuesta del usuario
	return x; //Se retorna esa respuesta
}

void balanceo(FILE *ptr){ //recibe como parametro un archvi que contiene la cadena a evaluar
  int linea=1; //Linea del archvo en la que nos enconramos la Inicio
  char c; //variable para ir recorriendo el archivo
  pila s; //Pila donde si van guardando los de apertura
  NODO D; //Nodo donde se guardan los datos requridos
  ini_pila(&s); //Iniciamos la pila
  c=fgetc(ptr); //Obtenemos el primer caracter del archivo
  while (c != EOF){ //Mientras el archivo no este vacio o no se haya llegado al final del mismo
    switch (c) { //Evaluamos el primer caracter
      case '(' : case '[' : case '{': //Caracteres de apertura
        D.LL=c;  //Si es una de apertura guardamos en el nodo
        D.Lg = linea; //Guardamos la linea en la que nos enconramos
        push(&s,D); //apilamos
        break;
        case')' : case ']' : case '}': //
        if(empty(s)){ //en caso de que no haya signo de apertura se detiene la ejecucion
          printf("\nFalta e signo de apertura en la linea %d",linea);
          exit(0);//
          break;
        }else
        {
          D=top(s); // Guardamos los datos
          if((D.LL=='{'&&c=='}')||(D.LL=='['&&c==']')||(D.LL=='('&&c==')')) //comparamos si es de cerradura
            pop(&s); // si si lo es desapliamos
          else
          {
            printf("\n\nError de correspondencia en la linea\t %d\n\n",linea); //Si no lo es marcamos el error de correspondencia ne la linea
            exit(0);
            }
        }
        break;

        case '\n': linea++; //en caso de salto de linea aumentamos la linea
    }// Termina el switch
    c = fgetc(ptr); //obtenemos el caracter que sigue
  }//Se termina el while
  if(empty(s)) // si la pila esta vacia entonces, todo esta balanceado
	{
		printf("\n\nArchivo balanceado\n");
	}
	else //Si no hay un error y marcamos en que linea
	{
		printf("\n\nError, falta signo de cierre en la linea %d\n\n",s->Lg);
		exit(0);
	}
	fclose(ptr); //ceramos el Archivo
	printf("\n\n\n");//Espacio final para que se ve mas ordenado
}

void hanoi(int N,const char O[],const char A[],const char D[]){ //recibe como parametro N, que son el numero de discos
  // Y O A Y D que son constantes con nos van a ayudar a dar las intrucciones para dar solucion al juego
  if(N==1)//la funcion es recuersiva este es nuestro caso base
  {
    printf ("Mover disco %d de %s a %s \n", N, O, D); // Se imprimen las instrucciones de los movimientos
  }else
  {
    hanoi(N-1, O, D, A); //Se aplica recursividad
    printf ("Mover disco %d de %s a %s \n", N, O, D); // Se imprimen las instrucciones de los movimoentos
    hanoi(N-1, A, O, D); // Recursividad de nuevo
  }
}


void asteriscos(int NumeroDeAsteriscosHorizontales)
{
	FILE *ptr_archivo;
	char nombreFichero [] = "Asteriscos.txt";
	int i,j,NumeroDeEspaciosFuera,NumeroDeEspaciosDentro, NumeroDeAsteriscosDentro = 1, acum1 = 0;
	if((ptr_archivo = fopen(nombreFichero,"w+")) == NULL)
	{
		printf("No se ha podido abrir el archivo %s\n",nombreFichero);
	}
	NumeroDeEspaciosFuera = (NumeroDeAsteriscosHorizontales/2);
	while(NumeroDeEspaciosFuera != 0)
	{
		NumeroDeEspaciosDentro = (NumeroDeEspaciosFuera*2);
		for(i = 1; i <= NumeroDeEspaciosFuera;i++)
		{
			printf(" ");
			fwrite(" ",sizeof(char),1,ptr_archivo);
			if(i == NumeroDeEspaciosFuera)
			{
				printf("*");
				fwrite("*",sizeof(char),1,ptr_archivo);
				if(acum1 ==0)
				{
					for(j = 1; j <= NumeroDeEspaciosDentro;j++)
					{
						printf(" ");
						fwrite(" ",sizeof(char),1,ptr_archivo);
						if(j == NumeroDeEspaciosDentro)
						{					
							printf("*");
							fwrite("*",sizeof(char),1,ptr_archivo);
							NumeroDeAsteriscosDentro = NumeroDeAsteriscosDentro+2;
							i = NumeroDeAsteriscosDentro;
							for(i = 1;i <= NumeroDeEspaciosFuera;i++)
							{
								printf(" ");
								fwrite(" ",sizeof(char),1,ptr_archivo);
							}
						}
					}
					acum1++;
				}else
				{
					for(i = 0; i < acum1; i++)
					{
						printf(" ");
						fwrite(" ",sizeof(char),1,ptr_archivo);
					}
					printf("*");
					fwrite("*",sizeof(char),1,ptr_archivo);
					acum1 = acum1 + 2;
					for(j = 1; j <= NumeroDeEspaciosDentro;j++)
					{
						printf(" ");
						fwrite(" ",sizeof(char),1,ptr_archivo);
						if(j == NumeroDeEspaciosDentro)
						{
							for(i = 0; i < acum1;i++)
							{
								printf("*");
								fwrite("*",sizeof(char),1,ptr_archivo);
							}
							NumeroDeAsteriscosDentro = NumeroDeAsteriscosDentro+2;
							i = NumeroDeAsteriscosDentro;
							for(i = 1;i <= NumeroDeEspaciosFuera;i++)
							{
								printf(" ");
								fwrite(" ",sizeof(char),1,ptr_archivo);
							}
						}
					}
				}
			}
		}
		printf("\n");
		fwrite("\n",sizeof(char),1,ptr_archivo);
		NumeroDeEspaciosFuera--;
	}	
	while(NumeroDeEspaciosFuera != (NumeroDeAsteriscosHorizontales/2)+1)
	{
		if(NumeroDeEspaciosFuera == 0)
		{
			printf("*");
			fwrite("*",sizeof(char),1,ptr_archivo);
			for(i = 0; i < acum1; i++)
			{
				printf(" ");
				fwrite(" ",sizeof(char),1,ptr_archivo);
			}
			for(i = 0; i <= NumeroDeAsteriscosDentro;i++)
			{
				printf("*");
				fwrite("*",sizeof(char),1,ptr_archivo);
			}
			acum1 = acum1 - 2;
		}else if(NumeroDeEspaciosFuera != (NumeroDeAsteriscosHorizontales/2)+1)
		{
			for(i = 0; i < NumeroDeEspaciosFuera;i++)
			{
				printf(" ");
				fwrite(" ",sizeof(char),1,ptr_archivo);
			}
			printf("*");
			fwrite("*",sizeof(char),1,ptr_archivo);
			for(i = 0; i < acum1;i++)
			{
				printf(" ");
				fwrite(" ",sizeof(char),1,ptr_archivo);
			}
			if((NumeroDeEspaciosFuera*2)+1 != NumeroDeAsteriscosHorizontales)
			{
				printf("*");
				fwrite("*",sizeof(char),1,ptr_archivo);
			}
			for(i = 0; i < (NumeroDeEspaciosFuera*2);i++)
			{
				printf(" ");
				fwrite(" ",sizeof(char),1,ptr_archivo);
			}
			for(i = 0; i < NumeroDeAsteriscosDentro; i++)
			{
				printf("*");
				fwrite("*",sizeof(char),1,ptr_archivo);
			}
			for(i = 0; i < NumeroDeEspaciosFuera; i++)
			{
				printf(" ");
				fwrite(" ",sizeof(char),1,ptr_archivo);
			}
			acum1 = acum1 - 2;
		}
		printf("\n");
		fwrite("\n",sizeof(char),1,ptr_archivo);
		NumeroDeAsteriscosDentro = NumeroDeAsteriscosDentro - 2;
		NumeroDeEspaciosFuera++;
	}
	printf("\n\n%cDesea guardar en un archivo?\n\n1. SI\t\t\t2.NO\n",168);
	scanf("%d",&i);
	fclose(ptr_archivo);
	if(i == 1)
		printf("Archivo guardado como %s\n",nombreFichero);
remove("Asteriscos.txt");
}
