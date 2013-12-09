//Written by Edgar Gonzalez
//on 12/8/13
//for CIS17A - 47975

#include <iostream>
#include <iomanip>
#include <string>
#include "BattleshipAi.h"

using namespace std;


//global constants

//function prototypes
void instructions();
void placeShips(Player<int> *);
void aiPlaceShips(BattleshipAi *);
void getUserInput(int&, int&);
char getDirection();
bool gameOver(const Player<int>*, const Player<int>*);
void onePlGame();
void twoPlGame();
int getN();


int main()
{
	//random seed for AI computations
	srand(time(0));

    int inN;
    do{
        instructions();
        inN=getN();
        switch(inN){
        case 1:    onePlGame();break;
        case 2:    twoPlGame();break;
		}
    }while(inN==1 || inN==2);

    return 0;
}
void instructions()
{
	cout << "This is the game of battleship. To begin, each player will secretly " << endl
		 << "arrange ships on a 10x10 grid. Each ship occupies a number of " << endl
		 << "consecutive spaces. Below is a list of the ships and their size." << endl << endl

		 << "Aircraft Carrier : 5" << endl
		 << "Battleship : 4" << endl
		 << "Sumbarine : 3" << endl
		 << "Destroyer : 3" << endl
		 << "Patrol Boat : 2" << endl << endl

		 << "After boats have been placed by both players, you will take turns attacking" << endl
		 << "each other's grid until all of your opponent's ships have been sunk!" << endl << endl;

	cout << "Type 1 to play a 1 player game vs AI."<<endl;
    cout << "Type 2 to play a 2 player game vs another player."<<endl;
    cout << "Type anything else to exit: ";
}
    
int getN(){
        int inN;
        cin>>inN;
		cin.clear();
		cin.ignore(1000, '\n');
		cin.sync();
        return inN;
}

//Two player match, one person vs another
void twoPlGame() 
{
	int x, y; //coordinates. Retrieved from user input and used to place ships or attack opponent.

	//create players and initialize
	Player<int> *p1 = new Player<int>;
	Player<int> *p2 = new Player<int>;

	//players place their ships
	cout << "Player 1, place your ships. " << endl;
	placeShips(p1);
	system("CLS");
	cout << "Player 2's turn to place ships. ";
	system("PAUSE");
	placeShips(p2);
	system("CLS");
	cout << "Both players have finished placing ships! The game will now begin." << endl << endl;
	
	//begin the attacking phase of the game. 
	//Loop until all ships on a board are sunk and a winner is declared.
	do{
		//change to player 1's turn
		cout << "Player 1, ";
		system("PAUSE");
		//show player 1 the status of their own board
		cout << "Your board:" << endl << endl;
		p1->displayBoard();
		system("PAUSE");
		system("CLS"); //clear screen after viewing own, for cheaters!
		//show player 1 the current enemy board
		cout << "Your enemy's board:" << endl << endl;
		p2->displayHiddenBoard();
		//player 1 choose an attack point
		cout << "It's your turn to attack! ";
		getUserInput(x, y);
		p2->attackPoint(x, y);
		cout << endl;
		p2->displayHiddenBoard();
		cout << "This is the end of your turn. ";


		//change to player 2's turn
		cout << "Player 2, ";
		system("PAUSE");
		//show player 2 the status of their own board
		cout << "Your board:" << endl << endl;
		p2->displayBoard();
		system("PAUSE");
		system("CLS"); //clear screen after viewing own, for cheaters!
		//show player 2 the enemy's board
		cout << "Your enemy's board:" << endl << endl;
		p1->displayHiddenBoard();
		//player 2 choose an attack point
		cout << "It's your turn to attack! ";
		getUserInput(x, y);
		p1->attackPoint(x, y);
		cout << endl;
		p1->displayHiddenBoard();
		cout << "This is the end of your turn. ";

		//check if game is over
	} while (!gameOver(p1, p2));
	
	//delete the players
	delete []p1;
	delete []p2;
}

