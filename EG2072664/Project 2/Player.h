#include "Battleship.h"

#ifndef PLAYER_H
#define PLAYER_H

#include <iomanip>

template <class T>
class Player
{
private:
    Battleship *ships;	//array of ships used in the game
	int numShips;		//number of ships on the board - check if ship sizes are too much for the board
	T **board;			//pointer to the board array
	int boardW;			//width of the board
	int boardH;			//height of the board

	void createBoard();

public:
	//Default Constructor - standard size game
	Player();

	//Constructors for unique size games
	Player(int num);
	Player(int width, int height); 
	Player(int width, int height, int num);

	//Destructor
    virtual ~Player();

	//Accessors
	int getBoardW() {return boardW;}
	int getBoardH() {return boardH;}
	void displayBoard();
	void displayHiddenBoard();
	int getShipNum() const {return numShips;}
	int getShipHitpoints(int) const;

	//Mutators
	bool placeShip(int &, int &, char, int);
	void attackPoint(int &, int &);

	//Overloaded constructors
	//overload[] for ship
	//T &operator[](const int &);

	//overload = operator to set hitpoints?
	//T &operator== (const int &);
};


//This is the default constructor for a standard size game, with the standard ships
template <class T>
Player<T>::Player(){

	//The standard game size paramaters
	boardW = 10;
	boardH = 10;
	numShips = 5;
	ships = new Battleship[numShips];

	//Initialize ships
	ships[0].setShipName("Carrier");
	ships[0].setLength(5, boardW, boardH);
	ships[0].setHitpoints(1, boardW, boardH);

	ships[1].setShipName("Battleship");
	ships[1].setLength(4, boardW, boardH);
	ships[1].setHitpoints(4, boardW, boardH);

	ships[2].setShipName("Destroyer");
	ships[2].setLength(3, boardW, boardH);
	ships[2].setHitpoints(3, boardW, boardH);

	ships[3].setShipName("Submarine");
	ships[3].setLength(3, boardW, boardH);
	ships[3].setHitpoints(3, boardW, boardH);

	ships[4].setShipName("Patrolboat");
	ships[4].setLength(2, boardW, boardH);
	ships[4].setHitpoints(2, boardW, boardH);

	createBoard();
}


//initialize game with a nonstandard number of ships - TODO validate size
template <class T>
Player<T>::Player(int num){
	
	boardW = 10;
	boardH = 10;
	numShips = num;
	ships = new Battleship[numShips];

	string name;
	int size;

	//Initialize ships
	for(int i=0; i<numShips; i++){
		cout << endl << "Ship name: ";
		cin >> name;
		ships[i].setShipName(name);
		cout << endl << "Ships length: ";
		cin >> size;
		ships[i].setLength(size, boardW, boardH);
	}

	createBoard();
}


//Initialize game with nonstandard board size
template <class T>
Player<T>::Player(int width, int height){

	//The standard game size paramaters
	boardW = width;
	boardH = height;
	numShips = 5;
	ships = new Battleship[numShips];

	//Initialize ships
	ships[0].setShipName("Carrier");
	ships[0].setLength(5, boardW, boardH);
	ships[0].setHitpoints(1, boardW, boardH);

	ships[1].setShipName("Battleship");
	ships[1].setLength(4, boardW, boardH);
	ships[1].setHitpoints(4, boardW, boardH);

	ships[2].setShipName("Destroyer");
	ships[2].setLength(3, boardW, boardH);
	ships[2].setHitpoints(3, boardW, boardH);

	ships[3].setShipName("Submarine");
	ships[3].setLength(3, boardW, boardH);
	ships[3].setHitpoints(3, boardW, boardH);

	ships[4].setShipName("Patrolboat");
	ships[4].setLength(2, boardW, boardH);
	ships[4].setHitpoints(2, boardW, boardH);

	createBoard();
}


//initialize game with a nonstandard number of ships and board size
template <class T>
Player<T>::Player(int num, int width, int height){
	
	boardW = width;
	boardH = height;
	numShips = num;
	ships = new Battleship[numShips];

	string name;
	int size;

	//Initialize ships
	for(int i=0; i<numShips; i++){
		cout << endl << "Ship name: ";
		cin >> name;
		ships[i].setShipName(name);
		cout << endl << "Ships length: ";
		cin >> size;
		ships[i].setLength(size, boardW, boardH);
	}

	createBoard();
}


//Destructor deletes allocated board array and ships array
template <class T>
Player<T>::~Player(){
	for(int i=0; i<boardW; i++){
		delete board[i];
	}
	delete []board;
	delete []ships;
}


