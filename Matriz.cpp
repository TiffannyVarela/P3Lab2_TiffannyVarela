#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

#ifndef MATRIZ_CPP
#define MATRIZ_CPP

class Matriz{
	private:
		int** matriz = NULL;
		int ancho, alto;
	
	public:
		
		int** provisionarMatriz(int size){
	        int** matriz = new int* [size];
	        for(int i=0; i<size; i++){
	                matriz[i]=new int[size];
	        }
	        return matriz;
		}

		int** readMatriz(int** matriz, int size){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					matriz[i][j] = (1+rand()%50);
				}
			}
			return matriz;
		}
		
		int** provisionarMatrizPersonalizada(int alto, int ancho){
	        int** matriz = new int* [alto];
	        for(int i=0; i<alto; i++){
	                matriz[i]=new int[ancho];
	                for(int j=0; j<ancho; j++){
	                	matriz[i][j]=0;
					}
	        }
	        return matriz;
		}

		int** readMatrizPersonalizada(int** matriz, int alto, int ancho){
			int val;
			for(int i=0;i<alto;i++){
				for(int j=0;j<ancho;j++){
					matriz[i][j] = (1+rand()%50);
				}
			}
			return matriz;
		}
		
		
		Matriz(){
			alto =5;
			ancho =5;
			matriz=provisionarMatriz(alto);
			readMatriz(matriz,alto);
		}
		
		Matriz(int alto, int ancho){
			this->alto=alto;
			this->ancho=ancho;
			matriz = provisionarMatrizPersonalizada(alto, ancho);
			readMatrizPersonalizada(matriz, alto, ancho);
		}
		
		int getAncho(){
			return ancho;
		}
		
		int getAlto(){
			return alto;
		}
		
		int** getMatriz(){
			return matriz;
		}
		
		void setAncho(int ancho){
			ancho=ancho;
		}
		
		void setAlto(int alto){
			alto=alto;
		}
		
		void setMatriz(int** matriz){
			matriz=matriz;
		}
		
		void printMatriz(Matriz* matriz, int size){
		    for(int i=0;i<size;i++){
		        for(int j=0;j<size;j++){
		            cout<<"["<<matriz->getMatriz()[i][j]<<"]";
		        }
		        cout<<endl;
		    }
		}

		void printMatrizPersonalizada(Matriz* matriz, int alto, int ancho){
		    for(int i=0;i<alto;i++){
		        for(int j=0;j<ancho;j++)
		            cout<<"["<<matriz->getMatriz()[i][j]<<"]";
		            cout<<endl;
		        }
		}
		
		void imprimirMatrizPersonalizada(int** matriz, int alto, int ancho){
		    for(int i=0;i<alto;i++){
		        for(int j=0;j<ancho;j++)
		            cout<<"["<<matriz[i][j]<<"]";
		            cout<<endl;
		        }
		}
		
		bool Suma(Matriz* matriz2){
			int alto2 = matriz2->getAlto() , ancho2 = matriz2->getAncho();
			bool result = false;
			if(alto==alto2 && ancho==ancho2){
				result =true;
				for(int i=0; i<alto; i++){
					for(int j=0; j<ancho; j++){
						matriz[i][j]=matriz[i][j]+matriz2->getMatriz()[i][j];
					}
				}
				imprimirMatrizPersonalizada(matriz,alto,ancho);
			}
			else{
				result=false;
			}
			
			return result;
		}
		
		bool Resta(Matriz* matriz2){
			int alto2 = matriz2->getAlto() , ancho2 = matriz2->getAncho();
			bool result = false;
			if(alto==alto2 && ancho==ancho2){
				result =true;
				for(int i=0; i<alto; i++){
					for(int j=0; j<ancho; j++){
						matriz[i][j]=matriz[i][j]-matriz2->getMatriz()[i][j];
					}
				}
				imprimirMatrizPersonalizada(matriz,alto,ancho);
			}
			else{
				result=false;
			}
			return result;
		}
		
		void Multiplicacion(int num){
			for(int i=0; i<alto; i++){
				for(int j=0; j<ancho;j++){
					matriz[i][j]=matriz[i][j]*num;
				}
			}
			imprimirMatrizPersonalizada(matriz, alto, ancho);
		}
		
		void Liberar(int**& matriz, int alto){
			for(int i=0; i<alto; i++){
				delete[] matriz[i];
			}
			delete[] matriz;
		}
		
		void Liberar(){
			for(int i=0; i<alto; i++){
				delete[] matriz[i];
			}
			delete[] matriz;
		}
		
		~Matriz(){
		}
		
};

#endif

