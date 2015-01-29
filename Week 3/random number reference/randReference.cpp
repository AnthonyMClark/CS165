#include<iostream>
#include<cstdlib>
using namespace std;

void rand_int(int min, int max, int &val);

int main()
{
	int minNum, maxNum, val;
	do 
	{
		cout << "Enter the maximum number for your number range.\n";
		cin >> maxNum;
		cout << "Enter the minimum number for your number range.\n"; 
		cin >> minNum;
		if(minNum > maxNum)
		{
			cout << "Your minimum range value is greater than your max range value.\n";
			cout <<	"Please reenter your range." << endl;
		}
	}while(minNum > maxNum);
	rand_int(minNum, maxNum, val);
	cout << "Your random number is " << val << endl;
	return 0;
}

void rand_int(int min, int max, int &val)
{
	val = rand() % (max + 1 - min) + min;
}  	
