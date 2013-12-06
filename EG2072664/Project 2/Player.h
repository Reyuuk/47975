#include "Battleship.h"

#ifndef PLAYER_H
#define PLAYER_H

#include <iomanip>

class Player
{
private:
    Battleship *ships; //array of ships used in the game
	int numShips; //number of ships on the board - check if ship sizes are too much for the board
	char **board;	//pointer to the board array
	int boardW; //width of the board
	int boardH; //height of the board

	void createBoard();

public:
	//Default Constructor - standard size game
	Player();

	//Constructors for unique size games
	Player(int num);
	Player(int width, int height); 
	Player(int width, int height, int num);

	//Destructor
    virtual ~Player(); //make sure this deletes allocated data - ships and the 2d board

	//Accessors
	int getBoardW() {return boardW;}
	int getBoardH() {return boardH;}
	void displayBoard();
	void displayHiddenBoard();

	//Mutators
	void placeShip();
	void attackPoint();

	//Overloaded constructors
	//overload[] for ship?
    //overload = operator to set hitpoints?
	T &operator= (const int &);
};

//This is the default constructor for a standard size game, with the standard ships
Player::Player(){

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
Player::Player(int num){
	
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
Player::Player(int width, int height){

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
Player::Player(int num, int width, int height){
	
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
Player::~Player(){
	for(int i=0; i<boardW; i++){
		delete board[i];
	}
	delete []board;
	delete []ships;
}

//initializes a 2D array for board and sets the elements to water
void Player::createBoard(){
    //allocate 2D array for the board
    char **temp = new char*[boardW];
	for(int i=0; i<boardW; i++){
		temp[i] = new char[boardH];
	}
    
    //initialize all elements to water
    for(int i=0; i<boardW; i++){
        for(int j=0; j<boardH; j++){
            temp[i][j] = 'W';
        }
    }
    
    //sets the board to the new array
    board = temp;
}

//Displays own board showing all ships on the board.
void Player::displayBoard(){
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
            if(board[i][j] == 'W')
            {
                cout << "  | ";
            }
			else if(board[i][j] == 'M')
			{
				cout << "O | ";
			}
			else if(board[i][j] == 'H')
			{
				cout << "X | ";
			}
            else if(board[i][j] == 'C')
            {
                cout << "C | ";
            }
            else if(board[i][j] == 'B')
            {
                cout << "B | ";
            }
            else if(board[i][j] == 'D')
            {
                cout << "D | ";
            }
            else if(board[i][j] == 'S')
            {
                cout << "S | ";
            }
            else
            {
                cout << "P | ";
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
void Player::displayHiddenBoard(){
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
            if(board[i][j] == 'M')
            {
                cout << "O | ";
            }
			//if we previously shot but missed, display an X
			else if(board[i][j] == 'H')
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

#endif