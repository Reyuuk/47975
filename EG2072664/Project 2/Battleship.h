#include "Ship.h"

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class Battleship : public Ship
{
private:
    int hitpoints;		//keeps track of hitpoints of the ship
	char identifier;	//identifier used to display on the gameboard

public:
	//Default Constructor
	Battleship() : Ship() {hitpoints = 0; identifier = 0;}

	//Constructors
	Battleship(string name) : Ship(name) {hitpoints=0; identifier = name.at(0);}
	Battleship(string name, int length) : Ship(name, length) {setHitpoints(length, 10, 10); identifier = name.at(0);}
	
	//Destructor
	virtual ~Battleship() {;}

	//Accessors
    virtual int getHitpoints() const {return hitpoints;}
	char getIdentifier() const {return identifier;}
	
	//Mutators
    virtual void setHitpoints(int, int, int);
	virtual void setLength(int, int, int);
	virtual void setShipName(string n);
	void setIdentifier(char i) {identifier = i;}

	//Overloaded operators
	Battleship &operator=(const Battleship &);
	Battleship &operator--();
	Battleship &operator--(int);
};

Battleship &Battleship::operator=(const Battleship &ship){
	setShipName(ship.getName());
	setLength(ship.getLength(), 10, 10);
	setHitpoints(ship.getHitpoints(), 10, 10);
	return *this;
}

Battleship &Battleship::operator--(){
	--hitpoints;
	return *this;
}

Battleship &Battleship::operator--(int){
	//Battleship temp(this->getName(), this->hitpoints);
	hitpoints--;
	return *this;
}

//Overridden setShipName function. Also sets identifier to first letter of name string.
void Battleship::setShipName(string n){
	Ship::setShipName(n);
	identifier = n.at(0);
}

//Sets hitpoints 
void Battleship::setHitpoints(int h, int brdW, int brdH){
	if(h < 1 || h > getLength() || h > brdW || h > brdH)
		throw "Invalid Hit Points.";
	else hitpoints = h;
}

//Overridden setLength function from Ship class. Sets the length and initializes hitpoints
//This function checks against the board parameters and 
//throws an exception if the ship is size 0 or too big for the board
void Battleship::setLength(int len, int w, int h){
	if(len < 2 || (len > w && len > h))
		throw "Invalid length.";
	else {
		hitpoints = len;
		Ship::setLength(len, w, h);
	}

}



#endif