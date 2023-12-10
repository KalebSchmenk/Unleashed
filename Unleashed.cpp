// Main starting point

#include <iostream>
#include "Player.h"


int main()
{
	std::cout << "Hello!\n\n";
	std::cout << "Please type a name for your character...\n\n";
	std::string temp;
	std::cin >> temp;
	PlayerObj* player = new PlayerObj(temp);
	std::cout << "\n\nHello " << player->name << "!";


	// Exit
	int x;
	std::cout << "\n";
	std::cin >> x;
	return 0;


	// Enter Intro
	// Get Player Info
	// Create init player obj
	// Save init player obj
	// Open Main Menu
	// Only allow first level tutorial selection
	// Enter tutorial version of game loop
	// Exit to main menu
	// Begin tutorial version of main menu loop
	// Let player begin journey 
}

