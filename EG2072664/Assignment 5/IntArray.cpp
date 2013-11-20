//Implementation of Month class
#include "IntArray.h"

#include <iostream>
#include <cstdlib>
using namespace std;

//constructor - sets the size of the array and allocates memory
IntArray::IntArray(int s){
	arraySize = s;
	aptr = new int [s];
	for(int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//copy constructor for the IntArray class
IntArray::IntArray(const IntArray &obj){
	arraySize = obj.arraySize;
	aptr = new int [arraySize];
	for(int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

//destructor for IntArray class
IntArray::~IntArray(){
	if(arraySize > 0)
		delete [] aptr;
}



//Overloaded [] operator. Argument is a subscript.
//This function returns a reference to the element in the array indexed by the subscript.
int &IntArray::operator [](const int &sub){
	if(sub < 0 || sub >= arraySize)
		throw "Subscript out of range.";
	return aptr[sub];
}
