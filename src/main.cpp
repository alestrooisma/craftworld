/* 
 * File:   main.cpp
 * Author: Ale Strooisma
 *
 * Created on July 10, 2015, 5:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "Controller.hpp"
#include "Raid.hpp"
#include "Ship.hpp"
#include "Player.hpp"

using namespace std;

/*
 * Test program for Craftworld: Raiders
 */
int main(int argc, char** argv) {
	cout << "Hello CraftWorld!" << endl;
	
	Controller controller;
	Ship ship;
	Raid raid(&ship);
	Player player("Oebele");
	bool exit = false;
	
	controller.startRaid(&raid, &player);
//	raid.setCurrentRoom(raid.getShip()->openDoor());
	
	cout << "> ";
	for (string line; !exit && getline(cin, line);) {
		if (~isatty(STDIN_FILENO)) {
			cout << line << endl;
		}
		if (line == "exit") {
			exit = true;
		} else {
			controller.processCommand(&player, line);
			cout << "> ";
		}
    }
	
	return 0;
}

