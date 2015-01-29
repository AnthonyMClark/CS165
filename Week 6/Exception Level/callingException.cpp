#include <iostream>
using namespace std;

void numberFunction(int x, int y);
int main()
{

	int i = 0;
	cout << "How many levels would you like to run the program to? (0-10)\n";
	try
	{
		cin >> i;
		if(i == 0)
		{
			throw i;
		}
		numberFunction(i, 0);
	}
	catch(int e)
	{
		cout << "An exception was thrown at this level." <<endl;
	}
	return 0;
}

void numberFunction(int x, int y)
{
        cout << "Program is currently on level: " << y << endl;
   	y++;
	if(y <= 10)
	{
		if(y <= x)
        	{
			numberFunction(x, y);
		}
		if(y == x || y == 10) 
		{
			throw x;
		}
	}
}
/***********************************************************************
 *I chose to go with this version because it allowed for what I felt was
 *the simplest method of taking the users input, running the function as
 *many times as they specified, and then throwing an error on the level 
 *that they had chosen to throw it. The problem did not specify what is 
 *supposed to happen if we get to the 10th level - do we stop running at 10,
 *do we throw an exception, do we allow them to pass 10 with no error? - 
 *so I chose to throw an exception at the 10th level, just to limit the 
 * options to what the problem specified. Using a recursive function 
 * however, makes putting a limit on the program unnecessary as they can
 * call any value, and we can throw the exception at that level regardless
 * of what it is.
 ** ************************************************************************/
