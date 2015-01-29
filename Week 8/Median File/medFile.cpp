#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	vector<double>numVect;
	double item;
	ifstream ifs("numbers.txt");
  	if (!ifs)
	{
		cout << "Error opening the file. \n";
	}
  	while (ifs.good())  
	{
      		ifs >> item;
		numVect.push_back(item);
	}
   	ifs.close();
   	for (int i = 0; i< numVect.size() - 1; i++)  
   	{
		cout << numVect[i] << endl;
   	}
	//are there an even number of elements in the array?
	int check = (numVect.size())-1;
	if(check % 2 == 0)
	{	
		cout << "The size of the vector is " << check <<endl;
                double temp = check / 2.00;
                double tempHigh = numVect[temp];
                double tempLow = numVect[tempHigh] - 1;
                double final = ((tempHigh + tempLow)/2.00);
                double secondQuart = final;
		cout << secondQuart << endl;
	}
	//is there an odd number, return the middle value
	else
	{
		cout << "The size of the vector is " << check <<endl;
                int temp = (check) / 2.00;
                cout << temp <<endl;	
	}
	return 0;
} 
