#include<iostream>
using namespace std;
const int FIX_SIZE = 10;
template<class T>
void search(const T a[], int first, int last, int key, bool& found, int & location);


int main()
{
	int a[FIX_SIZE];
	const int finalIndex = FIX_SIZE - 1;
	int key, location;
	bool found;
	for(int i = 0; i < FIX_SIZE; i++)
	{
		a[i] = 4 * i;
	}
	cout << "Here are the numbers in our array, shown for testing purposes. Pretend it's not here\n";
	for(int i = 0; i < FIX_SIZE; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Enter a number to be located. NOW!!!\n";
	cin >> key;
	search(a, 0, finalIndex, key, found, location);
	if(found)
	{
		cout << key << " is in index location " << location << endl;
	}
	else
	{
		cout << key << " is not in the array.\n";
	}
	return 0;
}
template<class T>
void search(const T a[], int first, int last, int key, bool& found, int & location)
{
	int mid;
	if(first > last)
	{
		found = false;
	}
	else
	{
		mid = (first + last)/2;
		if(key == a[mid])
		{
			found = true;
			location = mid;
		}
		else if(a[mid] > key)
		{
			search(a, first, mid - 1, key, found, location);
		}
		else if(key > a[mid])
		{
			search(a, mid + 1, last, key, found, location);
		}
	}
}



