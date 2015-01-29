#include<iostream>
using namespace std;
int main(){
	int roomCapacity;
	int peopleAttending;
	int roomRemainder = roomCapacity - peopleAttending;
	int roomExcess = peopleAttending - roomCapacity;
	cout << "What is the maximum capacity of the room/n";
	cin >> roomCapacity;
	cout << "How many people are attending the meeting?/n";
	cin >> peopleAttending;
	
	if (peopleAttending <= roomCapacity)
		cout << "It is legal to hold your meeting.\n"
		<< " You may have" << roomRemainder << " additional people attend./n;
	else
		cout << "Your meeting cannot be held as planned due to fire regulations.\n"
		<< " You must exclude" << roomExcess << " participants to meet fire regulations\n";
{