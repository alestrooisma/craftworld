/* 
 * File:   Room.cpp
 * Author: Ale Strooisma
 * 
 * Created on July 12, 2015, 11:22 AM
 */

#include "Room.hpp"
#include "enum.hpp"

using namespace std;

Room::Room() : state(CombatState::COMBAT), numberOfEnemies(3) {
}

Room::Room(const Room& orig) {
}

Room::~Room() {
}

string Room::statusUpdate() {
	string output;
	switch (state) {
		case CombatState::COMBAT:
			output = "There are " + to_string(numberOfEnemies) + " Gremlins in the room!";
			break;
		case CombatState::ENDING:
			state = CombatState::SAFE;
		case CombatState::SAFE:
			output = "The room is safe.";
			break;
	}
	return output;
}
