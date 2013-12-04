#include "Ship.h"

template <class T>
class Battleship : public Ship
{
private:
    int hitpoint;
    T shipPosX;
	T shipPosY;

public:
	//Default Constructor
	Battleship() : Ship() {hitpoints = 0; shipPos = 0;}

	//Constructors
    Battleship(T *pos) {shipPos = pos;}
	Battleship(T *pos, int hit) {setPosition(pos); setHitpoints(hit);}

	//Destructor
    virtual ~Battleship(); //make sure this deletes Ship class and deletes shipPos

	//Accessors
    virtual int getHitpoints() const {return hitpoint;}
    virtual T *getShipPos() const {return *shipPos;}
	
	//Mutators
    virtual void setHitpoints(int);
    virtual void setPosition(T,T);

	//Overloaded constructors
    //overload = operator to set hitpoints?
	T &operator= (const int &);
};

void Battleship<T>::setHitpoints(int h){
	if(h < 0 || h > ship::getLength())
		throw "Invalid Hit Points for battleship.";
	else hitpoints = h;
}

template <class T>
void Battleship<T>::setPosition(T **board, T x, T y){
	




}


#endif