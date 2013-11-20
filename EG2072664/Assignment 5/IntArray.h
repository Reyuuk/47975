//Specification for the Month class

#ifndef INTARRAY_H
#define INTARRAY_H


class IntArray
{
  
private:
    int *aptr;
    int arraySize;
  
public:
	//Constructors
    IntArray(int);
	IntArray(const IntArray &);
	~IntArray();

	//Mutators
	
	//Accessors
	int size() const {return arraySize;}    

	//Overloaded operators
	int &operator[](const int &);}

;
  
#endif