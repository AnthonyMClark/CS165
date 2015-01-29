/**********************************************************
 * Program: stringstream.cpp
 * Author: Joshua Smith
 * Description: This program uses stringstream to extract
 * 	an integer from a string.
 * Input: An integer
 * Output: The extracted integer in an int variable
**********************************************************/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int out;
	string str1;
	stringstream ss;

	cout << "Please input an integer into the string.\n";
	getline(cin , str1);
	ss.str(str1);
	ss >> out;
	while(ss.fail())
	{
		ss.clear();
		cout << "You must enter an integer.\n";
		cout << "Please enter an integer.\n";
		getline(cin , str1);
		ss.str(str1);
		ss >> out;
	}

	cout << "Now we can place the str into the string stream and then extract the int from the stream.\n";

	ss << str1;

	ss >> out;	

        cout << "The integer has been extracted into an int variable and is: " << out << endl;

	return 0;
}
