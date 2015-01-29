#include<iostream>
#include<fstream>
#include "headerFinal.h"
#include<vector>
#include<algorithm>
#include<string>
#include <boost/lexical_cast.hpp>
using namespace std;
namespace clarkant
{
	struct hof
	{
		string playerName, score, record, printScores; 
		char greeting[20];
		char hof;
		/*bool operator > (const hof &a, const hof &b)
		{
		 	return 
		}*/
	};
	void bestScore(int playerScore)
	{
		hof hofObj;
		cout << "Please enter your name: \n";
		getline(cin, hofObj.playerName);
		cout << "Thanks, " << hofObj.playerName << " your current score has been recorded in the hall of fame/shame!\n";
		hofObj.score = boost::lexical_cast<std::string>(playerScore);
		ofstream scoreFile;
		string spacer = " scored: ";
		hofObj.record = hofObj.playerName + spacer + hofObj.score;
		scoreFile.open("scores.txt", std::ios_base::app);
		vector<string>topScores;
		topScores.push_back(hofObj.record);
	        cout << endl;
		for(int i = 0; i < 1; i++)
        	{
                	scoreFile << topScores[i] << " " << endl;
        	}
		scoreFile.close();
		cout << "Would you like to view how your score compares to the best?(Y or N)\n"; 
		cin >> hofObj.hof;
	        hof *arrayPtr;
	      	hof date[10];
//	      	hof *date;
//		date = new char[10];
		// This will not be stored in HoF, it's for showing pointers only
	        cout << "Enter the date (dd/mm/yy)" <<endl;
	        for(int x = 0; x < 1; x++)
	        {
       		        cin >> date[x].greeting;
                	arrayPtr = &date[x];
        	}
		if(hofObj.hof == 'y' || hofObj.hof == 'Y')
		{

			//make a whole bunch of endlines to clear the screen
                	for (int b=0; b<=50; b++)
                        {
                        	cout<<endl;
                        }     		                                        
			cout << "Here are the best scores as of: " <<endl;
                	for(int y = 0; y < 8; y++)
                	{
                	        cout << arrayPtr -> greeting[y];
        	        }
	                cout << endl;
			//dynamic array
			string *dynArray;
			dynArray = new string[100];
			//end dyn array
			hofObj.printScores;
			ifstream scoreFileOut;
			scoreFileOut.open("scores.txt");
			while(getline(scoreFileOut, hofObj.printScores))
        		{
				// save date into dynamic array
				for(int i = 0; i < 1; i++)
				{
					dynArray[i] = hofObj.printScores;
				}
				// print information from dyn array
				for(int j = 0; j < 1; j++)
				{
					cout << dynArray[j] <<endl;
				}
			//	cout << hofObj.printScores << endl;
        		}
			delete[] dynArray;
		        dynArray = NULL;
			scoreFileOut.close();	
		}
		else
		{
			cout << "That's fine, you weren't that good anyway\n";
		}

	}

}


