#include <iostream>
#include <string.h>
#include<windows.h>
#define yuumi "cls"
#define neeko "pause"

using namespace std;
const char *nombre_archivo = "student.dat";
const char *nombre_archivo_temp = "student_aux.dat";
int opc = 0;

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	char direccion[50];
	int telefono;
};

void menu();
void crear();
void leer();
void actualizar();
void deleteS();
void linea_carga();

main(){
menu();
}

void menu(){
	system("color 30");
	system(yuumi);
	system("title Base de Datos Estudiante");
	
cout<<"    "<<endl<<endl;
cout<<"    "<<endl<<endl;		
cout<<"|------------ Base de datos Estudiante ------------|"<<endl;
cout<<"    "<<endl;	
cout<<"\t 1. Ingresar estudiante"<<endl;
cout<<"    "<<endl;
cout<<"\t 2. Ver lista de estudiantes"<<endl;
cout<<"    "<<endl;
cout<<"\t 3. Actualizar datos del estudiante"<<endl;
cout<<"    "<<endl;
cout<<"\t 4. Eliminar estudiante"<<endl;
cout<<"    "<<endl;
cout<<"\n\t 5. Salir del programa"<<endl<<endl;
cout<<"\t Eliga la opcion deseada: ";
cin>>opc; 
			
	system(yuumi);
	
	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: deleteS();	 		    ;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"ERROR 404";  
	}	
}
void leer(){
	system ("title CARGANDO");{
void linea_carga();
void linea_carga();
	int x,y,i;
 gotoxy(35,10);
 printf("CARGANDO");

 for(i=1; i<80; i++)
 {gotoxy(i,13);
  printf("%c",219);
  for(x=55;x<65;x++){for(y=1;y<80;y++){gotoxy(y,18);}
  }
}
 gotoxy(30,20);
 cout<<"CARGA COMPLETA"<<endl;
 cout<<"\n\t"<<endl;};
 
		system(yuumi);
		system("title Estudiantes");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Direccion"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
		system(neeko);
		menu();
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea agregar otro Estudiante (s/n): ";
		cin>>continuar;
		cout<<"___________________________________________________________"<<endl;
		cout<<endl;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void deleteS(){
 	
	FILE *archivo, *archivo_temp; 
	int codigo; 
	Estudiante estudiante; 
	
	archivo_temp=fopen(nombre_archivo_temp,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	                      				                
	cout<<"Codigo del estudiante a eliminar:"<<endl; 
	cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			if (estudiante.codigo != codigo) 
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	
	leer(); 

}
