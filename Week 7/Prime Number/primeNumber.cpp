#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;
class PrimeNumber {
	private:
		int aPrime;
	public:
		friend istream&operator>>(istream&, const PrimeNumber&);
		friend ostream& operator<<(ostream&, const PrimeNumber&);
		bool IsPrime(int);
		PrimeNumber();
		PrimeNumber(int numPrime = 1)
		{
			aPrime = numPrime;
		};
		int getPrime();
		PrimeNumber &operator++();
		PrimeNumber operator++(int);
   		PrimeNumber &operator--();
};
int PrimeNumber::getPrime(){
	return aPrime;
}
bool PrimeNumber::IsPrime(int num){
	bool hold = true;
   	if(num == 2)
	{
		return hold;
	}
	for(int i=2;i<num; i++){
		if(num % i == 0)
		{
			hold = false;
			break;
		}
	}
	return hold;
}

ostream &operator<<(ostream &output, const PrimeNumber &num)
{
	output<<num.aPrime<<" Is a prime ";
	return output;
}

PrimeNumber& PrimeNumber::operator++()
{

	do
	{
		aPrime ++;
	}while(!IsPrime(this->aPrime));
	return *this;
}

PrimeNumber PrimeNumber::operator++(int disregard){
	PrimeNumber set = *this;
	do
	{
		aPrime++;
	}while (!IsPrime(aPrime));		       
	return set;
}

PrimeNumber& PrimeNumber::operator--(){
	do
	{
		aPrime--;
	}while(!IsPrime(this->aPrime));
	return *this;
}


int main(){
	int theNumber;
	cout<<"Enter a prime number, if you even know what that is"<<endl;
	cin>>theNumber;
	PrimeNumber first(theNumber);
	--first;
	cout<<first;
	PrimeNumber second(theNumber);
	++second;
	cout<<second;
	cout <<endl <<endl;

	return 0;
}