//Single player match against AI.
void onePlGame()
{
	int x, y; //coordinates. Retrieved from user input and used to place ships or attack opponent.
	int result; //used to capture result of a shot for AI.

	//create players and initialize
	Player<int> *p1 = new Player<int>;
	BattleshipAi *p2 = new BattleshipAi;

	//Place ships for the player and AI
	cout << endl << "Place your ships. " << endl << endl;
	placeShips(p1);
	aiPlaceShips(p2);
	cout << "The game will now begin." << endl;
	
	//begin the attacking phase of the game. 
	//Loop until all ships on a board are sunk and a winner is declared.
	do{
		//change to player 1's turn
		cout << "Your board:" << endl;
		p1->displayBoard();
		system("PAUSE");
		//show player 1 the current enemy board
		cout << "Your enemy's board:" << endl << endl;
		p2->displayHiddenBoard();
		//player 1 choose an attack point
		cout << "It's your turn to attack! ";
		getUserInput(x, y);
		cout << "You ";
		p2->attackPoint(x, y);
		cout << endl;
		p2->displayHiddenBoard();
		cout << "This is the end of your turn. ";
		system("PAUSE");


		//change to AI's turn
		//AI chooses an attack point
		p2->selectAttackPoint(x, y);
		cout << "Your enemy ";
		result = p1->attackPoint(x, y);
		//Informs AI if the shot was a miss, hit, or if a ship sunk
		p2->getResults(result);

		//check if game is over
	} while (!gameOver(p1, p2));
	
	//delete the players
	delete []p1;
	delete []p2;
}

void placeShips(Player<int> *self)
{
	//places a ship for each ship on the player's board
	for(int i=0; i<self->getShipNum(); i++){
		int x;
		int y;
		char dir;
		bool badplacement;

		cout << endl << "Place your " << self->getShipName(i) << ". (" << self->getShipHitpoints(i) << "x1)" << endl <<endl;
		self->displayBoard();
		getUserInput(x, y);
		dir = getDirection();
		badplacement = self->placeShip(x, y, dir, i);
		while (!badplacement){
			cout << endl << "Your ship doesn't fit there! Please try again." << endl;
			self->displayBoard();
			getUserInput(x, y);
			dir = getDirection();
			badplacement = self->placeShip(x, y, dir, i);
		}
	}
}

void aiPlaceShips(BattleshipAi *ai){
	//Ai randomly selects locations to place ships.
	for(int ship=0; ship<ai->getShipNum(); ship++){
		int x;
		int y;
		char dir;
		bool badplacement;

		do{
		ai->placeShipRandom(x, y, dir);
		badplacement = ai->placeShip(x, y, dir, ship);
		} while (!badplacement);
	}
}

void getUserInput(int &x, int &y)
{
	char input[3];

	cout << "Choose a point on the map [Ex. A10, B5]: ";
	for(int i=0; i<3; i++)
	{
		cin.get(input[i]);
	}

	input[0] = toupper(input[0]);

	//validate the input
	while(input[0] < 'A' || input[0] > 'J' || !isdigit(input[1]) || (!isdigit(input[2]) && input[2]!='\n'))
	{
		cout << "Invalid input! Please try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin.sync();
		for(int i=0; i<3; i++)
		{
			cin.get(input[i]);
		}

	}

	cin.sync();
	
	//assign to an x,y location on player's grid
	x = input[0] - 65;

	if(input[2] == '0')
		y = 9;
	else y = input[1]-49;
}

char getDirection()
{
	char dir;
    //ask for orientation
	cout << "Place ship [H]orizontally or [V]ertically?: ";
	cin >> dir;

	//validate the orientation
	while(dir != 'h' && dir != 'H' && dir != 'v' && dir != 'V')
	{
		cout << "Invalid! Try inputting a direction again. [V or H]: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> dir;
	}

	dir = toupper(dir);

	cin.sync();

	return dir;
}

bool gameOver(const Player<int> *p1, const Player<int> *p2)
{
	bool p1lose = false;
	bool p2lose = false;

	//check if player 1's ships all have 0 hitpoints.
	for(int i=0; i<p1->getShipNum(); i++){
		if(p1->getShipHitpoints(i)!=0)
			break;
		if(i==p1->getShipNum()-1) 
			p1lose = true;
	}

	//check if player 2's ships all have 0 hitpoints.
	for(int i=0; i<p2->getShipNum(); i++){
		if(p2->getShipHitpoints(i)!=0)
			break;
		if(i==p2->getShipNum()-1) 
			p2lose = true;
	}

	//if both players have all ships at 0, the game is a draw.
	if (p1lose && p2lose){
		cout << endl << "Game is a draw! All ships on both teams were sunk at the same time!!!";
		return true;
	}

	if (p1lose){
		cout << endl << "Player 2 wins!";
		return true;
	}

	if (p2lose){
			cout << endl << "Player 1 wins!";
		return true;
	}

	return false;
}
