/* 
 * File:   Action.hpp
 * Author: Ale Strooisma
 *
 * Created on July 11, 2015, 9:29 PM
 */

#ifndef ACTION_HPP
#define	ACTION_HPP

enum class CombatState;
class Player;

class Action {
private:
	Player* user;
public:
	Action(Player* user);
	Action(const Action& orig);
	virtual ~Action();
	virtual void execute() = 0;
	virtual bool isApplicable(CombatState state) = 0;
	Player* getUser() const {
		return user;
	}
};

#endif	/* ACTION_HPP */

