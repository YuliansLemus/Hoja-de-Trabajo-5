/* HOJA DE TRABAJO #5
EJERCICIO # 1
En una librería se venden 4 modelos diferentes de cuadernos, con los siguientes precios:
	Modelo#1 – Q10.00
	Modelo#2 – Q15.00
	Modelo#3 – Q18.50
	Modelo#4 – Q25.00
Por otra parte, se tiene información sobre las ventas realizadas durante los últimos 30 días, estos
movimientos se deben de guardar en un archivo de la siguiente forma:
DIA1,MOD,CANT
DIA2,MOD,CANT
.
.
.
DIA30,MODELO,CANTIDAD
DIAi = Variable que representa el día que se efectuó la venta i (1 - 30)
MOD= Variable que representa código de Modelo que se vendió. (1 – 4)
CANT= Variable que representa la cantidad de unidades vendidas.
El programa debe ser capaz de:
	Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo
(modificación del archivo)
	Eliminación de un día especifico de venta (modificación del archivo)
	Calcular el total recaudado por modelo en los 30 días.
	Calcular cuál fue el modelo que se vendió mas en los 30 días*/
	
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void ingresar_Datos();
void Modificar_Datos();
void Eliminar_Datos();
void Calcular_Total_Modelo();



int DIAi=0,MOD,CANT,opc;
float Pre=0,Compra=0;	
	main(){
	do{
		system("cls");
		cout<<"		El siguiente programa es de una libreria"<<endl<<endl;
		cout<<"			1. Ingresar Ventas"<<endl;
		cout<<"			2. Modificar los registros"<<endl;
		cout<<"			3. Eliminar Registro de algun dia "<<endl;
		cout<<"			4. Calcular Total recaudado por modelo "<<endl;
		cout<<"			5. Exit"<<endl;
		cout<<"ingrese una opcion"<<endl;
		cin>>opc;
		
		switch (opc)
		{
			case(1):
				ingresar_Datos();
			break;
			case(2):
				system("cls");
				Modificar_Datos();
			break;	
			case(3):
				system("cls");
				Eliminar_Datos();
			break;
			case(4):
				system("cls");
				Calcular_Total_Modelo();			
			break;
			//case(5):
			
			case(5):			
			break;
		}
	}
	
while(opc>5);	
	system("Pause");
	}
	
