#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 50


//ESTRUCTURAS
typedef struct{
	char nombre_lib[N];
	char autor[N];
	int lleno_lib;
}libro;

typedef struct{
	char nombre_bi[N];
	libro lib[10];
	int lleno_bi;
}biblioteca;


biblioteca bi[7];

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//PROTOTIPOS DE LAS FUNCIONES
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
void CursorOn(bool visible, DWORD size);
void CursorOff();
void limpia();
void vacio();
void menu();
void anadebi();
void cambio(char a[]);
void anadelib();
void consultar();


int main(){
	system("COLOR F0");
	CursorOff();
	dibujarCuadro(0,0,78,24);//Cuadro grande
	dibujarCuadro(1,1,77,3);//Cuadro del titulo
	gotoxy(16,2); printf("              B I B L I O T E C A");
	menu();
	
	
	
	
	getch();
	return 0;
}


void menu(){
	char op;
	CursorOn(1,10);
	do{
		gotoxy(3,6); printf("MENU PRINCIPAL");
		gotoxy(3,9); printf("(1) Agregar Biblioteca");
		gotoxy(3,11); printf("(2) Agregar Libro");
		gotoxy(3,13); printf("(3) Consultar libro");
		gotoxy(3,15); printf("(4) Cerrar");
		gotoxy(3,17); printf("Ingrese opcion: ");
		scanf("%s",&op);
		
		if(op!='1' && op!='2' && op!='3' && op!='4'){
			gotoxy(3,22); printf("Error al ingresar valores. Presione una tecla para volver a ingresar..");
			CursorOff();
			getch();
			gotoxy(3,22); printf("                                                                       ");
			gotoxy(3,17); printf("                                                                       ");
			CursorOn(1,10);	
		}
			
	}while(op!='1' && op!='2' && op!='3' && op!='4');
	
	
	if (op=='1'){
		anadebi();
	}
	
	if (op=='2'){
		int a = 0;
		for(int i = 0; i < 10 && a==0; i++){
			if ( bi[i].lleno_bi == 1)
				a = 1;
		}
		if (a==0){
			CursorOff();
			gotoxy(3,21);printf("No hay bibliotecas. Primero se debe ingresar una biblioteca.");
			gotoxy(3,23);printf("Presione una tecla para continuar..");
			getch();
			gotoxy(3,17); printf("                                                       ");
			gotoxy(3,21);printf("                                                                    ");
			gotoxy(3,23);printf("                                       ");
			menu();
		}
		else
			anadelib();
	}
	
	if (op=='3'){
		int a = 0;
		for(int i = 0; i < 7 && a==0; i++){
			for(int j = 0; j < 10 && a==0; j++){
				if ( bi[i].lib[j].lleno_lib == 1)
				a = 1;	
			}
			
		}
		if (a==0){
			CursorOff();
			gotoxy(3,21);printf("No hay libros. Primero se debe ingresar un libro.");
			gotoxy(3,23);printf("Presione una tecla para continuar..");
			getch();
			gotoxy(3,17); printf("                                                       ");
			gotoxy(3,21);printf("                                                                    ");
			gotoxy(3,23);printf("                                       ");
			menu();
		}
		else
			consultar();
	}
	
	if (op=='4')
		exit(0);
	
}

void anadebi(){
	limpia();
	int aux = 0;
	char op;
	for(int i = 0; i < 7 && aux == 0; i++){
		if (bi[i].lleno_bi == 0){
			gotoxy(3,6); printf("AGREGAR BIBLIOTECA\n");
			gotoxy(3,9); printf("Ingrese un nombre: ");
			fflush(stdin);
			fgets(bi[i].nombre_bi, N, stdin);
			cambio(bi[i].nombre_bi);
			bi[i].lleno_bi = 1;
			
			do{
				CursorOff();
				gotoxy(3,22);printf("Pulse una tecla: <1> Ingresar otra biblioteca / <2> Ir al menu principal ");
				op = getch();	
			}while (op!='1' && op!='2');
			
			if(op=='1'){
					CursorOn(1,10);
					gotoxy(3,9); printf("                                                        ");
					gotoxy(3,22);printf("                                                                          ");
				}
				
			if (op == '2')
					aux=1;
				
		}	
	}
	
	if (aux == 0){
		gotoxy(3,22);printf("No quedan mas espacios. Presione una tecla para continuar..");
		getch();
		CursorOff();
	}
	
	limpia();
	menu();
}


