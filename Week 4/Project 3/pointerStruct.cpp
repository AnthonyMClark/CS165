#include<iostream>
#include<stdio.h>
using namespace std;

struct YourCat
{
	char catsName[10];
	int weight;
	char catFriends[5];

};

int main()
{
	YourCat cats[5];
	cout << "Enter your cat's friends" <<endl;
	for(int x = 0; x < 5; x++)
	{
		cin >> cats[x].catFriends;
	}
	for(int y = 0; y < 5; y++)
	{
		cout << cats[y].catFriends <<endl;
	}
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


