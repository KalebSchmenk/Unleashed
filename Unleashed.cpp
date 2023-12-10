// Main starting point

#include <iostream>
#include <fstream>
#include "Player.h"
#include "FileManager.h"

using namespace std;

int main()
{
	cout << "Hello!\n\n";
	cout << "Please type a name for your character...\n\n";
	string newName;
	cin >> newName;

	cout << "\nPlease type a health amount for your character...\n\n";
	int newHealth;
	cin >> newHealth;

	PlayerObj player(newName, newHealth);

	DataManager data;
	PlayerData tempData = player.GetPlayerData();
	data.SaveData(&tempData);
	PlayerData newData = data.LoadData();

	cout << "Player name is " << newData.playerName << " and health is " << newData.playerHealth << endl;

	return 1;


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

