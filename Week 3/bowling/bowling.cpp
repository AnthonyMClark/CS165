#include<iostream>
#include<cstdlib>
using namespace std;

int bowlingPins(int n);

int main()
{
	int rows, needed;
	cout << "How many rows of pins would you like?\n";
	cin >> rows;
	needed = bowlingPins(rows);
	cout << "You would need " << needed << " pins to make " << rows << " rows." <<endl;
	return 0;
}

int bowlingPins(int n)
{
 
	if (n == 1)
	{ 
		return 1; 
	}
	else
	{ 
		return (n + bowlingPins(n - 1)); 
	}
} 
	


