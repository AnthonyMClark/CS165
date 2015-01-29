#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;

void sumFunction(int integers[], int size); 

int main( )
{	
	int sum;	
	int size = 5; 
	int integers[size];
	sumFunction(integers, size);
	return 0;

}
void sumFunction(int integers[], int size)
{	
	int nonDigit = 0;
	int sum = 0;
	cout << "Enter " << size << " integers.\n";
	for (int i = 0; i < 5; i++)
        {
		cin >> integers[i];
           	while(!cin.good())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter an integer.\n";
			cin >> integers[i];
		}	
		sum = sum + integers[i];
	
	}
	cout << "The sum of your integers is " << sum << endl;	
}
