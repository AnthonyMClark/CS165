#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
#include<cstddef>
#include<algorithm>

using namespace std;

bool guessValidity(string guessedWord);
void playHangMan();

int main()
{
	cout <<	"Enter 1 to play Hang Man!\n";
	int play;
	cin >> play;
	if(play == 1)
	{
		playHangMan();
	}
	return 0;
}

void playHangMan()
{
	int playAgain;
	do{
		bool validGuess;
		string guessedWord;
		//Have the initial word be put in and make sure that it is valid.
		do
		{
			cout << "Enter a word of up to 20 characters (a-z) for player 2 to guess.\n";
			getline(cin, guessedWord);
			validGuess = guessValidity(guessedWord);
			//loop through the word to make it uppercase
			for(int i = 0; i < guessedWord.length(); i++)
			{
				guessedWord.at(i) = toupper(guessedWord.at(i));
			}
			if(guessedWord.length() > 20)
			{
				cout << "Please reenter a word that does not exceed 20 characters.\n";
			}
		}while((guessedWord.length() > 20) || (validGuess == false));
	
		string hiddenLetters = guessedWord;	
		//set the hidden letters
		for(int i = 0; i < hiddenLetters.length(); i++)
		{
			hiddenLetters[i] = '-';
		}
	                                                                       
     		//Let the user know how many guesses they have, which is det by length.
		int guessCounter = 0;
     		if (guessedWord.length() < 15)
        	{
                	guessCounter = 5;
        	}
        	else
        	{
        		guessCounter = 8;
        	}
		//START THE PART FOR PLAYER TWO
		bool playerTwoWin;
		bool validPlayerTwo;
		string playerTwoGuess;
		bool correctGuess;
		bool usedGuess;
		bool inGuessBank;
		string usedGuessBank;
		string missedLetters = guessedWord;
		do
		{	
			playerTwoWin = false;
			correctGuess = false;
			do
			{
				inGuessBank = false;
				usedGuess = false;	

				//Take player two's guess and make sure it is  valid.
				cout << endl <<endl;
				cout <<"Player two, you have " << guessCounter << " guesses remaining."  
				<<" Guess a letter (a-z) in the word." << endl;
				cin >> playerTwoGuess; 
				//Loop through the guess to change it to uppercase
				for(int i = 0; i < playerTwoGuess.length(); i++)
	                	{
                	        	playerTwoGuess.at(i) = toupper(playerTwoGuess.at(i));
        	        	}
				if(playerTwoGuess.length() > 1)
				{
					cout << "Please enter a single value as your guess." <<endl <<endl;
				}
				validGuess = guessValidity(playerTwoGuess);
		        
				//check player two's input for duplicate answers
				for(int i = 0; i < hiddenLetters.length(); i++)
                        	{
                                	if (playerTwoGuess.at(0) == hiddenLetters.at(i))
                                	{
                                        	usedGuess = true;
                                        	cout << playerTwoGuess << " has already been correctly guessed. Try again." << endl;
                                	}	
                        	}
				// make sure words in the bank arent entered twice, alter possible letters they can use.
				for(int i = 0; i < usedGuessBank.length(); i++)
				{
					if (playerTwoGuess.at(0) == usedGuessBank.at(i))
			        	{
			        		cout << "You have already guessed " << playerTwoGuess <<". Try again." <<endl <<endl;
			                	inGuessBank = true;
			        	}
			 	}
				if(playerTwoGuess.length() == 1)
				{
			 		//tell the user what their current guesses are
			 		usedGuessBank += playerTwoGuess.at(0);
			 		cout << endl;
			 		cout << "Here is your guess history:" <<endl;
					cout << usedGuessBank <<endl <<endl;                                                                                                                                                                                                                                                                                            
				}
			}while((playerTwoGuess.length() > 1) || (validGuess == false) || (usedGuess == true) || (inGuessBank == true));
		
                                                  
			//check the value of the guess vs the initial word	
			for(int i = 0; i < guessedWord.length(); i++)
			{
				if (playerTwoGuess.at(0) == guessedWord.at(i))
				{
					cout << "Good guess, " << playerTwoGuess << " is in the word at place " << i << endl <<endl;
					//replace the - in hidden letters with the guess value
					hiddenLetters.replace(i, 1, playerTwoGuess);
					correctGuess = true;
					missedLetters.at(i) = '-';
				}
			}
			cout << "Your word is: " << hiddenLetters << endl;
			//if you did not guess correctly, you lose a guess
			if(correctGuess == false)
			{
				guessCounter--;
			}
			//once the number of correct guesses equals the word length, you've won.
			if(hiddenLetters == guessedWord)
			{
				cout << "Nice work! You guessed " << guessedWord << "!" << endl << endl;
				playerTwoWin = true;
			}	    	                                                
			//tell player two they failed.
			if(guessCounter == 0)
			{
				cout << "You're out of guesses, and failed to guess the word!\n";
				cout << "The secret word was " << guessedWord <<endl;		
				cout << "Here's what you missed: " <<endl << missedLetters <<endl;
			}
		}while((guessCounter > 0) && (playerTwoWin == false)); 
		//The game is over. Play again?
		cout << "Enter 1 to play again, or 2 to exit" <<endl;
		cin >> 	playAgain;
		if(playAgain != 1)
		{
			cout << "Thanks for playing!" <<endl;
		}
	}while(playAgain == 1);
}
bool guessValidity(string guessedWord)
{
	bool validString;
	do
  	{	
		for(int i = 0; i < guessedWord.length(); i++)
		{	
			//Assume input is valid
	        	validString = true;
			//Is it alphabetical?    
    			if(!isalpha(guessedWord.at(i)))     
          		{ 
	              		validString = false;
				cout << "Your word contains invalid characters. Please use letters only.\n";
				break;
			} 	               							
		}break;
		//loop while it's not valid	
       }while(validString == false);     

	return validString;
}
