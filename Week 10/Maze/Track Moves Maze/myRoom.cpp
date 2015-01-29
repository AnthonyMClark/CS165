#include "myRoom.h"
#include <string>
#include <cstdlib>
using namespace std;

namespace maze
{

    Room::Room() : name(NULL), north(NULL), south(NULL), east(NULL), west(NULL) {/*intentionally empty*/}
    Room::Room(char newroom) : name(newroom), north(NULL), south(NULL), east(NULL), west(NULL){/*empty*/}
    char Room::get_name() const
    {
        return name;
    }
    Room* Room::nearbyRoom(char direction) const
    {
        switch(direction)
        {
            case 'N': return north;
            case 'E': return east;
            case 'S': return south;
            case 'W': return west;
        }
        return NULL;
    }
    void Room::linkRoom(char direction, Room *other)
    {
        switch(direction)
        {
            case 'N':
                north = other;
                break;
            case 'S':
                south = other;
                break;
            case 'E':
                east = other;
                break;
            case 'W':
                west = other;
                break;
        }
    }
}
