#include "Person.h"


bool Person::leapYear(int year){
	if (year%400 == 0)
		return true;
	else if(year%100 == 0)
		return false;
	else if(year%4 == 0)
		return true;
	else return false;
}


void Person::setDOB(string d){

	//get today's date in 3 integers
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int todayYear = now->tm_year + 1900;
    int todayMonth = now->tm_mon + 1;
    int todayDay = now->tm_mday;

	int dobYear;
	int dobMonth;
	int dobDay;
	int first;
	int second;

	//first and second are the places where '/' separator is found. Throws exception if both aren't found
	first = d.find('/');
	if(first==-1){
		first = d.find('\\');
		if (first ==-1)
			throw "Improperly formatted date.";
	}
	second = d.find('/', first+1);
	if(second==-1){
		second = d.find('\\');
		if (first ==-1)
			throw "Improperly formatted date.";
	}

	//Sets month based on position of first '/' separator.
	if (first==2){
		if(!isdigit(d[0]) || !isdigit(d[1]))
			throw "Improperly formatted date.";
		dobMonth = d[0]*10 + d[1];
	}
	else if(first==1){
		if(!isdigit(d[0]))
			throw "Improperly formatted date.";
		dobMonth = d[0];
	}
	else throw "Improperly formatted date.";

	//sets day based on digits found between first and second '/' separator
	if(second - first == 1){
		if(!isdigit(d[first+1]))
			throw "format";
		dobDay = d[first+1];
	}
	else if(second - first == 2){
		if(!isdigit(d[first+1]) || !isdigit(d[first+2]))
			throw "format";
		dobDay = d[first+1]*10 + d[first+2];
	}
	else throw "format";

	//sets year based on position of the second '/' separator
	if(d.size() == second+4){
		if(!isdigit(d[second+1]) || !isdigit(d[second+2]) || !isdigit(d[second+3]) || !isdigit(d[second+4]))
			throw "format";
		dobYear = d[second+1]*1000 + d[second+2]*100 + d[second+3]*10 + d[second+4];
	}
	else throw "format";


	//Check validity of month input
	if(dobMonth < 1 || dobMonth > 12)
		throw "Month out of range.";

	//Check validity of day input, based on month
	if(dobMonth==1 || dobMonth==3 || dobMonth==5 || dobMonth==7 || dobMonth==8 || dobMonth==10 || dobMonth==12){
		if(dobDay < 1 || dobDay > 31)
			throw "Day out of range for the month.";
	}
	else if(dobMonth==4 || dobMonth==6 || dobMonth==9 || dobMonth==11){
		if(dobDay < 1 || dobDay > 30)
			throw "Day out of range for the month.";
	}
	//Below is a leap year test for February.
	else if(dobYear%400 == 0)
		if(dobDay < 1 || dobDay > 29)
			throw "Day out of range for the month.";
	else if(dobYear%100 == 0)
		if(dobDay < 1 || dobDay > 28)
			throw "Day out of range for the month.";
	else if(dobYear%4 == 0)
		if(dobDay < 1 || dobDay > 29)
			throw "Day out of range for the month.";
	else
		if(dobDay < 1 || dobDay > 28)
			throw "Day out of range for the month.";

	//check validity of year input
	if(dobYear < 1900 || dobYear > todayYear)
		throw "Year out of range.";
	
	if(todayYear >= dobYear){
		if(todayMonth >= dobMonth)
			if(todayDay >= dobDay)
				throw "Date of birth must be in the passed.";
	}
	
}


string Person::getDOB() const{


}