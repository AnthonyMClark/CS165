#include<iostream>
#include<cstring>

using namespace std;
void stringComp(char *str1, int size1, char *str2, int size2);

int main()
{
	int size1 = 100;
	int size2 = 100;
	char str1[size1];
	cout << "Enter a string to be compared.\n";
	cin >> str1;

	char str2[size2];
	cout << "Enter another string to compare.\n";
	cin >> str2;
	stringComp(str1, size1, str2, size2);
	
}

void stringComp(char *str1, int size1, char *str2, int size2)
{
	if (strcmp(str1, str2) == 0) 
	{
		cout << "Your strings are equal.\n";
	}
	else
	{
		cout << "Your strings are not equal.\n";
	}
}
