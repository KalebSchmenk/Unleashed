// Main starting point

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

#include "Player.h" // Player
#include "FileManager.h" // File Management
#include "Dungeon Headers/Dungeons.h" // All Dungeons



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


	// Game Related Data
	DataManager data;
	PlayerData playerData;
	PlayerObj player;


	// If player data file exists use it, if not create new player data
	try
	{
		auto temp = &playerData;

		data.LoadData(temp);	// LoadData() Throws an exception if it could not load a player data file which is why
		                        // we have it in a try-catch. Not neccessary, but an interesting implementation

		// If load successful
		std::cout << "Hello again, " << playerData.playerName << ", you have " << playerData.playerHealth << " HP " << "and are level " << playerData.playerLevel << "\n";

		player.SetPlayerData(playerData); // Handles name and health setting internally
		
		// Sleep for title screen. Otherwise it disappears too quickly
		Sleep(5000);
	} 
	catch (...)
	{
		// If load unsuccessful
		std::string name;

		std::cout << "Hello new player!\n\n";
		std::cout << "Please type a name for your character...\n\n";
		
		std::cin >> name;

		playerData.playerName = name;
		playerData.playerHealth = 15; // Default

		player.SetPlayerData(playerData); // Handles name and health setting internally
	}


	//_______________________
	//
	// 
	// Game
	// 
	//_______________________
	
	bool goodSelect = false;
	int menuSelect;

	// Menu select loop
	do
	{
		system("CLS"); // Clear console (Slow)

		std::cout << "MAIN MENU\n\n";
		std::cout << "Please select an option\n\n";
		std::cout << "\n1. Enter A Dungeon";
		std::cout << "\n2. View Inventory";
		std::cout << "\n3. Delete Character";
		std::cout << "\n4. Quit\n\n";
		std::cin >> menuSelect;

		switch (menuSelect)
		{
			case 1:
			{
				// Entering a dungeon
				DungeonDifficulty difficulty = Hard;
				Dungeon* enteredDungeon = new CaveDungeon(difficulty);
				
				enteredDungeon->StartDungeon(&player);
				break;
			}
			case 2:
			{
				std::cout << "Inventory not implemented";
				break;
			}
			case 3:
			{
				std::cout << "Delete character not implemented";
				break;
			}
			case 4:
			{
				//PlayerData tempData = player.GetPlayerData();
				//data.SaveData(&tempData);

				data.SaveData(playerData);
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

