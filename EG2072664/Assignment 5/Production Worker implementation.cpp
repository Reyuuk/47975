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
	try{ worker1.setEmpNum(number); }
	catch(char *eString){
		cout << eString << endl;
	}
	cin.sync();

	cout << "Hire Date: ";
	getline(cin, input);
	worker1.setHireDate(input);

	cout << "First(Day) shift or Second(Night) shift?[1/2]: ";
	cin >> number;
	try	{worker1.setShift(number);}
	catch (char *eString){
		cout << eString << endl;
	}

	cout << "Hourly pay rate: $";
	cin >> pay;
	try	{worker1.setPayRate(pay);}
	catch(char *exceptionString){
		cout << exceptionString << endl;
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
