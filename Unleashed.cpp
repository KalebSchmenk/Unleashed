// Main starting point

#include <iostream>
#include <fstream>
#include "Player.h"

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


	// Data write and read
	std::fstream f; 

	// Write
	f.open("playerData.dat", ios::out);
	if (f)
	{
		PlayerData playerDataCopy = player.GetPlayerData();

		f << playerDataCopy.playerName << "" << std::endl;
		f << playerDataCopy.playerHealth << "" << std::endl;

		// Close
		f.close();
	}
	else
	{
		cout << "\n\nFailed to open a new data file...\n\n";
	}

	// Read
	f.open("playerData.dat", ios::in);
	if (f)
	{
		PlayerData readInData;

		int i = 0;
		string s;
		while (f)
		{
			std::getline(f, s);

			if (s.compare("") == 0) break;

			if (i == 0)
			{
				if (!s.empty() && s[s.length() - 1] == '\n') {
					s.erase(s.length() - 1);
				}
				readInData.playerName = s;
			}
			else
			{
				readInData.playerHealth = stoi(s);
			}
			i++;
		}

		cout << "\n\nFrom our data, we see that the player's name is " << readInData.playerName << " and their health is " << readInData.playerHealth;

		// Close
		f.close();
	}
	else
	{
		cout << "\n\nFailed to open a new data file...\n\n";
	}

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

