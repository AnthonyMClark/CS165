#include <iostream>
#include "myRoom.h"
using namespace std;
using namespace maze;


int main()
{
	//set all of the rooms
	RoomPoint a, b, c, d, e, f, g, h, i, j, k, l;
    	a = new Room('A');
    	b = new Room('B');
    	c = new Room('C');
    	d = new Room('D');
    	e = new Room('E');
    	f = new Room('F');
    	g = new Room('G');
    	h = new Room('H');
    	i = new Room('I');
    	j = new Room('J');
    	k = new Room('K');
    	l = new Room('L');
	//set the available directions for each room
    	a->linkRoom('E', b);
	b->linkRoom('W', a);
    	a->linkRoom('S', e);
	e->linkRoom('N', a);
    	e->linkRoom('S', i); 
	i->linkRoom('N', e);
    	i->linkRoom('E', j); 
	j->linkRoom('W', i);
    	b->linkRoom('S', f); 
	f->linkRoom('N', b);
    	f->linkRoom('E', g); 
	g->linkRoom('W', f);
    	g->linkRoom('N', c); 
	c->linkRoom('S', g);
    	c->linkRoom('E', d); 
	d->linkRoom('W', c);
    	g->linkRoom('S', k); 
	k->linkRoom('N', g);
    	g->linkRoom('E', h); 
	h->linkRoom('W', g);
    	h->linkRoom('S', l); 
	a->linkRoom('N', h);
	//set the starting room to room a
    	RoomPoint currentRoom = a;
    	char direction;

    	do
    	{
        	cout << "You are in a room " << currentRoom->get_name() << " choose a direction to travel (N,E,S,W) or give up (Q)";
        	cin >> direction;
        	direction = toupper(direction);
		if(direction == 'Q')
        	{
            		return 0;
        	}
	        RoomPoint roomChoice = currentRoom->nearbyRoom(direction);
	        if(roomChoice == NULL)
        	{
            		cout << "You can't travel this direction! Choose another." << endl;
        	}
        	else
		{
            		currentRoom = roomChoice;
		}
    	}
    	while (currentRoom->get_name() != 'L');
	cout << "Congratulations, you made it to the final room (L)!" << endl;
        return 0;

}



