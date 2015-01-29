#include<iostream>
#include<string>
using namespace std;

bool string_comp(string stringOne, string stringTwo); 

main()
{	
	bool stringTest;
	string string_1, string_2;
	cout << "We're going to compare two strings.\n";
	cout << "Enter the first string.\n";
	getline(cin, string_1);
	cout << "Now enter the second string.\n";
	getline(cin, string_2);
	stringTest = string_comp(string_1, string_2);
	if (stringTest)
	{
		cout << "You entered two similar strings.\n";
	}
	else
	{
		cout << "You entered two different strings.\n";  
	} 
	return 0; 
}

bool string_comp(string stringOne, string stringTwo)
{
	return (stringOne == stringTwo);
}

