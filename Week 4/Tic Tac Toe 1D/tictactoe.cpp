#include<iostream>

using namespace std;

int main()
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
			cout << "Player " << player << " wins!";
		}
		if((board[0] == 'X') && (board[3] == 'X') && (board[6] == 'X'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}	
		if((board[0] == 'O') && (board[1] == 'O') && (board[2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[0] == 'X') && (board[1] == 'X') && (board[2] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
                }
		if((board[0] == 'O') && (board[4] == 'O') && (board[8] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if ((board[0] == 'X') && (board[4] == 'X') && (board[8] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
                }
		if((board[1] == 'O') && (board[4] == 'O') && (board[7] == 'O'))
		{	
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[1] == 'X') && (board[4] == 'X') && (board[7] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
	        }
		if((board[2] == 'O') && (board[5] == 'O') && (board[8] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[2] == 'X') && (board[5] == 'X') && (board[8] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
                }
		if((board[3] == 'O') && (board[4] == 'O') && (board[5] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";	
		}
		if((board[3] == 'X') && (board[4] == 'X') && (board[5] == 'X'))
		{
                        playerWin = true;
			 cout << "Player " << player << " wins!";
                }
		if((board[6] == 'O') && (board[7] == 'O') && (board[8] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		} 
		if((board[6] == 'X') && (board[7] == 'X') && (board[8] == 'X'))
		{
 			playerWin = true;
			cout << "Player " << player << " wins!";
                }

		--player;
	}while(playerWin == false);			   
}
