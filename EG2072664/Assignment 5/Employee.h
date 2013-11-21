//Specification file for the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{

private:
	string name;
	int empNum;
	string hireDate;
public:
	//Constructors
	Employee() {name= "NULL"; empNum= 0; hireDate= "NULL";}
	Employee(string n, int num, int d) {name= n; empNum= num; hireDate= d;}

	//Mutators
	void setName(string n) {name = n;}
	void setEmpNum(int n);
	void setHireDate(string n) {hireDate = n;}

	//Accessors
	string getNam() const {return name;}
	int getEmpNumber() const {return empNum;}
	string getHireDate() const {return hireDate;}
};

#endif