void Calcular_Total_Modelo(){
	ifstream Archivo_Abrir;
	
	
	int DIAi=0,MOD,CANT,FINL=0;
	float CANT1=0,CANT2=0,CANT3=0,CANT4=0,CANT5=0,Comple=0;	
	try{	
		Archivo_Abrir.open("Ventas-libreria.txt",ios::in);
		while (Archivo_Abrir>>DIAi>>MOD>>CANT){	
			if (MOD==1)
				CANT1+=CANT;
			else if (MOD==2)
				CANT2+=CANT;
			else if (MOD==3)
				CANT3+=CANT;
			else if (MOD==4)
				CANT4+=CANT;	
		}	
		Archivo_Abrir.close();
		cout<<endl;
	
		cout<<"Desgloce por producto:  "<<endl<<endl;
		cout<<" Modelo #1 "<<CANT1<<" Total Vendido "<<CANT1*10.00<<endl;
		cout<<" Modelo #2 "<<CANT2<<" Total Vendido "<<CANT2*15.00<<endl;
		cout<<" Modelo #3 "<<CANT3<<" Total Vendido "<<CANT3*18.50<<endl;
		cout<<" Modelo #4 "<<CANT4<<" Total Vendido "<<CANT4*25.00<<endl;
		
		CANT5=((CANT1>CANT2)?(CANT1>CANT3 ? CANT1:CANT3):(CANT2>CANT3 ? CANT2:CANT3));
		
	Comple=(CANT5>CANT4 ? CANT5:CANT4);
	
	
		
		if(Comple==CANT1){
			cout<<"\nEl Modelo mas vendido es el #1 Con un Total de "<<Comple<<" Unidades"<<endl;
		}
		else if(Comple==CANT2){
			cout<<"\nEl Modelo mas vendido es el #2 Con un Total de "<<Comple<<" Unidades"<<endl;
		}
		else if(Comple==CANT3){
			cout<<"\nEl Modelo mas vendido es el #3 Con un Total de "<<Comple<<" Unidades"<<endl;
		}
		else if(Comple==CANT4){
			cout<<"\nEl Modelo mas vendido es el #4 Con un Total de "<<Comple<<" Unidades"<<endl;
		}
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}
	
	
	
	
void ingresar_Datos () {
	do{
	system("cls");
	cout<<"ingrese el dia"<<endl;
	cin>>DIAi;	
	if(DIAi>30){
		cout<<"La Fecha que Ingreso No Existe "<<endl;
	system("pause");
		}
	}
while(DIAi>30);	

	do{
	system("cls");	
	cout<<"   Modelos Disponibles \n"<<endl;
	cout<<"	  1. Modelo #1"<<endl;
	cout<<"	  2. Modelo #2"<<endl;
	cout<<"	  3. Modelo #3"<<endl;
	cout<<"	  4. Modelo #4\n"<<endl;
	cout<<"ingrese el modelo del libro"<<endl;
	cin>>MOD;
	if(MOD==1){
		cout<<"el Precio del Modelo 1 es de :"<<endl;
		Pre=10.00;
		cout<<fixed<<setprecision(2)<<"		Q."<<Pre<<endl;
		}
	else if(MOD==2){
		cout<<"el Precio del Modelo 2 es de :"<<endl;
		Pre=15.00;
		cout<<fixed<<setprecision(2)<<"		Q."<<Pre<<endl;
		}
	else if(MOD==3){
		cout<<"el Precio del Modelo 3 es de :"<<endl;
		Pre=18.50;
		cout<<fixed<<setprecision(2)<<"		Q."<<Pre<<endl;
		}
	else if(MOD==4){
		cout<<"el Precio del Modelo 4 es de :"<<endl;
		Pre=25.00;
		cout<<fixed<<setprecision(2)<<"		Q."<<Pre<<endl;
		}
	if(MOD>4){
		cout<<"Modelo No encontrado "<<endl;
		system("pause");
		}
	}
while(MOD>4);	
	
	cout<<"cuantas unidades desea ?"<<endl;
	cin>>CANT;
	Compra=CANT*Pre;
	cout<<endl;
	cout<<fixed<<setprecision(2)<<"El Total a Facturar es de :  Q."<<Compra<<endl<<endl;
	cout<<setw(10)<<"Dia "<<DIAi<<setw(20)<<"Modelo #"<<MOD<<setw(10)<<CANT<<" Cuadernos"<<endl<<endl;
	
	ofstream Archivo;
	try {
		Archivo.open("Ventas-libreria.txt",ios::app);
		Archivo<<DIAi<<" "<<MOD<<" "<<CANT<<endl;
		Archivo.close();
		cout<<setw(30)<<"Datos Guardados"<<endl;
	}
	catch(exception X){
		cout<<setw(20)<<"Error al Guardar"<<endl;
		system("PAUSE");
	
	}
}

void Modificar_Datos(){	
	ifstream Archivo_Abrir;
	ofstream Archivo_Crear;
	
	int DIAi_M=0,MOD_M,CANT_M,aux,AUX,flag;
	char respuesta;
	
	Archivo_Abrir.open("Ventas-libreria.txt",ios::in);
	Archivo_Crear.open("Temporal.txt",ios::out);
	cout<<"Ingrese El Dia a modificar : "<<endl;
	cin>>aux;
	cout<<"Ingrese El Modelo a Modificar modificar : "<<endl;
	cin>>AUX;
	do {
		cout<<"Ingrese La Cantidad a Cambiar: "<<endl;
		cin>>CANT_M;
		cout<<"\nEsta Seguro? S/N"<<endl;;
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
while(Archivo_Abrir>>DIAi_M>>MOD_M>>CANT_M){
		if(aux==DIAi_M){
			if(AUX==MOD_M){
			Archivo_Crear<<DIAi_M<<" "<<MOD_M<<" "<<CANT_M<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
				}}			
		else if(aux!=DIAi_M){
			if(AUX!=MOD_M){
			Archivo_Crear<<DIAi_M<<" "<<MOD_M<<" "<<CANT_M<<endl;
			}
			}				
}
 	Archivo_Abrir.close();
	Archivo_Crear.close();
	if(flag==1){
		remove("Ventas-libreria.txt");
		rename("Temporal.txt","Ventas-libreria.txt");
	}
}


void Eliminar_Datos(){

	ifstream Archivo_Abrir;
	ofstream Archivo_Crear;
	
	int DIAi_E=0,MOD_E,CANT_E,aux,flag;
	
	remove("Temporal.txt");
	cout<<"Ingre el dia a Eliminar: " <<endl;
	cin>>aux;
	
	Archivo_Abrir.open("Ventas-libreria.txt",ios::in);
	Archivo_Crear.open("Temporal.txt",ios::app);	
	
	while(Archivo_Abrir>>DIAi_E>>MOD_E>>CANT_E){
		if(aux==DIAi_E){
			cout<<"Registros del Dia "<<DIAi_E<<" Eliminado..."<<endl;
			flag=1;
		}
		else
		Archivo_Crear<<DIAi_E<<" "<<MOD_E<<" "<<CANT_E<<endl;
	}
	
 	Archivo_Abrir.close();
	Archivo_Crear.close();
	if(flag==1){
		remove("Ventas-libreria.txt");
		rename("Temporal.txt","Ventas-libreria.txt");
	}
}
