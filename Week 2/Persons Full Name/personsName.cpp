#include<iostream>
#include<string>
using namespace std;

int main()
{
	int nameSpace1 = 0, nameSpace2 = 0;	
	string totalName, firstName, middleName, lastName;
	cout << "Please enter your full name.\n";
	getline(cin, totalName);
	// we search the getline for the first space entered
	nameSpace1 = totalName.find_first_of(" ");
	//we go backwards from the first space to 0 to find the first name
	firstName = totalName.substr(0, nameSpace1);
	//we then go from the space forward to find the second space
	totalName = totalName.substr(nameSpace1 + 1, totalName.length());
	nameSpace2 = totalName.find_first_of(" ");
	// check to see both spaces are in place and then print out all three names
	if(nameSpace2 != -1)
	{
		middleName = totalName.substr(0, nameSpace2);
		lastName = totalName.substr(nameSpace2 + 1, totalName.length()); 
		cout << lastName << ", " << firstName << " " << middleName.at(0) << "." << endl;
	}
	//there is no second space, print only the first and last name
	else
	{
		cout << totalName << ", " << firstName << endl;
	}
	
		
	return 0;
}

//Code for this problem was devised with Joshua Cody and Ben Hobbs
