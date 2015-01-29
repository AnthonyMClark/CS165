#include <iostream>
using namespace std;
main()
{
	int numCoupons;
	cout << "How many coupons do you have? Enter a number.\n";
	cin >> numCoupons;
	int candyBars = numCoupons / 10;
	int remainingCoupons = numCoupons % 10;
	int gumBalls = remainingCoupons / 3;
	if (candyBars >= 1)
	{
		cout << "You can get " << candyBars << " candy bars.\n";
	}
	if (gumBalls >= 1)
	{
		cout << "You can get " << gumBalls << " gum balls.\n";
	}
	if ((candyBars < 1) && (gumBalls < 1))
	{
		cout << "You can't get any candy bars or gum balls. Get more coupons, loser.\n";
	}
	return 0;
}	
