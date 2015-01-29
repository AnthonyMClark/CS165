#include<iostream>
#include "g.h"
#include "f.h"

int main()
{
	int x, y, a, b;
	std::cout << "Enter value 1\n";
	std::cin >> x;
	std::cout << "Enter value 2\n";
	std::cin >> y;
	A::f(x, y);

        std::cout << "Enter value 1\n";
        std::cin >> a;
        std::cout << "Enter value 2\n";
        std::cin >> b;
	A::g(a, b);


	return 0;
}
