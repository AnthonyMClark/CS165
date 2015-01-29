#include<iostream>
#include<vector>
using namespace std;

class vector2D
{
	public:
		vector2D();
	        const vector2D operator*(const vector2D& usage) const;
		int retVal(int x, int y) const;
		void getDimensions(int a, int b);
		void findValue(int x, int y, int total);
	private:
		vector< vector<int> > vec;
		int x, y;
};
vector2D::vector2D():x(0),y(0){}
void vector2D::getDimensions(int a, int b)
{
	x = a;
	y = b;
	for(int i = 0; i < x; i++)
	{
		vector<int> row;
		for(int j = 0; j < y; j++)
		{
			row.push_back(0);
		}
		vec.push_back(row);
	}
}
void vector2D::findValue(int x, int y, int total)
{
	vec[x][y]=total;
}
int vector2D::retVal(int x, int y) const
{
	return vec[x][y];
}
const vector2D vector2D::operator*(const vector2D& usage) const
{
	vector2D opObj;
	opObj.getDimensions(x, 1);
	for(int i = 0; i < x; i++)
	{
		int product = 0;
		for(int j = 0; j < y; j++)
		{
			product = product + (vec[i][j] * usage.retVal(i, j));
		}
		opObj.findValue(i, 0, product);

	}
	return opObj;
}
int main()
{
	vector2D first; // declare object A
	int rows, cols, value;
	cout << "How many rows do you want?\n";
	cin >> rows;
	cout << "And how many columns?\n";
	cin >> cols;
	cout << "Enter the values for the first vector\n";
	first.getDimensions(rows, cols);
	for(int i = 0; i < rows; i ++)
	{
		for(int j = 0; j < cols; j++)
		{	
			cin >> value;
			first.findValue(i, j, value);
		}
	}
	cout << endl;
	cout << "The elements in the first vector are: " <<endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << first.retVal(i, j) << " ";
		}
		cout << endl;

	}
	cout << endl;

	vector2D second;
        cout << "Enter the values for the second vector\n";
        second.getDimensions(rows, cols);
        for(int i = 0; i < rows; i ++)
        {
                for(int j = 0; j < cols; j++)
                {
                        cin >> value;
                        second.findValue(i, j, value);
                }
        }
        cout << endl;
        cout << "The elements in the second vector are: " <<endl;
        for(int i = 0; i < rows; i++)
        {
                for(int j = 0; j < cols; j++)
                {
                        cout << second.retVal(i, j) << " ";
                }
                cout << endl;

        }
        cout << endl;
	vector2D third;
	third = first * second;
	cout << "The dot product for your two vectors is: \n";
	for (int i = 0; i < rows; i++)
	{
		cout << third.retVal(i, 0) <<endl;
	}

	return 0;
}






