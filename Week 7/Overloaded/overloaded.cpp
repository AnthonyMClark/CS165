#include <iostream>
//#include<stdlib.h>
using namespace std;

class Rational
{
	int numer, denom;
public:
	void wholeNumber(int x)
	{
		cout << x << '/' << 1 << endl; 
	}
	Rational(int = 0, int = 1);	// default numerator to 0, default denominator to 1
	void operator!(void) const;	// print the / for the fraction
	Rational& operator~(void);	// reduce the fraction
	Rational operator-(void) const;	// negative of fraction
	Rational operator*(void) const;	// reciprocal of fraction
	Rational operator+(int) const;
	Rational operator-(int) const;
	Rational operator*(int) const;
	Rational operator/(int) const;
	bool operator>(const Rational&) const;
	bool operator<(const Rational&) const;
	bool operator>=(const Rational&) const;
	bool operator<=(const Rational&) const;
	bool operator==(const Rational&) const;
	Rational operator+(const Rational&) const;
	Rational operator-(const Rational&) const;
	Rational operator*(const Rational&) const;
	Rational operator/(const Rational&) const;
	//std::cout << *this << *this
	friend ostream& operator<<(ostream &outs, const Rational& foo);
	friend istream& operator>>(istream &in, Rational &foo);
};
ostream& operator<<(ostream &out, const Rational& foo)
{
	out << foo;
	
	return out;
}
istream& operator>>(istream &in, Rational &foo)
{
	in >> foo;

	return in;
}
Rational::Rational(int n, int d)
{
//	if(numer == 0)
//	{
//		cout << "This is not a rational number.\n";
//		exit(EXIT_FAILURE);
//	}
	numer = n;
	denom = d;
}
//overload so we can just add in / for the divide sign
void Rational::operator!(void) const 
{
	cout << numer << '/' << denom << endl;
}

Rational& Rational::operator~(void) 
{
	int shrinkMe;
	// reduce the fraction
	shrinkMe = denom < numer ? denom : numer;
	for (int i = 2; i <= shrinkMe; i++)
	{
		while ((numer % i == 0) && (denom % i == 0))
		{
			numer /= i;
			denom /= i;
		}
	}
	return *this;
}

Rational Rational::operator-(void) const 
{
	return Rational(-numer,denom);
}
Rational Rational::operator*(void) const 
{
	return Rational(denom,numer);
}
bool Rational::operator>(const Rational& f) const 
{
	return (float) numer/denom > (float) f.numer/f.denom;
}
bool Rational::operator<(const Rational& f) const 
{
	return f>*this;
}
bool Rational::operator==(const Rational& f) const 
{
	return numer*f.denom == denom*f.numer;
}
bool Rational::operator<=(const Rational& f) const 
{
	return !(*this > f);
}
bool Rational::operator>=(const Rational& f) const 
{
	return !(*this<f);
}
Rational Rational::operator+(const Rational& f) const 
{
	return Rational(numer*f.denom+denom*f.numer,denom*f.denom);
}
Rational Rational::operator-(const Rational& f) const 
{
	return Rational(numer*f.denom-denom*f.numer,denom*f.denom);
}
Rational Rational::operator*(const Rational& f) const 
{
	return Rational(numer*f.numer,denom*f.denom);
}
Rational Rational::operator/(const Rational& f) const 
{
	return (*this) * (*f);
}
Rational Rational::operator+(int i) const 
{
	return Rational(numer+i*denom,denom);
}
Rational Rational::operator-(int i) const 
{
	return (*this) + -i;
}
Rational Rational::operator*(int i) const 
{
	return Rational(numer*i,denom);
}
Rational Rational::operator/(int i) const 
{
	return Rational(numer,i*denom);
}

int main(void)
{
	int numOne, numTwo, denOne, denTwo, compNum;
	cout << "Enter the numerator for the first fraction\n";
	cin >> numOne;
	cout << "Enter the denominator for the first fraction\n";
	cin >> denOne;
        Rational fracOne(numOne,denOne);
        cout << "Your fraction is: ";  !fracOne; cout<<endl;
        cout << "If it were negative: ";  !-fracOne; cout<<endl;
        cout << "If it were the inverse: ";  !*fracOne; cout<<endl;
	cout << "Thank You.\n\n";
	cout << "Enter the numerator for the second fraction\n";
	cin >> numTwo;
	cout << "Enter the denominator for the second fraction\n";
	cin >> denTwo;        
	Rational fracTwo(numTwo,denTwo);
	cout << "Your second fraction is: ";  !fracTwo;	cout << endl;
	Rational fracTotal = fracTwo + fracOne;	cout << endl;
	cout << "Your fractions added together are: ";  !fracTotal;
	cout << "Your fractions subtracted are: ";  ! (fracOne - fracTwo);
	cout << "Your fractions multiplied are: ";  ! (fracOne * fracTwo);
	cout << "Your fractions divided: ";  ! (fracOne / fracTwo);
	cout << "Reduced, the total is: ";  !~fracTotal; cout << endl;
	cout << "Are your fractions equal to eachother? 1 if yes, 0 if no: " << (fracOne == fracTwo) << endl;
	cout << "Is your fraction 2 > 1? 1 if yes, 0 if no: " << (fracOne < fracTwo) << endl;
	cout << "Is your fraction 1 > 2? 1 if yes, 0 if no: " << (fracOne > fracTwo) << endl;
	cout << "Is your fraction 2 >= 1? 1 if yes, 0 if no: " << (fracOne <= fracTwo) << endl;
	cout << "Is your fraction 1 >= 2? 1 if yes, 0 if no: " << (fracOne >= fracTwo) << endl;
	cout << "Enter a whole number to compare your first fraction against\n";
	cin >> compNum;
	cout << "fraction" << "+" << compNum << ": ";  !(fracOne + compNum);
	cout << "fraction" << "-" << compNum << ": ";   !(fracOne - compNum);
	cout << "fraction" << "*" << compNum << ": ";  !(fracOne * compNum);
	cout << "fraction" << "/" << compNum << ": ";;  !(fracOne / compNum);
	cout << endl;
	
	return 0;
}
