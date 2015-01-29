#include <iostream>
use namespace std;
main()
{
	int numCoupons;
	cout << "How many coupons do you have? Enter a number.\n";
	cin >> numCoupons;
	int candyBars = numCoupons / 10;
	int remainingCoupons = numCoupons % 10;
	int gumBalls = remainingCoupons / 3;
	if (candyBars >= 10)
		cout << "You can get " << candyBars << " candy bars.\n";
	else if (gumBalls >= 3)
		cout << "You can get " << gumBalls << " gum balls.\n;
	else
		cout << "You can't get any candy bars or gum balls. Get more coupons, loser.\n"
}	
