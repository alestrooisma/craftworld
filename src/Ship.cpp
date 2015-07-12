/* 
 * File:   Ship.cpp
 * Author: Ale Strooisma
 * 
 * Created on July 11, 2015, 9:18 PM
 */

#include "Ship.hpp"
#include "Room.hpp"

Ship::Ship() {
}

Ship::Ship(const Ship& orig) {
}

Ship::~Ship() {
	for (std::vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) {
		delete *it;
	}
}

Room* Ship::openDoor() {
	Room* room = new Room();
	rooms.push_back(room);
	return room;
}
