#include<iostream>
#include<stdlib.h>
using namespace std;

void isAPointer(int *n);

int main(int argc, char* argv[])
{
	cout << "Enter a whole number." <<endl;
        int aNum  = atoi(argv[1]);
	isAPointer(&aNum);
        cout << "That number is now: ";
        cout << aNum <<endl;

        return 0;
}


void isAPointer(int *n)
{
        *n += 10;
}

