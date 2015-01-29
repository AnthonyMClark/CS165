#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
#include<cstddef>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include<ctype.h>
using namespace std;

bool guessValidity(string guessedWord);
void playHangMan();
void playNumberGuess();
int playPhraseMan(string n);
string generateWord();
void runPhraseMan();
void tictactoe();

int main()
{
	int game;
	char play;
	do
	{
		int valid = 0;
		do
		{
			cout << endl << endl << endl << endl 
				<<"WELCOME TO TONY'S GAME STATION\n\n"
				<< "Choose a game:\n"
				<< "1. Number Guess\n"
				<< "2. Hang Man\n"
				<< "3. Hang Man: Phrase Edition\n"
				<< "4. Tic Tac Toe\n"
				<< "5. Exit\n"
				<< "Enter your choice: ";
			cin >> game;
			//Run the number guess game
			if(game == 1)
			{
				playNumberGuess();
			}
			//Run word guess
			else if(game == 2)
			{
				playHangMan();
			}
			//Run the phrase game
			else if(game == 3)
			{
				runPhraseMan();
			}
			else if(game == 4)
			{
				tictactoe();
			}
			//Exit the program.
			else if(game == 5)
			{
				return 0;
			}
			//They didn't enter an item on the menu. Tell them and show the menu again
			else if((game < 1) || (game > 5))
			{
				cout << "You've made an invalid menu selection. Please pick again.\n";
				valid = 1;
			}
		}while(valid == 1);
		//ask if they would like to play another game and send them back to the menu if they do.
		cout << "Would you like to play another game? (Y/N)\n";
		cin >> play;
	}while(play == 'Y' || play == 'y');
	return 0;
}

