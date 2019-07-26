#include <iostream>
#include <string>
#include "Matriz.cpp"
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int menu();
int menu2();
void printMatriz(Matriz*, int);
void printMatrizPersonalizada(Matriz*, int, int);
void liberarMatriz(Matriz*&, int);


int main(){
	int tam = 5;
	int alto = 0, ancho = 0;
	int opc = 0, opc2 = 0;
	int alto2 = 0, ancho2 = 0;
	
	int numeromulti;
	Matriz* matriz;
	Matriz* matriz2;
	string operacion;
	bool booleano;
	vector <string> bitacora;
	vector <bool> exito;
	
	do{
		switch(opc=menu()){
			case 1:
				switch(opc2=menu2()){
					case 1:
						matriz=new Matriz();
						matriz->printMatriz(matriz,tam);
						break;
						
					case 2:
						cout<<"Ingrese el alto: "<<endl;
						cin>>alto;
						cout<<"Ingrese el ancho: "<<endl;
						cin>>ancho;
						matriz=new Matriz(alto, ancho);
						matriz->printMatrizPersonalizada(matriz,alto,ancho);
						break;
				}
				break;
				
			case 2:
				//suma
				operacion="suma";
				cout<<"Ingrese el alto: "<<endl;
				cin>>alto2;
				cout<<"Ingrese el ancho: "<<endl;
				cin>>ancho2;
				matriz2=new Matriz(alto2, ancho2);
				matriz2->printMatrizPersonalizada(matriz2,alto2,ancho2);
				cout<<"Resultado"<<endl;
				//matriz->Suma(matriz2);
				if(matriz->Suma(matriz2)){
					booleano = true;
				}
				else{
					booleano = false;
				}
				bitacora.push_back(operacion);
				exito.push_back(booleano);
				operacion="";
				break;
				
			case 3:
				//resta
				operacion="resta";
				cout<<"Ingrese el alto: "<<endl;
				cin>>alto2;
				cout<<"Ingrese el ancho: "<<endl;
				cin>>ancho2;
				matriz2=new Matriz(alto2, ancho2);
				matriz2->printMatrizPersonalizada(matriz2,alto2,ancho2);
				cout<<"Resultado"<<endl;
				//matriz->Resta(matriz2);
				if(matriz->Resta(matriz2)){
					booleano = true;
				}
				else{
					booleano = false;
				}
				bitacora.push_back(operacion);
				exito.push_back(booleano);
				operacion="";
				break;
				
			case 4:
				//multiplicacion
				operacion="multiplicacion";
				cout<<"Ingrese el numero a multiplicar: "<<endl;
				cin>>numeromulti;
				cout<<"Resultado"<<endl;
				matriz->Multiplicacion(numeromulti);
				booleano = true;
				bitacora.push_back(operacion);
				exito.push_back(booleano);
				operacion="";
				break;
				
			case 5:
				for(int i=0; i<bitacora.size(); i++){
					cout<<bitacora[i];
					cout<<" = ";
					//cout<<exito[i]<<endl;
					if(exito[i]==true){
						cout<<"exito"<<endl;
					}
					else{
						cout<<"fallido"<<endl;
					}
				}
				break;
				
			case 6:
				cout<<"Saliendo"<<endl;
				bitacora.clear();
				exito.clear();
				break;
		}
	}while(opc!=6);
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Crear Matriz"<<endl
			<<"2.-Suma de Matriz"<<endl
			<<"3.-Resta de Matriz"<<endl
			<<"4.-Multiplicacion de Matriz"<<endl
			<<"5.-Bitacora"<<endl
			<<"6.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=6){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menu2(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-5x5"<<endl
			<<"2.-Personalizada"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=2){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}


void liberarMatriz(int**& matrix, int size){
        for(int i=0;i<size;i++){
                if (matrix[i]!=NULL){
                         delete[]matrix[i];
                        matrix[i]=NULL;
                }
        }

        if(matrix!=NULL){
                delete[] matrix;
                matrix=NULL;
        }
}



