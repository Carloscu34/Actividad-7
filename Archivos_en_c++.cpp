#include <iostream>
using namespace std;
//archivos binarios
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void Leer();
void Crear();
void Actualizar();
void Borrar();
main () {
  Leer();
  Crear();
  Actualizar();	
  Borrar();
	system ("pause");
}
void Leer(){
	system ("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
	FILE* archivo = fopen(nombre_archivo,"w+b");	
	}
	Estudiante estudiante;
	int id=0; //indice o posicion del registro(fila) dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"_______________________________"<<endl;
	cout<<"id"<<"|"<<"codido"<<"|"<<"nombres"<<"|"<<"apellidos"<<"|"<<"telefono"<<endl;
	do {
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void Crear(){
	FILE* archivo = fopen(nombre_archivo,"a+b");   //FOPEN es un metodo y recibe dos parametros: el nombre del archivo y el metodo de apertura
	
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin); // fflush: limpia todo el flujo de entrada en la memoria
		cout<<"Ingrese codigo";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese telefono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"desea ingresar otro estudiante(s/n)";
		cin>>res;
	}while(res=='s' || res=='S');
	
	
	
	
	fclose(archivo);
	Leer();
}
void Actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");   //ACTUALIZAR: primero crea y despues borra
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el id que desea modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	
		cout<<"Ingrese codigo";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese telefono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		 
	
	
	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Estudiante estudiante;
	int id=0,id_n=0;
	cout<<"ingrese el id a eliminar";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		if (id_n !=id ){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
	} 
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo = fopen(nombre_archivo,"w+b");
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
	    fwrite(&estudiante,sizeof(Estudiante),1,archivo);
}
            fclose(archivo);
	fclose(archivo_temp);
    Leer();

}



