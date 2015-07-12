/* 
 * File:   OpenAction.cpp
 * Author: Ale Strooisma
 * 
 * Created on July 12, 2015, 12:22 PM
 */

#include "OpenAction.hpp"
#include "Player.hpp"
#include "Raid.hpp"
#include "Ship.hpp"
#include "enum.hpp"

OpenAction::OpenAction(Player* user) : Action(user) {
}

OpenAction::OpenAction(const OpenAction& orig) : OpenAction(orig.getUser()) {
}

OpenAction::~OpenAction() {
}

void OpenAction::execute() {
	if (isApplicable(getUser()->getRaid()->getState())) {
		getUser()->getRaid()->setCurrentRoom(getUser()->getRaid()->getShip()->openDoor());
	}
	
}

bool OpenAction::isApplicable(CombatState state) {
	return getUser()->getRaid()->getState() == CombatState::SAFE;
}
