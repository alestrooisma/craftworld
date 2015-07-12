/* 
 * File:   Controller.cpp
 * Author: Ale Strooisma
 * 
 * Created on July 10, 2015, 5:41 PM
 */
#include <iostream>

#include "Controller.hpp"
#include "Raid.hpp"
#include "Player.hpp"
#include "Action.hpp"
#include "ShootAction.hpp"
#include "OpenAction.hpp"
#include "enum.hpp"

using namespace std;

Controller::Controller() {
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

void Controller::startRaid(Raid* raid, Player* leader) {
	this->raid = raid;
	raid->addPlayer(leader);
}

void Controller::processCommand(Player* player, std::string command) {
	Action* action = nullptr;
	if (command == "shoot") {
		action = new ShootAction(player);
	} else if (command == "open") {
		action = new OpenAction(player);
	} else {
		cout << "unknown command" << endl;
	}
	
	// If command sets an action, apply it and if all players have an action 
	// set, resolve them.
	if (action != nullptr) {
		if (action->isApplicable(raid->getState())) {
			if (raid->getState() == CombatState::SAFE) {
				action->execute();
			}
			if (player->getAction() != nullptr)  {
				delete player->getAction();
			}
			player->setAction(action);

			if (raid->allSet()) {
				raid->executeTurn();
			}
			
			for (int i = 0; i < raid->getRaiders().size(); i++) {
				action = raid->getRaiders()[i]->getAction();
				raid->getRaiders()[i]->setAction(nullptr);
				delete action;
			}
		} else {
			cout << "Action currently not applicable" << endl;
		}
	}
	
	
}
