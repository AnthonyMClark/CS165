#include<iostream>
#include "g.h"
using std::endl;
namespace A
{
	void g(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
		std::cout << "value one is " << a <<endl; 
		std::cout << "value two is " << b <<endl;
		std::cout << "void g called\n";
	}
	
}
