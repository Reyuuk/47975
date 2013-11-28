//Written by Edgar Gonzalez
//on 10/26/2013
//for CIS17A - 47975

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct player
{
	int carrier;	
	int battleship;	
	int destroyer;	
	int submarine;	
	int patrolboat;	
	char **board;	//pointer to the board array
};

//global constants
const int BRD_WIDTH = 10;
const int BRD_HEIGHT = 10;

//function prototypes
char **create_board();
void instructions();
void initialize(player*);
void disp_own_board(char**);
void disp_ene_board(char**);
void place_ships(player*);
void place_ship(player*, int, char, string);
void get_user_input(int&, int&);
char get_direction();
void attack_point(player*, const int&, const int&);
bool game_over(const player*, const player*);

int main() 
{
	int x, y; //coordinates. Retrieved from user input and used to place ships or attack opponent.
	char again; // used to ask player if they want to play the game again.

	instructions();

	do{
		//create players and initialize
		player *p1 = new player;
		player *p2 = new player;
		initialize(p1);
		initialize(p2);

		//players place their ships
		cout << "Player 1, place your ships. " << endl;
		place_ships(p1);
		system("CLS");
		cout << "Player 2's turn to place ships. ";
		system("PAUSE");
		place_ships(p2);
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
			disp_own_board(p1->board);
			system("PAUSE");
			system("CLS"); //clear screen after viewing own, for cheaters!
			//show player 1 the current enemy board
			cout << "Your enemy's board:" << endl << endl;
			disp_ene_board(p2->board);
			//player 1 choose an attack point
			cout << "It's your turn to attack! ";
			get_user_input(x, y);
			attack_point(p2, x, y);
			disp_ene_board(p2->board);
			cout << "This is the end of your turn. ";


			//change to player 2's turn
			cout << "Player 2, ";
			system("PAUSE");
			//show player 2 the status of their own board
			cout << "Your board:" << endl << endl;
			disp_own_board(p2->board);
			system("PAUSE");
			system("CLS"); //clear screen after viewing own, for cheaters!
			//show player 2 the enemy's board
			cout << "Your enemy's board:" << endl << endl;
			disp_ene_board(p1->board);
			//player 2 choose an attack point
			cout << "It's your turn to attack! ";
			get_user_input(x, y);
			attack_point(p1, x, y);
			disp_ene_board(p1->board);
			cout << "This is the end of your turn. ";

			//check if game is over
		} while (!game_over(p1, p2));
	
		//delete the board and the player structs
		for(int i=0; i<BRD_HEIGHT; i++)
		{
			delete p1->board[i];
	        delete p2->board[i];
		}
		delete []p1->board;
		delete []p2->board;
		delete []p1;
		delete []p2;

		//ask if they want to start a new game
		cout << "Do you want to play another game? [Y/N]: ";
		cin >> again;
	} while(again == 'Y' || again == 'y');
	
    
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

	system("PAUSE");
}
void initialize(player *p)
{
	//initialize the starting hitpoints for each ship and all elements of the board to water
	p->carrier = 5;
	p->battleship = 4;
	p->destroyer = 3;
	p->submarine = 3;
	p->patrolboat = 2;
	p->board = create_board();
}
char **create_board()
{
    //allocate 2d array for the board
    char **temp = new char*[BRD_WIDTH];
	for(int i=0; i<BRD_WIDTH; i++){
		temp[i] = new char[BRD_HEIGHT];
	}
    
    //initialize all elements to water
    for(int i=0; i<BRD_WIDTH; i++){
        for(int j=0; j<BRD_HEIGHT; j++){
            temp[i][j] = 'W';
        }
    }
    
    //returns a pointer to the player's board
    return temp;
}
void disp_own_board(char **player)
{
	cout << "     A   B   C   D   E   F   G   H   I   J " << endl;
	cout << "   -----------------------------------------" << endl;
	for(int i=0; i<BRD_WIDTH; i++)
	{
		cout << setw(3) << i+1 << "| ";
		for(int j=0; j<BRD_HEIGHT; j++)
		{
            //if the spot is water, display nothing
            if(player[i][j] == 'W')
            {
                cout << "  | ";
            }
			else if(player[i][j] == 'M')
			{
				cout << "O | ";
			}
			else if(player[i][j] == 'H')
			{
				cout << "X | ";
			}
            else if(player[i][j] == 'C')
            {
                cout << "C | ";
            }
            else if(player[i][j] == 'B')
            {
                cout << "B | ";
            }
            else if(player[i][j] == 'D')
            {
                cout << "D | ";
            }
            else if(player[i][j] == 'S')
            {
                cout << "S | ";
            }
            else
            {
                cout << "P | ";
            }
        }
	cout << endl << "   -----------------------------------------" << endl;
    }
}
void disp_ene_board(char **player)
{
	cout << "     A   B   C   D   E   F   G   H   I   J " << endl;
	cout << "   -----------------------------------------" << endl;
    for(int i=0; i<BRD_WIDTH; i++)
    {
		cout << setw(3) << i+1 << "| ";
        for(int j=0; j<BRD_HEIGHT; j++)
        {
            //if the spot is a hit_ship, display the hit
            if(player[i][j] == 'M')
            {
                cout << "O | ";
            }
			//if we previously shot but missed, display an X
			else if(player[i][j] == 'H')
			{
				cout << "X | ";
			}
            //for anything else, display only water
            else
            {
                cout << "  | ";
            }
        }
	cout << endl << "   -----------------------------------------" << endl;
    }
}
void place_ships(player *self)
{
	place_ship(self, self->carrier, 'C', "Aircraft Carrier");

	place_ship(self, self->battleship, 'B', "Battleship");
    
	place_ship(self, self->destroyer, 'D', "Destroyer");
    
	place_ship(self, self->submarine, 'S', "Submarine");
    
	place_ship(self, self->patrolboat, 'P', "Patrol Boat");
}
void place_ship(player *self, int ship_size, char ship_type, string boat_name)
{
	int hor, ver;	//horizontal and vertical position
	char direction;	//direction to place the ship
	bool collision = false;

	//display board and get user inputs
	disp_own_board(self->board);
	cout << "Please place your " << boat_name << ". (" << ship_size << "x1)" << endl;
	get_user_input(hor, ver);
	direction = get_direction();

    //test if the ship will collide with another ship already on the grid
	for(int i=0; i<ship_size; i++)
	{
		if(direction == 'H'){
			if(self->board[ver][hor+i] != 'W')
				collision = true;
		}
		if(direction == 'V'){
			if(self->board[ver+i][hor] != 'W')
				collision = true;
		}
	}
	//if there is a collision with another ship, or if the ship will be off the grid, get a new input.
	while((direction == 'V' && ver > (10-ship_size)) || (direction == 'H' && hor > (10-ship_size)) || collision == true)
	{
		cout << "Your ship doesn't fit there! ";
		get_user_input(hor, ver);
		direction = get_direction();
		collision = false;
		for(int i=0; i<ship_size; i++)
		{
			if(direction == 'H'){
				if(self->board[ver][hor+i] != 'W')
					collision = true;
			}
			if(direction == 'V'){
				if(self->board[ver+i][hor] != 'W')
					collision = true;
			}
		}
	}


	//set the position on the grid
	for(int i=0; i<ship_size; i++)
	{
		if(direction == 'H')
		{
			self->board[ver][hor+i] = ship_type;
		}
		if(direction == 'V')
		{
			self->board[ver+i][hor] = ship_type;
		}
	}
}
void get_user_input(int &x, int &y)
{
	char input[3];

	cout << "Choose a point on the map [Ex. A10, B5]: ";
	for(int i=0; i<3; i++)
	{
		cin.get(input[i]);
	}
	cin.clear();
	cin.sync();

	input[0] = toupper(input[0]);

	//validate the input
	while(input[0] < 'A' || input[0] > 'J' || !isdigit(input[1]) || (!isdigit(input[2]) && input[2]!='\n'))
	{
		cout << "Invalid input! Please try again: ";
		for(int i=0; i<3; i++)
		{
			cin.get(input[i]);
		}
		cin.clear();
		cin.sync();
	}
	
	//assign to an x,y location on player's grid
	x = input[0] - 65;

	if(input[2] == '0')
		y = 9;
	else y = input[1]-49;
}
char get_direction()
{
	char dir;
    //ask for orientation
	cout << "Place ship [H]orizontally or [V]ertically?: ";
	cin >> dir;
	cin.clear();
	cin.sync();

	//validate the orientation
	while(dir != 'h' && dir != 'H' && dir != 'v' && dir != 'V')
	{
		cout << "Invalid! Try inputting a direction again. [V or H]: ";
		cin.clear();
		cin.sync();
		cin >> dir;
	}

	dir = toupper(dir);

	return dir;
}
void attack_point(player *enemy, const int &x, const int &y)
{
	//check players board for a ship, announces the results of the hit
	if(enemy->board[y][x] == 'W' || enemy->board[y][x] == 'M')
	{
		enemy->board[y][x] = 'M';
		cout << "Miss!" << endl <<endl;
	}
	else if (enemy->board[y][x] == 'C')
	{
		enemy->board[y][x] = 'H';
		enemy->carrier--;
		if(enemy->carrier == 0)
			cout << "Enemy Aircraft Carrier sunk!" << endl << endl;
		else cout << "Hit!" << endl << endl;
	}
	else if(enemy->board[y][x] == 'B')
	{
		enemy->board[y][x] = 'H';
		enemy->battleship--;
		if(enemy->battleship == 0)
			cout << "Enemy Battleship sunk!" << endl << endl;
		else cout << "Hit!" << endl << endl;
	}
	else if(enemy->board[y][x] == 'D')
	{
		enemy->board[y][x] = 'H';
		enemy->destroyer--;
		if(enemy->destroyer == 0)
			cout << "Enemy Destroyer sunk!" << endl << endl;
		else cout << "Hit!" << endl << endl;
	}
	else if(enemy->board[y][x] == 'S')
	{
		enemy->board[y][x] = 'H';
		enemy->submarine--;
		if(enemy->submarine == 0)
			cout << "Enemy Submarine sunk!" << endl << endl;
		else cout << "Hit!" << endl << endl;
	}
	else if(enemy->board[y][x] == 'P')
	{
		enemy->board[y][x] = 'H';
		enemy->patrolboat--;
		if(enemy->patrolboat == 0)
			cout << "Enemy Patrol Boat sunk!" << endl << endl;
		else cout << "Hit!" << endl << endl;
	}
}
bool game_over(const player *p1, const player *p2)
{
	//check if game is a draw first, or if either player won.
	if(p1->carrier ==0 && p1->battleship ==0 && p1->destroyer ==0 && p1->submarine ==0 && p1->patrolboat ==0 && p2->carrier ==0 && p2->battleship ==0 && p2->destroyer ==0 && p2->submarine ==0 && p2->patrolboat ==0)
	{
		cout << endl << "Game is a draw! All ships on both teams were sunk at the same time!!!";
		return true;
	}
	else if (p1->carrier ==0 && p1->battleship ==0 && p1->destroyer ==0 && p1->submarine ==0 && p1->patrolboat ==0)
	{
		cout << endl << "Player 2 wins!";
		return true;
	}
	else if (p2->carrier ==0 && p2->battleship ==0 && p2->destroyer ==0 && p2->submarine ==0 && p2->patrolboat ==0)
	{
		cout << endl << "Player 1 wins!";
		return true;
	}
	else return false;
}
