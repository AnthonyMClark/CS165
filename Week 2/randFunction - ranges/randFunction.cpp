#include<iostream>
#include<cstdlib>
using namespace std;

int rand_int(int min, int max);

int main()
{
	int minNum, maxNum, rangeNum;
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
	rangeNum = rand_int(minNum, maxNum);
	cout << "Your random number is " << rangeNum << endl;
	return 0;
}

int rand_int(int min, int max)
{
	int result;
	result = rand() % (max + 1 - min) + min;
	return result;
}  	
