template <class T>
class Ai
{
private:
	T **board;
	bool sunk;
	T x;
	T y;
	//ship lengths?

	found();
	hunt();
public:
	attack();



}


//hunt mode
//fire random shot

//if a hit was found previously and a ship was not sunk go to
//found mode
//if two hits sit next to each other, attack in the same direction
//if no hits exist next to each other, rand the 4 spots and attack hor or ver
//attack until a ship is sunk
//keep track of which ships are sunk?
