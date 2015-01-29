#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void function(ifstream &ifs , ifstream &ifs1 , ofstream &ofs);

int main()
{
	ifstream file1("inputNum.txt"); 
	ifstream file2("inputNum2.txt");
	ofstream file3("inputNum3.txt");
	function(file1 , file2 , file3); 
	return 0;
}

void function(ifstream &ifs , ifstream &ifs1 , ofstream &ofs)
{
	vector<int> numbers;
	int inputNum, inputNum2;
		
	for(int i = 0 ; i < 5 ; ++i) //This loop places the numbers from the first file in the vector
	{
		ifs >> inputNum;
		numbers.push_back(inputNum);
	}

	cout << endl;
	cout << "File number 2 time\n";

	for(int i = 0 ; i < 5 ; ++i) 
	{
		
		ifs1 >> inputNum2; 
		numbers.push_back(inputNum2);
	}

	//Cout pre-sorted vector
	for(int i = 0 ; i < 10 ; ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	
	sort(numbers.begin() , numbers.end());
	
	//Cout sorted vector #winning
	for(int i = 0 ; i < 10 ; ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	
	
	for(int i = 0 ; i < 10 ; ++i) //This prints the vector in to the third file.
	{
		ofs << numbers[i] << " ";
	}

	//And close all the files.
	ifs.close();
	ifs1.close();
	ofs.close();
}

