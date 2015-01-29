#include<iostream>
using namespace std;

struct Person
{
	char name[10];
	int age;

};
int main ()
{
	Person a1;
	cout << "Please enter your name.\n";
	cin >> a1.name;
	cout << "Hello, " << a1.name << ".\n";
	cout << "How old are you, " << a1.name << endl;
	cin >> a1.age;
	cout << "You're " <<a1.age <<  "? That's cool.\n"; 
}
