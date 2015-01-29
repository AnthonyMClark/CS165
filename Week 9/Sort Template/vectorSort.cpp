#include<iostream>
#include<vector>
using namespace std;
template<class T>
//vector<int>
void insertion_sort(vector<T> &x, int length)
{
	int index,j;
  	for(int i = 1; i < length; i++)
  	{
     		index = x[i];
     		j = i - 1;
     		while(x[j] > index && j >= 0)
     		{
	       		x[j+1] = x[j];
	 		j--;
     		}
     		x[j + 1] = index;
  	}
}
int main()
{
	cout << string(50, '\n');
	vector<int>vect;
	int size;
	cout << "How many numbers?\n";
	cin >> size;
  	cout << "Enter numbers\n";
	int i;
	int sizeCount = 0;
	while (sizeCount < size) 
	{
		cin >> i;
		vect.push_back(i);
		sizeCount++;
	}
  	cout<<"Here are the numbers you entered:\n";
  	for(int i = 0; i < size; i++)
  	{
  		cout << vect[i] << " " << endl; 
	}
	insertion_sort(vect, size);
  	cout<<endl <<"Here are your numbers sorted:\n";
  	for(int i = 0; i < size; i++)
  	{
		cout << vect[i] << " " << endl;
  	}
	cout << "Now insert a new number into the vector:\n";
	cin >> i;
	vect.push_back(i);
	cout << "Here's your new number inside the vector:\n";
	for(int i = 0; i < size + 1; i++)
        {
                cout << vect[i] << " " << endl;
        }
	insertion_sort(vect, size + 1);
	cout << "Here is your vector, sorted again, with the new number:\n";
	for(int i = 0; i < size + 1; i++)
        {
                cout << vect[i] << " " << endl;
        }
	return 0;
}
