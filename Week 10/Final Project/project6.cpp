/***********************************************************************************************************************************
ANTHONY CLARK
MEMORY GAME w/ HoF feature
-Each requirement is labeled with its corresponding number. All requirements not listed below, exist within this file (project6.cpp)
#30 makefile is included in zipfile
#29 headerFinal.h
#5, #6, #18, #23, #25, #26, #27, #28, #31, #34, #35 in headerFile.cpp
#33 operator overload is not included in this program
Future plans for game: Improve visuals and allow the player to choose difficulty (increase card number or board size)
************************************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <stdlib.h>
#include "headerFinal.h" //#29
using namespace std;
template<class T> //#37 command line function is written to work with multiple types
void isAPointer(T *n);
class Memory //#24 class
{
	public:
		Memory(int theA, int theB);
		~Memory();
		Memory();
		char greeting[20];
		int row1, co1, row2, co2, cards[4][4], classScore;
		bool cardChecker[4][4];
		bool playerWin; 
		int tries;
		void shuffle(int [][4]);
		void printBoard();
		void cardChoiceOne();
		void cardChoiceTwo();
		void printChoices();
		void evaluateChoices();
		void winCheck();
		void getValue(int &classScore)
		{
			a = classScore;
			b = 8;
		}
	private:
	//These are just here to demo a constructor
		int a, b;
};
class Perfect : public Memory //#36 Inheritance
{
	public:
		int perfectScore;
};
int main(int argc, char* argv[])
{
	//#21 Argument is included to run isAPointer func and return. To run the command line argument, run ./proj n where n is any type (meant for int)
	if(argc > 1)
	{
		int aNum = atoi(argv[1]); 
		isAPointer(&aNum); //#16 pass by reference
  	}
	//#24 create class object
	Memory memoryObj;
	Perfect perfectObj;
	char ans;
	perfectObj.perfectScore = 8;
	memoryObj.playerWin = false;
	int bestScore;//#1/#2	-The lowest possible score is 8, or 1000 in binary (in 8 bit, 00001000). In two's compliment, this number is also 00001000. 
	//When negative, it's 11111000. There was no way to add these two requirements naturally into the program, so hopefully this will suffice.
	do
  	{    	 
	 	memoryObj.tries = 0; //no picks have been made, set to 0. 
		memoryObj.printBoard();       
    		do //begin playing
      	 	{
			memoryObj.cardChoiceOne(); //#14 majority of the code made in functions to reduce bulk/improve testing
			memoryObj.cardChoiceTwo();
			memoryObj.printChoices();
			memoryObj.evaluateChoices();			
  			memoryObj.winCheck(); 
            		memoryObj.tries++;
			//End the game when player wins
        	}while(memoryObj.playerWin != true); 
		cout << "Nice work! You cleared the board!"<<endl; //#4 - Numerous couts are used in both files.
        	cout << "You used " << memoryObj.tries << " picks to win."<<endl<<endl;
        	bestScore = memoryObj.tries;
		int difference = memoryObj.tries - perfectObj.perfectScore; //#8 - Numerous operators used
		cout << "Your score was " << difference << " picks from being perfect!\n"; 
		clarkant::bestScore(bestScore);	//#16 pass by value
		cout << "Would you like to play again? (Y/N): \n";
       		cin >> ans; //#5 - cin used numerous times.
    		
	}while(ans == 'y' || ans == 'Y'); 
	cout << "Thanks for playing "; cout << __FILE__ <<endl; //#3 I used __FILE__ to output the name of the file to the user
    	cin.get();
    	return 0;
}
//#32 copy constructor, destructor, and default constructor included
Memory::Memory(int theA, int theB)
              :a(theA), b(theB)
{/*intentionally blank constructor*/}
Memory::~Memory()
{/*intentionally blank destructor*/}
Memory::Memory() //#17 the default constructor uses the same function definition as the copy constructor, but with diff parameters.
{/*intentionally blank default constructor*/}
template<class T>
void isAPointer(T *n) //#13 one of many functions used
{
	cout << "Hi, " << *n << " is a number. Good job! Now let's play the game\n";  
}
void Memory::printBoard()
{
	shuffle(cards);
	cout<<"   1 2 3 4\n";
	cout<<"  ";
	for (int i = 0; i <= 8; i++)
	{
		cout<<"_";
	}
	cout<<endl;
	for (int r = 0; r < 4; r++)
	{
		cout << r + 1 <<" | ";
		for (int c = 0; c < 4; c++)
		{
			cout<<"* ";
			cardChecker[r][c] = false; //#20 cardChecker is a multidimensional array
		}
		cout<<endl;
	}
	cout<<endl;
}
//Take the players input for the first location and perform validation
void Memory::cardChoiceOne()
{
	do
	{	bool valid;
		cout << "Please enter your first position\n";
		cout << "Row: "; cin >> row1; cout << endl;
		do{
			valid = true;
			if(row1 > 4 || row1 < 1 || !cin.good()) //#7 one of many conditionals used
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid entry. A number (1-4) must be selected\n";
				cout << "Please enter your first position\n";
				cout << "Row: "; cin >> row1; cout << endl;
				valid = false;
			}
		}while(valid == false);
		try //#38 exception used as I would never use it, but here to demo
		{
			cout << "Column: "; cin >> co1; cout << endl;
			if(co1 > 4 || co1 < 1)
			{
				throw co1;
			}
		}
		catch(int f)
		{
			cout << f << " is an invalid entry. A number (1-4) must be selected\n";
			cardChoiceOne(); //# 19 Calling cardChoiceOne() within cardChoiceOne() 
		}
		if(cardChecker[row1 - 1][co1-1] == true)
		{
			cout << "You've already correctly guessed these cards! Try again.\n";
		}
	}while(cardChecker[row1-1][co1-1]!= false);

}
//Take the players input for the second location and perform validation
void Memory::cardChoiceTwo()
{
	do
	{
		bool valid;
		cout << "Please enter your second position\n";
		cout << "Row: "; cin >> row2; cout << endl;
		do
		{
			valid = true;
            		/*#11 A syntax error would result if I had written if !cin.good), forgetting the parentheses. A logic error would occur if I had failed 
			to take into account that the user could enter a letter for the row or column. A run-time error could occur if the user entered a row or 
			column that didn't exist (which I corrected for in the validation below)*/
			/*#12 input validation used here, along with the other instances of row/col input. Input validation reduces bugs here by eliminating
			the users potential to send the program into an infinite loop by entering an incorrect data type or value*/
			if(row2 > 4 || row2 < 1 || !cin.good())  
            		{
				cin.clear();
                		cin.ignore(1000, '\n');
                		cout << "Invalid entry. A number (1-4) must be selected\n";
                		cout << "Please enter your second position\n";
                		cout << "Row: "; cin >> row2; cout << endl;
				valid = false; 
				//#15 scoping of variables is used here to change the value of valid. Because it is only accessible within the if statement,
				//we can change it here, and it will become true again once the loop runs another time (or remain true if it doesnt fall in here)
            		}
		}while(valid == false);
		cout << "Column: "; cin >> co2; cout << endl;
		do
		{	
			valid = true;
			if(co2 > 4 || co2 < 1 || !cin.good())
                        {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid entry. A number (1-4) must be selected\n";
                                cout << "Please enter your second position\n";
                	        cout << "Column: "; cin >> co2; cout << endl;
                                valid = false;
                        }
		}while(valid == false);
	        if(cardChecker[row2 - 1][co2-1] == true)
                {
                        cout << "You've already correctly guessed these cards! Try again.\n";
                }
		if((row1 == row2)&&(co1 == co2))
		{
			cout << "You selected this card for your first already! Try again.\n";
		}
	}while((cardChecker[row2-1][co2-1]!= false) || ((row1 == row2)&&(co1 == co2)));

}
void Memory::printChoices()
{	
	//need to account for the zero in the array, subtract one from our elements 
	row1--;
	co1--;
	row2--;
	co2--;
	//print the border top
	cout<<"    1 2 3 4\n";
	cout<<"  ";
	for (int i = 0; i <= 8; i++) //#9 - for loop used amongst many others
	{
		cout<<"-";
	}
	cout<<endl;
	//print the border side
	for (int r = 0; r < 4; r++)
	{
		cout << r + 1 << " | ";
		for (int c = 0; c < 4; c++)
		{
			//put row1 and co1 into the array display
			if ((r == row1) && (c == co1))
			{
				cout << cards[r][c]<<" ";
			}
			//put row2 and co2 into the array display
			else if((r == row2)&&(c == co2))
			{
				cout<< cards[r][c]<<" ";
			}
			//the positions match, put them into the stored array
			else if (cardChecker[r][c] == true)
			{
				cout<< cards[r][c]<<" ";
			}
			//none of the above, leave as a * to hold the position
			else
			{
				cout<<"* ";
			}
		}
		cout<<endl;
	}

}
//Do our picks match? Store the matches, and print them to the screen, keeping them visible
void Memory::evaluateChoices()
{
	if (cards[row1][co1] == cards[row2][co2]) 
	{
		cout << "Nice Pick - We have a match!"<<endl;
		cardChecker[row1][co1] = true;
		cardChecker[row2][co2] = true;
	}
	cout << "Press the enter key to continue guessing!\n";
	cin.get();
	cin.get();
	//make a whole bunch of endlines to clear the screen
	for (int s = 0; s <= 50; s++)
	{
		cout << endl;
	}
	cout<<"    1 2 3 4\n";
        cout<<"  ";
        for (int i = 0; i <= 8; i++) //#9 - for loop used amongst many others
        {
                cout<<"-";
        }
        cout<<endl;
	for (int r = 0; r < 4; r++) // reprint the board
	{
		cout << r + 1 << " | ";
		for (int c = 0; c < 4; c++)
		{
			if (cardChecker[r][c] == true)
			{
				cout << cards[r][c] << " ";
			}
			else
			{
				cout<<"* ";
			}
		}
		cout<<endl;
	}
}
//Check if the player won the game. If all cards are found, end the game.
void Memory::winCheck()
{
	//initialize to true and show that it's not by looping through array
	playerWin = true;
	for (int r = 0; r < 4; r++) 
	{
		for (int c = 0; c < 4; c++)
		{
			//if we're missing a match at any place, we havent won
			if(cardChecker[r][c] == false)
			{
				playerWin = false;
				break;
			}
		}
		// if we havent won, break out of the loop and the function
		if(playerWin == false)
		{
			break;
		}
	}
}
void Memory::shuffle(int cards[][4])
{
	//start with 16 #s (cards) for a 4x4 array
 	int start[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	for (int s = 0; s <= 20; s++)
	{
		for (int i = 0; i < 16; i++)
        	{
            		srand((unsigned)time(NULL));
            		int randi = rand() % 15 + 1; //#10 - A random number is used to shuffle the cards in the deck
            		int tempStart = start[i];
            		start[i] = start[randi];
            		start[randi] = tempStart;
        	}
    	}    
	int i = 0;
    	for (int r = 0; r < 4; r++) 
        {
        	for (int c = 0; c < 4; c++)
            	{
                	cards[r][c] = start[i];
			//Comment out unless debugging - this will display the values under the hidden * positions
                	//cout << cards[r][c];                
                	i = i + 1;
            	}
            	cout<<endl;
        }
}



