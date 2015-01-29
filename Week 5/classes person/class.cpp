#include <iostream>
#include<string>
using namespace std;

class Person 
{
	public:
		Person(string theirName, int theirAge);	
		int getAge();
                string getName();
		void having_birthday();
                
	private:
		int age;
		string name;
};
Person::Person(string theirName, int theirAge)
			:name(theirName), age(theirAge)
{
	//yo yo
}
int Person::getAge()
{
	return age;
}
string Person::getName()
{
	return name;
}
void Person::having_birthday()
{
	age++;
}
int main ()
{
	string dudeName;
	int dudeAge;
	cout << "What's this dude's name?\n";
	cin >> dudeName;
	cout << "What's this dude's age?\n";
	cin >> dudeAge;
	Person guy(dudeName, dudeAge);
	cout << "You've entered: " << guy.getName() << endl;
	cout << "Age: " << guy.getAge() << endl;
	guy.having_birthday();
	cout << "In a year, " << guy.getName() << " will be " << guy.getAge() <<endl; 
	return 0;
}

