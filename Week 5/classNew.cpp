#include <iostream>
#include<cstring>
using namespace std;

class Person 
{
	public:
		void having_birthday()
		{
			age++;
		}
		Person(char* arrayName, int age);
		int getAge()
                {
                        return age;
                }
		char* getName()
		{
			return name;
		}
	private:
		int age;
		char* name;
};

Person::Person(char* persName, int x)
{
        for(int i = 0; i < 10; i++)
        {
                name[i] = persName[i];
        }
        age = x;
}

int main ()
{
	int x;
	char* persName = new char[10];
	cout << "Enter the person's name\n";
	cin.getline(persName, 10);
	cout << "Enter the person's age\n";
	cin >> x; 
	Person perObj (persName, x);
	char* name = perObj.getName();
	cout << "The name is " << name <<endl;
	cout << "The age is " << perObj.getAge() <<endl;
	perObj.having_birthday();
	cout << "Their age next year is " << perObj.getAge();	
	return 0;
}