//initializes a 2D array for board and sets the elements to water
template <class T>
void Player<T>::createBoard(){
    //allocate 2D array for the board
    T **temp = new T*[boardW];
	for(int i=0; i<boardW; i++){
		temp[i] = new T[boardH];
	}
    
    //initialize all elements to water
    for(int i=0; i<boardW; i++){
        for(int j=0; j<boardH; j++){
            temp[i][j] = 0;
        }
    }
    
    //sets the board to the new array
    board = temp;
}


//Displays own board showing all ships on the board.
template <class T>
void Player<T>::displayBoard(){
	char header=65;
	cout << "     ";
	for(int i=0; i<boardW; i++){
		cout << header << "   ";
	}
	cout << endl;
	cout << "   --";
	for(int i=0; i<boardW; i++){
		cout << "----";
	}
	cout << endl;


	for(int i=0; i<boardW; i++)
	{
		cout << setw(3) << i+1 << "| ";
		for(int j=0; j<boardH; j++)
		{
            //if the spot is water, display nothing
            if(board[i][j] == 0)
            {
                cout << "  | ";
            }
			else if(board[i][j] == 1)
			{
				cout << "O | ";
			}
			else if(board[i][j] == 2)
			{
				cout << "X | ";
			}
            else if(board[i][j] == 3)
            {
                cout << ships[0].getIdentifier() << " | ";
            }
            else if(board[i][j] == 4)
            {
                cout << ships[1].getIdentifier() << " | ";
            }
            else if(board[i][j] == 5)
            {
                cout << ships[2].getIdentifier() << " | ";
            }
            else if(board[i][j] == 6)
            {
                cout << ships[3].getIdentifier() << " | ";
            }
            else
            {
                cout << ships[4].getIdentifier() << " | ";
            }
        }
	cout << "   --";
	for(int i=0; i<boardW; i++){
		cout << "----";
	}
	cout << endl;
    }

}


//Displays the board for the enemy, hiding the ships
template <class T>
void Player<T>::displayHiddenBoard(){
	char header=65;
	cout << "     ";
	for(int i=0; i<boardW; i++){
		cout << header << "   ";
	}
	cout << endl;
	cout << "   --";
	for(int i=0; i<boardW; i++){
		cout << "----";
	}
	cout << endl;

    for(int i=0; i<boardW; i++)
    {
		cout << setw(3) << i+1 << "| ";
        for(int j=0; j<boardH; j++)
        {
            //if the spot is a hit_ship, display the hit
            if(board[i][j] == 1)
            {
                cout << "O | ";
            }
			//if we previously shot but missed, display an X
			else if(board[i][j] == 2)
			{
				cout << "X | ";
			}
            //for anything else, display only water
            else
            {
                cout << "  | ";
            }
        }
	cout << "   --";
	for(int i=0; i<boardW; i++){
		cout << "----";
	}
	cout << endl;
    }
}


//Places ship on the board. input is a direction, (x,y) coordinates, and the shipnumber
//returns bool: false if the placement was unsuccessful due to hitting the edge of the board
//also returns false if the ship intersects with another
template <class T>
bool Player<T>::placeShip(int &x, int &y, char dir, int shipnum){

	//test if the ship fits on the grid on it's current placement
	if(dir == 'V' && y > (boardH - ships[shipnum].getLength())){
		return false;
	}
	else if(dir == 'H' && x > (boardW - ships[shipnum].getLength())){
		return false;
	}

	//test if the ship will collide with another ship already on the grid
	for(int i=0; i<ships[shipnum].getLength(); i++)
	{
		if(dir == 'H')
		{
			if(board[y][x+i] != 0)
				return false;
		}
		if(dir == 'V')
		{
			if(board[y+i][x] != 0)
				return false;
		}
	}

	//set the position on the board
	for(int i=0; i<ships[shipnum].getLength(); i++)
	{
		if(dir == 'H')
		{
			board[y][x+i] = shipnum+3;
		}
		if(dir == 'V')
		{
			board[y+i][x] = shipnum+3;
		}
	}

	return true;
}

//Attacks a point on the map, changes the board and
template <class T>
void Player<T>::attackPoint(int &x, int &y){

	if(board[y][x]< 2)
	{
		board[y][x] = 1;
		cout << "Miss!" << endl << endl;
	}
	else if(board[y][x]> 2)
	{
		T currship = board[y][x] - 3;
		board[y][x] = 2;
		ships[currship]--;
		if(ships[currship].getHitpoints() == 0)
			cout << "Enemy " << ships[currship].getName() << " sunk!" << endl << endl;
		else cout << "Hit!" << endl << endl;
	}

}

//gets the hitpoints for a ship
template <class T>
int Player<T>::getShipHitpoints(int ship) const{
	return ships[ship].getHitpoints();
}



#endif