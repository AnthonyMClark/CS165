#include <string>
using namespace std;

namespace maze
{

	class Room
    	{
        	public:
            		Room();
            		Room(char newroom);
            		char get_name() const;
            		Room *nearbyRoom(char direction) const;
            		void linkRoom(char direction, Room *other);
        	private:
            		char name;
            		Room *north, *east, *south, *west;
	};typedef Room *RoomPoint;

}

