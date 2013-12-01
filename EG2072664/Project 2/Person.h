//Person class template - class specification and implementation

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Person
{
private:
    string name;		//name
    int relationship;	//relationship to applicant
	int dob;			//date of birth
	string ssn;			//social security number
	//char food;			//purchase and prepare food with the rest of the household
	//char citizen;		//US citizenship
	//T earnings;
	bool leapYear(int year);	//used in setting and getting DOB

public:
	//Default Constructor
	Person() {name = "NULL"; relationship = 0; ssn = "No SSN"; dob = 0;}

	//Constructors
	Person(string n) {name = n;}
	Person(string n, string r) {name = n; setRelationship(r);}
	Person(string n, string r, string d)  {name = n; setRelationship(r); setDOB(d); ssn = "No SSN";}
	Person(string n, string r, string d, string s) {name = n; setRelationship(r); setDOB(d); setSSN(s);}
    
     //Destructor
    virtual ~Person();

	//Accessors
    string getName() const {return name;}
    string getRelationship() const;
	string getDOB() const;
	string getSSN() const {return ssn;}
	virtual char getFood() = 0;
	virtual char getCitizenship() = 0;
	
	//Mutators
    void setName(string n) {name = n;}
	void setRelationship(string r);
	void setDOB(string d);
	void setSSN(string s);
    virtual void setFood(char f) = 0;
	virtual void setCitizenship(char c) = 0;

};
#endif

bool Person::leapYear(int year){
	if (year%400 == 0)
		return true;
	else if(year%100 == 0)
		return false;
	else if(year%4 == 0)
		return true;
	else return false;
}


void setDOB(string d){

	//get today's date in 3 integers
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int todayYear = now->tm_year + 1900;
    int todayMonth = now->tm_mon + 1;
    int todayDay = now->tm_mday;


	int first = d.find('/');
	int second = d.find('\\');
	if(first==-1)
		first = d.find('\\');


	


	//This is the test for the full mm/dd/yyyy input
	if(d.size() == 10){
		//Check formatting digit by digit
		if(!isdigit(d[0]) || !isdigit(d[1]) || (d[2]!='/' && d[2]!='\\' ) || 
			!isdigit(d[3]) || !isdigit(d[4]) || (d[2]!='/' && d[2]!='\\' ) || 
			!isdigit(d[6]) || !isdigit(d[7]) || !isdigit(d[8]) || !isdigit(d[9])){
			throw "Improperly formatted date.";
		}

		//convert the input to integers
		int dobYear = d[6]*1000 + d[7]*100 + d[8]*10 + d[9];
		int dobMonth = d[0]*10 + d[1];
		int dobDay = d[3]*10 + d[4];


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
		else if(!leapYear(dobYear)){
			if(dobDay < 1 || dobDay > 28)
				throw "Day out of range for the month.";
		}
		else {
			if(dobDay < 1 || dobDay > 29)
				throw "Day out of range for the month.";
		}
	

		//check validity of year input
		if(dobYear < 1900 || dobYear > todayYear)
			throw "Year out of range.";

	}

	//this corresponds to m/dd/yyyy or mm/d/yyyy
	else if(d.size() == 9){

	}
	//this corresponds to m/d/yyyy
	else if(d.size() == 8){

	}
	else throw "Improperly formatted date: Too many or too few digits.";


}



string Person::getDOB() const{


}