void tictactoe()
{
	char winner;
	bool playerWin = false;
	int choice;
	char board[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	do{
		int player = (player % 2) ? 1:2;
    		char markIt = (player == 1) ? 'X' : 'O';
		for (int i = 0; i < 3; i++)
		{
			cout << board[i] << " ";
		}
		cout << endl;

		for (int i = 3; i < 6; i++)
		{
			cout << board[i] << " ";
		} 
		cout << endl;

		for (int i = 6; i < 9; i++)
		{
			cout << board[i] << " ";
		}
		cout << endl;
	
		cout << "Select your location by picking the corresponding number position." << endl;
		cin >> choice;
		//test if it's a match
	
		if(choice == 1)
		{
			cout << "You've chosen " << choice <<endl;
			board[0] = markIt;
		}
		if(choice == 2)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[1] = markIt;
                }
		if(choice == 3)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[2] = markIt;
                }
		if(choice == 4)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[3] = markIt;
                }
		if(choice == 5)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[4] = markIt;
                }
		if(choice == 6)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[5] = markIt;
                }
		if(choice == 7)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[6] = markIt;
                }
		if(choice == 8)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[7] = markIt;
                }
		if(choice == 9)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[8] = markIt;
                }
		//check for wins
		if((board[0] == 'O') && (board[3] == 'O') && (board[6] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		}
		if((board[0] == 'X') && (board[3] == 'X') && (board[6] == 'X'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		}	
		if((board[0] == 'O') && (board[1] == 'O') && (board[2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		}
		if((board[0] == 'X') && (board[1] == 'X') && (board[2] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
                }
		if((board[0] == 'O') && (board[4] == 'O') && (board[8] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		}
		if ((board[0] == 'X') && (board[4] == 'X') && (board[8] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
                }
		if((board[1] == 'O') && (board[4] == 'O') && (board[7] == 'O'))
		{	
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		}
		if((board[1] == 'X') && (board[4] == 'X') && (board[7] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
	        }
		if((board[2] == 'O') && (board[4] == 'O') && (board[6] == 'O'))
                {
                        playerWin = true;
                        cout << "Player " << player << " wins!" <<endl;
                }
		if((board[2] == 'X') && (board[4] == 'X') && (board[6] == 'X'))
                {
                        playerWin = true;
                        cout << "Player " << player << " wins!" <<endl;
                }
		if((board[2] == 'O') && (board[5] == 'O') && (board[8] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		}
		if((board[2] == 'X') && (board[5] == 'X') && (board[8] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
                }
		if((board[3] == 'O') && (board[4] == 'O') && (board[5] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;	
		}
		if((board[3] == 'X') && (board[4] == 'X') && (board[5] == 'X'))
		{
                        playerWin = true;
			 cout << "Player " << player << " wins!" <<endl;
                }
		if((board[6] == 'O') && (board[7] == 'O') && (board[8] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
		} 
		if((board[6] == 'X') && (board[7] == 'X') && (board[8] == 'X'))
		{
 			playerWin = true;
			cout << "Player " << player << " wins!" <<endl;
                }
		
		--player;
	}while(playerWin == false);			   
}

void runPhraseMan()
{
	string word1, word2, word3, word4, word5, totalPhrase;
	char play;
	//Get a random amount of words for the user to guess
	srand((unsigned)time(NULL));
	int runCount = 3 + (rand() % (int)(5 - 3 + 1));
	
		
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
		failed = playPhraseMan(temp);
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
}            

int playPhraseMan(string n)
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
				cout << usedGuessBank <<endl <<endl;                                                                                                             		}
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

void playNumberGuess()
{
	
	int secretNumber_max;
	int secretNumber_min; 
	int guessedNumber;
	int secretNumber;
	int chancesToGuess;
	int guessCounter = 0;
	int playerTwoWin = false;
	int closestGuess;
	int playAgain;
	int nonDigit = 0;
	//Get the secret number and confirm that it is between the allowed range of 0-100
	do
	{
			
		cout << "Let's play a game! Player one, you will pick a secret number between 0 and 100.\n"
		<< "Player Two, you will attempt to guess the secret number.\n";
		cout << "Player One, pick a number between 0 and 100.\n";
		cin >> secretNumber;
		while(!(cin.good()))
		{
			cout << "You did not enter a number. Please try again.\n";
			cin.clear();
			cin.ignore();
			cin >> secretNumber;
		}
		if(1 > secretNumber || secretNumber > 100)
		{
			cout << "Let's try again. Pick a number between 1 and 100.\n";
			secretNumber = 0;
		}
	}while(1 > secretNumber || secretNumber > 100);
	//Get the number of chances the user has to guess the number and make sure it's in range of 0-10
	do
	{
		cout << "How many guesses would you like to allow Player Two? You can choose up to 10.\n";	
		cin >> chancesToGuess;
		while(!(cin.good()))
		{
			cout << "You did not enter a number. Please try again.\n";
			cin.clear();
			cin.ignore();
			cin >> chancesToGuess;
		}
		if(1 > chancesToGuess || chancesToGuess > 10)
		{
			cout << "Let's try again. Pick a number between 1 and 10.\n";
			chancesToGuess = 0;
		}
		else
		{
			cout << "Player Two, Player One graciously gave you " << chancesToGuess 
			<< " chances to correctly guess the number! Good luck!\n";
		}
	}while(1 > chancesToGuess || chancesToGuess > 10);
																																											while(guessCounter < chancesToGuess && playerTwoWin == false)
	{
		//Get the guess from Player Two
		do
		{
			cout << "You have: " << chancesToGuess - guessCounter << " guesses remaining.\n";
			cout << "Enter your guess.\n";
			cin >> guessedNumber;
			while(!(cin.good()))
			{
				cout << "You did not enter a number. Please try again.\n";
				cin.clear();
				cin.ignore();
				cin >> guessedNumber;
			}
			if(1 >  guessedNumber || guessedNumber > 100)
			{
				cout << "Let's try again. Guess a number between 1 and 100.\n";
				guessedNumber = 0;
			}
		}while(1 > guessedNumber || guessedNumber > 100);
		//Evaluate the guess for a new range
		//Guess was too high
		if(guessedNumber > secretNumber)
		{
			cout<< "Your guess was too high!\n";
			guessCounter++;
			cout<< "You have " << chancesToGuess - guessCounter << " chances remaining!\n";
			secretNumber_max = guessedNumber - 1;
			closestGuess = guessedNumber - secretNumber;
		}
		//Guess was too low
		else if(guessedNumber < secretNumber)
		{
			cout<< "Your guess was too low!\n";
			guessCounter++;
			cout<< "You have " << chancesToGuess - guessCounter << " chances remaining!\n";
			secretNumber_min = guessedNumber + 1;
			closestGuess = secretNumber - guessedNumber;
		}
		//Guess was neither high or low, so it must have been right
		else
		{
			cout<< "You guessed the secret number! Nice job!\n";
			playerTwoWin = true;
		}
	}
	cout << "The secret number was: " << secretNumber << endl;
	if(!(guessedNumber == secretNumber))
	{	
		cout << "Your closest guess was: " << closestGuess << " numbers away"  << endl;
	}
	chancesToGuess = 0;
	guessCounter = 0;    												
}

void playHangMan()
{
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
				cout << usedGuessBank <<endl <<endl;                                                                                                                            }
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
