/*EJERCICIO#2
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad. */

#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void ingresar_Datos();

void Reporte();

using namespace std;

int Numper=0,Alturaper=0,opc=0;
float Edadper=0;
char Generoper;
string Departamento;

struct Per
{
	int 	Edadper=0;
	float 	Alturaper=0,Pesoper=0;
	char 	Generoper=0;
	string Departamento;
};
void Ordenamiento(Per lista[], int Numper);

main(){
	do{
		system("cls");
		cout<<"		El siguiente programa es de una libreria"<<endl<<endl;
		cout<<"			1. Ingresar Datos"<<endl;
		cout<<"			2. Reporte"<<endl;
		cout<<"			3. Exit"<<endl;
		cout<<"ingrese una opcion"<<endl;
		cin>>opc;
		
		switch (opc)
		{
			case(1):
				system("cls");
				ingresar_Datos();
			break;
			case(2):
				system("cls");
				Reporte();
			break;	
			case(3):
			break;
		}
	}while(opc>3);	
system("Pause");
}


void ingresar_Datos()
{
int i=1,Numper=0,Edadper=0;
float Alturaper=0,Pesoper=0;
char Generoper=0;
string Departamento;

	cout<<"Cuantas Personas Va ingresar"<<endl;
	cin>>Numper;
	for(i=1;i<=Numper;i++)
	{
	cout<<"persona # "<<i<<endl;
	cout<<"Edad"<<"\t";
	cin>>Edadper;
	cout<<"Altura"<<"\t";
	cin>>Alturaper;
	cout<<"Peso"<<"\t";
	cin>>Pesoper;
	cout<<"Genero (M/F)"<<"\t";
	cin>>Generoper;
	cout<<"Departamento"<<"\t";
	cin>>Departamento;
	
	
		ofstream Archivo;
	try {
		Archivo.open("Personas.txt",ios::app);
		Archivo<<Edadper<<" "<<Alturaper<<" "<<Pesoper<<" "<<Generoper<<" "<<Departamento<<endl;
		Archivo.close();
		cout<<setw(30)<<"Datos Guardados"<<endl;
	}
	catch(exception X){
		cout<<setw(20)<<"Error al Guardar"<<endl;
		system("PAUSE");
	}	
	}
	system("cls");
	
	ifstream Archivo_Abrir;
    string Tmp;
	Archivo_Abrir.open ("Personas.txt",ios::in);
	Per Per_array [1000];

	if (Archivo_Abrir)
	{	
   		for (int contador = 0; contador <1000; contador ++)
    	{
        	Archivo_Abrir >> Per_array [contador] .Edadper;
			Archivo_Abrir >> Per_array [contador] .Alturaper;
        	Archivo_Abrir >> Per_array [contador] .Pesoper;
        	Archivo_Abrir >> Per_array [contador] .Generoper;
        	Archivo_Abrir >> Per_array [contador] .Departamento;
    	}
	}
	else
	 
	 puts("error");

	Ordenamiento (Per_array, 1000);
	ofstream Archivo_Crear;
       
	    Archivo_Crear.open("Temporal.txt",ios::app);        
		
		for(int contador = 0; contador <1000; contador ++)
	{	
			cout<<Per_array [contador] .Edadper<<"\t";
			cout<<Per_array [contador] .Alturaper<<"\t";
        	cout<<Per_array [contador] .Pesoper<<"\t";
        	cout<<Per_array [contador] .Generoper<<"\t";
        	cout<<Per_array [contador] .Departamento<<endl;
			Archivo_Crear<<Per_array [contador] .Edadper<<"\t";
			Archivo_Crear<<Per_array [contador] .Alturaper<<"\t";
        	Archivo_Crear<<Per_array [contador] .Pesoper<<"\t";
        	Archivo_Crear<<Per_array [contador] .Generoper<<"\t";
        	Archivo_Crear<<Per_array [contador] .Departamento<<endl;
}

	Archivo_Crear.close();
		remove("Personasa.txt");
		rename("Temporal.txt","Personasa.txt");

}


void Ordenamiento (Per lista[],int Numper)
{
    Per temp;
    int i;
    int indice;
    	for (i = 1; i <Numper; i ++)
    {
	    for (indice = 0; indice <Numper - i; indice ++)
            if (lista [indice] .Edadper> lista [indice + 1] .Edadper)
            {
                temp = lista [indice];
                lista [indice] = lista [indice + 1];
                lista [indice + 1] = temp;
            }
    }
}



void Reporte()
{
	ifstream Archivo;
	int TT=0;
	float Edad=0,Altura=0,Peso=0,sumatotal=1,Edad1=0,Altura1=0,Peso1=0;
	char Genero;
	string Departamento;
	try{	
		Archivo.open("Personas.txt",ios::in);
				
		while (Archivo>>Edad>>Altura>>Peso>>Genero>>Departamento>>TT){
				
			sumatotal = TT+sumatotal;	
				Edad1=+Edad;
				Altura1+=Altura;
				Peso1+=Peso;
				
		}	
		Archivo.close();
		
		cout<<"Total Datos:          "<<sumatotal<<endl;
	
		cout<<" El Promedio De Edad es :"<<Edad1<<endl;
		cout<<" El Promedio De Altura es :"<<Altura1<<endl;
		cout<<" El Promedio De Pesoss es :"<<Peso1<<endl;
		
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}
