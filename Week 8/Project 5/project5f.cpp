#include<iostream>
#include<cstdlib>
using namespace std;

class Life 
{
	int width, height;
	bool world [80][22];
	public:
		Life(int a, int b, int c);
		void generation();
		void display();
};
int main () 
{	
	int inputHeight = 80, inputWidth = 22;
	char runGen;
	int nextGen = 0;
	int number = 0;
	cout << "Enter a pattern selection (1-4) to run, where 4 is a random choice:\n";
	while(number > 4 || number < 1)
	{
		cin >> number;
		if(number > 4 || number < 1)
		{
			cout << "Improper selection. Choose a number from 1 to 4.\n";
		}
	}
	Life life(inputHeight, inputWidth, number);
	life.display();
	cout << endl;
	do 
	{
		nextGen = 0;
//		cout << "Press Enter to give life to the next generation!\n";
		cout << "Enter B to give birth to the next generation!\n";
		cout << "Enter any other key to exit the program and end all life!\n";
		cin >> runGen;
		if(runGen == 'B' || runGen == 'b')
		{
			nextGen = 1;
		}
/*		if(cin.get() != '\n')
		{
			nextGen = 1;
		}*/		
		life.generation();
		life.display();
		cout << endl;
	}while (nextGen == 1);	
	cout << "You are a cruel God!\n";
	cout << "Thanks for playing.\n";
	return 0;
}
Life::Life(int a, int b, int c) 
{
	height = a;
	width = b;
	int option = c;
	//Options for thr user to have different entrty patterns 
        if(option == 1)
	{
        	world[0][1] = true;
        	world[1][2] = true;
        	world[2][0] = false;
        	world[2][1] = false;
	}
	if(option == 2)
	{
		world[0][1] = false;
		world[1][2] = true;
		world[2][0] = true;
		world[2][1] = true;
		world[2][2] = false;	
	}
	if(option == 3)
	{
	        world[0][1] = false;
                world[1][2] = true;
                world[2][0] = false;
                world[2][1] = true;
                world[2][2] = false;
	}
	//run a random selection
        if(option == 4)
        {
		int randomStart = (rand()%2); 
	       	if((randomStart) == 0)
                {
                        world[0][1] = false;
                        world[1][2] = false;
                        world[2][0] = false;
                        world[2][1] = false;
			world[2][2] = false;
                }
                else
                {
                        world[0][1] = true;
                        world[1][2] = true;
                        world[2][0] = true;
                        world[2][1] = true;
                }
	}
}
void Life::generation() 
{
	//default 0 for neighbouring cells
	int neighbourCount = 0;
	//where we will store the changes before setting it to our actual world array
	bool tempWorld [height][width];
	
	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			//Test all 8 surrounding cells and if they have an X, count a neighbour
			if ((i+1) < height && world[i + 1][j] == true)
			{
				neighbourCount++;
			}
			if ((i-1) >= 0 && world[i - 1][j] == true)
			{
				neighbourCount++;
			}
			if ((j+1) < width && world[i][j+1] == true)
			{
				neighbourCount++;
			}
			if ((j-1) >= 0 && world[i][j-1] == true)
			{
				neighbourCount++;
			}
                        if ((i-1) >= 0 && (j+1) < width && world[i-1][j+1] == true)
                        {
                                neighbourCount++;
                        }
                        if ((i-1) >= 0 && (j-1) >= 0 && world[i-1][j-1] == true)
                        {
                                neighbourCount++;
                        }

			if ((i+1) < height && (j+1) < width && world[i+1][j+1] == true)
			{
				neighbourCount++;
			}
			if ((i+1) < height && (j-1) >= 0 && world[i+1][j-1] == true)
			{
				neighbourCount++;
			}
			//< 2 and > 3? Kill the cell	
			if (neighbourCount < 2 || neighbourCount > 3)
			{
				tempWorld[i][j] = false;
			}
			//Didn't apply to any of the rules? Just twiddle your thumbs
			else if (neighbourCount == 2)
			{
				tempWorld[i][j] = world[i][j];
			}
			//Three neighbors? Birth a new cell
			else if (neighbourCount == 3)
			{
				tempWorld[i][j] = true;
			}
			neighbourCount = 0;			
		}
	}	
	for (int i = 0 ; i < height ; i++)
	{
		for (int j = 0 ; j < width ; j++)
		{
			//set the temp array to the world array so we can print the new vals
			world[i][j] = tempWorld[i][j];
		}
	}
}
void Life::display() 
{
	for (int i = 0; i < height ; i++)
	{
		for (int j = 0 ; j < width ; j++)
		{
			if (world[i][j] == true)
			{
				cout << "x";
			}
			else
			{
				cout << " ";
			}
			if ((j + 1) >= width)
			{
				cout << endl;
			}
		}
	}
}
