//Written by Edgar Gonzalez
//on 11/22/13
//for CIS17A - 47975

#include <iostream>
#include <string>

using namespace std;

//function prototypes
void new_line();

//templates
template <class T>
T minimum(T var1, T var2){
	if(var1 < var2)
		return var1;
	return var2;
}
template <class T>
T maximum(T var1, T var2){
	if(var1 > var2)
		return var1;
	return var2;
}

int main()
{
	int a,b;
	float c,d;
	string e,f;
	char g,h;

	cout << "This program will test for maximums and minimums in various data types using templates." << endl;

	cout << "Please enter two integers." << endl;
	cin >> a;
	cin >> b;
	cout << "The smaller integer is " << minimum(a, b) << endl;

	cout << "Please type any two characters." << endl;
	cin >> g;
	cin >> h;
	cout << "The character that 'comes first' in the alphabet is " << minimum(g, h) << endl;

	cout << "Please type any two strings of characters." << endl;
	getline(cin, e);
	new_line();
	getline(cin, f);
	cout << "The string that 'comes first' in the alphabet is " << maximum(e, f) << endl;

	cout << "Please enter two floats." << endl;
	cin >> c;
	cin >> d;
	cout << "The larger float is " << maximum(c, d) << endl;

	system("PAUSE");
	return 0;
}
void new_line()
//Clears input buffer incase user inputs extra characters.
{
    char symbol;
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}