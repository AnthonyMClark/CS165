#include<iostream>
#include<stdlib.h>
using namespace std;

struct Grader
{
	double quiz1;
	double quiz2;
	double midterm;
	double final;
	double score; 
	double quizzes;
	string total;
};

int main(int argc, char* argv[] )
{
	Grader grade;
	
	if(argc > 4)
	{
		grade.quiz1 = atoi(argv[1]);
		grade.quiz2 = atoi(argv[2]);
		grade.midterm = atoi(argv[3]);
	 	grade.final = atoi(argv[4]);
	} 
	else
	{
		cout << "Enter the grade for the student's first quiz out of 10.\n";
		cin >> grade.quiz1;
		cout << "Enter the grade for the student's second quiz out of 10.\n";
		cin >> grade.quiz2;
		cout << "Enter the grade for the student's midterm out of 100.\n";
		cin >> grade.midterm;
		cout << "Enter the grade for the student's final out of 100.\n";
		cin >> grade.final;
	}		
	grade.midterm = grade.midterm * .25;
//	cout << grade.midterm <<endl;
	grade.quizzes = (grade.quiz1 + grade.quiz2) * .25;
//	cout << grade.quizzes <<endl;
	grade.final = grade.final * .5;
//	cout << grade.final << endl; 
	grade.score = (((grade.final + grade.quizzes + grade.midterm) / 80) * 100);
//	cout << grade.score << endl;
	if(grade.score >= 90)
		grade.total = "A";
	if((grade.score < 90) && (grade.score >= 80))
		grade.total = "B";
	if((grade.score < 80) && (grade.score >= 70))
		grade.total = "C";
	if((grade.score < 70) && (grade.score >= 60))
		grade.total = "D";
	if(grade.score < 60)
		grade.total = "F";
	cout << "The student's final score is: " << grade.total <<endl;
	
	return 0;

}


