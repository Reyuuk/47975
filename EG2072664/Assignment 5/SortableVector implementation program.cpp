//Written by Edgar Gonzalez
//On 11/23/13
//for CIS 17A - 47975

#include "SortableVector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(){

	int size;

	cout << "Please enter an array size for your vector to be sorted." << endl;
	cin >> size;

	SortableVector<int> uservect(size);

	cout << "Fill the array with elements(integers)." << endl;
	for(int i=0; i < size; i++){
		int element;
		cout << i << ": ";
		cin >> element;
		uservect[i] = element;
	}

	cout << "Now sorting elements." << endl;
	uservect.sort();

	cout << "Sorted elements..." << endl;
	for(int i=0; i < size; i++){
		cout << uservect.getElementAt(i) << endl;
	}

	cout << "Please enter an array size for your vector to be sorted." << endl;
	cin >> size;

	SortableVector<float> uservectfl(size);

	cout << "Fill the array with elements(floats)." << endl;
	for(int i=0; i < size; i++){
		float element;
		cout << i << ": ";
		cin >> element;
		uservectfl[i] = element;
	}

	cout << "Now sorting elements." << endl;
	uservectfl.sort();

	cout << "Sorted elements..." << endl;
	for(int i=0; i < size; i++){
		cout << uservectfl.getElementAt(i) << endl;
	}

	cout << endl << "End of program. ";
	system("PAUSE");
	return 0;
}

