#include "vectorNN.h"

Vector::Vector(int n) : size(n) {  data = new double[n](); }

Vector::Vector(const Vector&otro ) : size(otro.size) {

       data = new double[size];
	   for( int i = 0; i < size; i++) {  data[i] = otro.data[i];   }
}

Vector::~Vector(){
       
	   delete[] data; 
}

double& Vector::operator[](int index){

       return data[index];
}

const double& Vector::operator[](int index) const { 
        
	   return data[index];
}

int Vector::getSize()const{  return size; }

Vector& Vector::operator=(const Vector& otro) {

       if (this != &otro) {
	        
		   delete[] data; 
		   size = otro.size;
		   data = new double[size];
		   
		   for (int i=0; i<size; i++) {
		        
			    data[i] = otro.data[i];
		   }
	   }
	   return *this;
}