void anadelib(){
	limpia();
	int op,aux=0,f=8;
	char op2;
	for(int i = 0; i < 7; i++){
		if(bi[i].lleno_bi==1){
			gotoxy(3,6); printf("BIBLIOTECAS:");
			gotoxy(3,f); printf("(%i) %s\n",i+1,bi[i].nombre_bi);
			f+=2;
		}
	}
	gotoxy(3,f); printf("Ingrese opcion: ");
	scanf("%i",&op);
	
	limpia();
	
	for (int i = 0; i < 10 && aux == 0; i++){
		if(bi[op-1].lib[i].lleno_lib == 0){
			gotoxy(3,6); printf("BIBLIOTECA: %s",bi[op-1].nombre_bi);
			gotoxy(3,8); printf("INGRESO DE LIBROS\n");
			gotoxy(3,11); printf("Ingrese nombre del libro: ");
			fflush(stdin);
			fgets(bi[op-1].lib[i].nombre_lib, N, stdin);
			cambio(bi[op-1].lib[i].nombre_lib);
			
			gotoxy(3,13); printf("Ingrese nombre del autor: ");
			fflush(stdin);
			fgets(bi[op-1].lib[i].autor, N, stdin);
			cambio(bi[op-1].lib[i].autor);
			
			bi[op-1].lib[i].lleno_lib = 1;
			
			
			do{
				CursorOff();
				gotoxy(3,22);printf("Pulse una tecla: <1> Ingresar otro libro / <2> Ir al menu principal ");
				op2 = getch();	
			}while (op2!=1 && op2!=2);
			
			if(op2=='1'){
					CursorOn(1,10);
					gotoxy(3,11);printf("                                                        ");
					gotoxy(3,13);printf("                                                                          ");
					gotoxy(3,22);printf("                                                                          ");
			}
					
			else if (op2 == '2')
					aux=1;	
		}	
	}
	
	limpia();
	menu();	
}

