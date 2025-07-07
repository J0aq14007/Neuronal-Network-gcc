#include <iostream>
#include <cstdlib>
#include "nn.h"
#include "io.h"
using namespace std;

int main(){

    srand(42);
    NeuronalNetwork red(1); 
	
	while(true) {
	
	       cout<< "\n RED NEURONAL \n";
		   cout<< "1. Configurar Red Neuronal\n";
		   cout<< "2. Ejecutar Red con entradas\n";
		   cout<< "3. Salir\n";
		   cout<< "Seleccion: ";
		    
		   int opcion; cin>> opcion; 
		
		   switch(opcion){
		      
			   case 1: 
				   
				     Input_Output(red); break; 
			   case 2:
				     
				   if(red.n_layers==0){
				   
				      cout<<"Primero configure la red neuronal\n";
				   }
				   else{
				   
				      Ejecucion_IO(red); 
				   }break;
			
			   case 3: 
				   return 0; 
				   
			   default: 
				   
				   cout<<"Opcion no valida\n";
		   }
	
	}



}