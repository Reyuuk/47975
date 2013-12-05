#include "Ship.h"

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class Battleship : public Ship
{
private:
    int hitpoints;

public:
	//Default Constructor
	Battleship() : Ship() {hitpoints = 0;}

	//Constructors
	Battleship(string name) : Ship(name) {hitpoints=0;}
	Battleship(string name, int length) : Ship(name, length) {setHitpoints(length);}

	//Destructor
	~Battleship() {;}

	//Accessors
    virtual int getHitpoints() const {return hitpoints;}
	
	//Mutators
    virtual void setHitpoints(int);

	//Overloaded operators
	Battleship &operator=(const Battleship &);
	Battleship &operator--();
	Battleship operator--(int);
};

Battleship &Battleship::operator=(const Battleship &ship){
	setShipName(ship.getName());
	setLength(ship.getLength());
	setHitpoints(ship.getHitpoints());
	return *this;
}

Battleship &Battleship::operator--(){
	--hitpoints;
	return *this;
}

Battleship Battleship::operator--(int){
	Battleship temp(getName(), hitpoints);
	hitpoints--;
	return temp;
}
void Battleship::setHitpoints(int h){
	if(h < 0 || h > getLength())
		throw "Invalid Hit Points for battleship.";
	else hitpoints = h;
}



#endif