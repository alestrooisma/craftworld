/* 
 * File:   Controller.hpp
 * Author: Ale Strooisma
 *
 * Created on July 10, 2015, 5:41 PM
 */

#ifndef CONTROLLER_HPP
#define	CONTROLLER_HPP

class Raid;
class Player;

class Controller {
	Raid* raid = nullptr;
public:
	Controller();
	Controller(const Controller& orig);
	virtual ~Controller();
	void startRaid(Raid* raid, Player* leader);
	void processCommand(Player* player, std::string command);
};

#endif	/* CONTROLLER_HPP */

