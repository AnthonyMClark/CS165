#include<iostream>
#include<cmath>
#include<string>
using namespace std;

const double LITER_TO_GALLONS = .264179;
double gasInfo(int liters, int miles);
 
main ()
{	
	int runAgain;
	do
	{
		int litersUsed, milesDriven;
		double yourTrip;
		cout << "How many liters of gasoline did you use?\n";
		cin >> litersUsed;
		cout << "How many miles did you travel?\n"; 
		cin >> milesDriven;
		yourTrip = gasInfo(litersUsed, milesDriven);
		cout << "Your miles per gallon used is " << yourTrip << endl;
		cout << "Enter 1 to run another calculation or 2 to quit.\n";
		cin  >> runAgain;
			
	}while(runAgain == 1);
	return 0;
}
double gasInfo(int liters, int miles) 
{
	double usage = LITER_TO_GALLONS * liters;
	double mpg = usage / miles;
	return mpg;
}
 
