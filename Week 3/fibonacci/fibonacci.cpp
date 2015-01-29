#include<iostream>
using namespace std;

int fibonacciNum(int n);

int main()
{
	int fibOutput;
	int number;
	cout << "Enter a Fibonacci number.\n";
	cin >> number;
	fibOutput = fibonacciNum(number);
	cout << "The next Fibonacci number would be: " <<endl; 
	cout << fibOutput <<endl;
	return 0; 
}

int fibonacciNum(int n)
{
	if(n < 2)
	{	
		return n;
	}
	else
	{
		return fibonacciNum(n-1) + fibonacciNum(n-2);
	}
}
