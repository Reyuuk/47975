#include "Battleship.h"

template <class T>
class Player
{
private:
    Battleship *ships; 
	int numShips; //number of ships on the board - check if ship sizes are too much for the board
	T **board;	//pointer to the board array
	int boardW; //width of the board
	int boardH; //height of the board
	void initializeShips();

public:
	//Default Constructor - standard size game
	Player() {boardH=10; boardW=10; createBoard(); numShips = 5;}

	//Constructors for unique size games
	Player(int num) {boardW=10; boardH=10; numShips=num;}
	Player(T width, T height) {boardW=width; boardH=height; createBoard(); numShips = 5;}
	Player(T width, T height, int num) {boardW=width; boardH=height; createBoard(); numShips=num;}

	//Destructor
    virtual ~Player(); //make sure this deletes allocated data - ships and the 2d board

	//Accessors
	int getBoardW() {return boardW;}
	int getBoardH() {return boardH;}
	

	//Mutators


	//Overloaded constructors
	//overload[] for ship?
    //overload = operator to set hitpoints?
	T &operator= (const int &);
};

void Player::initializeShips(){
	ships = new Battleship[numShips];




	for(int i=0; i<numShips;i++){
		cout << "Please name your ship: ";
		cin >> 
		cout << "Please set the size of your ship: ";
		cin >> 
	}



}



void Battleship<T>::setHitpoints(int h){
	if(h < 0 || h > ship::getLength())
		throw "Invalid Hit Points for battleship.";
	else hitpoints = h;
}

template <class T>
void Battleship<T>::setPosition(T **board, T x, T y){
	




}

template <class T>
T Person::**create_board()
{
    //allocate 2d array for the board
    T **temp = new T*[boardW];
	for(int i=0; i<boardW; i++){
		temp[i] = new T[boardH];
	}
    
    //initialize all elements to water
    for(int i=0; i<boardW; i++){
        for(int j=0; j<boardH; j++){
            temp[i][j] = 0; //initialize depending on T?
        }
    }
    
    //returns a pointer to the player's board
    return temp;
}


#endif