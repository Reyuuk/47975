//Written by Edgar Gonzalez
//On 11/23/13
//for CIS 17A - 47975

#include "SortableVector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(){

	int size=5;

	//cout << "Please enter an array size for your vector to be sorted" << endl;
	//cin >> size;

	SortableVector<int> uservect(size);
	//SortableVector<int> *uservect = new SortableVector<int>(size);

	cout << "Fill the array with elements." << endl;
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

	//delete[]uservect;
	system("PAUSE");
	return 0;
}