void consultar(){
	limpia();
	char buscar[N]; 
	char op;
	char op2;
	CursorOn(1,10);
	do{
		gotoxy(3,6); printf("CONSULTA DE LIBROS\n");
		gotoxy(3,9); printf("(1) Busqueda por nombre");
		gotoxy(3,11); printf("(2) Busqueda por autor");
		gotoxy(3,13); printf("(3) Busqueda por biblioteca");
		gotoxy(3,15); printf("Ingrese opcion: ");
		scanf("%s",&op);
		
		if(op!='1' && op!='2' && op!='3') {
			gotoxy(3,22); printf("Error al ingresar valores. Presione una tecla para volver a ingresar..");
			CursorOff();
			getch();
			gotoxy(3,22); printf("                                                                       ");
			gotoxy(3,13); printf("                                                          ");
			CursorOn(1,10);	
		}
			
	}while(op!='1' && op!='2' && op!='3');
	
	limpia();
	
	
	switch(op){
		case '1':{
			gotoxy(3,6); printf("CONSULTA DE LIBROS\n");
			gotoxy(3,9); printf("Ingrese nombre del libro: ");
			fflush(stdin);
			fgets(buscar, N, stdin);
			cambio(buscar);
			
			int aux=0;
			for(int i = 0; i < 10; i++){
				for (int j = 0; j < 10; j++){
					if (strcmpi(buscar,bi[i].lib[j].nombre_lib) == 0 ){
						aux=1;
						gotoxy(3,12); printf("Libro:      %s",bi[i].lib[j].nombre_lib);
						gotoxy(3,16); printf("Biblioteca: %s",bi[i].nombre_bi);
						gotoxy(3,14); printf("Autor:      %s",bi[i].lib[j].autor);	
					}
				}
			}
			
			if (aux ==1){
				do{
					CursorOff();
					gotoxy(3,22);printf("Pulse una tecla: <1> Consultar otro libro / <2> Ir al menu principal ");
					op2 = getch();	
				}while (op2!='1' && op2!='2');
						
				if (op2 == '1'){
					limpia();
					consultar();
				}
						
				else if (op2 == '2'){
					limpia();
					menu();
				}
			}
			
			
			else if (aux==0){
				CursorOff();
				gotoxy(3,22);printf("Busqueda no encontrada. Presione una tecla para continuar..");
				getch();
				limpia();
				menu();
			}
			
			break;
		}
		
		case '2':{
			gotoxy(3,6); printf("CONSULTA DE LIBROS\n");
			gotoxy(3,9); printf("Ingrese nombre del autor: ");
			fflush(stdin);
			fgets(buscar, N, stdin);
			cambio(buscar);
			
			int f=12, aux=0;
			for(int i = 0; i < 7; i++){
				for (int j = 0; j < 10; j++){
					if (strcmpi(buscar,bi[i].lib[j].autor) == 0 ){
						aux=1;
						gotoxy(3,f); printf("Libro: %s ",bi[i].lib[j].nombre_lib);
						gotoxy(40,f); printf("Biblioteca: %s\n",bi[i].nombre_bi);
						f+=2;
					}
				}
			}
			
			if (aux ==1){
				do{
					CursorOff();
					gotoxy(3,22);printf("Pulse una tecla: <1> Consultar otro libro / <2> Ir al menu principal ");
					op2 = getch();	
				}while (op2!='1' && op2!='2');
						
				if (op2 == '1'){
					limpia();
					consultar();
				}
						
				else if (op2 == '2'){
					limpia();
					menu();
				}
			}
			
			
			else if (aux==0){
				CursorOff();
				gotoxy(3,22);printf("Busqueda no encontrada. Presione una tecla para continuar..");
				getch();
				limpia();
				menu();
			}
			
			
			
			
			break;
		}
		
		case '3':{
			limpia();
			int op,aux=0,f=8;
			char op2;
			for(int i = 0; i < 7; i++){
				if(bi[i].lleno_bi==1){
					gotoxy(3,6); printf("BIBLIOTECAS:");
					gotoxy(3,f); printf("(%i) %s\n",i+1,bi[i].nombre_bi);
					f+=2;
				}
			}
			gotoxy(3,f); printf("Ingrese opcion: ");
			scanf("%i",&op);
			
			limpia();
			CursorOff();
			gotoxy(3,6); printf("CONSULTA DE LIBROS\n");
			int f2=11;
			for (int i = 0; i < 10; i++){
				if(bi[op-1].lib[i].lleno_lib == 1){
					gotoxy(3,8); printf("BIBLIOTECA: %s",bi[op-1].nombre_bi);
					gotoxy(3,f2); printf("Libro: %s",bi[op-1].lib[i].nombre_lib);
					f2+=2;
				}	
			}
			
			do{
				
				gotoxy(3,22);printf("Pulse una tecla: <1> Consultar otro libro / <2> Ir al menu principal ");
				op2 = getch();	
			}while (op2!='1' && op2!='2');
			
			if (op2 == '1'){
				limpia();
				consultar();
			}
			
			else if (op2 == '2'){
				limpia();
				menu();
			}
			
			break;
		}
	}
	
	getch();
	menu();
}

//FUNCION VACIO: COLOCA UN CERO EN LLENO_BI y EN LLENO_LIB
void vacio(){
	for(int i = 0; i < 7; i++){
		bi[i].lleno_bi = 0;
		for(int j = 0; j < 10; j++){
			bi[i].lib[j].lleno_lib = 0;
		}
	}
}


void cambio(char a[]){
	int aux;
	aux = strlen(a);
	a[aux-1] = '\0';
}


//FUNCION LIMPIAR PANTALLA
void limpia(){
	int i,j;
	for(i=5;i<=23;i++){
		for(j=3;j<=76;j++){
			gotoxy(j,i); printf(" ");}}
}


//FUNCION GOTOXY
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 
 
//FUNCION DIBUJAR CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2)
{

    int i;
    for (i=x1;i<x2;i++)
    {
	gotoxy(i,y1);printf("Ä") ;//linea horizontal superior
	gotoxy(i,y2);printf("Ä") ;//linea horizontal inferior
    }

    for (i=y1;i<y2;i++)
    {
	gotoxy(x1,i);printf("³") ;//linea vertical izquierda
	gotoxy(x2,i);printf("³") ;//linea vertical derecha
    }
    gotoxy(x1,y1);printf("Ú");
    gotoxy(x1,y2);printf("À");
    gotoxy(x2,y1);printf("¿");
    gotoxy(x2,y2);printf("Ù");
}


// FUNCION PARA OCULTAR EL CURSOR
void CursorOff(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}



//FUNCION PARA APARECER EL CURSOR
void CursorOn(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// tamaño de cursor predeterminado Cambiar a números del 1 al 20, disminuye el ancho del cursor
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
