#include "nn.h"

NeuronalNetwork::NeuronalNetwork( int input_size) : input_size(input_size), layers(nullptr), n_layers(0) {}

NeuronalNetwork::~NeuronalNetwork(){
  
       for(int i=0; i < n_layers; i++) {
	   
	       delete layers[i];
	   }
       delete[] layers; 

}

void NeuronalNetwork::addLayer(Capa* layer) {

       Capa** new_l = new Capa*[n_layers + 1 ];
	   for (int i=0; i<n_layers; i++) {
	   
	        new_l[i] = layers[i]; 
	   }
       new_l[n_layers] = layer;
	
	   delete[] layers; 
	   layers = new_l;
	   n_layers++;

}

Vector NeuronalNetwork::predict(const Vector& inputs) {

       Vector x_Output = inputs; 
	   for(int i=0; i < n_layers; i++){
	     
	       x_Output = layers[i]->forward(x_Output);
	   }
	
       return x_Output;
}