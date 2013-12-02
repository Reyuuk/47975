//Person class template - class specification and implementation

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
};


class Person
{
private:
    string name;		//name
    string relationship;	//relationship to applicant - int to calculate?
	date dob;			//date of birth
	string ssn;			//social security number
	//char food;		//purchase and prepare food with the rest of the household
	//char citizen;		//US citizenship
	//T earnings;

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


