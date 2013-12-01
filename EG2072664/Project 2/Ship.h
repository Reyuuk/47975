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
	if(l < 0 || l > 5)
		throw "Invalid Length.";
	else ShipSize = len;
}
#endif