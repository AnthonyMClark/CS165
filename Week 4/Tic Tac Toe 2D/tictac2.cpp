#include<iostream>

using namespace std;

int main()
{
	char winner;
	bool playerWin = false;
	int choice;
	char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	do{
		int player = (player % 2) ? 1:2;
    		char markIt = (player == 1) ? 'X' : 'O';
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				cout << board[r][c];
				cout << " ";
			}
			cout <<endl;
			
		}
		cout << endl;
	
		cout << "Select your location by picking the corresponding number position." << endl;
		cin >> choice;
		//test if it's a match
	
		if(choice == 1)
		{
			cout << "You've chosen " << choice <<endl;
			board[0][0] = markIt;
		}
		if(choice == 2)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[0][1] = markIt;
                }
		if(choice == 3)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[0][2] = markIt;
                }
		if(choice == 4)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[1][0] = markIt;
                }
		if(choice == 5)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[1][1] = markIt;
                }
		if(choice == 6)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[1][2] = markIt;
                }
		if(choice == 7)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[2][0] = markIt;
                }
		if(choice == 8)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[2][1] = markIt;
                }
		if(choice == 9)
                {
                        cout << "You've chosen " << choice <<endl;
                        board[2][2] = markIt;
                }
		//check for wins
		if((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}	
		if((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[0][1] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
                }
		if((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if ((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
                }
		if((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O'))
		{	
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
	        }
		if((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		}
		if((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X'))
		{
                        playerWin = true;
			cout << "Player " << player << " wins!";
                }
		if((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";	
		}
		if((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X'))
		{
                        playerWin = true;
			 cout << "Player " << player << " wins!";
                }
		if((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O'))
		{
			playerWin = true;
			cout << "Player " << player << " wins!";
		} 
		if((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X'))
		{
 			playerWin = true;
			cout << "Player " << player << " wins!";
                }
		--player;
	}while(playerWin == false);			   
}
