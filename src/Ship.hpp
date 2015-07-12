/* 
 * File:   Ship.hpp
 * Author: Ale Strooisma
 *
 * Created on July 11, 2015, 9:18 PM
 */

#ifndef SHIP_HPP
#define	SHIP_HPP

#include <vector>

class Room;

/**
 * The ship functions as a generator for rooms.
 * 
 * TODO: change into abstract class + subclasses or make it read a script.
 */
class Ship {
	std::vector<Room*> rooms;
public:
	Ship();
	Ship(const Ship& orig);
	virtual ~Ship();
	Room* openDoor();
private:

};

#endif	/* SHIP_HPP */

