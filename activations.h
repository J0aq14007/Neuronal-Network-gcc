#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

#include "vectorNN.h"

class Activation{
public: 
	 
	  virtual Vector activate(const Vector& x) = 0;
	  virtual ~Activation() =default; 


};

class Sigmoid: public Activation {
public:
	 
	  Vector activate(const Vector&x) override;

};

class Relu  : public Activation{
public:
	 
	  Vector activate(const Vector&x) override;

};

class Softmax : public Activation {
public:
	 
	  Vector activate(const Vector&x) override;

};

#endif