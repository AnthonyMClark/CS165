#include<iostream>
#include<cmath>
#include<string>
using namespace std;

double hatInfo(int weight, int height);
double jacketInfo(int weight, int height, int age);
double waistInfo(int weight, int age);
 
main ()
{	
	int runAgain;
	do
	{
		int yourWeight, yourHeight, yourAge;
		double yourHat, yourJacket, yourWaist;
		cout << "What is your weight?\n";
		cin >> yourWeight;
		cout  << endl;
		cout << "In inches, what is your height?\n"; 
		cin >> yourHeight; 
		cout << endl;
		cout << "What is your age?\n";
		cin >> yourAge;
		cout << endl;  
		double yourHatSize = hatInfo(yourWeight, yourHeight);
		double yourJacketSize = jacketInfo(yourWeight, yourHeight, yourAge);
		double yourWaistSize = waistInfo(yourWeight, yourAge); 
		cout << "The following are your sizes:" << endl
		<< "Your hat size is: " << yourHatSize << endl
		<< "Your jacket size is: " << yourJacketSize << endl
		<< "Your waist size is: " << yourWaistSize << endl;  
		cout << "Enter 1 to run another calculation or 2 to quit.\n";
		cin  >> runAgain;
			
	}while(runAgain == 1);
	return 0;
}
double hatInfo(int weight, int height) 
{
	double hatSize = (weight / height) * 2.9;
	return hatSize;
}
double  jacketInfo(int weight, int height, int age)
{
	double ageIncrease = age > 39?(age - 10) / 0.1: 0;
	double jacketSize = (((weight * height) / 288) + (ageIncrease * 0.125));
	return jacketSize; 
}
double waistInfo(int weight, int age) 
{
	double ageWaistIncrease = age > 29?(age - 28) / 2: 0;
	double waistSize = ((weight/5.7) + (ageWaistIncrease * 0.1));
	return waistSize;
}
