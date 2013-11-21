//Implementation file for ProductionWorker Class
#include "ProductionWorker.h"

void ProductionWorker::setShift(int s){
	if(s!=1 && s!=2)
		throw "InvalidShift";
	shift = s;
}

void ProductionWorker::setPayRate(double r){
	if (s < 0)
		throw "InvalidPayRate";
	if(r < 7.50){
		payRate = 7.50;
	}
	else payRate = r;
}

