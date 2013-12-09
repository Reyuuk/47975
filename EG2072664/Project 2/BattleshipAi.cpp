//Written by Edgar Gonzalez
//on 12/8/13
//for CIS17A - 47975

//Class Implementation for Battleship Ai class

#include "BattleshipAi.h"

BattleshipAi::BattleshipAi(){

	//allocate 2D array for the board
    int **temp = new int*[getBoardW()];
	for(int i=0; i<getBoardW(); i++){
		temp[i] = new int[getBoardH()];
	}
    
    //initialize all elements to the same probability
    for(int i=0; i<getBoardW(); i++){
        for(int j=0; j<getBoardH(); j++){
            temp[i][j] = 1;
        }
    }
    
    //sets the hitboard to the new array
    hitboard = temp;

	//initializes attack status
	sunk = true;
	fhx = 0;
	fhy = 0;
	lhx = 0;
	lhy = 0;
}


//destructor deallocates hitboard memory
BattleshipAi::~BattleshipAi(){
	//deallocates memory
	for(int i=0; i<getBoardW(); i++)
		delete hitboard[i];
	delete []hitboard;
}

//uses rand() to place ship randomly on board
void BattleshipAi::placeShipRandom(int &ver, int &hor, char &dir){
	//random ship placement
	ver = rand()%10;

	int direction;
	direction = rand()%2;

	if (direction == 1)
		dir = 'H';
	else dir = 'V';

	hor = rand()%10;
}

//selects attack point based on whether last hit was successful or not
void BattleshipAi::selectAttackPoint(int &hor, int &ver){
	//if ship sunk was the last hit, hunt mode
	if(sunk == true){
		//randHuntCoords();
		y = 1;
		x = 1;
		ver = 1;//= y;
		hor = 1;//= x;
	}
	//a hit was made during hunt mode, go into attack mode
	else {
		//tests the spaces around the last hit. If there is no possible attack location, go to the first hit done on the ship
		if(!attackModeCoordsBias(lhx, lhy))
			if(!attackModeCoordsBias(fhx, fhy))
				if(!attackModeCoords(lhx, lhy))
					attackModeCoords(fhx, fhy);
		ver = y;
		hor = x;
	}
}

void BattleshipAi::randHuntCoords(){
	//Randomly search board for any spaces that have never been attacked
	do{
		y = rand()%getBoardH();
		x = rand()%getBoardW();

		if(x%2==0 && y%2==0)
			x++;

		if(x%2==1 && y%2==1)
			x++;
	} while (hitboard[y][x]!=1);
}

//this function searches for a spot on the board that was previously hit.
//if a hit is found, it searches the nearby spaces for a possible next attack location
//There is bias for attacking a space if two consecutive attack points have been found
//otherwise, hit positions nearby until a ship is sunk
bool BattleshipAi::attackModeCoordsBias(int a, int b){

	int potentialpointN=0;
	int potentialpointE=0;
	int potentialpointS=0;
	int potentialpointW=0;

	//found a point on the board that has been hit, check which spaces around exist(don't fall off board)
	if(hitboard[b][a] == 2){
		if(b-1 >= 0)
			potentialpointN++;
		if(a+1 <= getBoardW())
			potentialpointE++;
		if(b+1 <= getBoardH())
			potentialpointS++;
		if(a-1 >= 0)
			potentialpointW++;

		//if any spot is a confirmed miss, remove from possibilities. Only check on spaces that are known to be part of the board.
		if(potentialpointN==1)
			if(hitboard[b-1][a]==0)
				potentialpointN=0;
		if(potentialpointE==1)
			if(hitboard[b][a+1]==0)
				potentialpointE=0;
		if(potentialpointS==1)
			if(hitboard[b+1][a]==0)
				potentialpointS=0;
		if(potentialpointE==1)
			if(hitboard[y][a-1]==0)
				potentialpointW=0;

		//bias for checking two consecutive hits in any direction, attacks the next consecutive space
		if(potentialpointN==1 && potentialpointS==1 && hitboard[b+1][a]==2 && hitboard[b-1][a]==1){
			y = b-1;
			x = a;
			return true;
		}

		if(potentialpointW==1 && potentialpointE==1 && hitboard[b][a-1]==2 && hitboard[b][a+1]==1){
			y = b;
			x = a+1;
			return true;
		}

		if(potentialpointN==1 && potentialpointS==1 && hitboard[b-1][a]==2 && hitboard[b+1][a]==1){
			y = b+1;
			x = a;
			return true;
		}

		if(potentialpointW==1 && potentialpointE==1 && hitboard[b][a+1]==2 && hitboard[b][a-1]==1){
			y = b;
			x = a-1;
			return true;
		}

	//If we get here, it means all possible locations have been tested around this hit for bias, none exists.
	return false;
	}
}

bool BattleshipAi::attackModeCoords(int a, int b){

	int potentialpointN=0;
	int potentialpointE=0;
	int potentialpointS=0;
	int potentialpointW=0;

	//found a point on the board that has been hit, check which spaces around exist(don't fall off board)
	if(hitboard[b][a] == 2){
		if(b-1 >= 0)
			potentialpointN++;
		if(a+1 <= getBoardW())
			potentialpointE++;
		if(b+1 <= getBoardH())
			potentialpointS++;
		if(a-1 >= 0)
			potentialpointW++;

		//if any spot is a confirmed miss, remove from possibilities. Only check on spaces that are known to be part of the board.
		if(potentialpointN==1)
			if(hitboard[b-1][a]==0)
				potentialpointN=0;
		if(potentialpointE==1)
			if(hitboard[b][a+1]==0)
				potentialpointE=0;
		if(potentialpointS==1)
			if(hitboard[b+1][a]==0)
				potentialpointS=0;
		if(potentialpointE==1)
			if(hitboard[y][a-1]==0)
				potentialpointW=0;

		//attack spaces around that have not been shot at before
		if(potentialpointN==1 && hitboard[b-1][a]==1){
			y = b-1;
			x = a;
			return true;
		}

		if(potentialpointE==1 && hitboard[b][a+1]==1){
			x = a+1;
			y = b;
			return true;
		}

		if(potentialpointS==1 && hitboard[b+1][a]==1){
			y = b+1;
			x = a;
			return true;
		}

		if(potentialpointW==1 && hitboard[b][a-1]==1){
			x = a-1;
			y = b;
			return true;
		}
	}

	//If we get here, it means all possible locations have been tested around this hit.
	return false;
}


//gets a 1 if a hit is confirmed, 2 if ship sunk, 0 if miss. Sets hitboard and shipsunk bool.
void BattleshipAi::getResults(int result){
	if(result > 2){
		hitboard[y][x]=2;
		sunk = true;
		//go to hunt mode next turn
	}
	//This is a subsequent hit on a new ship, only set last hit
	else if(result == 2 && sunk == false){
		hitboard[y][x]=2;
		lhx = x;
		lhy = y;
		//Go to attack mode next turn
	}
	//This is the first hit on a new ship
	else if(result == 2 && sunk == true){
		hitboard[y][x]=2;
		fhx = x;
		fhy = y;
		lhx = x;
		lhy = y;
		sunk = false;
		//go to attack mode next turn
	}
	//Miss
	else if(result == 1){
		hitboard[y][x]=0;
		//hunt if sunk is true
		//attack if sunk is false
	}
}

