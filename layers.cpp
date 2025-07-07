#include "layers.h"
#include <cstdlib>

Neurona::Neurona(int n_inputs) : weights(n_inputs), bias(0), output(0) {
 
       for (int i=0; i<n_inputs; i++) {
	   
	        weights[i] = ((double)rand() / RAND_MAX) * 2 -1;
	   }
	   bias = ((double)rand() / RAND_MAX) * 2 -1;
  
}

double Neurona::calculus(const Vector& inputs) {

       double sum = 0;
	   for (int i =0; i < inputs.getSize(); i++){
	   
	        sum += weights[i] * inputs[i];
	   }
	   sum += bias; output = sum; return sum; 
}

Capa::Capa(int n_neuronas, int n_inputs, Activation* activationFunc):  n_neuronas(n_neuronas), activation(activationFunc){

       neuronas = new Neurona*[n_neuronas];
       for( int i = 0; i < n_neuronas; i++){
	        
		    neuronas[i] = new Neurona(n_inputs);
	   }
}

Capa::~Capa() {
 
	   for(int i=0; i<n_neuronas; i++){ delete neuronas[i]; }
       delete[] neuronas;  delete activation; 

}

Vector Capa::forward(const Vector& inputs){

       Vector sums(n_neuronas);
	   for(int i=0; i<n_neuronas; i++){
	      
		   sums[i] = neuronas[i]->calculus(inputs);
	   }
	   return activation->activate(sums); 
	
}
	


