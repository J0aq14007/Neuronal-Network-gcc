#ifndef VECTORNN_H
#define VECTORNN_H

class Vector {
  
private: 
	
	double* data; int size;
	
public:
	
    Vector(int n);
	Vector (const Vector& otro);
	
	~Vector();
	
	double& operator [](int index);
	const double& operator[](int index) const;
	int getSize() const;
	Vector& operator=(const Vector& otro);
};


#endif