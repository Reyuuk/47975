#include "Person.h"

void Person::setDOB(string d){

	int tempYear;	//temp holder for year
	int tempMonth;	//temp holder for month
	int tempDay;	//temp holder for day
	int first;		//first '/' separator in input
	int second;		//second '/' separator in input

	//get today's date in 3 integers
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int todayYear = now->tm_year + 1900;
    int todayMonth = now->tm_mon + 1;
    int todayDay = now->tm_mday;


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
		tempMonth = d[0]*10 + d[1];
	}
	else if(first==1){
		if(!isdigit(d[0]))
			throw "Improperly formatted date.";
		tempMonth = d[0];
	}
	else throw "Improperly formatted date.";

	//sets day based on digits found between first and second '/' separator
	if(second - first == 1){
		if(!isdigit(d[first+1]))
			throw "format";
		tempDay = d[first+1];
	}
	else if(second - first == 2){
		if(!isdigit(d[first+1]) || !isdigit(d[first+2]))
			throw "format";
		tempDay = d[first+1]*10 + d[first+2];
	}
	else throw "format";

	//sets year based on position of the second '/' separator
	if(d.size() == second+4){
		if(!isdigit(d[second+1]) || !isdigit(d[second+2]) || !isdigit(d[second+3]) || !isdigit(d[second+4]))
			throw "format";
		tempYear = d[second+1]*1000 + d[second+2]*100 + d[second+3]*10 + d[second+4];
	}
	else throw "format";


	//Check validity of month input
	if(tempMonth < 1 || tempMonth > 12)
		throw "Month out of range.";

	//Check validity of day input, based on month
	if(tempMonth==1 || tempMonth==3 || tempMonth==5 || tempMonth==7 || tempMonth==8 || tempMonth==10 || tempMonth==12){
		if(tempDay < 1 || tempDay > 31)
			throw "Day out of range for the month.";
	}
	else if(tempMonth==4 || tempMonth==6 || tempMonth==9 || tempMonth==11){
		if(tempDay < 1 || tempDay > 30)
			throw "Day out of range for the month.";
	}
	//Below is a leap year test for February.
	else if(tempYear%400 == 0)
		if(tempDay < 1 || tempDay > 29)
			throw "Day out of range for the month.";
	else if(tempYear%100 == 0)
		if(tempDay < 1 || tempDay > 28)
			throw "Day out of range for the month.";
	else if(tempYear%4 == 0)
		if(tempDay < 1 || tempDay > 29)
			throw "Day out of range for the month.";
	else
		if(tempDay < 1 || tempDay > 28)
			throw "Day out of range for the month.";

	//check validity of year input
	if(tempYear < 1900 || tempYear > todayYear)
		throw "Year out of range.";
	
	if(tempYear >= todayYear){
		if(tempMonth >= todayMonth)
			if(tempDay >= todayDay)
				throw "Date of birth out of range";
	}

	dob.day = tempDay;
	dob.month = tempMonth;
	dob.year = tempYear;
}

string Person::getDOB() const{
	stringstream ss;
	ss << dob.month << '/' << dob.day << '/' << dob.year;
	return ss.str();
}

void Person::setSSN(string s){
	if(s.size()==12){
		if(!isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[2]) || !isdigit(s[4]) || !isdigit(s[5]) || !isdigit(s[7]) || !isdigit(s[8]) || !isdigit(s[9]) || !isdigit(s[10]))
			throw "Invalid SSN";
		else ssn = s;
	}
	else if(s.size()==10){
		if(!isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[2]) || !isdigit(s[3]) || !isdigit(s[4]) || !isdigit(s[5]) || !isdigit(s[6]) || !isdigit(s[7]) || !isdigit(s[8]))
			throw "Invalid SSN";
		else ssn = s;
	}
	else throw "Invalid SSN";
}