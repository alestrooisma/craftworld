/* 
 * File:   OpenAction.hpp
 * Author: Ale Strooisma
 *
 * Created on July 12, 2015, 12:22 PM
 */

#ifndef OPENACTION_HPP
#define	OPENACTION_HPP

#include "Action.hpp"

class OpenAction : public Action {
public:
	OpenAction(Player* user);
	OpenAction(const OpenAction& orig);
	virtual ~OpenAction();
	virtual void execute();
	virtual bool isApplicable(CombatState state);
};

#endif	/* OPENACTION_HPP */

