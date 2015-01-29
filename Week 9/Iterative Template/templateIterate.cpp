#include<iostream>
using namespace std;
const int FIX_SIZE = 10;
template<class T>
void search( const T a[ ], int lowEnd, int highEnd,
	int key, bool & found, int & location);

int main()
{
	int a[FIX_SIZE];
	const int lastIndex = FIX_SIZE - 1;
	for (int i = 0; i < FIX_SIZE; i++)
	{
		a[i] = 4 * i;
	}
	cout << "These are the numbers in our array, shown for testing purposes. Pretend it isnt here \n";
	for (int i = 0; i < FIX_SIZE; i++)
        {
                cout << a[i] << " " ;
        }
        cout << endl;

	int key, location;
	bool found;
	cout << "Enter a number to search! NOW!!!\n";
	cin >> key;
	search(a, 0, lastIndex, key, found, location);
	if(found)
	{
		cout << "We have found your number at " << location << endl;
	}
	else
	{
		cout << key << " was not in the array. What a horrible search. Truly terrible.\n";
	}	

	return 0;
}
template<class T>
void search( const T a[ ], int lowEnd , int highEnd,
	int key, bool & found, int & location)
{
	int first = lowEnd;
	int last = highEnd;
	int mid;
	found = false ; //so far
	while ((first <= last) && !(found))
	{
		mid = (first + last)/2;
		if (key == a[mid])
		{
			found = true ;
			location = mid;
		}
		else if (key < a[mid])
		{
			last = mid - 1;
		}
		else if (key > a[mid])
		{
			first = mid + 1;
		}
	}
}
