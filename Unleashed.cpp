// Main starting point

#include <iostream>
#include <fstream>
#include "Player.h"
#include "FileManager.h"
#include <stdlib.h>
#include "Dungeon Headers/Dungeons.h"


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
	std::cout << "|      |   | \\   |   |         |            /    \\      |______    |      |   |         |     \\  \n";
	std::cout << "|      |   |  \\  |   |         |------     /______\\            |   |------|   |------   |     /   \n";
	std::cout << "|      |   |   \\ |   |         |          /        \\           |   |      |   |         |    /    \n";
	std::cout << "|______|   |    \\|   |______   |______   /          \\   _______|   |      |   |______   |___/     \n";
	std::cout << "\n\n===================================================================================================\n\n";


	std::string name;
	DataManager data;
	PlayerData playerData;
	PlayerObj player;

	// If player data file exists use it, if not create new player data
	try
	{
		playerData = data.LoadData(); // LoadData() Throws an exception if it could not load a player data file which is why
		                              // we have it in a try-catch. Not neccessary, but an interesting implementation

		// If load successful
		std::cout << "Hello again, " << playerData.playerName << " you have " << playerData.playerHealth << " HP!\n\n";

		player.SetPlayerData(playerData); // Handles name and health setting internally
	} 
	catch (...)
	{
		// If load unsuccessful
		std::cout << "Hello new player!\n\n";
		std::cout << "Please type a name for your character...\n\n";
		
		std::cin >> name;

		playerData.playerName = name;
		playerData.playerHealth = 15; // Default

		player.SetPlayerData(playerData); // Handles name and health setting internally
	}


	//_______________________
	// Game
	//-----------------------
	
	bool goodSelect = false;
	int menuSelect;

	// Menu select loop
	do
	{
		system("CLS"); // Clear console (Slow)

		std::cout << "Please select an option\n\n";
		std::cout << "\n1. Enter Cave Dungeon";
		std::cout << "\n2. Quit\n\n";
		std::cin >> menuSelect;

		switch (menuSelect)
		{
			case 1:
			{
				// Entering a dungeon
				DungeonDifficulty difficulty = Hard;
				CaveDungeon enteredDungeon = CaveDungeon(difficulty);
				
				enteredDungeon.StartDungeon(&player);

				goodSelect = false;
				break;
			}
			case 2:
			{
				PlayerData tempData = player.GetPlayerData();
				data.SaveData(&tempData);
				goodSelect = true;
				break;
			}
			default:
			{
				break;
			}
		}
	} while (goodSelect != true);
	
	
	//_______________________



	std::cout << "\n\nDelete saved file? (y/n)\n";
	
	char answer;
	std::cin >> answer;

	while (answer != 'y' && answer != 'n')
	{
		std::cout << "\n\nSorry, didn't catch that. Delete saved file? (y/n)\n";
		std::cin >> answer;
	}
	if (answer == 'y') data.DeleteData();

	return 1;
}

