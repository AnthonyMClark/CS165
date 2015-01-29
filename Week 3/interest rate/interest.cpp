#include<iostream>
#include<cstdlib>
using namespace std;

double accountValue(double deposit, double interest, int years);

int main()
{	
	double inputInterest, inputDeposit, cash;
	int inputYears;
	cout << "Welcome to the bank of Anthony, the bank you wish existed." << endl
	<<"Please enter the amount of your deposit.\n";
	cin >> inputDeposit;

	cout << "Thank you. Enter the amount of interest you would like.\n";
	cin >> inputInterest;
 	
	cout << "Great choice! Now enter the number of years you want it to mature.\n";
	cin >> inputYears;
	cash = accountValue(inputDeposit, inputInterest, inputYears);
	cout << "Your balance at that time would be $" << cash <<endl; 
	return 0;
}

double accountValue(double deposit, double interest, int years)
{	
	if(years == 0)
	{
		return deposit;
	}
	else
	{
		return ((1 + interest / 100) * accountValue(deposit, interest, years - 1));
	}
}
