#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;
int main()
{
	int choice;
	string yourName, searchName, removeName;
	vector<string>log;
	do{
		cout << "Welcome to the building. What would you like to do?";
		cout << endl;
		cout << "1: Log your name." << endl;
		cout << "2: Search a name." << endl;
		cout << "3: Remove your name from the log." << endl;
		cout << "4: Exit." << endl << endl << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter your name for the log.\n";
			cin >> yourName;
			log.push_back(yourName);
		}
		if (choice == 2)
		{
			cout << "Enter a name to search\n";
			cin >> searchName;
			int found = 0;
			for(int i = 0; i < log.size(); i++)
			{
				if(log.at(i) == searchName)
				{
					cout << searchName << " is in the building.\n";
					cout << endl;		
					found = 1;
				}		
			}
			if(found == 0)
			{
				cout << searchName << " is not currently in the building.\n";
				cout << endl;
			}
			
		}
                   
		if (choice == 3)
        	{
			cout << "Enter your name to remove it from the log.\n";
			cin >> removeName;
                	for(int i = 0; i < log.size(); i ++)
                	{
                        	if(log.at(i) == removeName)
                        	{
                                	log.erase(log.begin() + i); 	
                        	}
                	}
        	}

	}while(choice != 4);
	return 0;
}
