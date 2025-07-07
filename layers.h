#ifndef LAYERS_H
#define LAYERS_H

#include "vectorNN.h"
#include "activations.h"

class Neurona{

public: 
	  
	  Vector weights; double bias; double output;
	
	  Neurona(int n_inputs);
	  double calculus(const Vector& inputs);

};


class Capa{

protected:
	
	   Neurona** neuronas;
	   int n_neuronas; 
	   Activation* activation; 
public:
	   Capa(int n_neuronas, int n_inputs, Activation* activationFunc);
	   virtual ~Capa();

       Vector forward(const Vector& inputs);

};

#endif