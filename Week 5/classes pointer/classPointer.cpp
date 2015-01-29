#include<iostream>
#include<stdio.h>
using namespace std;

class YourCat
{
	public:
		char catsName[10];
		int weight;
		char catFriends[10];

};

int main()
{
	YourCat *arrayPtr;
	YourCat cats[5];
	cout << "Enter your cat's friend" <<endl;
	for(int x = 0; x < 1; x++)
	{
		cin >> cats[x].catFriends;
		arrayPtr = &cats[x];
	}
//	cout << arrayPtr -> catFriends;
	cout << "Your cat's friend is: " <<endl;
	for(int y = 0; y < 5; y++)
	{
		cout << arrayPtr -> catFriends[y];
	}
	cout << endl;
//	cout << arrayPtr -> catFriends[0];
//	cout << endl;
//	for(int y = 0; y < 5; y++)
//	{
//		cout << cats[y].catFriends; 
//		cout << endl;
//	}
	YourCat catInfo={"Lucy", 1100};
	YourCat *ptr;
        ptr = &catInfo;
	cout << "Your cat's name is: ";
//	cout << (*ptr).catsName <<endl;
	cout << ptr->catsName;
	cout <<endl;       
	cout << "Your cat's weight is: ";
//      cout << (*ptr).weight <<endl;
	cout << ptr->weight;
	cout <<endl;
        return 0;
}


