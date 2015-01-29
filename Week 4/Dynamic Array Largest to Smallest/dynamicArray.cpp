#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;

int main() 
{
    	int maxtemp = 0, mintemp = 10000000;
	int *array;
	array = new int [5];
	cout << "Add 5 integers to the array.\n";	
	for(int i = 0; i < 5; i++)
    	{	
		cin >> array[i];
		while(!cin.good()) 
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a digit.\n";
			cin >> array[i];
		}
		if(array[i] > maxtemp)
		{
			maxtemp = array[i];
		}
		if(array[i] < mintemp)
		{
			mintemp = array[i];
		}
	}
	cout << "The biggest number is " << maxtemp << ". The small is " << mintemp << "." <<endl;
}

