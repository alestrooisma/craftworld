/* 
 * File:   Shoot.cpp
 * Author: Ale Strooisma
 * 
 * Created on July 11, 2015, 9:57 PM
 */

#include <iostream>

#include "ShootAction.hpp"
#include "Player.hpp"
#include "Raid.hpp"
#include "enum.hpp"

using namespace std;

ShootAction::ShootAction(Player* user) : Action(user) {
}

ShootAction::ShootAction(const ShootAction& orig) : ShootAction(orig.getUser()) {
}

ShootAction::~ShootAction() {
}

void ShootAction::execute() {
	if (isApplicable(getUser()->getRaid()->getState())) {
		cout << getUser()->getName() << " hit and killed Gremlin!" << endl;
		getUser()->getRaid()->registerKill();
	}
}

bool ShootAction::isApplicable(CombatState state) {
	return state == CombatState::COMBAT;
}
