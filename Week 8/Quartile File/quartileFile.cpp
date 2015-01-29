#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	vector<double>numVect;
	double item;
	ifstream ifs("numbers2.txt");
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
		double firstQuart = final / 2.00; 
		cout << "First Quartile: " << firstQuart << endl;
		cout << "Second Quartile: " << secondQuart << endl;
		double thirdQuart = firstQuart + secondQuart;
		cout << "Third Quartile: " << thirdQuart << endl;
	} 
	//is there an odd number, return the middle value
	else
	{
		cout << "The size of the vector is " << check <<endl;
	        double temp = (check) / 2.00;
		double odd2Quart = numVect[temp];
		double odd1Quart = odd2Quart / 2.00;
		cout << "First Quartile: " << odd1Quart <<endl;
	        cout << "Second Quartile: " << odd2Quart <<endl;
		double odd3Quart = odd1Quart + odd2Quart;
		cout << "Third Quartile: " << odd3Quart << endl;
	}
	return 0;
} 
