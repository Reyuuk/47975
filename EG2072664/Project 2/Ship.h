//Written by Edgar Gonzalez
//on 12/8/13
//for CIS17A - 47975

//Class Specification and implementation for Ship class

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

using namespace std;

class Ship
{
private:
    string shipName;
    int shipSize;

public:
	//Default Constructor
	Ship() {shipName = "NULL"; shipSize = 0;}
	//Constructors
    Ship(string n) {shipName = n;}
    Ship(string n, int l) {shipName = n; setLength(l, 10, 10);}

     //Destructor
	virtual ~Ship() {;}

	//Accessors
    string getName() const {return shipName;}
    int getLength() const {return shipSize;}
    virtual int getHitpoints() const =0;
	
	//Mutators
    virtual void setShipName(string n) {shipName = n;}
    virtual void setLength(int, int, int);
    virtual void setHitpoints(int, int, int)=0;

};

void Ship::setLength(int len, int w, int h){
	//prevent making of ships of size 0 or greater than the length/width of the board
	if(len < 2 || (len > w && len > h))
		throw "Invalid Length.";
	shipSize = len;
}

#endif