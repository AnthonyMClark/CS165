#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
#include<cstddef>
#include<algorithm>
#include<cstdlib>
#include<time.h>
using namespace std;

bool guessValidity(string guessedWord);
int playHangMan(string n);
string generateWord();
int main()
{
	int go;
	string word1, word2, word3, word4, word5, totalPhrase;
	char play;
	//Get a random amount of words for the user to guess
	srand((unsigned)time(NULL));
	int runCount = 3 + (rand() % (int)(5 - 3 + 1));
	do
	{
		
		int failed;
		int timesRan = 0;
		
		cout << "Your phrase contains " <<runCount << " words. Here is your first word:" <<endl;
		do
		{
			string temp;
			//call the generateWord function to give us our randomly chosen word
			temp = generateWord();
			//count how many times the function runs, and run the hangman function using the randomly chosen word
			timesRan++;
			failed = playHangMan(temp);
			//Store the word from the game before it's wiped out for the next game
			if(timesRan == 1)
			{
				word1 = temp + " ";
			}
			if(timesRan == 2)
			{
				word2 = temp + " ";
			}
			if(timesRan == 3)
			{
				word3 = temp + " ";
			}
			if(timesRan == 4)
			{
				word4 = temp + " ";
			}
			if(timesRan == 5)
			{
				word5 == temp;
			}	
			// the user did not fail to guess the last word, and they still have words left, tell them it's 
			// time for the next word
			if((timesRan < runCount) && (failed == 0))
			{
				cout << "Here's the next word of the phrase:" <<endl;
			}	
		}while((timesRan < (runCount)) && (failed == 0));
		//The user lost on the first word, populate the rest of the phrase to display.
		if(word2.empty())
		{
			word2 = generateWord();
		}
		if(word3.empty())
		{
			word3 = generateWord();
		}
		if((runCount == 4) && (word4.empty()))
		{
			word4 = generateWord();
		}
		if((runCount == 5) && (word5.empty()))
		{
			word5 = generateWord();
		}
		//Print the secret phrase
		cout << "Your secret phrase was:\n";
		totalPhrase = word1 + word2 + word3 + word4 + word5;
		cout << totalPhrase << endl;
		cout << "Would you like to play again? (Y/N)" <<endl;
		cin >> play;
	}while((play == 'y') || play == 'Y');
	



	return 0;
}
string generateWord()
{
	string wordNum, phrase;
	string wordBank[12] = {"POOP", "CHAIR", "YELLOW", "COFFEE", "BOOB", "BABY", "BOXING", "ADDRESS", "REMOTE", "HOMEWORK", "CARPENTRY", "VILLAGE"}; 
	int minWord = 0, maxWord = 11, wordCount, wordOutput = 3;
	//This tells us which words in the array to print                           
	for(int i = 0; i < 1; i++)
	{	
		//Print the array locations to make the phrase
		srand((unsigned)time(NULL));
		wordCount = (rand() % (maxWord + 1 - minWord) + minWord);		
		phrase = wordBank[wordCount];			
	}
        return phrase;	
}                                                                       
int playHangMan(string n)
{
																	
		
		string guessedWord = n;
		string hiddenLetters = guessedWord;	
		//set the hidden letters
		for(int i = 0; i < hiddenLetters.length(); i++)
		{
			hiddenLetters[i] = '-';
		}
	        cout << hiddenLetters << endl;                                                              
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
		bool validGuess;
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
					cout << usedGuessBank <<endl <<endl;                                                                                                             }
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
				return 0;
			}	    	                                                
			//tell player two they failed.
			if(guessCounter == 0)
			{
				cout << "You're out of guesses, and failed to guess the word!\n";
				cout << "The secret word was " << guessedWord <<endl;		
				cout << "Here's what you missed: " <<endl << missedLetters <<endl;
				return 1;
			}

		}while((guessCounter > 0) && (playerTwoWin == false)); 

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
