#include <iostream>

#include "Player.h"


int main() 
{ 
	std::cout << "Hello!\n\n";
	std::cout << "Please type a name for your character...\n\n";
	string temp;
	std::cin >> temp;
	PlayerObj* player = new PlayerObj(temp);
	std:cout << "\n\nHello " << player->name << "!";

	// Exit
	int x;
	std::cout << "\n";
	std::cin >> x;
	return 0;
}