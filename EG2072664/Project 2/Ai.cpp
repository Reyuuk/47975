

template <class T>
class BattleshipAi : friend Player
{
private:
	T ** hitboard;
	bool sunk;
	T x;
	T y;
	//ship lengths?

public:
	//Default constructor
	BattleshipAi();

	//Destructor
	~BattleshipAi();

	search();
	place();
	hunt();
	found();
	attackMode();
	randHuntCoords(T &x, T &y);

	
};

template <class T>
BattleshipAi<T>::BattleshipAi(){
	//allocate 2D array for the board
    int **temp = new int*[Player::boardW];
	for(int i=0; i<Player::boardW; i++){
		temp[i] = new int[Player::boardH];
	}
    
    //initialize all elements to the same probability
    for(int i=0; i<Player::boardW; i++){
        for(int j=0; j<Player::boardH; j++){
            temp[i][j] = 1;
        }
    }
    
    //sets the hitboard to the new array
    hitboard = temp;
}

//destructor deallocates hitboard memory
template <class T>
BattleshipAi<T>::~BattleshipAi(){
	//deallocates memory
	for(int i=0; i<Player::boardW; i++)
		delete hitboard[i];
	delete []hitboard;
}

template <class T>
BattleshipAi<T>::search(){

	int potentialpoint=0;

	for(int i=0; i<Player::boardW; i++){
		for(int i=0; i<Player::boardH; i++){
			if (hitboard[i][j] > 1){
				if(potentialpoint < hitboard[i][j]){
					potentialpoint = hitboard[i][j];
				}
			}
		}
	}

	for(int i=0; i<Player::boardW; i++){
		for(int i=0; i<Player::boardH; i++){

		}
	}
}

template <class T>
BattleshipAi<T>::randHuntCoords(T &x, T &y){

	T xspace = rand()%10;
	T yspace = rand()%10;

	if(xspace%2==0 && yspace%2==0)
		xspace+1;

	if(xspace%2==1 && yspace%2==1)
		xspace+1;

	x = xspace;
	y = yspace;
}

template <class T>
BattleshipAi<T>::found(){
	//if there is a hit, add to possibility table using:

	//check to make sure 4 spaces around don't fall off board
	//check spaces around for any other hit, misses, or sunk ship
	//decide between the remaining choices
	//if another hit, add to possibility table the new coords using above criteria

	//if there are two consecutive hits, increment possibility for the spaces lined up

	//if a ship is sunk, change all the hits to sunk



}



//search board. if any 2's exist, look at the 4 spaces around. If there are more 2's increment
//the spaces adjecent to those in the same direction


//if a hit was found previously and a ship was not sunk go to
//found mode
//if two hits sit next to each other, attack in the same direction
//if no hits exist next to each other, rand the 4 spots and attack hor or ver
//attack until a ship is sunk
//keep track of which ships are sunk?
