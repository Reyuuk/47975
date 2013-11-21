//Specification file for the Production worker class
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"
#include <string>
using namespace std;

class ProductionWorker : public Employee
{

private:
	int shift;		// 1 = dayshift, 2 = night shift
	double payRate;	// payrate, federal minimum is $10.00 hourly

public:
	//Constructors
	ProductionWorker() {shift= 1; payRate = 0.0;}
	ProductionWorker(int s, double rate) {setShift(s); setPayRate(rate);}

	//Mutators
	void setShift(int s);
	void setPayRate(double r);

	//Accessors
	int getShift() const {return shift;}
	double getPayRate() const {return payRate;}
};

#endif


