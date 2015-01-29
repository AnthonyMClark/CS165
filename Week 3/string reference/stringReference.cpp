#include<iostream>
#include<string>
using namespace std;

void string_comp(string &stringOne, string &stringTwo, string &comparison); 

int main()
{	
	string string_1, string_2, comparison;
	cout << "We're going to compare two strings.\n";
	cout << "Enter the first string.\n";
	getline(cin, string_1);
	cout << "Now enter the second string.\n";
	getline(cin, string_2);
	string_comp(string_1, string_2, comparison);
	cout << comparison << endl; 
	return 0; 
}

void string_comp(string &stringOne, string &stringTwo, string &comparison)
{
	if(stringOne.compare(stringTwo) == 0) 
	{
		comparison = "You entered two similar strings.\n";
	}
	else
	{
		comparison = "You entered two different strings.\n";
	}
}

