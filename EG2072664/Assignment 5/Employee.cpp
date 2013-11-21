//implementation for Employee class
#include "Employee.h"

void Employee::setEmpNum(int n){
	if(n < 0 || n > 9999)
		throw "InvalidEmployeeNumber";
	empNum = n;
}