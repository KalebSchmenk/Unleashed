#include <iostream>
#include <string>
#include "FileManager.h"


// A successful way of using the data manager is as follows
// 
// DataManager data;
// 
// Saving data:
// PlayerData tempData = player.GetPlayerData(); (Where player = PlayerObj)
// data.SaveData(&tempData);
// 
// Loading Data:
// PlayerData newData = data.LoadData();



// Data write and read
std::fstream f;

// Saves data
void DataManager::SaveData(PlayerData* playerData)
{
	// Write
	f.open("playerData.dat", std::ios::out);
	if (f)
	{
		f << playerData->playerName << std::endl;
		f << playerData->playerHealth << std::endl;

		// Close
		f.close();
	}
	else
	{
		std::cout << "\n\nFailed to open a new data file...\n\n";
	}
}

// Loads data
PlayerData DataManager::LoadData()
{
	PlayerData readInData;
	readInData.playerHealth = -1;
	readInData.playerName = "empty";

	// Read
	f.open("playerData.dat", std::ios::in);
	if (f)
	{
		int i = 0;
		std::string s;
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
		// Close
		f.close();
	}
	else
	{
		std::cout << "\n\nFailed to read a data file...\n\n";
	}
	return readInData;
}


