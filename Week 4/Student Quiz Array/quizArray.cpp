#include<iostream>
using namespace std;
int main()
{

	int gradeCount, studGrade;
	int grades[6] = {0, 0, 0, 0, 0, 0};
	cout << "How many grades are there" <<endl;
	cin >> gradeCount;
	
	for(int i = 0; i < gradeCount; i++)
	{
			cout << "Enter the student's grade (0-5)" <<endl;
			cin >> studGrade;
			grades[studGrade]++;
	}
	for(int i = 0; i < 6; i++)
	{
		cout << "There are " << grades[i] << " grade(s) of " << i << endl;
	}
	
	return 0;
}

