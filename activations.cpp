#include "activations.h"
#include <cmath>

double c_exp(double x){

       double result = 1.0;   double term = 1.0;
	   for (int i= 1; i <= 7; i++) {
	        
		   term *= x/i;
		   result += term;
	   }
	   return result;
}

Vector Sigmoid::activate(const Vector& x){

       Vector res(x.getSize() ); 
	   for( int i=0; i< x.getSize(); i++){
	   
	        res[i] = 1.0 / (1.0 + c_exp(-x[i]) );
	   }
       return res; 

}

Vector Relu::activate(const Vector& x){

       Vector res(x.getSize() );
	    for( int i=0; i< x.getSize(); i++){
	   
	        res[i] = ( x[i] > 0 ) ? x[i] : 0; 
	   }
       return res; 
 
}

Vector Softmax::activate(const Vector& x){ 

       Vector res(x.getSize() );
	   double max_val = x[0];
	
	    for( int i=0; i< x.getSize(); i++){
	      
			if ( x[i] > max_val ) max_val = x[i]; 
      	}
	
	   double sum = 0.0;
	   for (int i =0; i< x.getSize(); i++) {
	   
	        res[i] = c_exp(x[i] - max_val); 
		    sum+= res[i];
	   }
	
	   for( int i=0; i< x.getSize(); i++){
	      
			res[i] /= sum; 
	        
	   }return res; 
	
 
}

