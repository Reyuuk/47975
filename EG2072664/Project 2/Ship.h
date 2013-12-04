//Ship class template - class specification and implementation

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
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
    Ship(string n, int l) {shipName = n; setLength(l);}

     //Destructor
    virtual ~Ship();

	//Accessors
    string getName() const {return shipName;}
    int getLength() const {return shipSize;}
    virtual int getHitpoints() = 0;
    virtual T *getShipPos() = 0;
	
	//Mutators
    void setShipName(string n) {shipName = n;}
    void setLength(int l);
    virtual void setHitpoints(int h) = 0;
    virtual void setPosition(T *pos) = 0;

};

template <class T>
void Ship<T>::setLength(int len){
	//prevent making of ships of size 0 or greater than the length/width of the board
	if(l < 0 || (l > getBoardH() && l > getBoardW()))
		throw "Invalid Length.";
	ShipSize = len;
}
#endif