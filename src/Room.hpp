/* 
 * File:   Room.hpp
 * Author: Ale Strooisma
 *
 * Created on July 12, 2015, 11:22 AM
 */

#ifndef ROOM_HPP
#define	ROOM_HPP

#include <string>
#include "enum.hpp"

class Room {
	CombatState state;
	// Temporary
	int numberOfEnemies;
public:
	Room();
	Room(const Room& orig);
	virtual ~Room();
	std::string statusUpdate();
	CombatState getState() {
		return state;
	};
	
	int getNumberOfEnemies() const {
		return numberOfEnemies;
	}

	void setNumberOfEnemies(int numberOfEnemies) {
		this->numberOfEnemies = numberOfEnemies;
		if (numberOfEnemies == 0) {
			state = CombatState::ENDING;
		}
	}

};

#endif	/* ROOM_HPP */

