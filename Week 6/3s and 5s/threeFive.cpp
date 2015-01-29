#include<iostream>
int threeSums(int num);
int main()
{
	using namespace std;
	int num;
	//the problem asked for 3 OR 5, so ask which one to run, but don't run both
	cout << "Would you like the sums for 3 or for 5? (Enter 3 or 5)\n";
	cin >> num;
	//Check to make sure a 3 or a 5 was entered
	while(!((num == 3) || (num == 5)))
	{
		cout << "Enter a 3 or a 5\n";
		cin >> num;
	}
	//return the sum
	threeSums(num);

	return 0;
}

int threeSums(int num)
{
	using namespace std;
	int startThree = 3;
	int startFive = 5;
	int multiplier;
	int sumThree = 0;
	int sumFive = 0;
	int totalSumThree = 0;
	int totalSumFive = 0;
	//the user chose 3
	if(num == 3)
	{	cout << "The sum of all the multiples for 3s that exist below 1000 is:" <<endl;
		//run the multiplier until the sum exceeds 1000
		for (multiplier = 0; sumThree < 1000; multiplier++)
		{
			//use the incremented multiplier against the set value of 3
			sumThree = multiplier * startThree;
			//Is it under 1000?
			if(sumThree < 1000)
			{
			//	add all the sums that exist under 1000
				totalSumThree += sumThree;		
			}
		}
		//give the final value
		cout << totalSumThree <<endl;
		
	}
	if(num == 5)
	{
		cout << "The sum of all the multiples for 5s that exist below 1000 is:" <<endl;	
		for (multiplier = 0; sumFive < 1000; multiplier++)
		{
			sumFive = multiplier * startFive;
			if(sumFive < 1000)
			{
			//	cout << sumFive << " ";
				totalSumFive += sumFive;
			}
		}
		cout << totalSumFive <<endl;
	}
}
/* I assumed for my program that it was asking that we give the user the option to either choose a 3 or a 5, and then from there, we use their choice and begin
 * multiplying it by every possible number, and adding the product of those numbers together.  Once the sum of those two numbers was over 1000, then we stopped
 * adding it to the total sum (all the previos products that we've added together), and printed the total sum.
