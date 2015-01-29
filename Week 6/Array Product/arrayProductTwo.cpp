#include <iostream>
using namespace std;
//set all these to 5
void make_array1(int array[10][10])
{
	int i, n;
	for (i = 0; i<10; i++)
  	{
    		for (n = 0; n<10; n++)
    		{
      			array[i][n] = 5;
    		}
  	}
}
//set all these to 2
void make_array2(int array[10][10])
{
	int i, n;
	for (i = 0; i<10; i++)
  	{
    		for (n = 0; n<10; n++)
    		{
      			array[i][n] = 2;
    		}
  	}
}
//multiply the array of 5's and the array of 2's
void make_arrays(int array1[10][10], int array2[10][10], int array3[10][10])
{
	int i, n, j;
	for (i = 0; i<10; i++)
	{
		for (n = 0; n<10; n++)
		{
			for (j = 0; j<10; j++)
			{
	        		array3[i][n] += array1[i][j]*array2[j][n];
      			}
    		}
  	}
}

int main()
{
	using namespace std;
	//initialize the empty arrays
	int array1[10][10];
	int array2[10][10];
	int array3[10][10] = {{}};
	//build the arrays
	make_array1(array1); 
	make_array2(array2);
	make_arrays(array1, array2, array3);
	//this should return 5
	cout << array1[5][2];
	//this should return 2
	cout << endl << array2[9][3];
	//this should equal 100
	cout << endl << array3[8][4];
	cout <<endl;
  return 0;
}
