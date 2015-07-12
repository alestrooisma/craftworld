/* 
 * File:   Raid.cpp
 * Author: Ale Strooisma
 * 
 * Created on July 11, 2015, 9:18 PM
 */

#include <algorithm>
#include <iostream>

#include "Action.hpp"
#include "Raid.hpp"
#include "Player.hpp"
#include "Ship.hpp"
#include "Room.hpp"

using namespace std;

Raid::Raid(Ship* ship) : ship(ship) {
}

Raid::Raid(const Raid& orig) {
}

Raid::~Raid() {
}

void Raid::addPlayer(Player* player) {
	player->setRaid(this);
	player->setPlayerNumber(raiders.size()+1);
	raiders.push_back(player);
}

void Raid::removePlayer(Player* player) {
	raiders.erase(std::remove(raiders.begin(), raiders.end(), player), raiders.end());
	for (int i = 0; i < raiders.size(); i++) {
		raiders[i]->setPlayerNumber(i);
	}
}

bool Raid::allSet() {
	bool allset = true;
	for (int i = 0; allset && i < raiders.size(); i++) {
		if (raiders[i]->getAction() == nullptr) {
			allset = false;
		}
	}
	return allset;
}

void Raid::executeTurn() {
	for (int i = 0; i < raiders.size(); i++) {
		raiders[i]->getAction()->execute();
	}
	cout << currentRoom->statusUpdate() << endl;
}

void Raid::registerKill() {
	if (currentRoom->getNumberOfEnemies() > 0) {
		currentRoom->setNumberOfEnemies(currentRoom->getNumberOfEnemies()-1);
	}
}

CombatState Raid::getState() {
	return currentRoom != nullptr ? currentRoom->getState() : CombatState::SAFE;
}
