/* 
 * File:   Shoot.hpp
 * Author: Ale Strooisma
 *
 * Created on July 11, 2015, 9:57 PM
 */

#ifndef SHOOTACTION_HPP
#define	SHOOTACTION_HPP

#include "Action.hpp"

class Player;

class ShootAction : public Action {
public:
	ShootAction(Player* user);
	ShootAction(const ShootAction& orig);
	virtual ~ShootAction();
	virtual void execute();
	virtual bool isApplicable(CombatState state);
};

#endif	/* SHOOTACTION_HPP */

