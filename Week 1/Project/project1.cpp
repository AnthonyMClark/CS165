#include<iostream>
using namespace std;
int main()
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
	
	do{

		//Get the secret number and confirm that it is between the allowed range of 0-100
		do
		{
			cout << "Let's play a game! Player one, you will pick a secret number between 0 and 100.\n"
				<< "Player Two, you will attempt to guess the secret number.\n";
			cout << "Player One, pick a number between 0 and 100.\n";
			cin >> secretNumber;
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
			if(1 > chancesToGuess || chancesToGuess > 10)
			{
				cout << "Let's try again. Pick a number between 1 and 10.\n";
				chancesToGuess = 0;
			}
			cout << "Player Two, Player One graciously gave you " << chancesToGuess 
				<< " chances to correctly guess the number! Good luck!\n";
		}while(1 > chancesToGuess || chancesToGuess > 10);
																																																														
		while(guessCounter < chancesToGuess && playerTwoWin == false)
		{
			//Get the guess from Player Two
			do
			{
		
			cout << "You have: " << chancesToGuess - guessCounter << " guesses remaining.\n";
			cout << "Enter your guess.\n";
			cin >> guessedNumber;
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
		cout << "Your closest guess was: " << closestGuess << " numbers away"  << endl;
		chancesToGuess = 0;
		guessCounter = 0;    																																																																																																																																													
		cout<< "Enter 1 to play again or 2 to exit.\n";
		cin >> playAgain;																																													
	}while(playAgain == 1);	
	cout << "Good game! Thanks for playing.\n";	
	return 0;
}
