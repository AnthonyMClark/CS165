#include<iostream>
#include<string>
using namespace std;

int main()
{
	string my_str;
	cout << "Enter your name.\n";
	getline (cin,my_str);
	for (int i = 0; i < my_str.length(); i++)
	{
		cout<< my_str.at(i) << " " << endl;
		
	}
        for (int i = my_str.length()-1; i >= 0; i--)
	{
		cout<< my_str.at(i) << " " << endl;
	}
	for (int i = 0; i < my_str.length(); i++)
	{
		if(i = my_str.length())
		{
			cout << "You have " << i << " characters in your string\n";
		}
	}


	return 0;

}
