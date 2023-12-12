// Main starting point

#include <iostream>
#include <fstream>
#include "Player.h"
#include "FileManager.h"


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

int main()
{
	std::cout << "===================================================================================================\n\n";
	std::cout << "                                ______                   _______               ______    ___        \n";
	std::cout << "|      |   |     |   |         |              /\\        |          |      |   |         |   \\     \n";
	std::cout << "|      |   |\\    |   |         |             /  \\       |          |      |   |         |    \\   \n";
	std::cout << "|      |   | \\   |   |         |            /    \\      |          |      |   |         |     \\  \n";
	std::cout << "|      |   |  \\  |   |         |------     /______\\     |------|   |------|   |------   |     /   \n";
	std::cout << "|      |   |   \\ |   |         |          /        \\           |   |      |   |         |    /    \n";
	std::cout << "|______|   |    \\|   |______   |______   /          \\   _______|   |      |   |______   |___/     \n";
	std::cout << "\n\n===================================================================================================\n\n";


	std::string name;
	DataManager data;
	PlayerData playerData;
	PlayerObj player;

	try
	{
		playerData = data.LoadData();

		// If load successful
		std::cout << "Hello again, " << playerData.playerName << "\n\n";

		player.SetPlayerData(playerData); // Handles name and health setting
	} 
	catch (...)
	{
		// If load unsuccessful
		std::cout << "Hello!\n\n";
		std::cout << "Please type a name for your character...\n\n";
		
		std::cin >> name;

		playerData.playerName = name;
		playerData.playerHealth = 15; // Default

		player.SetPlayerData(playerData); // Handles name and health setting

		// Saves new data
		PlayerData tempData = player.GetPlayerData();
		data.SaveData(&tempData);
	}

	
	PlayerData newData = data.LoadData();

	std::cout << "\nPlayer name is " << newData.playerName << " and health is " << newData.playerHealth << std::endl;


	return 1;
}

