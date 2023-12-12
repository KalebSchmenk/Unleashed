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
		throw std::invalid_argument("Couldn't open a new file");	
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
		// Hard coded for data formatted as follows:
		// Line 1: Player Name
		// Line 2: Player Health
		// Research into serialization was fruitless so far

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
		throw std::invalid_argument("No data file found");
	}

	// If the name or health are invalid arguments, default to these values.
	// Does it have to be a try catch? No, but it's interesting to have this be considered an exception
	try
	{
		if (readInData.playerName.compare("") == 0) throw std::invalid_argument("Name was empty");
	}
	catch (const std::invalid_argument& e)
	{
		readInData.playerName = "Phoenix";
	}
	
	try
	{
		if (readInData.playerHealth == -1) throw std::invalid_argument("Health was never overriden");
	}
	catch (const std::invalid_argument& e)
	{
		readInData.playerHealth = 15;
	}

	return readInData;
}


