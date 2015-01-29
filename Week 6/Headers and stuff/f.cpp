#include<iostream>
#include "f.h"
using std::endl; 
namespace A
{
	void f(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
		std::cout << "value one is " << a <<endl;
		std::cout << "value two is " << b <<endl;
		std::cout << "Function f being called\n";
	}
}
