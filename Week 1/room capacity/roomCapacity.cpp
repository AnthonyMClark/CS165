#include<iostream>
using namespace std;
int main()
{
	int roomCapacity;
	int peopleAttending;
	cout << "What is the maximum capacity of the room? Enter a number.\n";
	cin >> roomCapacity;
	cout <<"How many people are attending the meeting? Enter a number. \n";
	cin >> peopleAttending;
	
	if (peopleAttending <= roomCapacity)
	{
		int roomRemainder = roomCapacity - peopleAttending;
		cout << "It is legal to hold your meeting.\n"
		<< "You may have " << roomRemainder << " additional people attend.\n";
	}
	else
	{
		int roomExcess = peopleAttending - roomCapacity;
		cout << "Your meeting cannot be held as planned due to fire regulations.\n"
		<<"You must exclude " << roomExcess << " participants to meet fire regulations.\n";
	}
	return 0;
}
