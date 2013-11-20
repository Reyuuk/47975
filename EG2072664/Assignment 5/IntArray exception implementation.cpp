//Written by Edgar Gonzalez
//on 11/3/13
//For CIS 17A - 47975

#include <iostream>
#include "IntArray.h"

using namespace std;

//global constants

//function prototypes

int main()
{
	const int SIZE = 10;
	int subscript=0;

	//define int array with 10 elements
	IntArray table(SIZE);

	cout << "Building an array of " << SIZE << " integers." << endl;
	//Store values in the array
	for(int x=0; x < SIZE; x++)
		table[x] = (x*2);

	cout << "The values are..." << endl;
	//display the values stored in the array.
	for(int x=0; x < SIZE; x++)
		cout << table[x] << " ";
	cout << endl;

	try{
		cout << "Input a subscript: ";
		cin >> subscript;
		cout << "The value is " << table[subscript];
	}
	catch(char *exceptionString){
		cout << exceptionString;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
