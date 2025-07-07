#ifndef NEURONAL_NETWORK_H
#define NEURONAL_NETWORK_H

#include "vectorNN.h"
#include "layers.h"

class NeuronalNetwork{
public:
	
	  int input_size; 
      Capa** layers;
      int n_layers;


      NeuronalNetwork(int input_size);
	  ~NeuronalNetwork();
	  
	  void addLayer(Capa*layer);
	  Vector predict(const Vector& inputs);
};

#endif