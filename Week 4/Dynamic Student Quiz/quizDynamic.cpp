#include<iostream>
using namespace std;
int main()
{

        int gradeCount, studGrade;
        int *grades;
        cout << "How many grades are there" <<endl;
        cin >> gradeCount;
	grades = new int[gradeCount];

        for(int i = 0; i < gradeCount; i++)
        {
                        cout << "Enter the student's grade (0-5)" <<endl;
                        cin >> studGrade;
                        grades[studGrade]++;
        }
        for(int i = 0; i < gradeCount; i++)
        {
                cout << "There are " << grades[i] << " grade(s) of " << i << endl; 
	}

	delete[] grades;
	grades = NULL;
	
        return 0;
}


