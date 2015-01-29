#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int out;
	string storeInt;
	stringstream stringS;

	cout << "Enter an integer.\n";
	getline(cin , storeInt);
	stringS.str(storeInt);
	stringS >> out;
	while(stringS.fail())
	{
		stringS.clear();
		cout << "Only an integer may be entered\n";
		getline(cin , storeInt);
		stringS.str(storeInt);
		stringS >> out;
	}
	stringS << storeInt;
	stringS >> out;	
    cout << "Your integer is: " << out << endl;

	return 0;
}
