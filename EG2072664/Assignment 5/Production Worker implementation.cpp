//Written by Edgar Gonzalez
//on 11/10/13
//For CIS 17A - 47975

#include <iostream>
#include "ProductionWorker.h"

using namespace std;

//global constants

//function prototypes

int main()
{
	ProductionWorker worker1;
	
	int number;
	string input;
	double pay;

	cout << "Please enter employee data below." << endl;
	cout << "Name: ";
	getline(cin, input);
	worker1.setName(input);

	cout << "Employee Number: ";
	cin >> number;
	worker1.setEmpNum(number);
	cin.sync();

	cout << "Hire Date: ";
	getline(cin, input);
	worker1.setHireDate(input);

	cout << "Day shift or night shift?[D/N]: ";
	getline(cin, input);
	while(input[0] !='D' && input[0] !='N'){
		cout << "Invalid input! Try again: ";
		cin.clear();
		cin.sync();
		getline(cin, input);
	}
	if(input[0]=='D')
		worker1.setShift(1);
	else worker1.setShift(2);

	cout << "Hourly pay rate: $";
	cin >> pay;
	try	worker1.setPayRate(pay);
	catch(char *exceptionString){
		cout << exceptionString;
	}

	cout << endl << endl;

	cout << "The employee's data is below." << endl;
	cout << "Name: " << worker1.getNam() << endl;
	cout << "Employee Number: " << worker1.getEmpNumber() << endl;
	cout << "Hire Date: " << worker1.getHireDate() << endl;
	cout << "Shift: ";
	if(worker1.getShift() ==1)
		cout << "Day" << endl;
	else cout << "Night" << endl;
	cout << "Hourly pay rate: $" << worker1.getPayRate() << endl;

	system("PAUSE");
	return 0;
}
