#include <iostream>
using namespace std;

void sort(int& num_1, int& num_2, int& num_3);

main() 
{
	int a, b, c; 
	cout << "Enter integer one.\n";
	cin >> a;
	cout << "Enter integer two.\n";
	cin >> b;
	cout << "Enter integer three.\n";
	cin >> c;
	sort(a, b, c);
      	cout << a << ", " << b << ", " << c <<endl;     // displays 20  10
	return 0;    
}

void sort(int& num_1, int& num_2, int& num_3) 
{
	//in this case, num_1 is the lowest value.
      	if((num_2 > num_1) && (num_3 > num_1))
	{
		//one is the lowest, and three is next, two is greatest
		if(num_2 > num_3)
		{
			int temp = num_2;
			num_2 = num_3;
			num_3 = temp;
		}	 
		
	}
	//in this case, num_2 is the lowest value. 	
	if((num_1 > num_2) && (num_3 > num_2))
	{
		int temp1 = num_1;
		num_1 = num_2;
		num_2 = temp1;
		//two is the lowest, and three is next, one is greatest
		if(num_1 > num_3)
		{
			int temp2 = num_2;
			num_2 = num_3;
			num_3 = temp2; 	
		}
		
	}
	//in this case, 3 is the lowest value.
	if((num_1 > num_3) && (num_2 > num_3))
	{
		int temp1 = num_1;
		int temp2 = num_2;
		num_1 = num_3;
		num_2 = temp1;
		num_3 = temp2;
		//three is the lowest, two is next, one is the greatest.
		if(num_2 > num_3)
		{	
			num_2 = temp2;
			num_3 = temp1;
		}
	}

}


