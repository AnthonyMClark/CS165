#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i <= 9; i++)
	{
		cout << rand() << endl;
	}
 
	return 0;
}
