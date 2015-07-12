/* 
 * File:   Player.hpp
 * Author: Ale Strooisma
 *
 * Created on July 11, 2015, 9:18 PM
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include <string>

class Action;
class Raid;

class Player {
private:
	int playerNumber;
	std::string name; // To character?
	Raid* raid = nullptr;
	Action* action = nullptr;
public:
	Player(std::string name);
	virtual ~Player();
	
	// Getters and Setters
	int getPlayerNumber() const {
		return playerNumber;
	}
	
	void setPlayerNumber(int playerNumber) {
		this->playerNumber = playerNumber;
	}

	Action* getAction() const {
		return action;
	}

	void setAction(Action* action) {
		this->action = action;
	}
	
	std::string getName() const {
		return name;
	}

	void setName(std::string name) {
		this->name = name;
	}
	
	Raid* getRaid() const {
		return raid;
	}

	void setRaid(Raid* raid) {
		this->raid = raid;
	}
};

#endif	/* PLAYER_HPP */

