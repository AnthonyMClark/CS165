#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>  
using namespace std;

main ()
{	
	int randOne, randTwo, randThree, randFour;   	
	do
 	{	
		//print out four random numbers
		srand((unsigned)time(NULL));
		randOne = rand() % (25 + 1 - 0) + 0;
		randTwo = rand() % (25 + 1 - 0) + 0;
		randThree = rand() % (25 + 1 - 0) + 0;
		randFour = rand() % (25 + 1 - 0) + 0;
		//test to make sure none of the outputs are equal
	}while (randOne == randTwo || randOne == randThree || randOne == randFour ||
		randTwo == randThree || randTwo == randFour || 
		randThree == randFour);
	cout << "The prize winners are numbers: " << randOne << ", " << randTwo
		<< ", " << randThree << ", " << randFour << endl;	

	return 0;
  
} 
	
