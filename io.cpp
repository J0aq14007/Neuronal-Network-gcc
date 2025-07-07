#include "io.h"
#include <iostream>
using namespace std; 

void Input_Output(NeuronalNetwork& red){

     int input_size;
	 cout<<"Ingrese el numero de neuronas: ";
	 cin>>input_size;
	 
	 red = NeuronalNetwork(input_size);
	
	 int n_capas;
	 cout<<"Ingrese numero de capas ocultas a integrar: ";
	 cin>>n_capas;
	
	 int c_neuronas = input_size;
	 for(int i=0; i<n_capas; i++){
	 
	     int neuronas; 
		 cout<< "Neuronas en capa "<<i+1<<" :";
		 cin>>neuronas;
		 
		 
		 int tipo_act;
		 cout<<"Tipo de funcion de activacion (1 = Sigmoide, 2 = ReLU, 3 = Softmax): ";
		 cin>>tipo_act;
		 
		 Capa* nueva_capa = nullptr; 
		 switch(tipo_act){
		 
			 case 1: nueva_capa = new Capa(neuronas, c_neuronas, new Sigmoid()); break;
			 case 2: nueva_capa = new Capa(neuronas, c_neuronas, new Relu()); break;
			 case 3: nueva_capa = new Capa(neuronas, c_neuronas, new Softmax()); break;
			 default: nueva_capa = new Capa(neuronas, c_neuronas, new Sigmoid()); break;
		 }
	     
		 red.addLayer(nueva_capa);
		 c_neuronas = neuronas; 
	 
	 }
		 
}

void Ejecucion_IO(NeuronalNetwork& red) {

     Vector inputs(red.input_size);
	 
	 cout<<"\nIngrese los valores de entrada ( "<<red.input_size<<" valores): ";
	 for( int i=0; i< red.input_size; i++){
	      
		  cin>>inputs[i];
	 }
 
     Vector output = red.predict(inputs);
	
	 cout<<"\nSalida de la red: [";
	 for(int i=0; i<output.getSize(); i++){
	     
		 cout<<output[i];
		 if(i != output.getSize() - 1){ cout<<", "; }
			
	 }cout<<"]" <<endl;
			
}