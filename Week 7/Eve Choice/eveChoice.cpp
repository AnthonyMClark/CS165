#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int>men;
	int number, count = 0;
	cout << "Enter the number of desperate men.\n";
        cin >> number;
	for(int i = 1; i <= number; i++)
	{	
		men.push_back(i);
		cout << men[i-1] <<endl;
	}
	do
	{
		for(int i = 0; i < men.size(); i++)
		{
			count = count+1;
			if(count == 3)
			{
			//	cout << i;
				cout << men[i] << " isn't desperate enough\n";
				men.erase(men.begin()+i);
				count = 0;
				i--;
			}
		}
		cout << endl;
	}while(men.size() > 1);
	cout << men[0] << " is the most desperate man of all!\n";
	return 0; 
        
}       



