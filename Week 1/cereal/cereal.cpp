#include<iostream>
using namespace std;
int main()
{
	//set a metric ton's value, and get the ounces of user's cereal
	double metricTon = 35273.92;
	double cerealOunces;
	cout << "What is the weight in ounces of your cereal? Enter a number.\n";
	cin >> cerealOunces;
	cout << "Your cereal in ounces is " 
	<< cerealOunces << "." <<endl;

	//show cereal's weight in tons
	double convertToMetric;
	convertToMetric = cerealOunces / metricTon;
	cout << "The weight of your cereal in metric tons is\n"
	<< convertToMetric << "." << endl;
								
	//calculate number of boxes needed to get to a ton and the boxes
	//needed, excluding the original box.
	double numBoxes;
	numBoxes = metricTon / cerealOunces;
	double remainingNumBoxes = numBoxes - cerealOunces;
	cout << numBoxes 
	<< " boxes of your cereal are needed to reach a metric ton.\n"
	<< "Excluding your box, there are "
	<< remainingNumBoxes << " still needed.\n";
	return 0;
}
