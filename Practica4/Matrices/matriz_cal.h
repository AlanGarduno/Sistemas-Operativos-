
struct matriz {
	char name;
	int n;
	double **mat;
};
typedef struct matriz Matriz;
Matriz *creaMatriz(int n);
void imprimeMatriz(Matriz *a);
Matriz *copiaMatriz(Matriz *a);
Matriz *sumaMatriz(Matriz *a, Matriz *b);
Matriz *restaMatriz(Matriz *a, Matriz *b);
Matriz *multiMatriz(Matriz *a, Matriz *b);
void invierteMatriz(Matriz *orig, Matriz *inv);
Matriz* llenarMatriz();
Matriz* transpuesta(Matriz*a);
Matriz* cofactores(Matriz*a,int n, double determinante);
double Determinante(Matriz *a, int n);
void crearArchivo( char* resultado , char* archivo);
void leerArchivo(char* direccion );