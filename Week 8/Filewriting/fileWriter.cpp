/**********************************************************
 * Program: 3files.cpp
 * Author: Joshua Smith
 * Description: Takes values from two files, sorts and prints
 * 	them in to a third file.
 * Input: None
 * Output: Creates 3rd file of sorted values.
**********************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void function(ifstream &ifs , ifstream &ifs1 , ofstream &ofs);

int main()
{
	ifstream file1("input.txt"); //Opening the 3 files
	ifstream file2("input2.txt");
	ofstream file3("input3.txt");
	function(file1 , file2 , file3); //Sending the files to the function
	return 0;
}

void function(ifstream &ifs , ifstream &ifs1 , ofstream &ofs)
{
	vector<int> numbers;
	int input, input2;
	
	//Because the files are being passed to a function and they are already opened, this is no longer needed.
//	ifstream ifs("input.txt");
	
	for(int i = 0 ; i < 5 ; ++i) //This loop places the numbers from the first file in the vector
	{
		ifs >> input;
		numbers.push_back(input);
	}

	cout << endl;
	cout << "File number 2 time\n";

//	ifs.close();
//	ifstream ifs1("input2.txt");

	for(int i = 0 ; i < 5 ; ++i) //Places the second file in to the vector
	{
		ifs1 >> input2; 
		numbers.push_back(input2);
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
	
//	ifs1.close();
//	ofstream ofs("input3.txt");
	
	for(int i = 0 ; i < 10 ; ++i) //This prints the vector in to the third file.
	{
		ofs << numbers[i] << " ";
	}

	//And close all the files.
	ifs.close();
	ifs1.close();
	ofs.close();
}

