/* 
 * File:   Raid.hpp
 * Author: Ale Strooisma
 *
 * Created on July 11, 2015, 9:18 PM
 */

#ifndef RAID_HPP
#define	RAID_HPP

#include <vector>

class Player;
class Room;
class Ship;

enum class CombatState;

class Raid {
private:
	std::vector<Player*> raiders;
	Ship* ship;
	Room* currentRoom = nullptr;
public:
	Raid(Ship* ship);
	Raid(const Raid& orig);
	virtual ~Raid();
	void addPlayer(Player* player);
	void removePlayer(Player* player);
	bool allSet();
	void executeTurn();
	void registerKill();
	CombatState getState();
	
	std::vector<Player*> getRaiders() const {
		return raiders;
	}
	Ship* getShip() const {
		return ship;
	}
	Room* getCurrentRoom() const {
		return currentRoom;
	}
	void setCurrentRoom(Room* currentRoom) {
		this->currentRoom = currentRoom;
	}
};

#endif	/* RAID_HPP */

