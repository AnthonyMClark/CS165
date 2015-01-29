#include<iostream>
using namespace std;

void isAPointer(int *n);

int main()
{
	cout << "Enter a whole number." <<endl;
	int aNum;
	cin >> aNum;
	isAPointer(&aNum);
	cout << "That number is now: ";
	cout << aNum <<endl; 

	return 0;
}


void isAPointer(int *n)
{
	*n += 10;
}
