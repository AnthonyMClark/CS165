#include <iostream>
using namespace std;
main()
{
	int numCoupons;
	cout << "How many coupons do you have? Enter a number.\n";
	cin >> numCoupons;
	while (numCoupons >= 10)
	{
		cout << "You got 1 candy bar.\n";
		numCoupons = numCoupons - 10;
	}
	while ((numCoupons <= 10) && (numCoupons >= 3))
	{
		cout << "You got 1 gum ball.\n";
		numCoupons = numCoupons - 3;
	}
	if (numCoupons < 3)
	{
		cout << "You have " <<numCoupons 
		<< " coupon(s) remaining.\n"; 
	} 
	return 0;
}	
